#include <helix/d3d11/d3d11.h>

#include <windows.h>

namespace helix::d3d11
{
    namespace
    {
        ::HMODULE d3d11 = nullptr;
        ::HMODULE dxgi = nullptr;
        PFN_D3D11_CREATE_DEVICE createDevice = nullptr;
        PFN_CREATE_DXGI_FACTORY2 createFactory2 = nullptr;

        template <typename T>
        T Symbol(::HMODULE module, const char* name)
        {
            return reinterpret_cast<T>(reinterpret_cast<void*>(GetProcAddress(module, name)));
        }
    }

    bool LoadLibraries()
    {
        if (!d3d11)
            d3d11 = LoadLibraryW(L"d3d11.dll");
        if (!dxgi)
            dxgi = LoadLibraryW(L"dxgi.dll");
        if (d3d11 && !createDevice)
            createDevice = Symbol<PFN_D3D11_CREATE_DEVICE>(d3d11, "D3D11CreateDevice");
        if (dxgi && !createFactory2)
            createFactory2 = Symbol<PFN_CREATE_DXGI_FACTORY2>(dxgi, "CreateDXGIFactory2");
        return createDevice && createFactory2;
    }

    void UnloadLibraries()
    {
        if (d3d11)
            FreeLibrary(d3d11);
        if (dxgi)
            FreeLibrary(dxgi);
        d3d11 = dxgi = nullptr;
        createDevice = nullptr;
        createFactory2 = nullptr;
    }

    HRESULT D3D11CreateDevice(IDXGIAdapter* adapter, D3D_DRIVER_TYPE driverType, HMODULE software, UINT flags, const D3D_FEATURE_LEVEL* levels,
                              UINT levelCount, UINT sdkVersion, ID3D11Device** device, D3D_FEATURE_LEVEL* chosenLevel, ID3D11DeviceContext** context)
    {
        if (!LoadLibraries())
            return E_FAIL;
        return createDevice(adapter, driverType, software, flags, levels, levelCount, sdkVersion, device, chosenLevel, context);
    }

    HRESULT CreateDXGIFactory2(UINT flags, const GUID& riid, void** factory)
    {
        if (!LoadLibraries())
            return E_FAIL;
        return createFactory2(flags, riid, factory);
    }
}
