#include <Helix/D3D11/D3D11.h>
#include <Helix/Testing/Test.h>

#include <cstdio>
#include <cstring>

using namespace helix::d3d11;

bool HelixD3D11SdkIidsMatch();
void HelixD3D11SdkConstants(unsigned long long* out);
int HelixD3D11ConstantCount();
void HelixD3D11OurConstants(unsigned long long* out, const char** names);

HX_TEST(D3D11Bindings, InterfaceIdsMatchTheSdk) { HX_CHECK(HelixD3D11SdkIidsMatch()); }

HX_TEST(D3D11Bindings, ConstantsMatchTheSdk)
{
    unsigned long long ours[128], sdk[128];
    const char* names[128];
    int n = HelixD3D11ConstantCount();
    HX_REQUIRE(n <= 128);
    HelixD3D11OurConstants(ours, names);
    HelixD3D11SdkConstants(sdk);
    for (int i = 0; i < n; i++)
    {
        if (ours[i] != sdk[i])
            std::printf("    %s: ours 0x%llx, sdk 0x%llx\n", names[i], ours[i], sdk[i]);
        HX_CHECK_EQ(ours[i], sdk[i]);
    }
}

HX_TEST(D3D11Bindings, RenderAndReadBack)
{
    HX_REQUIRE(LoadLibraries());
    const D3D_FEATURE_LEVEL levels[] = {D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0};
    ID3D11Device* device = nullptr;
    ID3D11DeviceContext* context = nullptr;
    D3D_FEATURE_LEVEL level{};
    HRESULT hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT, levels, 3, D3D11_SDK_VERSION,
                                   &device, &level, &context);
    if (Failed(hr))
        hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, 0, levels, 3, D3D11_SDK_VERSION, &device, &level, &context);
    HX_REQUIRE(Succeeded(hr) && device && context);
    HX_CHECK_EQ(device->GetFeatureLevel(), level);
    HX_CHECK_EQ(context->GetType(), D3D11_DEVICE_CONTEXT_IMMEDIATE);

    IDXGIDevice* dxgiDevice = nullptr;
    HX_REQUIRE(Succeeded(device->QueryInterface(&dxgiDevice)));
    IDXGIAdapter* adapter = nullptr;
    HX_REQUIRE(Succeeded(dxgiDevice->GetAdapter(&adapter)));
    DXGI_ADAPTER_DESC adapterDesc{};
    HX_CHECK(Succeeded(adapter->GetDesc(&adapterDesc)));
    std::printf("    adapter: %ls, feature level 0x%x\n", adapterDesc.Description, unsigned(level));

    IDXGIFactory2* factory = nullptr;
    HX_CHECK(Succeeded(CreateDXGIFactory2(0, IDXGIFactory2::Iid, reinterpret_cast<void**>(&factory))));
    IDXGIFactory5* factory5 = nullptr;
    if (factory && Succeeded(factory->QueryInterface(&factory5)))
    {
        BOOL tearing = 0;
        factory5->CheckFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING, &tearing, sizeof(tearing));
        std::printf("    tearing support: %d\n", tearing);
        SafeRelease(factory5);
    }

    D3D11_TEXTURE2D_DESC td{};
    td.Width = 8;
    td.Height = 8;
    td.MipLevels = 1;
    td.ArraySize = 1;
    td.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    td.SampleDesc = {1, 0};
    td.Usage = D3D11_USAGE_DEFAULT;
    td.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    ID3D11Texture2D* target = nullptr;
    HX_REQUIRE(Succeeded(device->CreateTexture2D(&td, nullptr, &target)));
    ID3D11RenderTargetView* rtv = nullptr;
    HX_REQUIRE(Succeeded(device->CreateRenderTargetView(target, nullptr, &rtv)));
    D3D11_RENDER_TARGET_VIEW_DESC rd{};
    rtv->GetDesc(&rd);
    HX_CHECK_EQ(rd.ViewDimension, D3D11_RTV_DIMENSION_TEXTURE2D);
    HX_CHECK_EQ(rd.Format, DXGI_FORMAT_R8G8B8A8_UNORM);

    td.Usage = D3D11_USAGE_STAGING;
    td.BindFlags = 0;
    td.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    ID3D11Texture2D* staging = nullptr;
    HX_REQUIRE(Succeeded(device->CreateTexture2D(&td, nullptr, &staging)));

    const FLOAT color[4] = {1.0f, 0.5f, 0.0f, 1.0f};
    context->ClearRenderTargetView(rtv, color);
    context->CopyResource(staging, target);
    D3D11_MAPPED_SUBRESOURCE mapped{};
    HX_REQUIRE(Succeeded(context->Map(staging, 0, D3D11_MAP_READ, 0, &mapped)));
    unsigned pixel;
    std::memcpy(&pixel, mapped.pData, 4);
    context->Unmap(staging, 0);
    HX_CHECK_EQ(pixel, 0xff0080ffu);

    D3D11_BUFFER_DESC bd{256, D3D11_USAGE_DYNAMIC, D3D11_BIND_CONSTANT_BUFFER, D3D11_CPU_ACCESS_WRITE, 0, 0};
    ID3D11Buffer* buffer = nullptr;
    HX_REQUIRE(Succeeded(device->CreateBuffer(&bd, nullptr, &buffer)));
    D3D11_BUFFER_DESC back{};
    buffer->GetDesc(&back);
    HX_CHECK_EQ(back.ByteWidth, 256u);
    HX_REQUIRE(Succeeded(context->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped)));
    std::memset(mapped.pData, 0, 256);
    context->Unmap(buffer, 0);

    ID3D11DeviceContext1* context1 = nullptr;
    if (Succeeded(context->QueryInterface(&context1)))
    {
        UINT first = 0, count = 16;
        context1->VSSetConstantBuffers1(0, 1, &buffer, &first, &count);
        ID3D11Buffer* bound = nullptr;
        UINT boundFirst = 99, boundCount = 99;
        context1->VSGetConstantBuffers1(0, 1, &bound, &boundFirst, &boundCount);
        HX_CHECK(bound == buffer);
        HX_CHECK_EQ(boundCount, 16u);
        SafeRelease(bound);
        SafeRelease(context1);
    }

    D3D11_QUERY_DESC qd{D3D11_QUERY_EVENT, 0};
    ID3D11Query* query = nullptr;
    HX_REQUIRE(Succeeded(device->CreateQuery(&qd, &query)));
    context->End(query);
    context->Flush();
    BOOL done = 0;
    for (int i = 0; i < 100000 && context->GetData(query, &done, sizeof(done), 0) != S_OK; i++)
    {
    }
    HX_CHECK(done != 0);

    SafeRelease(query);
    SafeRelease(buffer);
    SafeRelease(staging);
    SafeRelease(rtv);
    SafeRelease(target);
    SafeRelease(factory);
    SafeRelease(adapter);
    SafeRelease(dxgiDevice);
    context->ClearState();
    SafeRelease(context);
    HX_CHECK_EQ(device->Release(), 0ul);
}
