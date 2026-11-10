#pragma once

#include <cstddef>

#ifndef HX_D3D_CALL
#define HX_D3D_CALL __stdcall
#endif

namespace helix::d3d11
{
    using BOOL = int;
    using BYTE = unsigned char;
    using UINT8 = unsigned char;
    using WCHAR = wchar_t;
    using INT = int;
    using UINT = unsigned int;
    using UINT64 = unsigned long long;
    using LONG = long;
    using ULONG = unsigned long;
    using DWORD = unsigned long;
    using FLOAT = float;
    using SIZE_T = std::size_t;
    using HRESULT = long;
    using HANDLE = void*;
    using LPCSTR = const char*;
    using LPSTR = char*;
    using LPCWSTR = const wchar_t*;
    struct HWND__;
    struct HINSTANCE__;
    struct HMONITOR__;
    using HWND = HWND__*;
    using HMODULE = HINSTANCE__*;
    using HMONITOR = HMONITOR__*;
    using DXGI_USAGE = UINT;

    struct GUID
    {
        unsigned long Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[8];
    };

    constexpr bool operator==(const GUID& a, const GUID& b)
    {
        if (a.Data1 != b.Data1 || a.Data2 != b.Data2 || a.Data3 != b.Data3)
            return false;
        for (int i = 0; i < 8; i++)
            if (a.Data4[i] != b.Data4[i])
                return false;
        return true;
    }

    struct LUID
    {
        DWORD LowPart;
        LONG HighPart;
    };

    struct LARGE_INTEGER
    {
        long long QuadPart;
    };

    struct RECT
    {
        LONG left, top, right, bottom;
    };

    struct POINT
    {
        LONG x, y;
    };

    using D3D11_RECT = RECT;

    constexpr bool Succeeded(HRESULT hr) { return hr >= 0; }
    constexpr bool Failed(HRESULT hr) { return hr < 0; }

    enum DXGI_FORMAT : int
    {
        DXGI_FORMAT_UNKNOWN = 0,
        DXGI_FORMAT_R32G32B32A32_TYPELESS = 1,
        DXGI_FORMAT_R32G32B32A32_FLOAT = 2,
        DXGI_FORMAT_R32G32B32A32_UINT = 3,
        DXGI_FORMAT_R32G32B32A32_SINT = 4,
        DXGI_FORMAT_R32G32B32_TYPELESS = 5,
        DXGI_FORMAT_R32G32B32_FLOAT = 6,
        DXGI_FORMAT_R32G32B32_UINT = 7,
        DXGI_FORMAT_R32G32B32_SINT = 8,
        DXGI_FORMAT_R16G16B16A16_TYPELESS = 9,
        DXGI_FORMAT_R16G16B16A16_FLOAT = 10,
        DXGI_FORMAT_R16G16B16A16_UNORM = 11,
        DXGI_FORMAT_R16G16B16A16_UINT = 12,
        DXGI_FORMAT_R16G16B16A16_SNORM = 13,
        DXGI_FORMAT_R16G16B16A16_SINT = 14,
        DXGI_FORMAT_R32G32_TYPELESS = 15,
        DXGI_FORMAT_R32G32_FLOAT = 16,
        DXGI_FORMAT_R32G32_UINT = 17,
        DXGI_FORMAT_R32G32_SINT = 18,
        DXGI_FORMAT_R32G8X24_TYPELESS = 19,
        DXGI_FORMAT_D32_FLOAT_S8X24_UINT = 20,
        DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,
        DXGI_FORMAT_X32_TYPELESS_G8X24_UINT = 22,
        DXGI_FORMAT_R10G10B10A2_TYPELESS = 23,
        DXGI_FORMAT_R10G10B10A2_UNORM = 24,
        DXGI_FORMAT_R10G10B10A2_UINT = 25,
        DXGI_FORMAT_R11G11B10_FLOAT = 26,
        DXGI_FORMAT_R8G8B8A8_TYPELESS = 27,
        DXGI_FORMAT_R8G8B8A8_UNORM = 28,
        DXGI_FORMAT_R8G8B8A8_UNORM_SRGB = 29,
        DXGI_FORMAT_R8G8B8A8_UINT = 30,
        DXGI_FORMAT_R8G8B8A8_SNORM = 31,
        DXGI_FORMAT_R8G8B8A8_SINT = 32,
        DXGI_FORMAT_R16G16_TYPELESS = 33,
        DXGI_FORMAT_R16G16_FLOAT = 34,
        DXGI_FORMAT_R16G16_UNORM = 35,
        DXGI_FORMAT_R16G16_UINT = 36,
        DXGI_FORMAT_R16G16_SNORM = 37,
        DXGI_FORMAT_R16G16_SINT = 38,
        DXGI_FORMAT_R32_TYPELESS = 39,
        DXGI_FORMAT_D32_FLOAT = 40,
        DXGI_FORMAT_R32_FLOAT = 41,
        DXGI_FORMAT_R32_UINT = 42,
        DXGI_FORMAT_R32_SINT = 43,
        DXGI_FORMAT_R24G8_TYPELESS = 44,
        DXGI_FORMAT_D24_UNORM_S8_UINT = 45,
        DXGI_FORMAT_R24_UNORM_X8_TYPELESS = 46,
        DXGI_FORMAT_X24_TYPELESS_G8_UINT = 47,
        DXGI_FORMAT_R8G8_TYPELESS = 48,
        DXGI_FORMAT_R8G8_UNORM = 49,
        DXGI_FORMAT_R8G8_UINT = 50,
        DXGI_FORMAT_R8G8_SNORM = 51,
        DXGI_FORMAT_R8G8_SINT = 52,
        DXGI_FORMAT_R16_TYPELESS = 53,
        DXGI_FORMAT_R16_FLOAT = 54,
        DXGI_FORMAT_D16_UNORM = 55,
        DXGI_FORMAT_R16_UNORM = 56,
        DXGI_FORMAT_R16_UINT = 57,
        DXGI_FORMAT_R16_SNORM = 58,
        DXGI_FORMAT_R16_SINT = 59,
        DXGI_FORMAT_R8_TYPELESS = 60,
        DXGI_FORMAT_R8_UNORM = 61,
        DXGI_FORMAT_R8_UINT = 62,
        DXGI_FORMAT_R8_SNORM = 63,
        DXGI_FORMAT_R8_SINT = 64,
        DXGI_FORMAT_A8_UNORM = 65,
        DXGI_FORMAT_R1_UNORM = 66,
        DXGI_FORMAT_R9G9B9E5_SHAREDEXP = 67,
        DXGI_FORMAT_R8G8_B8G8_UNORM = 68,
        DXGI_FORMAT_G8R8_G8B8_UNORM = 69,
        DXGI_FORMAT_BC1_TYPELESS = 70,
        DXGI_FORMAT_BC1_UNORM = 71,
        DXGI_FORMAT_BC1_UNORM_SRGB = 72,
        DXGI_FORMAT_BC2_TYPELESS = 73,
        DXGI_FORMAT_BC2_UNORM = 74,
        DXGI_FORMAT_BC2_UNORM_SRGB = 75,
        DXGI_FORMAT_BC3_TYPELESS = 76,
        DXGI_FORMAT_BC3_UNORM = 77,
        DXGI_FORMAT_BC3_UNORM_SRGB = 78,
        DXGI_FORMAT_BC4_TYPELESS = 79,
        DXGI_FORMAT_BC4_UNORM = 80,
        DXGI_FORMAT_BC4_SNORM = 81,
        DXGI_FORMAT_BC5_TYPELESS = 82,
        DXGI_FORMAT_BC5_UNORM = 83,
        DXGI_FORMAT_BC5_SNORM = 84,
        DXGI_FORMAT_B5G6R5_UNORM = 85,
        DXGI_FORMAT_B5G5R5A1_UNORM = 86,
        DXGI_FORMAT_B8G8R8A8_UNORM = 87,
        DXGI_FORMAT_B8G8R8X8_UNORM = 88,
        DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
        DXGI_FORMAT_B8G8R8A8_TYPELESS = 90,
        DXGI_FORMAT_B8G8R8A8_UNORM_SRGB = 91,
        DXGI_FORMAT_B8G8R8X8_TYPELESS = 92,
        DXGI_FORMAT_B8G8R8X8_UNORM_SRGB = 93,
        DXGI_FORMAT_BC6H_TYPELESS = 94,
        DXGI_FORMAT_BC6H_UF16 = 95,
        DXGI_FORMAT_BC6H_SF16 = 96,
        DXGI_FORMAT_BC7_TYPELESS = 97,
        DXGI_FORMAT_BC7_UNORM = 98,
        DXGI_FORMAT_BC7_UNORM_SRGB = 99,
        DXGI_FORMAT_AYUV = 100,
        DXGI_FORMAT_Y410 = 101,
        DXGI_FORMAT_Y416 = 102,
        DXGI_FORMAT_NV12 = 103,
        DXGI_FORMAT_P010 = 104,
        DXGI_FORMAT_P016 = 105,
        DXGI_FORMAT_420_OPAQUE = 106,
        DXGI_FORMAT_YUY2 = 107,
        DXGI_FORMAT_Y210 = 108,
        DXGI_FORMAT_Y216 = 109,
        DXGI_FORMAT_NV11 = 110,
        DXGI_FORMAT_AI44 = 111,
        DXGI_FORMAT_IA44 = 112,
        DXGI_FORMAT_P8 = 113,
        DXGI_FORMAT_A8P8 = 114,
        DXGI_FORMAT_B4G4R4A4_UNORM = 115,
    };

    enum D3D_FEATURE_LEVEL : int
    {
        D3D_FEATURE_LEVEL_9_1 = 37120,
        D3D_FEATURE_LEVEL_9_2 = 37376,
        D3D_FEATURE_LEVEL_9_3 = 37632,
        D3D_FEATURE_LEVEL_10_0 = 40960,
        D3D_FEATURE_LEVEL_10_1 = 41216,
        D3D_FEATURE_LEVEL_11_0 = 45056,
        D3D_FEATURE_LEVEL_11_1 = 45312,
        D3D_FEATURE_LEVEL_12_0 = 49152,
        D3D_FEATURE_LEVEL_12_1 = 49408,
    };

    enum D3D_DRIVER_TYPE : int
    {
        D3D_DRIVER_TYPE_UNKNOWN = 0,
        D3D_DRIVER_TYPE_HARDWARE = 1,
        D3D_DRIVER_TYPE_REFERENCE = 2,
        D3D_DRIVER_TYPE_NULL = 3,
        D3D_DRIVER_TYPE_SOFTWARE = 4,
        D3D_DRIVER_TYPE_WARP = 5,
    };

    enum D3D11_CREATE_DEVICE_FLAG : int
    {
        D3D11_CREATE_DEVICE_SINGLETHREADED = 1,
        D3D11_CREATE_DEVICE_DEBUG = 2,
        D3D11_CREATE_DEVICE_SWITCH_TO_REF = 4,
        D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS = 8,
        D3D11_CREATE_DEVICE_BGRA_SUPPORT = 32,
        D3D11_CREATE_DEVICE_DEBUGGABLE = 64,
        D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY = 128,
        D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT = 256,
        D3D11_CREATE_DEVICE_VIDEO_SUPPORT = 2048,
    };

    enum D3D11_USAGE : int
    {
        D3D11_USAGE_DEFAULT = 0,
        D3D11_USAGE_IMMUTABLE = 1,
        D3D11_USAGE_DYNAMIC = 2,
        D3D11_USAGE_STAGING = 3,
    };

    enum D3D11_BIND_FLAG : int
    {
        D3D11_BIND_VERTEX_BUFFER = 1,
        D3D11_BIND_INDEX_BUFFER = 2,
        D3D11_BIND_CONSTANT_BUFFER = 4,
        D3D11_BIND_SHADER_RESOURCE = 8,
        D3D11_BIND_STREAM_OUTPUT = 16,
        D3D11_BIND_RENDER_TARGET = 32,
        D3D11_BIND_DEPTH_STENCIL = 64,
        D3D11_BIND_UNORDERED_ACCESS = 128,
        D3D11_BIND_DECODER = 512,
        D3D11_BIND_VIDEO_ENCODER = 1024,
    };

    enum D3D11_CPU_ACCESS_FLAG : int
    {
        D3D11_CPU_ACCESS_WRITE = 65536,
        D3D11_CPU_ACCESS_READ = 131072,
    };

    enum D3D11_RESOURCE_MISC_FLAG : int
    {
        D3D11_RESOURCE_MISC_GENERATE_MIPS = 1,
        D3D11_RESOURCE_MISC_SHARED = 2,
        D3D11_RESOURCE_MISC_TEXTURECUBE = 4,
        D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS = 16,
        D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS = 32,
        D3D11_RESOURCE_MISC_BUFFER_STRUCTURED = 64,
        D3D11_RESOURCE_MISC_RESOURCE_CLAMP = 128,
        D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX = 256,
        D3D11_RESOURCE_MISC_GDI_COMPATIBLE = 512,
        D3D11_RESOURCE_MISC_SHARED_NTHANDLE = 2048,
        D3D11_RESOURCE_MISC_RESTRICTED_CONTENT = 4096,
        D3D11_RESOURCE_MISC_TILE_POOL = 131072,
        D3D11_RESOURCE_MISC_TILED = 262144,
    };

    enum D3D11_MAP : int
    {
        D3D11_MAP_READ = 1,
        D3D11_MAP_WRITE = 2,
        D3D11_MAP_READ_WRITE = 3,
        D3D11_MAP_WRITE_DISCARD = 4,
        D3D11_MAP_WRITE_NO_OVERWRITE = 5,
    };

    enum D3D11_MAP_FLAG : int
    {
        D3D11_MAP_FLAG_DO_NOT_WAIT = 1048576,
    };

    enum D3D11_RESOURCE_DIMENSION : int
    {
        D3D11_RESOURCE_DIMENSION_UNKNOWN = 0,
        D3D11_RESOURCE_DIMENSION_BUFFER = 1,
        D3D11_RESOURCE_DIMENSION_TEXTURE1D = 2,
        D3D11_RESOURCE_DIMENSION_TEXTURE2D = 3,
        D3D11_RESOURCE_DIMENSION_TEXTURE3D = 4,
    };

    enum D3D_SRV_DIMENSION : int
    {
        D3D11_SRV_DIMENSION_UNKNOWN = 0,
        D3D11_SRV_DIMENSION_BUFFER = 1,
        D3D11_SRV_DIMENSION_TEXTURE1D = 2,
        D3D11_SRV_DIMENSION_TEXTURE1DARRAY = 3,
        D3D11_SRV_DIMENSION_TEXTURE2D = 4,
        D3D11_SRV_DIMENSION_TEXTURE2DARRAY = 5,
        D3D11_SRV_DIMENSION_TEXTURE2DMS = 6,
        D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY = 7,
        D3D11_SRV_DIMENSION_TEXTURE3D = 8,
        D3D11_SRV_DIMENSION_TEXTURECUBE = 9,
        D3D11_SRV_DIMENSION_TEXTURECUBEARRAY = 10,
        D3D11_SRV_DIMENSION_BUFFEREX = 11,
    };
    using D3D11_SRV_DIMENSION = D3D_SRV_DIMENSION;

    enum D3D11_RTV_DIMENSION : int
    {
        D3D11_RTV_DIMENSION_UNKNOWN = 0,
        D3D11_RTV_DIMENSION_BUFFER = 1,
        D3D11_RTV_DIMENSION_TEXTURE1D = 2,
        D3D11_RTV_DIMENSION_TEXTURE1DARRAY = 3,
        D3D11_RTV_DIMENSION_TEXTURE2D = 4,
        D3D11_RTV_DIMENSION_TEXTURE2DARRAY = 5,
        D3D11_RTV_DIMENSION_TEXTURE2DMS = 6,
        D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY = 7,
        D3D11_RTV_DIMENSION_TEXTURE3D = 8,
    };

    enum D3D11_DSV_DIMENSION : int
    {
        D3D11_DSV_DIMENSION_UNKNOWN = 0,
        D3D11_DSV_DIMENSION_TEXTURE1D = 1,
        D3D11_DSV_DIMENSION_TEXTURE1DARRAY = 2,
        D3D11_DSV_DIMENSION_TEXTURE2D = 3,
        D3D11_DSV_DIMENSION_TEXTURE2DARRAY = 4,
        D3D11_DSV_DIMENSION_TEXTURE2DMS = 5,
        D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY = 6,
    };

    enum D3D11_UAV_DIMENSION : int
    {
        D3D11_UAV_DIMENSION_UNKNOWN = 0,
        D3D11_UAV_DIMENSION_BUFFER = 1,
        D3D11_UAV_DIMENSION_TEXTURE1D = 2,
        D3D11_UAV_DIMENSION_TEXTURE1DARRAY = 3,
        D3D11_UAV_DIMENSION_TEXTURE2D = 4,
        D3D11_UAV_DIMENSION_TEXTURE2DARRAY = 5,
        D3D11_UAV_DIMENSION_TEXTURE3D = 8,
    };

    enum D3D11_BUFFEREX_SRV_FLAG : int
    {
        D3D11_BUFFEREX_SRV_FLAG_RAW = 1,
    };

    enum D3D11_BUFFER_UAV_FLAG : int
    {
        D3D11_BUFFER_UAV_FLAG_RAW = 1,
        D3D11_BUFFER_UAV_FLAG_APPEND = 2,
        D3D11_BUFFER_UAV_FLAG_COUNTER = 4,
    };

    enum D3D11_DSV_FLAG : int
    {
        D3D11_DSV_READ_ONLY_DEPTH = 1,
        D3D11_DSV_READ_ONLY_STENCIL = 2,
    };

    enum D3D11_INPUT_CLASSIFICATION : int
    {
        D3D11_INPUT_PER_VERTEX_DATA = 0,
        D3D11_INPUT_PER_INSTANCE_DATA = 1,
    };

    enum D3D11_FILL_MODE : int
    {
        D3D11_FILL_WIREFRAME = 2,
        D3D11_FILL_SOLID = 3,
    };

    enum D3D11_CULL_MODE : int
    {
        D3D11_CULL_NONE = 1,
        D3D11_CULL_FRONT = 2,
        D3D11_CULL_BACK = 3,
    };

    enum D3D11_COMPARISON_FUNC : int
    {
        D3D11_COMPARISON_NEVER = 1,
        D3D11_COMPARISON_LESS = 2,
        D3D11_COMPARISON_EQUAL = 3,
        D3D11_COMPARISON_LESS_EQUAL = 4,
        D3D11_COMPARISON_GREATER = 5,
        D3D11_COMPARISON_NOT_EQUAL = 6,
        D3D11_COMPARISON_GREATER_EQUAL = 7,
        D3D11_COMPARISON_ALWAYS = 8,
    };

    enum D3D11_DEPTH_WRITE_MASK : int
    {
        D3D11_DEPTH_WRITE_MASK_ZERO = 0,
        D3D11_DEPTH_WRITE_MASK_ALL = 1,
    };

    enum D3D11_STENCIL_OP : int
    {
        D3D11_STENCIL_OP_KEEP = 1,
        D3D11_STENCIL_OP_ZERO = 2,
        D3D11_STENCIL_OP_REPLACE = 3,
        D3D11_STENCIL_OP_INCR_SAT = 4,
        D3D11_STENCIL_OP_DECR_SAT = 5,
        D3D11_STENCIL_OP_INVERT = 6,
        D3D11_STENCIL_OP_INCR = 7,
        D3D11_STENCIL_OP_DECR = 8,
    };

    enum D3D11_BLEND : int
    {
        D3D11_BLEND_ZERO = 1,
        D3D11_BLEND_ONE = 2,
        D3D11_BLEND_SRC_COLOR = 3,
        D3D11_BLEND_INV_SRC_COLOR = 4,
        D3D11_BLEND_SRC_ALPHA = 5,
        D3D11_BLEND_INV_SRC_ALPHA = 6,
        D3D11_BLEND_DEST_ALPHA = 7,
        D3D11_BLEND_INV_DEST_ALPHA = 8,
        D3D11_BLEND_DEST_COLOR = 9,
        D3D11_BLEND_INV_DEST_COLOR = 10,
        D3D11_BLEND_SRC_ALPHA_SAT = 11,
        D3D11_BLEND_BLEND_FACTOR = 14,
        D3D11_BLEND_INV_BLEND_FACTOR = 15,
        D3D11_BLEND_SRC1_COLOR = 16,
        D3D11_BLEND_INV_SRC1_COLOR = 17,
        D3D11_BLEND_SRC1_ALPHA = 18,
        D3D11_BLEND_INV_SRC1_ALPHA = 19,
    };

    enum D3D11_BLEND_OP : int
    {
        D3D11_BLEND_OP_ADD = 1,
        D3D11_BLEND_OP_SUBTRACT = 2,
        D3D11_BLEND_OP_REV_SUBTRACT = 3,
        D3D11_BLEND_OP_MIN = 4,
        D3D11_BLEND_OP_MAX = 5,
    };

    enum D3D11_LOGIC_OP : int
    {
        D3D11_LOGIC_OP_CLEAR = 0,
        D3D11_LOGIC_OP_SET = 1,
        D3D11_LOGIC_OP_COPY = 2,
        D3D11_LOGIC_OP_COPY_INVERTED = 3,
        D3D11_LOGIC_OP_NOOP = 4,
        D3D11_LOGIC_OP_INVERT = 5,
        D3D11_LOGIC_OP_AND = 6,
        D3D11_LOGIC_OP_NAND = 7,
        D3D11_LOGIC_OP_OR = 8,
        D3D11_LOGIC_OP_NOR = 9,
        D3D11_LOGIC_OP_XOR = 10,
        D3D11_LOGIC_OP_EQUIV = 11,
        D3D11_LOGIC_OP_AND_REVERSE = 12,
        D3D11_LOGIC_OP_AND_INVERTED = 13,
        D3D11_LOGIC_OP_OR_REVERSE = 14,
        D3D11_LOGIC_OP_OR_INVERTED = 15,
    };

    enum D3D11_COLOR_WRITE_ENABLE : int
    {
        D3D11_COLOR_WRITE_ENABLE_RED = 1,
        D3D11_COLOR_WRITE_ENABLE_GREEN = 2,
        D3D11_COLOR_WRITE_ENABLE_BLUE = 4,
        D3D11_COLOR_WRITE_ENABLE_ALPHA = 8,
        D3D11_COLOR_WRITE_ENABLE_ALL = 15,
    };

    enum D3D11_FILTER : int
    {
        D3D11_FILTER_MIN_MAG_MIP_POINT = 0,
        D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR = 1,
        D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 4,
        D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR = 5,
        D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT = 16,
        D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 17,
        D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT = 20,
        D3D11_FILTER_MIN_MAG_MIP_LINEAR = 21,
        D3D11_FILTER_ANISOTROPIC = 85,
        D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT = 128,
        D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 148,
        D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR = 149,
        D3D11_FILTER_COMPARISON_ANISOTROPIC = 213,
        D3D11_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR = 277,
        D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR = 405,
    };

    enum D3D11_TEXTURE_ADDRESS_MODE : int
    {
        D3D11_TEXTURE_ADDRESS_WRAP = 1,
        D3D11_TEXTURE_ADDRESS_MIRROR = 2,
        D3D11_TEXTURE_ADDRESS_CLAMP = 3,
        D3D11_TEXTURE_ADDRESS_BORDER = 4,
        D3D11_TEXTURE_ADDRESS_MIRROR_ONCE = 5,
    };

    enum D3D11_CLEAR_FLAG : int
    {
        D3D11_CLEAR_DEPTH = 1,
        D3D11_CLEAR_STENCIL = 2,
    };

    enum D3D_PRIMITIVE_TOPOLOGY : int
    {
        D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED = 0,
        D3D11_PRIMITIVE_TOPOLOGY_POINTLIST = 1,
        D3D11_PRIMITIVE_TOPOLOGY_LINELIST = 2,
        D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP = 3,
        D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST = 4,
        D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,
        D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10,
        D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ = 11,
        D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ = 12,
        D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ = 13,
        D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33,
        D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST = 34,
        D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST = 35,
        D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST = 36,
        D3D11_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST = 37,
        D3D11_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST = 38,
        D3D11_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST = 39,
        D3D11_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST = 40,
        D3D11_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST = 41,
        D3D11_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = 42,
        D3D11_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = 43,
        D3D11_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = 44,
        D3D11_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = 45,
        D3D11_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = 46,
        D3D11_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = 47,
        D3D11_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = 48,
        D3D11_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = 49,
        D3D11_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = 50,
        D3D11_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = 51,
        D3D11_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = 52,
        D3D11_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = 53,
        D3D11_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = 54,
        D3D11_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = 55,
        D3D11_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = 56,
        D3D11_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = 57,
        D3D11_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = 58,
        D3D11_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = 59,
        D3D11_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = 60,
        D3D11_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = 61,
        D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = 62,
        D3D11_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = 63,
        D3D11_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = 64,
    };
    using D3D11_PRIMITIVE_TOPOLOGY = D3D_PRIMITIVE_TOPOLOGY;

    enum D3D11_QUERY : int
    {
        D3D11_QUERY_EVENT = 0,
        D3D11_QUERY_OCCLUSION = 1,
        D3D11_QUERY_TIMESTAMP = 2,
        D3D11_QUERY_TIMESTAMP_DISJOINT = 3,
        D3D11_QUERY_PIPELINE_STATISTICS = 4,
        D3D11_QUERY_OCCLUSION_PREDICATE = 5,
        D3D11_QUERY_SO_STATISTICS = 6,
        D3D11_QUERY_SO_OVERFLOW_PREDICATE = 7,
    };

    enum D3D11_ASYNC_GETDATA_FLAG : int
    {
        D3D11_ASYNC_GETDATA_DONOTFLUSH = 1,
    };

    enum D3D11_COUNTER : int
    {
        D3D11_COUNTER_DEVICE_DEPENDENT_0 = 1073741824,
    };

    enum D3D11_COUNTER_TYPE : int
    {
        D3D11_COUNTER_TYPE_FLOAT32 = 0,
        D3D11_COUNTER_TYPE_UINT16 = 1,
        D3D11_COUNTER_TYPE_UINT32 = 2,
        D3D11_COUNTER_TYPE_UINT64 = 3,
    };

    enum D3D11_DEVICE_CONTEXT_TYPE : int
    {
        D3D11_DEVICE_CONTEXT_IMMEDIATE = 0,
        D3D11_DEVICE_CONTEXT_DEFERRED = 1,
    };

    enum D3D11_FEATURE : int
    {
        D3D11_FEATURE_THREADING = 0,
        D3D11_FEATURE_DOUBLES = 1,
        D3D11_FEATURE_FORMAT_SUPPORT = 2,
        D3D11_FEATURE_FORMAT_SUPPORT2 = 3,
        D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS = 4,
        D3D11_FEATURE_D3D11_OPTIONS = 5,
        D3D11_FEATURE_ARCHITECTURE_INFO = 6,
        D3D11_FEATURE_D3D9_OPTIONS = 7,
        D3D11_FEATURE_SHADER_MIN_PRECISION_SUPPORT = 8,
        D3D11_FEATURE_D3D9_SHADOW_SUPPORT = 9,
        D3D11_FEATURE_D3D11_OPTIONS1 = 10,
        D3D11_FEATURE_D3D9_SIMPLE_INSTANCING_SUPPORT = 11,
        D3D11_FEATURE_MARKER_SUPPORT = 12,
        D3D11_FEATURE_D3D9_OPTIONS1 = 13,
        D3D11_FEATURE_D3D11_OPTIONS2 = 14,
        D3D11_FEATURE_D3D11_OPTIONS3 = 15,
        D3D11_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT = 16,
        D3D11_FEATURE_D3D11_OPTIONS4 = 17,
        D3D11_FEATURE_SHADER_CACHE = 18,
        D3D11_FEATURE_D3D11_OPTIONS5 = 19,
    };

    enum D3D11_COPY_FLAGS : int
    {
        D3D11_COPY_NO_OVERWRITE = 1,
        D3D11_COPY_DISCARD = 2,
    };

    enum D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG : int
    {
        D3D11_1_CREATE_DEVICE_CONTEXT_STATE_SINGLETHREADED = 1,
    };

    enum DXGI_MODE_SCANLINE_ORDER : int
    {
        DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED = 0,
        DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE = 1,
        DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST = 2,
        DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST = 3,
    };

    enum DXGI_MODE_SCALING : int
    {
        DXGI_MODE_SCALING_UNSPECIFIED = 0,
        DXGI_MODE_SCALING_CENTERED = 1,
        DXGI_MODE_SCALING_STRETCHED = 2,
    };

    enum DXGI_MODE_ROTATION : int
    {
        DXGI_MODE_ROTATION_UNSPECIFIED = 0,
        DXGI_MODE_ROTATION_IDENTITY = 1,
        DXGI_MODE_ROTATION_ROTATE90 = 2,
        DXGI_MODE_ROTATION_ROTATE180 = 3,
        DXGI_MODE_ROTATION_ROTATE270 = 4,
    };

    enum DXGI_SWAP_EFFECT : int
    {
        DXGI_SWAP_EFFECT_DISCARD = 0,
        DXGI_SWAP_EFFECT_SEQUENTIAL = 1,
        DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 3,
        DXGI_SWAP_EFFECT_FLIP_DISCARD = 4,
    };

    enum DXGI_SCALING : int
    {
        DXGI_SCALING_STRETCH = 0,
        DXGI_SCALING_NONE = 1,
        DXGI_SCALING_ASPECT_RATIO_STRETCH = 2,
    };

    enum DXGI_ALPHA_MODE : int
    {
        DXGI_ALPHA_MODE_UNSPECIFIED = 0,
        DXGI_ALPHA_MODE_PREMULTIPLIED = 1,
        DXGI_ALPHA_MODE_STRAIGHT = 2,
        DXGI_ALPHA_MODE_IGNORE = 3,
    };

    enum DXGI_SWAP_CHAIN_FLAG : int
    {
        DXGI_SWAP_CHAIN_FLAG_NONPREROTATED = 1,
        DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH = 2,
        DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE = 4,
        DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT = 64,
        DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING = 2048,
    };

    enum DXGI_COLOR_SPACE_TYPE : int
    {
        DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709 = 0,
        DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709 = 1,
        DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020 = 12,
        DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020 = 17,
    };

    enum DXGI_FEATURE : int
    {
        DXGI_FEATURE_PRESENT_ALLOW_TEARING = 0,
    };

    enum DXGI_ADAPTER_FLAG : int
    {
        DXGI_ADAPTER_FLAG_NONE = 0,
        DXGI_ADAPTER_FLAG_REMOTE = 1,
        DXGI_ADAPTER_FLAG_SOFTWARE = 2,
    };

    inline constexpr UINT DXGI_USAGE_SHADER_INPUT = 0x00000010;
    inline constexpr UINT DXGI_USAGE_RENDER_TARGET_OUTPUT = 0x00000020;
    inline constexpr UINT DXGI_USAGE_BACK_BUFFER = 0x00000040;
    inline constexpr UINT DXGI_USAGE_SHARED = 0x00000080;
    inline constexpr UINT DXGI_USAGE_READ_ONLY = 0x00000100;
    inline constexpr UINT DXGI_USAGE_UNORDERED_ACCESS = 0x00000400;
    inline constexpr UINT DXGI_PRESENT_TEST = 0x00000001;
    inline constexpr UINT DXGI_PRESENT_DO_NOT_SEQUENCE = 0x00000002;
    inline constexpr UINT DXGI_PRESENT_RESTART = 0x00000004;
    inline constexpr UINT DXGI_PRESENT_DO_NOT_WAIT = 0x00000008;
    inline constexpr UINT DXGI_PRESENT_ALLOW_TEARING = 0x00000200;
    inline constexpr UINT DXGI_MWA_NO_WINDOW_CHANGES = 1;
    inline constexpr UINT DXGI_MWA_NO_ALT_ENTER = 2;
    inline constexpr UINT DXGI_MWA_NO_PRINT_SCREEN = 4;
    inline constexpr UINT DXGI_CREATE_FACTORY_DEBUG = 0x1;
    inline constexpr UINT D3D11_SDK_VERSION = 7;
    inline constexpr UINT D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT = 8;
    inline constexpr UINT D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT = 14;
    inline constexpr UINT D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT = 128;
    inline constexpr UINT D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT = 16;
    inline constexpr UINT D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT = 32;
    inline constexpr UINT D3D11_1_UAV_SLOT_COUNT = 64;
    inline constexpr UINT D3D11_PS_CS_UAV_REGISTER_COUNT = 8;
    inline constexpr UINT D3D11_APPEND_ALIGNED_ELEMENT = 0xffffffff;
    inline constexpr UINT D3D11_DEFAULT_SAMPLE_MASK = 0xffffffff;
    inline constexpr UINT D3D11_REQ_TEXTURE2D_U_OR_V_DIMENSION = 16384;
    inline constexpr UINT D3D11_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL = 0xffffffff;
    inline constexpr UINT D3D11_KEEP_UNORDERED_ACCESS_VIEWS = 0xffffffff;
    inline constexpr HRESULT DXGI_ERROR_DEVICE_REMOVED = HRESULT(0x887A0005);
    inline constexpr HRESULT DXGI_ERROR_DEVICE_HUNG = HRESULT(0x887A0006);
    inline constexpr HRESULT DXGI_ERROR_DEVICE_RESET = HRESULT(0x887A0007);
    inline constexpr HRESULT DXGI_ERROR_WAS_STILL_DRAWING = HRESULT(0x887A000A);
    inline constexpr HRESULT DXGI_ERROR_NOT_FOUND = HRESULT(0x887A0002);
    inline constexpr HRESULT DXGI_ERROR_UNSUPPORTED = HRESULT(0x887A0004);
    inline constexpr HRESULT DXGI_STATUS_OCCLUDED = HRESULT(0x087A0001);
    inline constexpr HRESULT S_OK = 0;
    inline constexpr HRESULT S_FALSE = 1;
    inline constexpr HRESULT E_INVALIDARG = HRESULT(0x80070057);
    inline constexpr HRESULT E_OUTOFMEMORY = HRESULT(0x8007000E);
    inline constexpr HRESULT E_FAIL = HRESULT(0x80004005);
    inline constexpr HRESULT E_NOINTERFACE = HRESULT(0x80004002);

    struct DXGI_RATIONAL
    {
        UINT Numerator;
        UINT Denominator;
    };

    struct DXGI_SAMPLE_DESC
    {
        UINT Count;
        UINT Quality;
    };

    struct DXGI_RGBA
    {
        float r;
        float g;
        float b;
        float a;
    };

    struct DXGI_MATRIX_3X2_F
    {
        FLOAT _11;
        FLOAT _12;
        FLOAT _21;
        FLOAT _22;
        FLOAT _31;
        FLOAT _32;
    };

    struct DXGI_MODE_DESC
    {
        UINT Width;
        UINT Height;
        DXGI_RATIONAL RefreshRate;
        DXGI_FORMAT Format;
        DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
        DXGI_MODE_SCALING Scaling;
    };

    struct DXGI_SWAP_CHAIN_DESC
    {
        DXGI_MODE_DESC BufferDesc;
        DXGI_SAMPLE_DESC SampleDesc;
        DXGI_USAGE BufferUsage;
        UINT BufferCount;
        HWND OutputWindow;
        BOOL Windowed;
        DXGI_SWAP_EFFECT SwapEffect;
        UINT Flags;
    };

    struct DXGI_SWAP_CHAIN_DESC1
    {
        UINT Width;
        UINT Height;
        DXGI_FORMAT Format;
        BOOL Stereo;
        DXGI_SAMPLE_DESC SampleDesc;
        DXGI_USAGE BufferUsage;
        UINT BufferCount;
        DXGI_SCALING Scaling;
        DXGI_SWAP_EFFECT SwapEffect;
        DXGI_ALPHA_MODE AlphaMode;
        UINT Flags;
    };

    struct DXGI_SWAP_CHAIN_FULLSCREEN_DESC
    {
        DXGI_RATIONAL RefreshRate;
        DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
        DXGI_MODE_SCALING Scaling;
        BOOL Windowed;
    };

    struct DXGI_PRESENT_PARAMETERS
    {
        UINT DirtyRectsCount;
        RECT* pDirtyRects;
        RECT* pScrollRect;
        POINT* pScrollOffset;
    };

    struct DXGI_ADAPTER_DESC
    {
        WCHAR Description[128];
        UINT VendorId;
        UINT DeviceId;
        UINT SubSysId;
        UINT Revision;
        SIZE_T DedicatedVideoMemory;
        SIZE_T DedicatedSystemMemory;
        SIZE_T SharedSystemMemory;
        LUID AdapterLuid;
    };

    struct DXGI_ADAPTER_DESC1
    {
        WCHAR Description[128];
        UINT VendorId;
        UINT DeviceId;
        UINT SubSysId;
        UINT Revision;
        SIZE_T DedicatedVideoMemory;
        SIZE_T DedicatedSystemMemory;
        SIZE_T SharedSystemMemory;
        LUID AdapterLuid;
        UINT Flags;
    };

    struct DXGI_OUTPUT_DESC
    {
        WCHAR DeviceName[32];
        RECT DesktopCoordinates;
        BOOL AttachedToDesktop;
        DXGI_MODE_ROTATION Rotation;
        HMONITOR Monitor;
    };

    struct DXGI_SURFACE_DESC
    {
        UINT Width;
        UINT Height;
        DXGI_FORMAT Format;
        DXGI_SAMPLE_DESC SampleDesc;
    };

    struct DXGI_MAPPED_RECT
    {
        INT Pitch;
        BYTE* pBits;
    };

    struct DXGI_FRAME_STATISTICS
    {
        UINT PresentCount;
        UINT PresentRefreshCount;
        UINT SyncRefreshCount;
        LARGE_INTEGER SyncQPCTime;
        LARGE_INTEGER SyncGPUTime;
    };

    struct D3D11_BUFFER_DESC
    {
        UINT ByteWidth;
        D3D11_USAGE Usage;
        UINT BindFlags;
        UINT CPUAccessFlags;
        UINT MiscFlags;
        UINT StructureByteStride;
    };

    struct D3D11_SUBRESOURCE_DATA
    {
        const void* pSysMem;
        UINT SysMemPitch;
        UINT SysMemSlicePitch;
    };

    struct D3D11_MAPPED_SUBRESOURCE
    {
        void* pData;
        UINT RowPitch;
        UINT DepthPitch;
    };

    struct D3D11_TEXTURE1D_DESC
    {
        UINT Width;
        UINT MipLevels;
        UINT ArraySize;
        DXGI_FORMAT Format;
        D3D11_USAGE Usage;
        UINT BindFlags;
        UINT CPUAccessFlags;
        UINT MiscFlags;
    };

    struct D3D11_TEXTURE2D_DESC
    {
        UINT Width;
        UINT Height;
        UINT MipLevels;
        UINT ArraySize;
        DXGI_FORMAT Format;
        DXGI_SAMPLE_DESC SampleDesc;
        D3D11_USAGE Usage;
        UINT BindFlags;
        UINT CPUAccessFlags;
        UINT MiscFlags;
    };

    struct D3D11_TEXTURE3D_DESC
    {
        UINT Width;
        UINT Height;
        UINT Depth;
        UINT MipLevels;
        DXGI_FORMAT Format;
        D3D11_USAGE Usage;
        UINT BindFlags;
        UINT CPUAccessFlags;
        UINT MiscFlags;
    };

    struct D3D11_BUFFER_SRV
    {
        union
        {
            UINT FirstElement;
            UINT ElementOffset;
        };
        union
        {
            UINT NumElements;
            UINT ElementWidth;
        };
    };

    struct D3D11_BUFFEREX_SRV
    {
        UINT FirstElement;
        UINT NumElements;
        UINT Flags;
    };

    struct D3D11_TEX1D_SRV
    {
        UINT MostDetailedMip;
        UINT MipLevels;
    };

    struct D3D11_TEX1D_ARRAY_SRV
    {
        UINT MostDetailedMip;
        UINT MipLevels;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX2D_SRV
    {
        UINT MostDetailedMip;
        UINT MipLevels;
    };

    struct D3D11_TEX2D_ARRAY_SRV
    {
        UINT MostDetailedMip;
        UINT MipLevels;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX2DMS_SRV
    {
        UINT UnusedField_NothingToDefine;
    };

    struct D3D11_TEX2DMS_ARRAY_SRV
    {
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX3D_SRV
    {
        UINT MostDetailedMip;
        UINT MipLevels;
    };

    struct D3D11_TEXCUBE_SRV
    {
        UINT MostDetailedMip;
        UINT MipLevels;
    };

    struct D3D11_TEXCUBE_ARRAY_SRV
    {
        UINT MostDetailedMip;
        UINT MipLevels;
        UINT First2DArrayFace;
        UINT NumCubes;
    };

    struct D3D11_SHADER_RESOURCE_VIEW_DESC
    {
        DXGI_FORMAT Format;
        D3D_SRV_DIMENSION ViewDimension;
        union
        {
            D3D11_BUFFER_SRV Buffer;
            D3D11_TEX1D_SRV Texture1D;
            D3D11_TEX1D_ARRAY_SRV Texture1DArray;
            D3D11_TEX2D_SRV Texture2D;
            D3D11_TEX2D_ARRAY_SRV Texture2DArray;
            D3D11_TEX2DMS_SRV Texture2DMS;
            D3D11_TEX2DMS_ARRAY_SRV Texture2DMSArray;
            D3D11_TEX3D_SRV Texture3D;
            D3D11_TEXCUBE_SRV TextureCube;
            D3D11_TEXCUBE_ARRAY_SRV TextureCubeArray;
            D3D11_BUFFEREX_SRV BufferEx;
        };
    };

    struct D3D11_BUFFER_RTV
    {
        union
        {
            UINT FirstElement;
            UINT ElementOffset;
        };
        union
        {
            UINT NumElements;
            UINT ElementWidth;
        };
    };

    struct D3D11_TEX1D_RTV
    {
        UINT MipSlice;
    };

    struct D3D11_TEX1D_ARRAY_RTV
    {
        UINT MipSlice;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX2D_RTV
    {
        UINT MipSlice;
    };

    struct D3D11_TEX2DMS_RTV
    {
        UINT UnusedField_NothingToDefine;
    };

    struct D3D11_TEX2D_ARRAY_RTV
    {
        UINT MipSlice;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX2DMS_ARRAY_RTV
    {
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX3D_RTV
    {
        UINT MipSlice;
        UINT FirstWSlice;
        UINT WSize;
    };

    struct D3D11_RENDER_TARGET_VIEW_DESC
    {
        DXGI_FORMAT Format;
        D3D11_RTV_DIMENSION ViewDimension;
        union
        {
            D3D11_BUFFER_RTV Buffer;
            D3D11_TEX1D_RTV Texture1D;
            D3D11_TEX1D_ARRAY_RTV Texture1DArray;
            D3D11_TEX2D_RTV Texture2D;
            D3D11_TEX2D_ARRAY_RTV Texture2DArray;
            D3D11_TEX2DMS_RTV Texture2DMS;
            D3D11_TEX2DMS_ARRAY_RTV Texture2DMSArray;
            D3D11_TEX3D_RTV Texture3D;
        };
    };

    struct D3D11_TEX1D_DSV
    {
        UINT MipSlice;
    };

    struct D3D11_TEX1D_ARRAY_DSV
    {
        UINT MipSlice;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX2D_DSV
    {
        UINT MipSlice;
    };

    struct D3D11_TEX2D_ARRAY_DSV
    {
        UINT MipSlice;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX2DMS_DSV
    {
        UINT UnusedField_NothingToDefine;
    };

    struct D3D11_TEX2DMS_ARRAY_DSV
    {
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_DEPTH_STENCIL_VIEW_DESC
    {
        DXGI_FORMAT Format;
        D3D11_DSV_DIMENSION ViewDimension;
        UINT Flags;
        union
        {
            D3D11_TEX1D_DSV Texture1D;
            D3D11_TEX1D_ARRAY_DSV Texture1DArray;
            D3D11_TEX2D_DSV Texture2D;
            D3D11_TEX2D_ARRAY_DSV Texture2DArray;
            D3D11_TEX2DMS_DSV Texture2DMS;
            D3D11_TEX2DMS_ARRAY_DSV Texture2DMSArray;
        };
    };

    struct D3D11_BUFFER_UAV
    {
        UINT FirstElement;
        UINT NumElements;
        UINT Flags;
    };

    struct D3D11_TEX1D_UAV
    {
        UINT MipSlice;
    };

    struct D3D11_TEX1D_ARRAY_UAV
    {
        UINT MipSlice;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX2D_UAV
    {
        UINT MipSlice;
    };

    struct D3D11_TEX2D_ARRAY_UAV
    {
        UINT MipSlice;
        UINT FirstArraySlice;
        UINT ArraySize;
    };

    struct D3D11_TEX3D_UAV
    {
        UINT MipSlice;
        UINT FirstWSlice;
        UINT WSize;
    };

    struct D3D11_UNORDERED_ACCESS_VIEW_DESC
    {
        DXGI_FORMAT Format;
        D3D11_UAV_DIMENSION ViewDimension;
        union
        {
            D3D11_BUFFER_UAV Buffer;
            D3D11_TEX1D_UAV Texture1D;
            D3D11_TEX1D_ARRAY_UAV Texture1DArray;
            D3D11_TEX2D_UAV Texture2D;
            D3D11_TEX2D_ARRAY_UAV Texture2DArray;
            D3D11_TEX3D_UAV Texture3D;
        };
    };

    struct D3D11_INPUT_ELEMENT_DESC
    {
        LPCSTR SemanticName;
        UINT SemanticIndex;
        DXGI_FORMAT Format;
        UINT InputSlot;
        UINT AlignedByteOffset;
        D3D11_INPUT_CLASSIFICATION InputSlotClass;
        UINT InstanceDataStepRate;
    };

    struct D3D11_SO_DECLARATION_ENTRY
    {
        UINT Stream;
        LPCSTR SemanticName;
        UINT SemanticIndex;
        BYTE StartComponent;
        BYTE ComponentCount;
        BYTE OutputSlot;
    };

    struct D3D11_RENDER_TARGET_BLEND_DESC
    {
        BOOL BlendEnable;
        D3D11_BLEND SrcBlend;
        D3D11_BLEND DestBlend;
        D3D11_BLEND_OP BlendOp;
        D3D11_BLEND SrcBlendAlpha;
        D3D11_BLEND DestBlendAlpha;
        D3D11_BLEND_OP BlendOpAlpha;
        UINT8 RenderTargetWriteMask;
    };

    struct D3D11_BLEND_DESC
    {
        BOOL AlphaToCoverageEnable;
        BOOL IndependentBlendEnable;
        D3D11_RENDER_TARGET_BLEND_DESC RenderTarget[8];
    };

    struct D3D11_RENDER_TARGET_BLEND_DESC1
    {
        BOOL BlendEnable;
        BOOL LogicOpEnable;
        D3D11_BLEND SrcBlend;
        D3D11_BLEND DestBlend;
        D3D11_BLEND_OP BlendOp;
        D3D11_BLEND SrcBlendAlpha;
        D3D11_BLEND DestBlendAlpha;
        D3D11_BLEND_OP BlendOpAlpha;
        D3D11_LOGIC_OP LogicOp;
        UINT8 RenderTargetWriteMask;
    };

    struct D3D11_BLEND_DESC1
    {
        BOOL AlphaToCoverageEnable;
        BOOL IndependentBlendEnable;
        D3D11_RENDER_TARGET_BLEND_DESC1 RenderTarget[8];
    };

    struct D3D11_DEPTH_STENCILOP_DESC
    {
        D3D11_STENCIL_OP StencilFailOp;
        D3D11_STENCIL_OP StencilDepthFailOp;
        D3D11_STENCIL_OP StencilPassOp;
        D3D11_COMPARISON_FUNC StencilFunc;
    };

    struct D3D11_DEPTH_STENCIL_DESC
    {
        BOOL DepthEnable;
        D3D11_DEPTH_WRITE_MASK DepthWriteMask;
        D3D11_COMPARISON_FUNC DepthFunc;
        BOOL StencilEnable;
        UINT8 StencilReadMask;
        UINT8 StencilWriteMask;
        D3D11_DEPTH_STENCILOP_DESC FrontFace;
        D3D11_DEPTH_STENCILOP_DESC BackFace;
    };

    struct D3D11_RASTERIZER_DESC
    {
        D3D11_FILL_MODE FillMode;
        D3D11_CULL_MODE CullMode;
        BOOL FrontCounterClockwise;
        INT DepthBias;
        FLOAT DepthBiasClamp;
        FLOAT SlopeScaledDepthBias;
        BOOL DepthClipEnable;
        BOOL ScissorEnable;
        BOOL MultisampleEnable;
        BOOL AntialiasedLineEnable;
    };

    struct D3D11_RASTERIZER_DESC1
    {
        D3D11_FILL_MODE FillMode;
        D3D11_CULL_MODE CullMode;
        BOOL FrontCounterClockwise;
        INT DepthBias;
        FLOAT DepthBiasClamp;
        FLOAT SlopeScaledDepthBias;
        BOOL DepthClipEnable;
        BOOL ScissorEnable;
        BOOL MultisampleEnable;
        BOOL AntialiasedLineEnable;
        UINT ForcedSampleCount;
    };

    struct D3D11_SAMPLER_DESC
    {
        D3D11_FILTER Filter;
        D3D11_TEXTURE_ADDRESS_MODE AddressU;
        D3D11_TEXTURE_ADDRESS_MODE AddressV;
        D3D11_TEXTURE_ADDRESS_MODE AddressW;
        FLOAT MipLODBias;
        UINT MaxAnisotropy;
        D3D11_COMPARISON_FUNC ComparisonFunc;
        FLOAT BorderColor[4];
        FLOAT MinLOD;
        FLOAT MaxLOD;
    };

    struct D3D11_QUERY_DESC
    {
        D3D11_QUERY Query;
        UINT MiscFlags;
    };

    struct D3D11_QUERY_DATA_TIMESTAMP_DISJOINT
    {
        UINT64 Frequency;
        BOOL Disjoint;
    };

    struct D3D11_QUERY_DATA_PIPELINE_STATISTICS
    {
        UINT64 IAVertices;
        UINT64 IAPrimitives;
        UINT64 VSInvocations;
        UINT64 GSInvocations;
        UINT64 GSPrimitives;
        UINT64 CInvocations;
        UINT64 CPrimitives;
        UINT64 PSInvocations;
        UINT64 HSInvocations;
        UINT64 DSInvocations;
        UINT64 CSInvocations;
    };

    struct D3D11_COUNTER_DESC
    {
        D3D11_COUNTER Counter;
        UINT MiscFlags;
    };

    struct D3D11_COUNTER_INFO
    {
        D3D11_COUNTER LastDeviceDependentCounter;
        UINT NumSimultaneousCounters;
        UINT8 NumDetectableParallelUnits;
    };

    struct D3D11_CLASS_INSTANCE_DESC
    {
        UINT InstanceId;
        UINT InstanceIndex;
        UINT TypeId;
        UINT ConstantBuffer;
        UINT BaseConstantBufferOffset;
        UINT BaseTexture;
        UINT BaseSampler;
        BOOL Created;
    };

    struct D3D11_VIEWPORT
    {
        FLOAT TopLeftX;
        FLOAT TopLeftY;
        FLOAT Width;
        FLOAT Height;
        FLOAT MinDepth;
        FLOAT MaxDepth;
    };

    struct D3D11_BOX
    {
        UINT left;
        UINT top;
        UINT front;
        UINT right;
        UINT bottom;
        UINT back;
    };

    struct D3D11_FEATURE_DATA_THREADING
    {
        BOOL DriverConcurrentCreates;
        BOOL DriverCommandLists;
    };

    struct D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS
    {
        BOOL ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x;
    };

    struct D3D11_FEATURE_DATA_D3D11_OPTIONS
    {
        BOOL OutputMergerLogicOp;
        BOOL UAVOnlyRenderingForcedSampleCount;
        BOOL DiscardAPIsSeenByDriver;
        BOOL FlagsForUpdateAndCopySeenByDriver;
        BOOL ClearView;
        BOOL CopyWithOverlap;
        BOOL ConstantBufferPartialUpdate;
        BOOL ConstantBufferOffsetting;
        BOOL MapNoOverwriteOnDynamicConstantBuffer;
        BOOL MapNoOverwriteOnDynamicBufferSRV;
        BOOL MultisampleRTVWithForcedSampleCountOne;
        BOOL SAD4ShaderInstructions;
        BOOL ExtendedDoublesShaderInstructions;
        BOOL ExtendedResourceSharing;
    };

    struct IUnknown;
    struct ID3D11DeviceChild;
    struct ID3D11DepthStencilState;
    struct ID3D11BlendState;
    struct ID3D11RasterizerState;
    struct ID3D11Resource;
    struct ID3D11Buffer;
    struct ID3D11Texture1D;
    struct ID3D11Texture2D;
    struct ID3D11Texture3D;
    struct ID3D11View;
    struct ID3D11ShaderResourceView;
    struct ID3D11RenderTargetView;
    struct ID3D11DepthStencilView;
    struct ID3D11UnorderedAccessView;
    struct ID3D11VertexShader;
    struct ID3D11HullShader;
    struct ID3D11DomainShader;
    struct ID3D11GeometryShader;
    struct ID3D11PixelShader;
    struct ID3D11ComputeShader;
    struct ID3D11InputLayout;
    struct ID3D11SamplerState;
    struct ID3D11Asynchronous;
    struct ID3D11Query;
    struct ID3D11Predicate;
    struct ID3D11Counter;
    struct ID3D11ClassInstance;
    struct ID3D11ClassLinkage;
    struct ID3D11CommandList;
    struct ID3D11DeviceContext;
    struct ID3D11Device;
    struct ID3D11BlendState1;
    struct ID3D11RasterizerState1;
    struct ID3DDeviceContextState;
    struct ID3D11DeviceContext1;
    struct ID3D11Device1;
    struct ID3DUserDefinedAnnotation;
    struct IDXGIObject;
    struct IDXGIDeviceSubObject;
    struct IDXGISurface;
    struct IDXGIOutput;
    struct IDXGIAdapter;
    struct IDXGIAdapter1;
    struct IDXGIDevice;
    struct IDXGIDevice1;
    struct IDXGISwapChain;
    struct IDXGISwapChain1;
    struct IDXGISwapChain2;
    struct IDXGISwapChain3;
    struct IDXGIFactory;
    struct IDXGIFactory1;
    struct IDXGIFactory2;
    struct IDXGIFactory3;
    struct IDXGIFactory4;
    struct IDXGIFactory5;

    struct IUnknown
    {
        static constexpr GUID Iid = {0x00000000, 0x0000, 0x0000, {0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
        };

        HRESULT QueryInterface(const GUID& riid, void** object) { return static_cast<const Vtbl*>(vtbl_)->QueryInterface(this, riid, object); }
        ULONG AddRef() { return static_cast<const Vtbl*>(vtbl_)->AddRef(this); }
        ULONG Release() { return static_cast<const Vtbl*>(vtbl_)->Release(this); }

        template <typename T>
        HRESULT QueryInterface(T** object) { return QueryInterface(T::Iid, reinterpret_cast<void**>(object)); }

    protected:
        const void* vtbl_;
    };

    struct ID3D11DeviceChild : IUnknown
    {
        static constexpr GUID Iid = {0x1841e5c8, 0x16b0, 0x489b, {0xbc, 0xc8, 0x44, 0xcf, 0xb0, 0xd5, 0xde, 0xae}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

        void GetDevice(ID3D11Device** device) { static_cast<const Vtbl*>(vtbl_)->GetDevice(this, device); }
        HRESULT GetPrivateData(const GUID& guid, UINT* dataSize, void* data) { return static_cast<const Vtbl*>(vtbl_)->GetPrivateData(this, guid, dataSize, data); }
        HRESULT SetPrivateData(const GUID& guid, UINT dataSize, const void* data) { return static_cast<const Vtbl*>(vtbl_)->SetPrivateData(this, guid, dataSize, data); }
        HRESULT SetPrivateDataInterface(const GUID& guid, IUnknown* data) { return static_cast<const Vtbl*>(vtbl_)->SetPrivateDataInterface(this, guid, data); }
    };

    struct ID3D11DepthStencilState : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x03823efb, 0x8d8f, 0x4e1c, {0x9a, 0xa2, 0xf6, 0x4b, 0xb2, 0xcb, 0xfd, 0xf1}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_DEPTH_STENCIL_DESC* desc);
        };

        void GetDesc(D3D11_DEPTH_STENCIL_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11BlendState : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x75b68faa, 0x347d, 0x4159, {0x8f, 0x45, 0xa0, 0x64, 0x0f, 0x01, 0xcd, 0x9a}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_BLEND_DESC* desc);
        };

        void GetDesc(D3D11_BLEND_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11RasterizerState : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x9bb4ab81, 0xab1a, 0x4d8f, {0xb5, 0x06, 0xfc, 0x04, 0x20, 0x0b, 0x6e, 0xe7}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_RASTERIZER_DESC* desc);
        };

        void GetDesc(D3D11_RASTERIZER_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11Resource : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xdc8e63f3, 0xd12b, 0x4952, {0xb4, 0x7b, 0x5e, 0x45, 0x02, 0x6a, 0x86, 0x2d}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetType)(void* self, D3D11_RESOURCE_DIMENSION* dimension);
            void(HX_D3D_CALL* SetEvictionPriority)(void* self, UINT priority);
            UINT(HX_D3D_CALL* GetEvictionPriority)(void* self);
        };

        void GetType(D3D11_RESOURCE_DIMENSION* dimension) { static_cast<const Vtbl*>(vtbl_)->GetType(this, dimension); }
        void SetEvictionPriority(UINT priority) { static_cast<const Vtbl*>(vtbl_)->SetEvictionPriority(this, priority); }
        UINT GetEvictionPriority() { return static_cast<const Vtbl*>(vtbl_)->GetEvictionPriority(this); }
    };

    struct ID3D11Buffer : ID3D11Resource
    {
        static constexpr GUID Iid = {0x48570b85, 0xd1ee, 0x4fcd, {0xa2, 0x50, 0xeb, 0x35, 0x07, 0x22, 0xb0, 0x37}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetType)(void* self, D3D11_RESOURCE_DIMENSION* dimension);
            void(HX_D3D_CALL* SetEvictionPriority)(void* self, UINT priority);
            UINT(HX_D3D_CALL* GetEvictionPriority)(void* self);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_BUFFER_DESC* desc);
        };

        void GetDesc(D3D11_BUFFER_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11Texture1D : ID3D11Resource
    {
        static constexpr GUID Iid = {0xf8fb5c27, 0xc6b3, 0x4f75, {0xa4, 0xc8, 0x43, 0x9a, 0xf2, 0xef, 0x56, 0x4c}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetType)(void* self, D3D11_RESOURCE_DIMENSION* dimension);
            void(HX_D3D_CALL* SetEvictionPriority)(void* self, UINT priority);
            UINT(HX_D3D_CALL* GetEvictionPriority)(void* self);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_TEXTURE1D_DESC* desc);
        };

        void GetDesc(D3D11_TEXTURE1D_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11Texture2D : ID3D11Resource
    {
        static constexpr GUID Iid = {0x6f15aaf2, 0xd208, 0x4e89, {0x9a, 0xb4, 0x48, 0x95, 0x35, 0xd3, 0x4f, 0x9c}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetType)(void* self, D3D11_RESOURCE_DIMENSION* dimension);
            void(HX_D3D_CALL* SetEvictionPriority)(void* self, UINT priority);
            UINT(HX_D3D_CALL* GetEvictionPriority)(void* self);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_TEXTURE2D_DESC* desc);
        };

        void GetDesc(D3D11_TEXTURE2D_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11Texture3D : ID3D11Resource
    {
        static constexpr GUID Iid = {0x037e866e, 0xf56d, 0x4357, {0xa8, 0xaf, 0x9d, 0xab, 0xbe, 0x6e, 0x25, 0x0e}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetType)(void* self, D3D11_RESOURCE_DIMENSION* dimension);
            void(HX_D3D_CALL* SetEvictionPriority)(void* self, UINT priority);
            UINT(HX_D3D_CALL* GetEvictionPriority)(void* self);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_TEXTURE3D_DESC* desc);
        };

        void GetDesc(D3D11_TEXTURE3D_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11View : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x839d1216, 0xbb2e, 0x412b, {0xb7, 0xf4, 0xa9, 0xdb, 0xeb, 0xe0, 0x8e, 0xd1}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetResource)(void* self, ID3D11Resource** resource);
        };

        void GetResource(ID3D11Resource** resource) { static_cast<const Vtbl*>(vtbl_)->GetResource(this, resource); }
    };

    struct ID3D11ShaderResourceView : ID3D11View
    {
        static constexpr GUID Iid = {0xb0e06fe0, 0x8192, 0x4e1a, {0xb1, 0xca, 0x36, 0xd7, 0x41, 0x47, 0x10, 0xb2}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetResource)(void* self, ID3D11Resource** resource);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_SHADER_RESOURCE_VIEW_DESC* desc);
        };

        void GetDesc(D3D11_SHADER_RESOURCE_VIEW_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11RenderTargetView : ID3D11View
    {
        static constexpr GUID Iid = {0xdfdba067, 0x0b8d, 0x4865, {0x87, 0x5b, 0xd7, 0xb4, 0x51, 0x6c, 0xc1, 0x64}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetResource)(void* self, ID3D11Resource** resource);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_RENDER_TARGET_VIEW_DESC* desc);
        };

        void GetDesc(D3D11_RENDER_TARGET_VIEW_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11DepthStencilView : ID3D11View
    {
        static constexpr GUID Iid = {0x9fdac92a, 0x1876, 0x48c3, {0xaf, 0xad, 0x25, 0xb9, 0x4f, 0x84, 0xa9, 0xb6}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetResource)(void* self, ID3D11Resource** resource);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_DEPTH_STENCIL_VIEW_DESC* desc);
        };

        void GetDesc(D3D11_DEPTH_STENCIL_VIEW_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11UnorderedAccessView : ID3D11View
    {
        static constexpr GUID Iid = {0x28acf509, 0x7f5c, 0x48f6, {0x86, 0x11, 0xf3, 0x16, 0x01, 0x0a, 0x63, 0x80}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetResource)(void* self, ID3D11Resource** resource);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_UNORDERED_ACCESS_VIEW_DESC* desc);
        };

        void GetDesc(D3D11_UNORDERED_ACCESS_VIEW_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11VertexShader : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x3b301d64, 0xd678, 0x4289, {0x88, 0x97, 0x22, 0xf8, 0x92, 0x8b, 0x72, 0xf3}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11HullShader : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x8e5c6061, 0x628a, 0x4c8e, {0x82, 0x64, 0xbb, 0xe4, 0x5c, 0xb3, 0xd5, 0xdd}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11DomainShader : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xf582c508, 0x0f36, 0x490c, {0x99, 0x77, 0x31, 0xee, 0xce, 0x26, 0x8c, 0xfa}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11GeometryShader : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x38325b96, 0xeffb, 0x4022, {0xba, 0x02, 0x2e, 0x79, 0x5b, 0x70, 0x27, 0x5c}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11PixelShader : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xea82e40d, 0x51dc, 0x4f33, {0x93, 0xd4, 0xdb, 0x7c, 0x91, 0x25, 0xae, 0x8c}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11ComputeShader : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x4f5b196e, 0xc2bd, 0x495e, {0xbd, 0x01, 0x1f, 0xde, 0xd3, 0x8e, 0x49, 0x69}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11InputLayout : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xe4819ddc, 0x4cf0, 0x4025, {0xbd, 0x26, 0x5d, 0xe8, 0x2a, 0x3e, 0x07, 0xb7}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11SamplerState : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xda6fea51, 0x564c, 0x4487, {0x98, 0x10, 0xf0, 0xd0, 0xf9, 0xb4, 0xe3, 0xa5}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_SAMPLER_DESC* desc);
        };

        void GetDesc(D3D11_SAMPLER_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11Asynchronous : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x4b35d0cd, 0x1e15, 0x4258, {0x9c, 0x98, 0x1b, 0x13, 0x33, 0xf6, 0xdd, 0x3b}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            UINT(HX_D3D_CALL* GetDataSize)(void* self);
        };

        UINT GetDataSize() { return static_cast<const Vtbl*>(vtbl_)->GetDataSize(this); }
    };

    struct ID3D11Query : ID3D11Asynchronous
    {
        static constexpr GUID Iid = {0xd6c00747, 0x87b7, 0x425e, {0xb8, 0x4d, 0x44, 0xd1, 0x08, 0x56, 0x0a, 0xfd}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            UINT(HX_D3D_CALL* GetDataSize)(void* self);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_QUERY_DESC* desc);
        };

        void GetDesc(D3D11_QUERY_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11Predicate : ID3D11Query
    {
        static constexpr GUID Iid = {0x9eb576dd, 0x9f77, 0x4d86, {0x81, 0xaa, 0x8b, 0xab, 0x5f, 0xe4, 0x90, 0xe2}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            UINT(HX_D3D_CALL* GetDataSize)(void* self);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_QUERY_DESC* desc);
        };

    };

    struct ID3D11Counter : ID3D11Asynchronous
    {
        static constexpr GUID Iid = {0x6e8c49fb, 0xa371, 0x4770, {0xb4, 0x40, 0x29, 0x08, 0x60, 0x22, 0xb7, 0x41}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            UINT(HX_D3D_CALL* GetDataSize)(void* self);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_COUNTER_DESC* desc);
        };

        void GetDesc(D3D11_COUNTER_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
    };

    struct ID3D11ClassInstance : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xa6cd7faa, 0xb0b7, 0x4a2f, {0x94, 0x36, 0x86, 0x62, 0xa6, 0x57, 0x97, 0xcb}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetClassLinkage)(void* self, ID3D11ClassLinkage** linkage);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_CLASS_INSTANCE_DESC* desc);
            void(HX_D3D_CALL* GetInstanceName)(void* self, LPSTR name, SIZE_T* length);
            void(HX_D3D_CALL* GetTypeName)(void* self, LPSTR name, SIZE_T* length);
        };

        void GetClassLinkage(ID3D11ClassLinkage** linkage) { static_cast<const Vtbl*>(vtbl_)->GetClassLinkage(this, linkage); }
        void GetDesc(D3D11_CLASS_INSTANCE_DESC* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
        void GetInstanceName(LPSTR name, SIZE_T* length) { static_cast<const Vtbl*>(vtbl_)->GetInstanceName(this, name, length); }
        void GetTypeName(LPSTR name, SIZE_T* length) { static_cast<const Vtbl*>(vtbl_)->GetTypeName(this, name, length); }
    };

    struct ID3D11ClassLinkage : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xddf57cba, 0x9543, 0x46e4, {0xa1, 0x2b, 0xf2, 0x07, 0xa0, 0xfe, 0x7f, 0xed}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            HRESULT(HX_D3D_CALL* GetClassInstance)(void* self, LPCSTR name, UINT index, ID3D11ClassInstance** instance);
            HRESULT(HX_D3D_CALL* CreateClassInstance)(void* self, LPCSTR typeName, UINT constantBufferOffset, UINT constantVectorOffset, UINT textureOffset, UINT samplerOffset, ID3D11ClassInstance** instance);
        };

        HRESULT GetClassInstance(LPCSTR name, UINT index, ID3D11ClassInstance** instance) { return static_cast<const Vtbl*>(vtbl_)->GetClassInstance(this, name, index, instance); }
        HRESULT CreateClassInstance(LPCSTR typeName, UINT constantBufferOffset, UINT constantVectorOffset, UINT textureOffset, UINT samplerOffset, ID3D11ClassInstance** instance) { return static_cast<const Vtbl*>(vtbl_)->CreateClassInstance(this, typeName, constantBufferOffset, constantVectorOffset, textureOffset, samplerOffset, instance); }
    };

    struct ID3D11CommandList : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xa24bc4d1, 0x769e, 0x43f7, {0x80, 0x13, 0x98, 0xff, 0x56, 0x6c, 0x18, 0xe2}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            UINT(HX_D3D_CALL* GetContextFlags)(void* self);
        };

        UINT GetContextFlags() { return static_cast<const Vtbl*>(vtbl_)->GetContextFlags(this); }
    };

    struct ID3D11DeviceContext : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0xc0bfa96c, 0xe089, 0x44fb, {0x8e, 0xaf, 0x26, 0xf8, 0x79, 0x61, 0x90, 0xda}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* VSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* PSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* PSSetShader)(void* self, ID3D11PixelShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* PSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* VSSetShader)(void* self, ID3D11VertexShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* DrawIndexed)(void* self, UINT indexCount, UINT startIndex, INT baseVertex);
            void(HX_D3D_CALL* Draw)(void* self, UINT vertexCount, UINT startVertex);
            HRESULT(HX_D3D_CALL* Map)(void* self, ID3D11Resource* resource, UINT subresource, D3D11_MAP mapType, UINT mapFlags, D3D11_MAPPED_SUBRESOURCE* mapped);
            void(HX_D3D_CALL* Unmap)(void* self, ID3D11Resource* resource, UINT subresource);
            void(HX_D3D_CALL* PSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* IASetInputLayout)(void* self, ID3D11InputLayout* layout);
            void(HX_D3D_CALL* IASetVertexBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* strides, const UINT* offsets);
            void(HX_D3D_CALL* IASetIndexBuffer)(void* self, ID3D11Buffer* buffer, DXGI_FORMAT format, UINT offset);
            void(HX_D3D_CALL* DrawIndexedInstanced)(void* self, UINT indexCountPerInstance, UINT instanceCount, UINT startIndex, INT baseVertex, UINT startInstance);
            void(HX_D3D_CALL* DrawInstanced)(void* self, UINT vertexCountPerInstance, UINT instanceCount, UINT startVertex, UINT startInstance);
            void(HX_D3D_CALL* GSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* GSSetShader)(void* self, ID3D11GeometryShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* IASetPrimitiveTopology)(void* self, D3D11_PRIMITIVE_TOPOLOGY topology);
            void(HX_D3D_CALL* VSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* VSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* Begin)(void* self, ID3D11Asynchronous* async);
            void(HX_D3D_CALL* End)(void* self, ID3D11Asynchronous* async);
            HRESULT(HX_D3D_CALL* GetData)(void* self, ID3D11Asynchronous* async, void* data, UINT dataSize, UINT flags);
            void(HX_D3D_CALL* SetPredication)(void* self, ID3D11Predicate* predicate, BOOL value);
            void(HX_D3D_CALL* GSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* GSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* OMSetRenderTargets)(void* self, UINT count, ID3D11RenderTargetView* const* views, ID3D11DepthStencilView* depth);
            void(HX_D3D_CALL* OMSetRenderTargetsAndUnorderedAccessViews)(void* self, UINT rtvCount, ID3D11RenderTargetView* const* views, ID3D11DepthStencilView* depth, UINT uavStart, UINT uavCount, ID3D11UnorderedAccessView* const* uavs, const UINT* initialCounts);
            void(HX_D3D_CALL* OMSetBlendState)(void* self, ID3D11BlendState* state, const FLOAT* blendFactor, UINT sampleMask);
            void(HX_D3D_CALL* OMSetDepthStencilState)(void* self, ID3D11DepthStencilState* state, UINT stencilRef);
            void(HX_D3D_CALL* SOSetTargets)(void* self, UINT count, ID3D11Buffer* const* targets, const UINT* offsets);
            void(HX_D3D_CALL* DrawAuto)(void* self);
            void(HX_D3D_CALL* DrawIndexedInstancedIndirect)(void* self, ID3D11Buffer* args, UINT offset);
            void(HX_D3D_CALL* DrawInstancedIndirect)(void* self, ID3D11Buffer* args, UINT offset);
            void(HX_D3D_CALL* Dispatch)(void* self, UINT x, UINT y, UINT z);
            void(HX_D3D_CALL* DispatchIndirect)(void* self, ID3D11Buffer* args, UINT offset);
            void(HX_D3D_CALL* RSSetState)(void* self, ID3D11RasterizerState* state);
            void(HX_D3D_CALL* RSSetViewports)(void* self, UINT count, const D3D11_VIEWPORT* viewports);
            void(HX_D3D_CALL* RSSetScissorRects)(void* self, UINT count, const D3D11_RECT* rects);
            void(HX_D3D_CALL* CopySubresourceRegion)(void* self, ID3D11Resource* dst, UINT dstSubresource, UINT dstX, UINT dstY, UINT dstZ, ID3D11Resource* src, UINT srcSubresource, const D3D11_BOX* srcBox);
            void(HX_D3D_CALL* CopyResource)(void* self, ID3D11Resource* dst, ID3D11Resource* src);
            void(HX_D3D_CALL* UpdateSubresource)(void* self, ID3D11Resource* dst, UINT dstSubresource, const D3D11_BOX* dstBox, const void* data, UINT rowPitch, UINT depthPitch);
            void(HX_D3D_CALL* CopyStructureCount)(void* self, ID3D11Buffer* dst, UINT dstOffset, ID3D11UnorderedAccessView* src);
            void(HX_D3D_CALL* ClearRenderTargetView)(void* self, ID3D11RenderTargetView* view, const FLOAT* color);
            void(HX_D3D_CALL* ClearUnorderedAccessViewUint)(void* self, ID3D11UnorderedAccessView* view, const UINT* values);
            void(HX_D3D_CALL* ClearUnorderedAccessViewFloat)(void* self, ID3D11UnorderedAccessView* view, const FLOAT* values);
            void(HX_D3D_CALL* ClearDepthStencilView)(void* self, ID3D11DepthStencilView* view, UINT flags, FLOAT depth, UINT8 stencil);
            void(HX_D3D_CALL* GenerateMips)(void* self, ID3D11ShaderResourceView* view);
            void(HX_D3D_CALL* SetResourceMinLOD)(void* self, ID3D11Resource* resource, FLOAT minLod);
            FLOAT(HX_D3D_CALL* GetResourceMinLOD)(void* self, ID3D11Resource* resource);
            void(HX_D3D_CALL* ResolveSubresource)(void* self, ID3D11Resource* dst, UINT dstSubresource, ID3D11Resource* src, UINT srcSubresource, DXGI_FORMAT format);
            void(HX_D3D_CALL* ExecuteCommandList)(void* self, ID3D11CommandList* list, BOOL restoreState);
            void(HX_D3D_CALL* HSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* HSSetShader)(void* self, ID3D11HullShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* HSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* HSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* DSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* DSSetShader)(void* self, ID3D11DomainShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* DSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* DSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* CSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* CSSetUnorderedAccessViews)(void* self, UINT startSlot, UINT count, ID3D11UnorderedAccessView* const* views, const UINT* initialCounts);
            void(HX_D3D_CALL* CSSetShader)(void* self, ID3D11ComputeShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* CSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* CSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* VSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* PSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* PSGetShader)(void* self, ID3D11PixelShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* PSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* VSGetShader)(void* self, ID3D11VertexShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* PSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* IAGetInputLayout)(void* self, ID3D11InputLayout** layout);
            void(HX_D3D_CALL* IAGetVertexBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* strides, UINT* offsets);
            void(HX_D3D_CALL* IAGetIndexBuffer)(void* self, ID3D11Buffer** buffer, DXGI_FORMAT* format, UINT* offset);
            void(HX_D3D_CALL* GSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* GSGetShader)(void* self, ID3D11GeometryShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* IAGetPrimitiveTopology)(void* self, D3D11_PRIMITIVE_TOPOLOGY* topology);
            void(HX_D3D_CALL* VSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* VSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* GetPredication)(void* self, ID3D11Predicate** predicate, BOOL* value);
            void(HX_D3D_CALL* GSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* GSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* OMGetRenderTargets)(void* self, UINT count, ID3D11RenderTargetView** views, ID3D11DepthStencilView** depth);
            void(HX_D3D_CALL* OMGetRenderTargetsAndUnorderedAccessViews)(void* self, UINT rtvCount, ID3D11RenderTargetView** views, ID3D11DepthStencilView** depth, UINT uavStart, UINT uavCount, ID3D11UnorderedAccessView** uavs);
            void(HX_D3D_CALL* OMGetBlendState)(void* self, ID3D11BlendState** state, FLOAT* blendFactor, UINT* sampleMask);
            void(HX_D3D_CALL* OMGetDepthStencilState)(void* self, ID3D11DepthStencilState** state, UINT* stencilRef);
            void(HX_D3D_CALL* SOGetTargets)(void* self, UINT count, ID3D11Buffer** targets);
            void(HX_D3D_CALL* RSGetState)(void* self, ID3D11RasterizerState** state);
            void(HX_D3D_CALL* RSGetViewports)(void* self, UINT* count, D3D11_VIEWPORT* viewports);
            void(HX_D3D_CALL* RSGetScissorRects)(void* self, UINT* count, D3D11_RECT* rects);
            void(HX_D3D_CALL* HSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* HSGetShader)(void* self, ID3D11HullShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* HSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* HSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* DSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* DSGetShader)(void* self, ID3D11DomainShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* DSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* DSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* CSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* CSGetUnorderedAccessViews)(void* self, UINT startSlot, UINT count, ID3D11UnorderedAccessView** views);
            void(HX_D3D_CALL* CSGetShader)(void* self, ID3D11ComputeShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* CSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* CSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* ClearState)(void* self);
            void(HX_D3D_CALL* Flush)(void* self);
            D3D11_DEVICE_CONTEXT_TYPE(HX_D3D_CALL* GetType)(void* self);
            UINT(HX_D3D_CALL* GetContextFlags)(void* self);
            HRESULT(HX_D3D_CALL* FinishCommandList)(void* self, BOOL restoreState, ID3D11CommandList** list);
        };

        void VSSetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer* const* buffers) { static_cast<const Vtbl*>(vtbl_)->VSSetConstantBuffers(this, startSlot, count, buffers); }
        void PSSetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views) { static_cast<const Vtbl*>(vtbl_)->PSSetShaderResources(this, startSlot, count, views); }
        void PSSetShader(ID3D11PixelShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount) { static_cast<const Vtbl*>(vtbl_)->PSSetShader(this, shader, instances, instanceCount); }
        void PSSetSamplers(UINT startSlot, UINT count, ID3D11SamplerState* const* samplers) { static_cast<const Vtbl*>(vtbl_)->PSSetSamplers(this, startSlot, count, samplers); }
        void VSSetShader(ID3D11VertexShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount) { static_cast<const Vtbl*>(vtbl_)->VSSetShader(this, shader, instances, instanceCount); }
        void DrawIndexed(UINT indexCount, UINT startIndex, INT baseVertex) { static_cast<const Vtbl*>(vtbl_)->DrawIndexed(this, indexCount, startIndex, baseVertex); }
        void Draw(UINT vertexCount, UINT startVertex) { static_cast<const Vtbl*>(vtbl_)->Draw(this, vertexCount, startVertex); }
        HRESULT Map(ID3D11Resource* resource, UINT subresource, D3D11_MAP mapType, UINT mapFlags, D3D11_MAPPED_SUBRESOURCE* mapped) { return static_cast<const Vtbl*>(vtbl_)->Map(this, resource, subresource, mapType, mapFlags, mapped); }
        void Unmap(ID3D11Resource* resource, UINT subresource) { static_cast<const Vtbl*>(vtbl_)->Unmap(this, resource, subresource); }
        void PSSetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer* const* buffers) { static_cast<const Vtbl*>(vtbl_)->PSSetConstantBuffers(this, startSlot, count, buffers); }
        void IASetInputLayout(ID3D11InputLayout* layout) { static_cast<const Vtbl*>(vtbl_)->IASetInputLayout(this, layout); }
        void IASetVertexBuffers(UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* strides, const UINT* offsets) { static_cast<const Vtbl*>(vtbl_)->IASetVertexBuffers(this, startSlot, count, buffers, strides, offsets); }
        void IASetIndexBuffer(ID3D11Buffer* buffer, DXGI_FORMAT format, UINT offset) { static_cast<const Vtbl*>(vtbl_)->IASetIndexBuffer(this, buffer, format, offset); }
        void DrawIndexedInstanced(UINT indexCountPerInstance, UINT instanceCount, UINT startIndex, INT baseVertex, UINT startInstance) { static_cast<const Vtbl*>(vtbl_)->DrawIndexedInstanced(this, indexCountPerInstance, instanceCount, startIndex, baseVertex, startInstance); }
        void DrawInstanced(UINT vertexCountPerInstance, UINT instanceCount, UINT startVertex, UINT startInstance) { static_cast<const Vtbl*>(vtbl_)->DrawInstanced(this, vertexCountPerInstance, instanceCount, startVertex, startInstance); }
        void GSSetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer* const* buffers) { static_cast<const Vtbl*>(vtbl_)->GSSetConstantBuffers(this, startSlot, count, buffers); }
        void GSSetShader(ID3D11GeometryShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount) { static_cast<const Vtbl*>(vtbl_)->GSSetShader(this, shader, instances, instanceCount); }
        void IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY topology) { static_cast<const Vtbl*>(vtbl_)->IASetPrimitiveTopology(this, topology); }
        void VSSetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views) { static_cast<const Vtbl*>(vtbl_)->VSSetShaderResources(this, startSlot, count, views); }
        void VSSetSamplers(UINT startSlot, UINT count, ID3D11SamplerState* const* samplers) { static_cast<const Vtbl*>(vtbl_)->VSSetSamplers(this, startSlot, count, samplers); }
        void Begin(ID3D11Asynchronous* async) { static_cast<const Vtbl*>(vtbl_)->Begin(this, async); }
        void End(ID3D11Asynchronous* async) { static_cast<const Vtbl*>(vtbl_)->End(this, async); }
        HRESULT GetData(ID3D11Asynchronous* async, void* data, UINT dataSize, UINT flags) { return static_cast<const Vtbl*>(vtbl_)->GetData(this, async, data, dataSize, flags); }
        void SetPredication(ID3D11Predicate* predicate, BOOL value) { static_cast<const Vtbl*>(vtbl_)->SetPredication(this, predicate, value); }
        void GSSetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views) { static_cast<const Vtbl*>(vtbl_)->GSSetShaderResources(this, startSlot, count, views); }
        void GSSetSamplers(UINT startSlot, UINT count, ID3D11SamplerState* const* samplers) { static_cast<const Vtbl*>(vtbl_)->GSSetSamplers(this, startSlot, count, samplers); }
        void OMSetRenderTargets(UINT count, ID3D11RenderTargetView* const* views, ID3D11DepthStencilView* depth) { static_cast<const Vtbl*>(vtbl_)->OMSetRenderTargets(this, count, views, depth); }
        void OMSetRenderTargetsAndUnorderedAccessViews(UINT rtvCount, ID3D11RenderTargetView* const* views, ID3D11DepthStencilView* depth, UINT uavStart, UINT uavCount, ID3D11UnorderedAccessView* const* uavs, const UINT* initialCounts) { static_cast<const Vtbl*>(vtbl_)->OMSetRenderTargetsAndUnorderedAccessViews(this, rtvCount, views, depth, uavStart, uavCount, uavs, initialCounts); }
        void OMSetBlendState(ID3D11BlendState* state, const FLOAT* blendFactor, UINT sampleMask) { static_cast<const Vtbl*>(vtbl_)->OMSetBlendState(this, state, blendFactor, sampleMask); }
        void OMSetDepthStencilState(ID3D11DepthStencilState* state, UINT stencilRef) { static_cast<const Vtbl*>(vtbl_)->OMSetDepthStencilState(this, state, stencilRef); }
        void SOSetTargets(UINT count, ID3D11Buffer* const* targets, const UINT* offsets) { static_cast<const Vtbl*>(vtbl_)->SOSetTargets(this, count, targets, offsets); }
        void DrawAuto() { static_cast<const Vtbl*>(vtbl_)->DrawAuto(this); }
        void DrawIndexedInstancedIndirect(ID3D11Buffer* args, UINT offset) { static_cast<const Vtbl*>(vtbl_)->DrawIndexedInstancedIndirect(this, args, offset); }
        void DrawInstancedIndirect(ID3D11Buffer* args, UINT offset) { static_cast<const Vtbl*>(vtbl_)->DrawInstancedIndirect(this, args, offset); }
        void Dispatch(UINT x, UINT y, UINT z) { static_cast<const Vtbl*>(vtbl_)->Dispatch(this, x, y, z); }
        void DispatchIndirect(ID3D11Buffer* args, UINT offset) { static_cast<const Vtbl*>(vtbl_)->DispatchIndirect(this, args, offset); }
        void RSSetState(ID3D11RasterizerState* state) { static_cast<const Vtbl*>(vtbl_)->RSSetState(this, state); }
        void RSSetViewports(UINT count, const D3D11_VIEWPORT* viewports) { static_cast<const Vtbl*>(vtbl_)->RSSetViewports(this, count, viewports); }
        void RSSetScissorRects(UINT count, const D3D11_RECT* rects) { static_cast<const Vtbl*>(vtbl_)->RSSetScissorRects(this, count, rects); }
        void CopySubresourceRegion(ID3D11Resource* dst, UINT dstSubresource, UINT dstX, UINT dstY, UINT dstZ, ID3D11Resource* src, UINT srcSubresource, const D3D11_BOX* srcBox) { static_cast<const Vtbl*>(vtbl_)->CopySubresourceRegion(this, dst, dstSubresource, dstX, dstY, dstZ, src, srcSubresource, srcBox); }
        void CopyResource(ID3D11Resource* dst, ID3D11Resource* src) { static_cast<const Vtbl*>(vtbl_)->CopyResource(this, dst, src); }
        void UpdateSubresource(ID3D11Resource* dst, UINT dstSubresource, const D3D11_BOX* dstBox, const void* data, UINT rowPitch, UINT depthPitch) { static_cast<const Vtbl*>(vtbl_)->UpdateSubresource(this, dst, dstSubresource, dstBox, data, rowPitch, depthPitch); }
        void CopyStructureCount(ID3D11Buffer* dst, UINT dstOffset, ID3D11UnorderedAccessView* src) { static_cast<const Vtbl*>(vtbl_)->CopyStructureCount(this, dst, dstOffset, src); }
        void ClearRenderTargetView(ID3D11RenderTargetView* view, const FLOAT* color) { static_cast<const Vtbl*>(vtbl_)->ClearRenderTargetView(this, view, color); }
        void ClearUnorderedAccessViewUint(ID3D11UnorderedAccessView* view, const UINT* values) { static_cast<const Vtbl*>(vtbl_)->ClearUnorderedAccessViewUint(this, view, values); }
        void ClearUnorderedAccessViewFloat(ID3D11UnorderedAccessView* view, const FLOAT* values) { static_cast<const Vtbl*>(vtbl_)->ClearUnorderedAccessViewFloat(this, view, values); }
        void ClearDepthStencilView(ID3D11DepthStencilView* view, UINT flags, FLOAT depth, UINT8 stencil) { static_cast<const Vtbl*>(vtbl_)->ClearDepthStencilView(this, view, flags, depth, stencil); }
        void GenerateMips(ID3D11ShaderResourceView* view) { static_cast<const Vtbl*>(vtbl_)->GenerateMips(this, view); }
        void SetResourceMinLOD(ID3D11Resource* resource, FLOAT minLod) { static_cast<const Vtbl*>(vtbl_)->SetResourceMinLOD(this, resource, minLod); }
        FLOAT GetResourceMinLOD(ID3D11Resource* resource) { return static_cast<const Vtbl*>(vtbl_)->GetResourceMinLOD(this, resource); }
        void ResolveSubresource(ID3D11Resource* dst, UINT dstSubresource, ID3D11Resource* src, UINT srcSubresource, DXGI_FORMAT format) { static_cast<const Vtbl*>(vtbl_)->ResolveSubresource(this, dst, dstSubresource, src, srcSubresource, format); }
        void ExecuteCommandList(ID3D11CommandList* list, BOOL restoreState) { static_cast<const Vtbl*>(vtbl_)->ExecuteCommandList(this, list, restoreState); }
        void HSSetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views) { static_cast<const Vtbl*>(vtbl_)->HSSetShaderResources(this, startSlot, count, views); }
        void HSSetShader(ID3D11HullShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount) { static_cast<const Vtbl*>(vtbl_)->HSSetShader(this, shader, instances, instanceCount); }
        void HSSetSamplers(UINT startSlot, UINT count, ID3D11SamplerState* const* samplers) { static_cast<const Vtbl*>(vtbl_)->HSSetSamplers(this, startSlot, count, samplers); }
        void HSSetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer* const* buffers) { static_cast<const Vtbl*>(vtbl_)->HSSetConstantBuffers(this, startSlot, count, buffers); }
        void DSSetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views) { static_cast<const Vtbl*>(vtbl_)->DSSetShaderResources(this, startSlot, count, views); }
        void DSSetShader(ID3D11DomainShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount) { static_cast<const Vtbl*>(vtbl_)->DSSetShader(this, shader, instances, instanceCount); }
        void DSSetSamplers(UINT startSlot, UINT count, ID3D11SamplerState* const* samplers) { static_cast<const Vtbl*>(vtbl_)->DSSetSamplers(this, startSlot, count, samplers); }
        void DSSetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer* const* buffers) { static_cast<const Vtbl*>(vtbl_)->DSSetConstantBuffers(this, startSlot, count, buffers); }
        void CSSetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views) { static_cast<const Vtbl*>(vtbl_)->CSSetShaderResources(this, startSlot, count, views); }
        void CSSetUnorderedAccessViews(UINT startSlot, UINT count, ID3D11UnorderedAccessView* const* views, const UINT* initialCounts) { static_cast<const Vtbl*>(vtbl_)->CSSetUnorderedAccessViews(this, startSlot, count, views, initialCounts); }
        void CSSetShader(ID3D11ComputeShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount) { static_cast<const Vtbl*>(vtbl_)->CSSetShader(this, shader, instances, instanceCount); }
        void CSSetSamplers(UINT startSlot, UINT count, ID3D11SamplerState* const* samplers) { static_cast<const Vtbl*>(vtbl_)->CSSetSamplers(this, startSlot, count, samplers); }
        void CSSetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer* const* buffers) { static_cast<const Vtbl*>(vtbl_)->CSSetConstantBuffers(this, startSlot, count, buffers); }
        void VSGetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer** buffers) { static_cast<const Vtbl*>(vtbl_)->VSGetConstantBuffers(this, startSlot, count, buffers); }
        void PSGetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView** views) { static_cast<const Vtbl*>(vtbl_)->PSGetShaderResources(this, startSlot, count, views); }
        void PSGetShader(ID3D11PixelShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount) { static_cast<const Vtbl*>(vtbl_)->PSGetShader(this, shader, instances, instanceCount); }
        void PSGetSamplers(UINT startSlot, UINT count, ID3D11SamplerState** samplers) { static_cast<const Vtbl*>(vtbl_)->PSGetSamplers(this, startSlot, count, samplers); }
        void VSGetShader(ID3D11VertexShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount) { static_cast<const Vtbl*>(vtbl_)->VSGetShader(this, shader, instances, instanceCount); }
        void PSGetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer** buffers) { static_cast<const Vtbl*>(vtbl_)->PSGetConstantBuffers(this, startSlot, count, buffers); }
        void IAGetInputLayout(ID3D11InputLayout** layout) { static_cast<const Vtbl*>(vtbl_)->IAGetInputLayout(this, layout); }
        void IAGetVertexBuffers(UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* strides, UINT* offsets) { static_cast<const Vtbl*>(vtbl_)->IAGetVertexBuffers(this, startSlot, count, buffers, strides, offsets); }
        void IAGetIndexBuffer(ID3D11Buffer** buffer, DXGI_FORMAT* format, UINT* offset) { static_cast<const Vtbl*>(vtbl_)->IAGetIndexBuffer(this, buffer, format, offset); }
        void GSGetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer** buffers) { static_cast<const Vtbl*>(vtbl_)->GSGetConstantBuffers(this, startSlot, count, buffers); }
        void GSGetShader(ID3D11GeometryShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount) { static_cast<const Vtbl*>(vtbl_)->GSGetShader(this, shader, instances, instanceCount); }
        void IAGetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY* topology) { static_cast<const Vtbl*>(vtbl_)->IAGetPrimitiveTopology(this, topology); }
        void VSGetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView** views) { static_cast<const Vtbl*>(vtbl_)->VSGetShaderResources(this, startSlot, count, views); }
        void VSGetSamplers(UINT startSlot, UINT count, ID3D11SamplerState** samplers) { static_cast<const Vtbl*>(vtbl_)->VSGetSamplers(this, startSlot, count, samplers); }
        void GetPredication(ID3D11Predicate** predicate, BOOL* value) { static_cast<const Vtbl*>(vtbl_)->GetPredication(this, predicate, value); }
        void GSGetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView** views) { static_cast<const Vtbl*>(vtbl_)->GSGetShaderResources(this, startSlot, count, views); }
        void GSGetSamplers(UINT startSlot, UINT count, ID3D11SamplerState** samplers) { static_cast<const Vtbl*>(vtbl_)->GSGetSamplers(this, startSlot, count, samplers); }
        void OMGetRenderTargets(UINT count, ID3D11RenderTargetView** views, ID3D11DepthStencilView** depth) { static_cast<const Vtbl*>(vtbl_)->OMGetRenderTargets(this, count, views, depth); }
        void OMGetRenderTargetsAndUnorderedAccessViews(UINT rtvCount, ID3D11RenderTargetView** views, ID3D11DepthStencilView** depth, UINT uavStart, UINT uavCount, ID3D11UnorderedAccessView** uavs) { static_cast<const Vtbl*>(vtbl_)->OMGetRenderTargetsAndUnorderedAccessViews(this, rtvCount, views, depth, uavStart, uavCount, uavs); }
        void OMGetBlendState(ID3D11BlendState** state, FLOAT* blendFactor, UINT* sampleMask) { static_cast<const Vtbl*>(vtbl_)->OMGetBlendState(this, state, blendFactor, sampleMask); }
        void OMGetDepthStencilState(ID3D11DepthStencilState** state, UINT* stencilRef) { static_cast<const Vtbl*>(vtbl_)->OMGetDepthStencilState(this, state, stencilRef); }
        void SOGetTargets(UINT count, ID3D11Buffer** targets) { static_cast<const Vtbl*>(vtbl_)->SOGetTargets(this, count, targets); }
        void RSGetState(ID3D11RasterizerState** state) { static_cast<const Vtbl*>(vtbl_)->RSGetState(this, state); }
        void RSGetViewports(UINT* count, D3D11_VIEWPORT* viewports) { static_cast<const Vtbl*>(vtbl_)->RSGetViewports(this, count, viewports); }
        void RSGetScissorRects(UINT* count, D3D11_RECT* rects) { static_cast<const Vtbl*>(vtbl_)->RSGetScissorRects(this, count, rects); }
        void HSGetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView** views) { static_cast<const Vtbl*>(vtbl_)->HSGetShaderResources(this, startSlot, count, views); }
        void HSGetShader(ID3D11HullShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount) { static_cast<const Vtbl*>(vtbl_)->HSGetShader(this, shader, instances, instanceCount); }
        void HSGetSamplers(UINT startSlot, UINT count, ID3D11SamplerState** samplers) { static_cast<const Vtbl*>(vtbl_)->HSGetSamplers(this, startSlot, count, samplers); }
        void HSGetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer** buffers) { static_cast<const Vtbl*>(vtbl_)->HSGetConstantBuffers(this, startSlot, count, buffers); }
        void DSGetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView** views) { static_cast<const Vtbl*>(vtbl_)->DSGetShaderResources(this, startSlot, count, views); }
        void DSGetShader(ID3D11DomainShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount) { static_cast<const Vtbl*>(vtbl_)->DSGetShader(this, shader, instances, instanceCount); }
        void DSGetSamplers(UINT startSlot, UINT count, ID3D11SamplerState** samplers) { static_cast<const Vtbl*>(vtbl_)->DSGetSamplers(this, startSlot, count, samplers); }
        void DSGetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer** buffers) { static_cast<const Vtbl*>(vtbl_)->DSGetConstantBuffers(this, startSlot, count, buffers); }
        void CSGetShaderResources(UINT startSlot, UINT count, ID3D11ShaderResourceView** views) { static_cast<const Vtbl*>(vtbl_)->CSGetShaderResources(this, startSlot, count, views); }
        void CSGetUnorderedAccessViews(UINT startSlot, UINT count, ID3D11UnorderedAccessView** views) { static_cast<const Vtbl*>(vtbl_)->CSGetUnorderedAccessViews(this, startSlot, count, views); }
        void CSGetShader(ID3D11ComputeShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount) { static_cast<const Vtbl*>(vtbl_)->CSGetShader(this, shader, instances, instanceCount); }
        void CSGetSamplers(UINT startSlot, UINT count, ID3D11SamplerState** samplers) { static_cast<const Vtbl*>(vtbl_)->CSGetSamplers(this, startSlot, count, samplers); }
        void CSGetConstantBuffers(UINT startSlot, UINT count, ID3D11Buffer** buffers) { static_cast<const Vtbl*>(vtbl_)->CSGetConstantBuffers(this, startSlot, count, buffers); }
        void ClearState() { static_cast<const Vtbl*>(vtbl_)->ClearState(this); }
        void Flush() { static_cast<const Vtbl*>(vtbl_)->Flush(this); }
        D3D11_DEVICE_CONTEXT_TYPE GetType() { return static_cast<const Vtbl*>(vtbl_)->GetType(this); }
        UINT GetContextFlags() { return static_cast<const Vtbl*>(vtbl_)->GetContextFlags(this); }
        HRESULT FinishCommandList(BOOL restoreState, ID3D11CommandList** list) { return static_cast<const Vtbl*>(vtbl_)->FinishCommandList(this, restoreState, list); }
    };

    struct ID3D11Device : IUnknown
    {
        static constexpr GUID Iid = {0xdb6f6ddb, 0xac77, 0x4e88, {0x82, 0x53, 0x81, 0x9d, 0xf9, 0xbb, 0xf1, 0x40}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* CreateBuffer)(void* self, const D3D11_BUFFER_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Buffer** buffer);
            HRESULT(HX_D3D_CALL* CreateTexture1D)(void* self, const D3D11_TEXTURE1D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture1D** texture);
            HRESULT(HX_D3D_CALL* CreateTexture2D)(void* self, const D3D11_TEXTURE2D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture2D** texture);
            HRESULT(HX_D3D_CALL* CreateTexture3D)(void* self, const D3D11_TEXTURE3D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture3D** texture);
            HRESULT(HX_D3D_CALL* CreateShaderResourceView)(void* self, ID3D11Resource* resource, const D3D11_SHADER_RESOURCE_VIEW_DESC* desc, ID3D11ShaderResourceView** view);
            HRESULT(HX_D3D_CALL* CreateUnorderedAccessView)(void* self, ID3D11Resource* resource, const D3D11_UNORDERED_ACCESS_VIEW_DESC* desc, ID3D11UnorderedAccessView** view);
            HRESULT(HX_D3D_CALL* CreateRenderTargetView)(void* self, ID3D11Resource* resource, const D3D11_RENDER_TARGET_VIEW_DESC* desc, ID3D11RenderTargetView** view);
            HRESULT(HX_D3D_CALL* CreateDepthStencilView)(void* self, ID3D11Resource* resource, const D3D11_DEPTH_STENCIL_VIEW_DESC* desc, ID3D11DepthStencilView** view);
            HRESULT(HX_D3D_CALL* CreateInputLayout)(void* self, const D3D11_INPUT_ELEMENT_DESC* elements, UINT count, const void* bytecode, SIZE_T bytecodeLength, ID3D11InputLayout** layout);
            HRESULT(HX_D3D_CALL* CreateVertexShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11VertexShader** shader);
            HRESULT(HX_D3D_CALL* CreateGeometryShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11GeometryShader** shader);
            HRESULT(HX_D3D_CALL* CreateGeometryShaderWithStreamOutput)(void* self, const void* bytecode, SIZE_T bytecodeLength, const D3D11_SO_DECLARATION_ENTRY* entries, UINT entryCount, const UINT* strides, UINT strideCount, UINT rasterizedStream, ID3D11ClassLinkage* linkage, ID3D11GeometryShader** shader);
            HRESULT(HX_D3D_CALL* CreatePixelShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11PixelShader** shader);
            HRESULT(HX_D3D_CALL* CreateHullShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11HullShader** shader);
            HRESULT(HX_D3D_CALL* CreateDomainShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11DomainShader** shader);
            HRESULT(HX_D3D_CALL* CreateComputeShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11ComputeShader** shader);
            HRESULT(HX_D3D_CALL* CreateClassLinkage)(void* self, ID3D11ClassLinkage** linkage);
            HRESULT(HX_D3D_CALL* CreateBlendState)(void* self, const D3D11_BLEND_DESC* desc, ID3D11BlendState** state);
            HRESULT(HX_D3D_CALL* CreateDepthStencilState)(void* self, const D3D11_DEPTH_STENCIL_DESC* desc, ID3D11DepthStencilState** state);
            HRESULT(HX_D3D_CALL* CreateRasterizerState)(void* self, const D3D11_RASTERIZER_DESC* desc, ID3D11RasterizerState** state);
            HRESULT(HX_D3D_CALL* CreateSamplerState)(void* self, const D3D11_SAMPLER_DESC* desc, ID3D11SamplerState** state);
            HRESULT(HX_D3D_CALL* CreateQuery)(void* self, const D3D11_QUERY_DESC* desc, ID3D11Query** query);
            HRESULT(HX_D3D_CALL* CreatePredicate)(void* self, const D3D11_QUERY_DESC* desc, ID3D11Predicate** predicate);
            HRESULT(HX_D3D_CALL* CreateCounter)(void* self, const D3D11_COUNTER_DESC* desc, ID3D11Counter** counter);
            HRESULT(HX_D3D_CALL* CreateDeferredContext)(void* self, UINT flags, ID3D11DeviceContext** context);
            HRESULT(HX_D3D_CALL* OpenSharedResource)(void* self, HANDLE resource, const GUID& riid, void** object);
            HRESULT(HX_D3D_CALL* CheckFormatSupport)(void* self, DXGI_FORMAT format, UINT* support);
            HRESULT(HX_D3D_CALL* CheckMultisampleQualityLevels)(void* self, DXGI_FORMAT format, UINT sampleCount, UINT* levels);
            void(HX_D3D_CALL* CheckCounterInfo)(void* self, D3D11_COUNTER_INFO* info);
            HRESULT(HX_D3D_CALL* CheckCounter)(void* self, const D3D11_COUNTER_DESC* desc, D3D11_COUNTER_TYPE* type, UINT* activeCounters, LPSTR name, UINT* nameLength, LPSTR units, UINT* unitsLength, LPSTR description, UINT* descriptionLength);
            HRESULT(HX_D3D_CALL* CheckFeatureSupport)(void* self, D3D11_FEATURE feature, void* data, UINT dataSize);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            D3D_FEATURE_LEVEL(HX_D3D_CALL* GetFeatureLevel)(void* self);
            UINT(HX_D3D_CALL* GetCreationFlags)(void* self);
            HRESULT(HX_D3D_CALL* GetDeviceRemovedReason)(void* self);
            void(HX_D3D_CALL* GetImmediateContext)(void* self, ID3D11DeviceContext** context);
            HRESULT(HX_D3D_CALL* SetExceptionMode)(void* self, UINT flags);
            UINT(HX_D3D_CALL* GetExceptionMode)(void* self);
        };

        HRESULT CreateBuffer(const D3D11_BUFFER_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Buffer** buffer) { return static_cast<const Vtbl*>(vtbl_)->CreateBuffer(this, desc, data, buffer); }
        HRESULT CreateTexture1D(const D3D11_TEXTURE1D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture1D** texture) { return static_cast<const Vtbl*>(vtbl_)->CreateTexture1D(this, desc, data, texture); }
        HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture2D** texture) { return static_cast<const Vtbl*>(vtbl_)->CreateTexture2D(this, desc, data, texture); }
        HRESULT CreateTexture3D(const D3D11_TEXTURE3D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture3D** texture) { return static_cast<const Vtbl*>(vtbl_)->CreateTexture3D(this, desc, data, texture); }
        HRESULT CreateShaderResourceView(ID3D11Resource* resource, const D3D11_SHADER_RESOURCE_VIEW_DESC* desc, ID3D11ShaderResourceView** view) { return static_cast<const Vtbl*>(vtbl_)->CreateShaderResourceView(this, resource, desc, view); }
        HRESULT CreateUnorderedAccessView(ID3D11Resource* resource, const D3D11_UNORDERED_ACCESS_VIEW_DESC* desc, ID3D11UnorderedAccessView** view) { return static_cast<const Vtbl*>(vtbl_)->CreateUnorderedAccessView(this, resource, desc, view); }
        HRESULT CreateRenderTargetView(ID3D11Resource* resource, const D3D11_RENDER_TARGET_VIEW_DESC* desc, ID3D11RenderTargetView** view) { return static_cast<const Vtbl*>(vtbl_)->CreateRenderTargetView(this, resource, desc, view); }
        HRESULT CreateDepthStencilView(ID3D11Resource* resource, const D3D11_DEPTH_STENCIL_VIEW_DESC* desc, ID3D11DepthStencilView** view) { return static_cast<const Vtbl*>(vtbl_)->CreateDepthStencilView(this, resource, desc, view); }
        HRESULT CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* elements, UINT count, const void* bytecode, SIZE_T bytecodeLength, ID3D11InputLayout** layout) { return static_cast<const Vtbl*>(vtbl_)->CreateInputLayout(this, elements, count, bytecode, bytecodeLength, layout); }
        HRESULT CreateVertexShader(const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11VertexShader** shader) { return static_cast<const Vtbl*>(vtbl_)->CreateVertexShader(this, bytecode, bytecodeLength, linkage, shader); }
        HRESULT CreateGeometryShader(const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11GeometryShader** shader) { return static_cast<const Vtbl*>(vtbl_)->CreateGeometryShader(this, bytecode, bytecodeLength, linkage, shader); }
        HRESULT CreateGeometryShaderWithStreamOutput(const void* bytecode, SIZE_T bytecodeLength, const D3D11_SO_DECLARATION_ENTRY* entries, UINT entryCount, const UINT* strides, UINT strideCount, UINT rasterizedStream, ID3D11ClassLinkage* linkage, ID3D11GeometryShader** shader) { return static_cast<const Vtbl*>(vtbl_)->CreateGeometryShaderWithStreamOutput(this, bytecode, bytecodeLength, entries, entryCount, strides, strideCount, rasterizedStream, linkage, shader); }
        HRESULT CreatePixelShader(const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11PixelShader** shader) { return static_cast<const Vtbl*>(vtbl_)->CreatePixelShader(this, bytecode, bytecodeLength, linkage, shader); }
        HRESULT CreateHullShader(const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11HullShader** shader) { return static_cast<const Vtbl*>(vtbl_)->CreateHullShader(this, bytecode, bytecodeLength, linkage, shader); }
        HRESULT CreateDomainShader(const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11DomainShader** shader) { return static_cast<const Vtbl*>(vtbl_)->CreateDomainShader(this, bytecode, bytecodeLength, linkage, shader); }
        HRESULT CreateComputeShader(const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11ComputeShader** shader) { return static_cast<const Vtbl*>(vtbl_)->CreateComputeShader(this, bytecode, bytecodeLength, linkage, shader); }
        HRESULT CreateClassLinkage(ID3D11ClassLinkage** linkage) { return static_cast<const Vtbl*>(vtbl_)->CreateClassLinkage(this, linkage); }
        HRESULT CreateBlendState(const D3D11_BLEND_DESC* desc, ID3D11BlendState** state) { return static_cast<const Vtbl*>(vtbl_)->CreateBlendState(this, desc, state); }
        HRESULT CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC* desc, ID3D11DepthStencilState** state) { return static_cast<const Vtbl*>(vtbl_)->CreateDepthStencilState(this, desc, state); }
        HRESULT CreateRasterizerState(const D3D11_RASTERIZER_DESC* desc, ID3D11RasterizerState** state) { return static_cast<const Vtbl*>(vtbl_)->CreateRasterizerState(this, desc, state); }
        HRESULT CreateSamplerState(const D3D11_SAMPLER_DESC* desc, ID3D11SamplerState** state) { return static_cast<const Vtbl*>(vtbl_)->CreateSamplerState(this, desc, state); }
        HRESULT CreateQuery(const D3D11_QUERY_DESC* desc, ID3D11Query** query) { return static_cast<const Vtbl*>(vtbl_)->CreateQuery(this, desc, query); }
        HRESULT CreatePredicate(const D3D11_QUERY_DESC* desc, ID3D11Predicate** predicate) { return static_cast<const Vtbl*>(vtbl_)->CreatePredicate(this, desc, predicate); }
        HRESULT CreateCounter(const D3D11_COUNTER_DESC* desc, ID3D11Counter** counter) { return static_cast<const Vtbl*>(vtbl_)->CreateCounter(this, desc, counter); }
        HRESULT CreateDeferredContext(UINT flags, ID3D11DeviceContext** context) { return static_cast<const Vtbl*>(vtbl_)->CreateDeferredContext(this, flags, context); }
        HRESULT OpenSharedResource(HANDLE resource, const GUID& riid, void** object) { return static_cast<const Vtbl*>(vtbl_)->OpenSharedResource(this, resource, riid, object); }
        HRESULT CheckFormatSupport(DXGI_FORMAT format, UINT* support) { return static_cast<const Vtbl*>(vtbl_)->CheckFormatSupport(this, format, support); }
        HRESULT CheckMultisampleQualityLevels(DXGI_FORMAT format, UINT sampleCount, UINT* levels) { return static_cast<const Vtbl*>(vtbl_)->CheckMultisampleQualityLevels(this, format, sampleCount, levels); }
        void CheckCounterInfo(D3D11_COUNTER_INFO* info) { static_cast<const Vtbl*>(vtbl_)->CheckCounterInfo(this, info); }
        HRESULT CheckCounter(const D3D11_COUNTER_DESC* desc, D3D11_COUNTER_TYPE* type, UINT* activeCounters, LPSTR name, UINT* nameLength, LPSTR units, UINT* unitsLength, LPSTR description, UINT* descriptionLength) { return static_cast<const Vtbl*>(vtbl_)->CheckCounter(this, desc, type, activeCounters, name, nameLength, units, unitsLength, description, descriptionLength); }
        HRESULT CheckFeatureSupport(D3D11_FEATURE feature, void* data, UINT dataSize) { return static_cast<const Vtbl*>(vtbl_)->CheckFeatureSupport(this, feature, data, dataSize); }
        HRESULT GetPrivateData(const GUID& guid, UINT* dataSize, void* data) { return static_cast<const Vtbl*>(vtbl_)->GetPrivateData(this, guid, dataSize, data); }
        HRESULT SetPrivateData(const GUID& guid, UINT dataSize, const void* data) { return static_cast<const Vtbl*>(vtbl_)->SetPrivateData(this, guid, dataSize, data); }
        HRESULT SetPrivateDataInterface(const GUID& guid, IUnknown* data) { return static_cast<const Vtbl*>(vtbl_)->SetPrivateDataInterface(this, guid, data); }
        D3D_FEATURE_LEVEL GetFeatureLevel() { return static_cast<const Vtbl*>(vtbl_)->GetFeatureLevel(this); }
        UINT GetCreationFlags() { return static_cast<const Vtbl*>(vtbl_)->GetCreationFlags(this); }
        HRESULT GetDeviceRemovedReason() { return static_cast<const Vtbl*>(vtbl_)->GetDeviceRemovedReason(this); }
        void GetImmediateContext(ID3D11DeviceContext** context) { static_cast<const Vtbl*>(vtbl_)->GetImmediateContext(this, context); }
        HRESULT SetExceptionMode(UINT flags) { return static_cast<const Vtbl*>(vtbl_)->SetExceptionMode(this, flags); }
        UINT GetExceptionMode() { return static_cast<const Vtbl*>(vtbl_)->GetExceptionMode(this); }
    };

    struct ID3D11BlendState1 : ID3D11BlendState
    {
        static constexpr GUID Iid = {0xcc86fabe, 0xda55, 0x401d, {0x85, 0xe7, 0xe3, 0xc9, 0xde, 0x28, 0x77, 0xe9}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_BLEND_DESC* desc);
            void(HX_D3D_CALL* GetDesc1)(void* self, D3D11_BLEND_DESC1* desc);
        };

        void GetDesc1(D3D11_BLEND_DESC1* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc1(this, desc); }
    };

    struct ID3D11RasterizerState1 : ID3D11RasterizerState
    {
        static constexpr GUID Iid = {0x1217d7a6, 0x5039, 0x418c, {0xb0, 0x42, 0x9c, 0xbe, 0x25, 0x6a, 0xfd, 0x6e}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* GetDesc)(void* self, D3D11_RASTERIZER_DESC* desc);
            void(HX_D3D_CALL* GetDesc1)(void* self, D3D11_RASTERIZER_DESC1* desc);
        };

        void GetDesc1(D3D11_RASTERIZER_DESC1* desc) { static_cast<const Vtbl*>(vtbl_)->GetDesc1(this, desc); }
    };

    struct ID3DDeviceContextState : ID3D11DeviceChild
    {
        static constexpr GUID Iid = {0x5c1e0d8a, 0x7c23, 0x48f9, {0x8c, 0x59, 0xa9, 0x29, 0x58, 0xce, 0xff, 0x11}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
        };

    };

    struct ID3D11DeviceContext1 : ID3D11DeviceContext
    {
        static constexpr GUID Iid = {0xbb2c6faa, 0xb5fb, 0x4082, {0x8e, 0x6b, 0x38, 0x8b, 0x8c, 0xfa, 0x90, 0xe1}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            void(HX_D3D_CALL* GetDevice)(void* self, ID3D11Device** device);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            void(HX_D3D_CALL* VSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* PSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* PSSetShader)(void* self, ID3D11PixelShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* PSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* VSSetShader)(void* self, ID3D11VertexShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* DrawIndexed)(void* self, UINT indexCount, UINT startIndex, INT baseVertex);
            void(HX_D3D_CALL* Draw)(void* self, UINT vertexCount, UINT startVertex);
            HRESULT(HX_D3D_CALL* Map)(void* self, ID3D11Resource* resource, UINT subresource, D3D11_MAP mapType, UINT mapFlags, D3D11_MAPPED_SUBRESOURCE* mapped);
            void(HX_D3D_CALL* Unmap)(void* self, ID3D11Resource* resource, UINT subresource);
            void(HX_D3D_CALL* PSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* IASetInputLayout)(void* self, ID3D11InputLayout* layout);
            void(HX_D3D_CALL* IASetVertexBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* strides, const UINT* offsets);
            void(HX_D3D_CALL* IASetIndexBuffer)(void* self, ID3D11Buffer* buffer, DXGI_FORMAT format, UINT offset);
            void(HX_D3D_CALL* DrawIndexedInstanced)(void* self, UINT indexCountPerInstance, UINT instanceCount, UINT startIndex, INT baseVertex, UINT startInstance);
            void(HX_D3D_CALL* DrawInstanced)(void* self, UINT vertexCountPerInstance, UINT instanceCount, UINT startVertex, UINT startInstance);
            void(HX_D3D_CALL* GSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* GSSetShader)(void* self, ID3D11GeometryShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* IASetPrimitiveTopology)(void* self, D3D11_PRIMITIVE_TOPOLOGY topology);
            void(HX_D3D_CALL* VSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* VSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* Begin)(void* self, ID3D11Asynchronous* async);
            void(HX_D3D_CALL* End)(void* self, ID3D11Asynchronous* async);
            HRESULT(HX_D3D_CALL* GetData)(void* self, ID3D11Asynchronous* async, void* data, UINT dataSize, UINT flags);
            void(HX_D3D_CALL* SetPredication)(void* self, ID3D11Predicate* predicate, BOOL value);
            void(HX_D3D_CALL* GSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* GSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* OMSetRenderTargets)(void* self, UINT count, ID3D11RenderTargetView* const* views, ID3D11DepthStencilView* depth);
            void(HX_D3D_CALL* OMSetRenderTargetsAndUnorderedAccessViews)(void* self, UINT rtvCount, ID3D11RenderTargetView* const* views, ID3D11DepthStencilView* depth, UINT uavStart, UINT uavCount, ID3D11UnorderedAccessView* const* uavs, const UINT* initialCounts);
            void(HX_D3D_CALL* OMSetBlendState)(void* self, ID3D11BlendState* state, const FLOAT* blendFactor, UINT sampleMask);
            void(HX_D3D_CALL* OMSetDepthStencilState)(void* self, ID3D11DepthStencilState* state, UINT stencilRef);
            void(HX_D3D_CALL* SOSetTargets)(void* self, UINT count, ID3D11Buffer* const* targets, const UINT* offsets);
            void(HX_D3D_CALL* DrawAuto)(void* self);
            void(HX_D3D_CALL* DrawIndexedInstancedIndirect)(void* self, ID3D11Buffer* args, UINT offset);
            void(HX_D3D_CALL* DrawInstancedIndirect)(void* self, ID3D11Buffer* args, UINT offset);
            void(HX_D3D_CALL* Dispatch)(void* self, UINT x, UINT y, UINT z);
            void(HX_D3D_CALL* DispatchIndirect)(void* self, ID3D11Buffer* args, UINT offset);
            void(HX_D3D_CALL* RSSetState)(void* self, ID3D11RasterizerState* state);
            void(HX_D3D_CALL* RSSetViewports)(void* self, UINT count, const D3D11_VIEWPORT* viewports);
            void(HX_D3D_CALL* RSSetScissorRects)(void* self, UINT count, const D3D11_RECT* rects);
            void(HX_D3D_CALL* CopySubresourceRegion)(void* self, ID3D11Resource* dst, UINT dstSubresource, UINT dstX, UINT dstY, UINT dstZ, ID3D11Resource* src, UINT srcSubresource, const D3D11_BOX* srcBox);
            void(HX_D3D_CALL* CopyResource)(void* self, ID3D11Resource* dst, ID3D11Resource* src);
            void(HX_D3D_CALL* UpdateSubresource)(void* self, ID3D11Resource* dst, UINT dstSubresource, const D3D11_BOX* dstBox, const void* data, UINT rowPitch, UINT depthPitch);
            void(HX_D3D_CALL* CopyStructureCount)(void* self, ID3D11Buffer* dst, UINT dstOffset, ID3D11UnorderedAccessView* src);
            void(HX_D3D_CALL* ClearRenderTargetView)(void* self, ID3D11RenderTargetView* view, const FLOAT* color);
            void(HX_D3D_CALL* ClearUnorderedAccessViewUint)(void* self, ID3D11UnorderedAccessView* view, const UINT* values);
            void(HX_D3D_CALL* ClearUnorderedAccessViewFloat)(void* self, ID3D11UnorderedAccessView* view, const FLOAT* values);
            void(HX_D3D_CALL* ClearDepthStencilView)(void* self, ID3D11DepthStencilView* view, UINT flags, FLOAT depth, UINT8 stencil);
            void(HX_D3D_CALL* GenerateMips)(void* self, ID3D11ShaderResourceView* view);
            void(HX_D3D_CALL* SetResourceMinLOD)(void* self, ID3D11Resource* resource, FLOAT minLod);
            FLOAT(HX_D3D_CALL* GetResourceMinLOD)(void* self, ID3D11Resource* resource);
            void(HX_D3D_CALL* ResolveSubresource)(void* self, ID3D11Resource* dst, UINT dstSubresource, ID3D11Resource* src, UINT srcSubresource, DXGI_FORMAT format);
            void(HX_D3D_CALL* ExecuteCommandList)(void* self, ID3D11CommandList* list, BOOL restoreState);
            void(HX_D3D_CALL* HSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* HSSetShader)(void* self, ID3D11HullShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* HSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* HSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* DSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* DSSetShader)(void* self, ID3D11DomainShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* DSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* DSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* CSSetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView* const* views);
            void(HX_D3D_CALL* CSSetUnorderedAccessViews)(void* self, UINT startSlot, UINT count, ID3D11UnorderedAccessView* const* views, const UINT* initialCounts);
            void(HX_D3D_CALL* CSSetShader)(void* self, ID3D11ComputeShader* shader, ID3D11ClassInstance* const* instances, UINT instanceCount);
            void(HX_D3D_CALL* CSSetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState* const* samplers);
            void(HX_D3D_CALL* CSSetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers);
            void(HX_D3D_CALL* VSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* PSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* PSGetShader)(void* self, ID3D11PixelShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* PSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* VSGetShader)(void* self, ID3D11VertexShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* PSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* IAGetInputLayout)(void* self, ID3D11InputLayout** layout);
            void(HX_D3D_CALL* IAGetVertexBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* strides, UINT* offsets);
            void(HX_D3D_CALL* IAGetIndexBuffer)(void* self, ID3D11Buffer** buffer, DXGI_FORMAT* format, UINT* offset);
            void(HX_D3D_CALL* GSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* GSGetShader)(void* self, ID3D11GeometryShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* IAGetPrimitiveTopology)(void* self, D3D11_PRIMITIVE_TOPOLOGY* topology);
            void(HX_D3D_CALL* VSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* VSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* GetPredication)(void* self, ID3D11Predicate** predicate, BOOL* value);
            void(HX_D3D_CALL* GSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* GSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* OMGetRenderTargets)(void* self, UINT count, ID3D11RenderTargetView** views, ID3D11DepthStencilView** depth);
            void(HX_D3D_CALL* OMGetRenderTargetsAndUnorderedAccessViews)(void* self, UINT rtvCount, ID3D11RenderTargetView** views, ID3D11DepthStencilView** depth, UINT uavStart, UINT uavCount, ID3D11UnorderedAccessView** uavs);
            void(HX_D3D_CALL* OMGetBlendState)(void* self, ID3D11BlendState** state, FLOAT* blendFactor, UINT* sampleMask);
            void(HX_D3D_CALL* OMGetDepthStencilState)(void* self, ID3D11DepthStencilState** state, UINT* stencilRef);
            void(HX_D3D_CALL* SOGetTargets)(void* self, UINT count, ID3D11Buffer** targets);
            void(HX_D3D_CALL* RSGetState)(void* self, ID3D11RasterizerState** state);
            void(HX_D3D_CALL* RSGetViewports)(void* self, UINT* count, D3D11_VIEWPORT* viewports);
            void(HX_D3D_CALL* RSGetScissorRects)(void* self, UINT* count, D3D11_RECT* rects);
            void(HX_D3D_CALL* HSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* HSGetShader)(void* self, ID3D11HullShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* HSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* HSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* DSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* DSGetShader)(void* self, ID3D11DomainShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* DSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* DSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* CSGetShaderResources)(void* self, UINT startSlot, UINT count, ID3D11ShaderResourceView** views);
            void(HX_D3D_CALL* CSGetUnorderedAccessViews)(void* self, UINT startSlot, UINT count, ID3D11UnorderedAccessView** views);
            void(HX_D3D_CALL* CSGetShader)(void* self, ID3D11ComputeShader** shader, ID3D11ClassInstance** instances, UINT* instanceCount);
            void(HX_D3D_CALL* CSGetSamplers)(void* self, UINT startSlot, UINT count, ID3D11SamplerState** samplers);
            void(HX_D3D_CALL* CSGetConstantBuffers)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers);
            void(HX_D3D_CALL* ClearState)(void* self);
            void(HX_D3D_CALL* Flush)(void* self);
            D3D11_DEVICE_CONTEXT_TYPE(HX_D3D_CALL* GetType)(void* self);
            UINT(HX_D3D_CALL* GetContextFlags)(void* self);
            HRESULT(HX_D3D_CALL* FinishCommandList)(void* self, BOOL restoreState, ID3D11CommandList** list);
            void(HX_D3D_CALL* CopySubresourceRegion1)(void* self, ID3D11Resource* dst, UINT dstSubresource, UINT dstX, UINT dstY, UINT dstZ, ID3D11Resource* src, UINT srcSubresource, const D3D11_BOX* srcBox, UINT copyFlags);
            void(HX_D3D_CALL* UpdateSubresource1)(void* self, ID3D11Resource* dst, UINT dstSubresource, const D3D11_BOX* dstBox, const void* data, UINT rowPitch, UINT depthPitch, UINT copyFlags);
            void(HX_D3D_CALL* DiscardResource)(void* self, ID3D11Resource* resource);
            void(HX_D3D_CALL* DiscardView)(void* self, ID3D11View* view);
            void(HX_D3D_CALL* VSSetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount);
            void(HX_D3D_CALL* HSSetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount);
            void(HX_D3D_CALL* DSSetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount);
            void(HX_D3D_CALL* GSSetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount);
            void(HX_D3D_CALL* PSSetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount);
            void(HX_D3D_CALL* CSSetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount);
            void(HX_D3D_CALL* VSGetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount);
            void(HX_D3D_CALL* HSGetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount);
            void(HX_D3D_CALL* DSGetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount);
            void(HX_D3D_CALL* GSGetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount);
            void(HX_D3D_CALL* PSGetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount);
            void(HX_D3D_CALL* CSGetConstantBuffers1)(void* self, UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount);
            void(HX_D3D_CALL* SwapDeviceContextState)(void* self, ID3DDeviceContextState* state, ID3DDeviceContextState** previous);
            void(HX_D3D_CALL* ClearView)(void* self, ID3D11View* view, const FLOAT* color, const D3D11_RECT* rects, UINT rectCount);
            void(HX_D3D_CALL* DiscardView1)(void* self, ID3D11View* view, const D3D11_RECT* rects, UINT rectCount);
        };

        void CopySubresourceRegion1(ID3D11Resource* dst, UINT dstSubresource, UINT dstX, UINT dstY, UINT dstZ, ID3D11Resource* src, UINT srcSubresource, const D3D11_BOX* srcBox, UINT copyFlags) { static_cast<const Vtbl*>(vtbl_)->CopySubresourceRegion1(this, dst, dstSubresource, dstX, dstY, dstZ, src, srcSubresource, srcBox, copyFlags); }
        void UpdateSubresource1(ID3D11Resource* dst, UINT dstSubresource, const D3D11_BOX* dstBox, const void* data, UINT rowPitch, UINT depthPitch, UINT copyFlags) { static_cast<const Vtbl*>(vtbl_)->UpdateSubresource1(this, dst, dstSubresource, dstBox, data, rowPitch, depthPitch, copyFlags); }
        void DiscardResource(ID3D11Resource* resource) { static_cast<const Vtbl*>(vtbl_)->DiscardResource(this, resource); }
        void DiscardView(ID3D11View* view) { static_cast<const Vtbl*>(vtbl_)->DiscardView(this, view); }
        void VSSetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->VSSetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void HSSetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->HSSetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void DSSetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->DSSetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void GSSetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->GSSetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void PSSetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->PSSetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void CSSetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer* const* buffers, const UINT* firstConstant, const UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->CSSetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void VSGetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->VSGetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void HSGetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->HSGetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void DSGetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->DSGetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void GSGetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->GSGetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void PSGetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->PSGetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void CSGetConstantBuffers1(UINT startSlot, UINT count, ID3D11Buffer** buffers, UINT* firstConstant, UINT* constantCount) { static_cast<const Vtbl*>(vtbl_)->CSGetConstantBuffers1(this, startSlot, count, buffers, firstConstant, constantCount); }
        void SwapDeviceContextState(ID3DDeviceContextState* state, ID3DDeviceContextState** previous) { static_cast<const Vtbl*>(vtbl_)->SwapDeviceContextState(this, state, previous); }
        void ClearView(ID3D11View* view, const FLOAT* color, const D3D11_RECT* rects, UINT rectCount) { static_cast<const Vtbl*>(vtbl_)->ClearView(this, view, color, rects, rectCount); }
        void DiscardView1(ID3D11View* view, const D3D11_RECT* rects, UINT rectCount) { static_cast<const Vtbl*>(vtbl_)->DiscardView1(this, view, rects, rectCount); }
    };

    struct ID3D11Device1 : ID3D11Device
    {
        static constexpr GUID Iid = {0xa04bfb29, 0x08ef, 0x43d6, {0xa4, 0x9c, 0xa9, 0xbd, 0xbd, 0xcb, 0xe6, 0x86}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* CreateBuffer)(void* self, const D3D11_BUFFER_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Buffer** buffer);
            HRESULT(HX_D3D_CALL* CreateTexture1D)(void* self, const D3D11_TEXTURE1D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture1D** texture);
            HRESULT(HX_D3D_CALL* CreateTexture2D)(void* self, const D3D11_TEXTURE2D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture2D** texture);
            HRESULT(HX_D3D_CALL* CreateTexture3D)(void* self, const D3D11_TEXTURE3D_DESC* desc, const D3D11_SUBRESOURCE_DATA* data, ID3D11Texture3D** texture);
            HRESULT(HX_D3D_CALL* CreateShaderResourceView)(void* self, ID3D11Resource* resource, const D3D11_SHADER_RESOURCE_VIEW_DESC* desc, ID3D11ShaderResourceView** view);
            HRESULT(HX_D3D_CALL* CreateUnorderedAccessView)(void* self, ID3D11Resource* resource, const D3D11_UNORDERED_ACCESS_VIEW_DESC* desc, ID3D11UnorderedAccessView** view);
            HRESULT(HX_D3D_CALL* CreateRenderTargetView)(void* self, ID3D11Resource* resource, const D3D11_RENDER_TARGET_VIEW_DESC* desc, ID3D11RenderTargetView** view);
            HRESULT(HX_D3D_CALL* CreateDepthStencilView)(void* self, ID3D11Resource* resource, const D3D11_DEPTH_STENCIL_VIEW_DESC* desc, ID3D11DepthStencilView** view);
            HRESULT(HX_D3D_CALL* CreateInputLayout)(void* self, const D3D11_INPUT_ELEMENT_DESC* elements, UINT count, const void* bytecode, SIZE_T bytecodeLength, ID3D11InputLayout** layout);
            HRESULT(HX_D3D_CALL* CreateVertexShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11VertexShader** shader);
            HRESULT(HX_D3D_CALL* CreateGeometryShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11GeometryShader** shader);
            HRESULT(HX_D3D_CALL* CreateGeometryShaderWithStreamOutput)(void* self, const void* bytecode, SIZE_T bytecodeLength, const D3D11_SO_DECLARATION_ENTRY* entries, UINT entryCount, const UINT* strides, UINT strideCount, UINT rasterizedStream, ID3D11ClassLinkage* linkage, ID3D11GeometryShader** shader);
            HRESULT(HX_D3D_CALL* CreatePixelShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11PixelShader** shader);
            HRESULT(HX_D3D_CALL* CreateHullShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11HullShader** shader);
            HRESULT(HX_D3D_CALL* CreateDomainShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11DomainShader** shader);
            HRESULT(HX_D3D_CALL* CreateComputeShader)(void* self, const void* bytecode, SIZE_T bytecodeLength, ID3D11ClassLinkage* linkage, ID3D11ComputeShader** shader);
            HRESULT(HX_D3D_CALL* CreateClassLinkage)(void* self, ID3D11ClassLinkage** linkage);
            HRESULT(HX_D3D_CALL* CreateBlendState)(void* self, const D3D11_BLEND_DESC* desc, ID3D11BlendState** state);
            HRESULT(HX_D3D_CALL* CreateDepthStencilState)(void* self, const D3D11_DEPTH_STENCIL_DESC* desc, ID3D11DepthStencilState** state);
            HRESULT(HX_D3D_CALL* CreateRasterizerState)(void* self, const D3D11_RASTERIZER_DESC* desc, ID3D11RasterizerState** state);
            HRESULT(HX_D3D_CALL* CreateSamplerState)(void* self, const D3D11_SAMPLER_DESC* desc, ID3D11SamplerState** state);
            HRESULT(HX_D3D_CALL* CreateQuery)(void* self, const D3D11_QUERY_DESC* desc, ID3D11Query** query);
            HRESULT(HX_D3D_CALL* CreatePredicate)(void* self, const D3D11_QUERY_DESC* desc, ID3D11Predicate** predicate);
            HRESULT(HX_D3D_CALL* CreateCounter)(void* self, const D3D11_COUNTER_DESC* desc, ID3D11Counter** counter);
            HRESULT(HX_D3D_CALL* CreateDeferredContext)(void* self, UINT flags, ID3D11DeviceContext** context);
            HRESULT(HX_D3D_CALL* OpenSharedResource)(void* self, HANDLE resource, const GUID& riid, void** object);
            HRESULT(HX_D3D_CALL* CheckFormatSupport)(void* self, DXGI_FORMAT format, UINT* support);
            HRESULT(HX_D3D_CALL* CheckMultisampleQualityLevels)(void* self, DXGI_FORMAT format, UINT sampleCount, UINT* levels);
            void(HX_D3D_CALL* CheckCounterInfo)(void* self, D3D11_COUNTER_INFO* info);
            HRESULT(HX_D3D_CALL* CheckCounter)(void* self, const D3D11_COUNTER_DESC* desc, D3D11_COUNTER_TYPE* type, UINT* activeCounters, LPSTR name, UINT* nameLength, LPSTR units, UINT* unitsLength, LPSTR description, UINT* descriptionLength);
            HRESULT(HX_D3D_CALL* CheckFeatureSupport)(void* self, D3D11_FEATURE feature, void* data, UINT dataSize);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& guid, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& guid, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& guid, IUnknown* data);
            D3D_FEATURE_LEVEL(HX_D3D_CALL* GetFeatureLevel)(void* self);
            UINT(HX_D3D_CALL* GetCreationFlags)(void* self);
            HRESULT(HX_D3D_CALL* GetDeviceRemovedReason)(void* self);
            void(HX_D3D_CALL* GetImmediateContext)(void* self, ID3D11DeviceContext** context);
            HRESULT(HX_D3D_CALL* SetExceptionMode)(void* self, UINT flags);
            UINT(HX_D3D_CALL* GetExceptionMode)(void* self);
            void(HX_D3D_CALL* GetImmediateContext1)(void* self, ID3D11DeviceContext1** context);
            HRESULT(HX_D3D_CALL* CreateDeferredContext1)(void* self, UINT flags, ID3D11DeviceContext1** context);
            HRESULT(HX_D3D_CALL* CreateBlendState1)(void* self, const D3D11_BLEND_DESC1* desc, ID3D11BlendState1** state);
            HRESULT(HX_D3D_CALL* CreateRasterizerState1)(void* self, const D3D11_RASTERIZER_DESC1* desc, ID3D11RasterizerState1** state);
            HRESULT(HX_D3D_CALL* CreateDeviceContextState)(void* self, UINT flags, const D3D_FEATURE_LEVEL* levels, UINT levelCount, UINT sdkVersion, const GUID& emulatedInterface, D3D_FEATURE_LEVEL* chosenLevel, ID3DDeviceContextState** state);
            HRESULT(HX_D3D_CALL* OpenSharedResource1)(void* self, HANDLE resource, const GUID& riid, void** object);
            HRESULT(HX_D3D_CALL* OpenSharedResourceByName)(void* self, LPCWSTR name, DWORD access, const GUID& riid, void** object);
        };

        void GetImmediateContext1(ID3D11DeviceContext1** context) { static_cast<const Vtbl*>(vtbl_)->GetImmediateContext1(this, context); }
        HRESULT CreateDeferredContext1(UINT flags, ID3D11DeviceContext1** context) { return static_cast<const Vtbl*>(vtbl_)->CreateDeferredContext1(this, flags, context); }
        HRESULT CreateBlendState1(const D3D11_BLEND_DESC1* desc, ID3D11BlendState1** state) { return static_cast<const Vtbl*>(vtbl_)->CreateBlendState1(this, desc, state); }
        HRESULT CreateRasterizerState1(const D3D11_RASTERIZER_DESC1* desc, ID3D11RasterizerState1** state) { return static_cast<const Vtbl*>(vtbl_)->CreateRasterizerState1(this, desc, state); }
        HRESULT CreateDeviceContextState(UINT flags, const D3D_FEATURE_LEVEL* levels, UINT levelCount, UINT sdkVersion, const GUID& emulatedInterface, D3D_FEATURE_LEVEL* chosenLevel, ID3DDeviceContextState** state) { return static_cast<const Vtbl*>(vtbl_)->CreateDeviceContextState(this, flags, levels, levelCount, sdkVersion, emulatedInterface, chosenLevel, state); }
        HRESULT OpenSharedResource1(HANDLE resource, const GUID& riid, void** object) { return static_cast<const Vtbl*>(vtbl_)->OpenSharedResource1(this, resource, riid, object); }
        HRESULT OpenSharedResourceByName(LPCWSTR name, DWORD access, const GUID& riid, void** object) { return static_cast<const Vtbl*>(vtbl_)->OpenSharedResourceByName(this, name, access, riid, object); }
    };

    struct ID3DUserDefinedAnnotation : IUnknown
    {
        static constexpr GUID Iid = {0xb2daad8b, 0x03d4, 0x4dbf, {0x95, 0xeb, 0x32, 0xab, 0x4b, 0x63, 0xd0, 0xab}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            INT(HX_D3D_CALL* BeginEvent)(void* self, LPCWSTR name);
            INT(HX_D3D_CALL* EndEvent)(void* self);
            void(HX_D3D_CALL* SetMarker)(void* self, LPCWSTR name);
            BOOL(HX_D3D_CALL* GetStatus)(void* self);
        };

        INT BeginEvent(LPCWSTR name) { return static_cast<const Vtbl*>(vtbl_)->BeginEvent(this, name); }
        INT EndEvent() { return static_cast<const Vtbl*>(vtbl_)->EndEvent(this); }
        void SetMarker(LPCWSTR name) { static_cast<const Vtbl*>(vtbl_)->SetMarker(this, name); }
        BOOL GetStatus() { return static_cast<const Vtbl*>(vtbl_)->GetStatus(this); }
    };

    struct IDXGIObject : IUnknown
    {
        static constexpr GUID Iid = {0xaec22fb8, 0x76f3, 0x4639, {0x9b, 0xe0, 0x28, 0xeb, 0x43, 0xa6, 0x7a, 0x2e}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
        };

        HRESULT SetPrivateData(const GUID& name, UINT dataSize, const void* data) { return static_cast<const Vtbl*>(vtbl_)->SetPrivateData(this, name, dataSize, data); }
        HRESULT SetPrivateDataInterface(const GUID& name, const IUnknown* unknown) { return static_cast<const Vtbl*>(vtbl_)->SetPrivateDataInterface(this, name, unknown); }
        HRESULT GetPrivateData(const GUID& name, UINT* dataSize, void* data) { return static_cast<const Vtbl*>(vtbl_)->GetPrivateData(this, name, dataSize, data); }
        HRESULT GetParent(const GUID& riid, void** parent) { return static_cast<const Vtbl*>(vtbl_)->GetParent(this, riid, parent); }
    };

    struct IDXGIDeviceSubObject : IDXGIObject
    {
        static constexpr GUID Iid = {0x3d3e0379, 0xf9de, 0x4d58, {0xbb, 0x6c, 0x18, 0xd6, 0x29, 0x92, 0xf1, 0xa6}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetDevice)(void* self, const GUID& riid, void** device);
        };

        HRESULT GetDevice(const GUID& riid, void** device) { return static_cast<const Vtbl*>(vtbl_)->GetDevice(this, riid, device); }
    };

    struct IDXGISurface : IDXGIDeviceSubObject
    {
        static constexpr GUID Iid = {0xcafcb56c, 0x6ac3, 0x4889, {0xbf, 0x47, 0x9e, 0x23, 0xbb, 0xd2, 0x60, 0xec}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetDevice)(void* self, const GUID& riid, void** device);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_SURFACE_DESC* desc);
            HRESULT(HX_D3D_CALL* Map)(void* self, DXGI_MAPPED_RECT* rect, UINT flags);
            HRESULT(HX_D3D_CALL* Unmap)(void* self);
        };

        HRESULT GetDesc(DXGI_SURFACE_DESC* desc) { return static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
        HRESULT Map(DXGI_MAPPED_RECT* rect, UINT flags) { return static_cast<const Vtbl*>(vtbl_)->Map(this, rect, flags); }
        HRESULT Unmap() { return static_cast<const Vtbl*>(vtbl_)->Unmap(this); }
    };

    struct IDXGIOutput : IDXGIObject
    {
        static constexpr GUID Iid = {0xae02eedb, 0xc735, 0x4690, {0x8d, 0x52, 0x5a, 0x8d, 0xc2, 0x02, 0x13, 0xaa}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_OUTPUT_DESC* desc);
            HRESULT(HX_D3D_CALL* GetDisplayModeList)(void* self, DXGI_FORMAT format, UINT flags, UINT* count, DXGI_MODE_DESC* modes);
            HRESULT(HX_D3D_CALL* FindClosestMatchingMode)(void* self, const DXGI_MODE_DESC* mode, DXGI_MODE_DESC* closest, IUnknown* device);
            HRESULT(HX_D3D_CALL* WaitForVBlank)(void* self);
            HRESULT(HX_D3D_CALL* TakeOwnership)(void* self, IUnknown* device, BOOL exclusive);
            void(HX_D3D_CALL* ReleaseOwnership)(void* self);
            HRESULT(HX_D3D_CALL* GetGammaControlCapabilities)(void* self, void* capabilities);
            HRESULT(HX_D3D_CALL* SetGammaControl)(void* self, const void* array);
            HRESULT(HX_D3D_CALL* GetGammaControl)(void* self, void* array);
            HRESULT(HX_D3D_CALL* SetDisplaySurface)(void* self, IDXGISurface* surface);
            HRESULT(HX_D3D_CALL* GetDisplaySurfaceData)(void* self, IDXGISurface* destination);
            HRESULT(HX_D3D_CALL* GetFrameStatistics)(void* self, DXGI_FRAME_STATISTICS* stats);
        };

        HRESULT GetDesc(DXGI_OUTPUT_DESC* desc) { return static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
        HRESULT GetDisplayModeList(DXGI_FORMAT format, UINT flags, UINT* count, DXGI_MODE_DESC* modes) { return static_cast<const Vtbl*>(vtbl_)->GetDisplayModeList(this, format, flags, count, modes); }
        HRESULT FindClosestMatchingMode(const DXGI_MODE_DESC* mode, DXGI_MODE_DESC* closest, IUnknown* device) { return static_cast<const Vtbl*>(vtbl_)->FindClosestMatchingMode(this, mode, closest, device); }
        HRESULT WaitForVBlank() { return static_cast<const Vtbl*>(vtbl_)->WaitForVBlank(this); }
        HRESULT TakeOwnership(IUnknown* device, BOOL exclusive) { return static_cast<const Vtbl*>(vtbl_)->TakeOwnership(this, device, exclusive); }
        void ReleaseOwnership() { static_cast<const Vtbl*>(vtbl_)->ReleaseOwnership(this); }
        HRESULT GetGammaControlCapabilities(void* capabilities) { return static_cast<const Vtbl*>(vtbl_)->GetGammaControlCapabilities(this, capabilities); }
        HRESULT SetGammaControl(const void* array) { return static_cast<const Vtbl*>(vtbl_)->SetGammaControl(this, array); }
        HRESULT GetGammaControl(void* array) { return static_cast<const Vtbl*>(vtbl_)->GetGammaControl(this, array); }
        HRESULT SetDisplaySurface(IDXGISurface* surface) { return static_cast<const Vtbl*>(vtbl_)->SetDisplaySurface(this, surface); }
        HRESULT GetDisplaySurfaceData(IDXGISurface* destination) { return static_cast<const Vtbl*>(vtbl_)->GetDisplaySurfaceData(this, destination); }
        HRESULT GetFrameStatistics(DXGI_FRAME_STATISTICS* stats) { return static_cast<const Vtbl*>(vtbl_)->GetFrameStatistics(this, stats); }
    };

    struct IDXGIAdapter : IDXGIObject
    {
        static constexpr GUID Iid = {0x2411e7e1, 0x12ac, 0x4ccf, {0xbd, 0x14, 0x97, 0x98, 0xe8, 0x53, 0x4d, 0xc0}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumOutputs)(void* self, UINT index, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_ADAPTER_DESC* desc);
            HRESULT(HX_D3D_CALL* CheckInterfaceSupport)(void* self, const GUID& name, LARGE_INTEGER* umdVersion);
        };

        HRESULT EnumOutputs(UINT index, IDXGIOutput** output) { return static_cast<const Vtbl*>(vtbl_)->EnumOutputs(this, index, output); }
        HRESULT GetDesc(DXGI_ADAPTER_DESC* desc) { return static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
        HRESULT CheckInterfaceSupport(const GUID& name, LARGE_INTEGER* umdVersion) { return static_cast<const Vtbl*>(vtbl_)->CheckInterfaceSupport(this, name, umdVersion); }
    };

    struct IDXGIAdapter1 : IDXGIAdapter
    {
        static constexpr GUID Iid = {0x29038f61, 0x3839, 0x4626, {0x91, 0xfd, 0x08, 0x68, 0x79, 0x01, 0x1a, 0x05}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumOutputs)(void* self, UINT index, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_ADAPTER_DESC* desc);
            HRESULT(HX_D3D_CALL* CheckInterfaceSupport)(void* self, const GUID& name, LARGE_INTEGER* umdVersion);
            HRESULT(HX_D3D_CALL* GetDesc1)(void* self, DXGI_ADAPTER_DESC1* desc);
        };

        HRESULT GetDesc1(DXGI_ADAPTER_DESC1* desc) { return static_cast<const Vtbl*>(vtbl_)->GetDesc1(this, desc); }
    };

    struct IDXGIDevice : IDXGIObject
    {
        static constexpr GUID Iid = {0x54ec77fa, 0x1377, 0x44e6, {0x8c, 0x32, 0x88, 0xfd, 0x5f, 0x44, 0xc8, 0x4c}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetAdapter)(void* self, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* CreateSurface)(void* self, const DXGI_SURFACE_DESC* desc, UINT count, DXGI_USAGE usage, const void* sharedResource, IDXGISurface** surface);
            HRESULT(HX_D3D_CALL* QueryResourceResidency)(void* self, IUnknown* const* resources, void* status, UINT count);
            HRESULT(HX_D3D_CALL* SetGPUThreadPriority)(void* self, INT priority);
            HRESULT(HX_D3D_CALL* GetGPUThreadPriority)(void* self, INT* priority);
        };

        HRESULT GetAdapter(IDXGIAdapter** adapter) { return static_cast<const Vtbl*>(vtbl_)->GetAdapter(this, adapter); }
        HRESULT CreateSurface(const DXGI_SURFACE_DESC* desc, UINT count, DXGI_USAGE usage, const void* sharedResource, IDXGISurface** surface) { return static_cast<const Vtbl*>(vtbl_)->CreateSurface(this, desc, count, usage, sharedResource, surface); }
        HRESULT QueryResourceResidency(IUnknown* const* resources, void* status, UINT count) { return static_cast<const Vtbl*>(vtbl_)->QueryResourceResidency(this, resources, status, count); }
        HRESULT SetGPUThreadPriority(INT priority) { return static_cast<const Vtbl*>(vtbl_)->SetGPUThreadPriority(this, priority); }
        HRESULT GetGPUThreadPriority(INT* priority) { return static_cast<const Vtbl*>(vtbl_)->GetGPUThreadPriority(this, priority); }
    };

    struct IDXGIDevice1 : IDXGIDevice
    {
        static constexpr GUID Iid = {0x77db970f, 0x6276, 0x48ba, {0xba, 0x28, 0x07, 0x01, 0x43, 0xb4, 0x39, 0x2c}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetAdapter)(void* self, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* CreateSurface)(void* self, const DXGI_SURFACE_DESC* desc, UINT count, DXGI_USAGE usage, const void* sharedResource, IDXGISurface** surface);
            HRESULT(HX_D3D_CALL* QueryResourceResidency)(void* self, IUnknown* const* resources, void* status, UINT count);
            HRESULT(HX_D3D_CALL* SetGPUThreadPriority)(void* self, INT priority);
            HRESULT(HX_D3D_CALL* GetGPUThreadPriority)(void* self, INT* priority);
            HRESULT(HX_D3D_CALL* SetMaximumFrameLatency)(void* self, UINT maxLatency);
            HRESULT(HX_D3D_CALL* GetMaximumFrameLatency)(void* self, UINT* maxLatency);
        };

        HRESULT SetMaximumFrameLatency(UINT maxLatency) { return static_cast<const Vtbl*>(vtbl_)->SetMaximumFrameLatency(this, maxLatency); }
        HRESULT GetMaximumFrameLatency(UINT* maxLatency) { return static_cast<const Vtbl*>(vtbl_)->GetMaximumFrameLatency(this, maxLatency); }
    };

    struct IDXGISwapChain : IDXGIDeviceSubObject
    {
        static constexpr GUID Iid = {0x310d36a0, 0xd2e7, 0x4c0a, {0xaa, 0x04, 0x6a, 0x9d, 0x23, 0xb8, 0x88, 0x6a}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetDevice)(void* self, const GUID& riid, void** device);
            HRESULT(HX_D3D_CALL* Present)(void* self, UINT syncInterval, UINT flags);
            HRESULT(HX_D3D_CALL* GetBuffer)(void* self, UINT index, const GUID& riid, void** surface);
            HRESULT(HX_D3D_CALL* SetFullscreenState)(void* self, BOOL fullscreen, IDXGIOutput* target);
            HRESULT(HX_D3D_CALL* GetFullscreenState)(void* self, BOOL* fullscreen, IDXGIOutput** target);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_SWAP_CHAIN_DESC* desc);
            HRESULT(HX_D3D_CALL* ResizeBuffers)(void* self, UINT count, UINT width, UINT height, DXGI_FORMAT format, UINT flags);
            HRESULT(HX_D3D_CALL* ResizeTarget)(void* self, const DXGI_MODE_DESC* target);
            HRESULT(HX_D3D_CALL* GetContainingOutput)(void* self, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* GetFrameStatistics)(void* self, DXGI_FRAME_STATISTICS* stats);
            HRESULT(HX_D3D_CALL* GetLastPresentCount)(void* self, UINT* count);
        };

        HRESULT Present(UINT syncInterval, UINT flags) { return static_cast<const Vtbl*>(vtbl_)->Present(this, syncInterval, flags); }
        HRESULT GetBuffer(UINT index, const GUID& riid, void** surface) { return static_cast<const Vtbl*>(vtbl_)->GetBuffer(this, index, riid, surface); }
        HRESULT SetFullscreenState(BOOL fullscreen, IDXGIOutput* target) { return static_cast<const Vtbl*>(vtbl_)->SetFullscreenState(this, fullscreen, target); }
        HRESULT GetFullscreenState(BOOL* fullscreen, IDXGIOutput** target) { return static_cast<const Vtbl*>(vtbl_)->GetFullscreenState(this, fullscreen, target); }
        HRESULT GetDesc(DXGI_SWAP_CHAIN_DESC* desc) { return static_cast<const Vtbl*>(vtbl_)->GetDesc(this, desc); }
        HRESULT ResizeBuffers(UINT count, UINT width, UINT height, DXGI_FORMAT format, UINT flags) { return static_cast<const Vtbl*>(vtbl_)->ResizeBuffers(this, count, width, height, format, flags); }
        HRESULT ResizeTarget(const DXGI_MODE_DESC* target) { return static_cast<const Vtbl*>(vtbl_)->ResizeTarget(this, target); }
        HRESULT GetContainingOutput(IDXGIOutput** output) { return static_cast<const Vtbl*>(vtbl_)->GetContainingOutput(this, output); }
        HRESULT GetFrameStatistics(DXGI_FRAME_STATISTICS* stats) { return static_cast<const Vtbl*>(vtbl_)->GetFrameStatistics(this, stats); }
        HRESULT GetLastPresentCount(UINT* count) { return static_cast<const Vtbl*>(vtbl_)->GetLastPresentCount(this, count); }
    };

    struct IDXGISwapChain1 : IDXGISwapChain
    {
        static constexpr GUID Iid = {0x790a45f7, 0x0d42, 0x4876, {0x98, 0x3a, 0x0a, 0x55, 0xcf, 0xe6, 0xf4, 0xaa}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetDevice)(void* self, const GUID& riid, void** device);
            HRESULT(HX_D3D_CALL* Present)(void* self, UINT syncInterval, UINT flags);
            HRESULT(HX_D3D_CALL* GetBuffer)(void* self, UINT index, const GUID& riid, void** surface);
            HRESULT(HX_D3D_CALL* SetFullscreenState)(void* self, BOOL fullscreen, IDXGIOutput* target);
            HRESULT(HX_D3D_CALL* GetFullscreenState)(void* self, BOOL* fullscreen, IDXGIOutput** target);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_SWAP_CHAIN_DESC* desc);
            HRESULT(HX_D3D_CALL* ResizeBuffers)(void* self, UINT count, UINT width, UINT height, DXGI_FORMAT format, UINT flags);
            HRESULT(HX_D3D_CALL* ResizeTarget)(void* self, const DXGI_MODE_DESC* target);
            HRESULT(HX_D3D_CALL* GetContainingOutput)(void* self, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* GetFrameStatistics)(void* self, DXGI_FRAME_STATISTICS* stats);
            HRESULT(HX_D3D_CALL* GetLastPresentCount)(void* self, UINT* count);
            HRESULT(HX_D3D_CALL* GetDesc1)(void* self, DXGI_SWAP_CHAIN_DESC1* desc);
            HRESULT(HX_D3D_CALL* GetFullscreenDesc)(void* self, DXGI_SWAP_CHAIN_FULLSCREEN_DESC* desc);
            HRESULT(HX_D3D_CALL* GetHwnd)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* GetCoreWindow)(void* self, const GUID& riid, void** window);
            HRESULT(HX_D3D_CALL* Present1)(void* self, UINT syncInterval, UINT flags, const DXGI_PRESENT_PARAMETERS* parameters);
            BOOL(HX_D3D_CALL* IsTemporaryMonoSupported)(void* self);
            HRESULT(HX_D3D_CALL* GetRestrictToOutput)(void* self, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* SetBackgroundColor)(void* self, const DXGI_RGBA* color);
            HRESULT(HX_D3D_CALL* GetBackgroundColor)(void* self, DXGI_RGBA* color);
            HRESULT(HX_D3D_CALL* SetRotation)(void* self, DXGI_MODE_ROTATION rotation);
            HRESULT(HX_D3D_CALL* GetRotation)(void* self, DXGI_MODE_ROTATION* rotation);
        };

        HRESULT GetDesc1(DXGI_SWAP_CHAIN_DESC1* desc) { return static_cast<const Vtbl*>(vtbl_)->GetDesc1(this, desc); }
        HRESULT GetFullscreenDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* desc) { return static_cast<const Vtbl*>(vtbl_)->GetFullscreenDesc(this, desc); }
        HRESULT GetHwnd(HWND* hwnd) { return static_cast<const Vtbl*>(vtbl_)->GetHwnd(this, hwnd); }
        HRESULT GetCoreWindow(const GUID& riid, void** window) { return static_cast<const Vtbl*>(vtbl_)->GetCoreWindow(this, riid, window); }
        HRESULT Present1(UINT syncInterval, UINT flags, const DXGI_PRESENT_PARAMETERS* parameters) { return static_cast<const Vtbl*>(vtbl_)->Present1(this, syncInterval, flags, parameters); }
        BOOL IsTemporaryMonoSupported() { return static_cast<const Vtbl*>(vtbl_)->IsTemporaryMonoSupported(this); }
        HRESULT GetRestrictToOutput(IDXGIOutput** output) { return static_cast<const Vtbl*>(vtbl_)->GetRestrictToOutput(this, output); }
        HRESULT SetBackgroundColor(const DXGI_RGBA* color) { return static_cast<const Vtbl*>(vtbl_)->SetBackgroundColor(this, color); }
        HRESULT GetBackgroundColor(DXGI_RGBA* color) { return static_cast<const Vtbl*>(vtbl_)->GetBackgroundColor(this, color); }
        HRESULT SetRotation(DXGI_MODE_ROTATION rotation) { return static_cast<const Vtbl*>(vtbl_)->SetRotation(this, rotation); }
        HRESULT GetRotation(DXGI_MODE_ROTATION* rotation) { return static_cast<const Vtbl*>(vtbl_)->GetRotation(this, rotation); }
    };

    struct IDXGISwapChain2 : IDXGISwapChain1
    {
        static constexpr GUID Iid = {0xa8be2ac4, 0x199f, 0x4946, {0xb3, 0x31, 0x79, 0x59, 0x9f, 0xb9, 0x8d, 0xe7}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetDevice)(void* self, const GUID& riid, void** device);
            HRESULT(HX_D3D_CALL* Present)(void* self, UINT syncInterval, UINT flags);
            HRESULT(HX_D3D_CALL* GetBuffer)(void* self, UINT index, const GUID& riid, void** surface);
            HRESULT(HX_D3D_CALL* SetFullscreenState)(void* self, BOOL fullscreen, IDXGIOutput* target);
            HRESULT(HX_D3D_CALL* GetFullscreenState)(void* self, BOOL* fullscreen, IDXGIOutput** target);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_SWAP_CHAIN_DESC* desc);
            HRESULT(HX_D3D_CALL* ResizeBuffers)(void* self, UINT count, UINT width, UINT height, DXGI_FORMAT format, UINT flags);
            HRESULT(HX_D3D_CALL* ResizeTarget)(void* self, const DXGI_MODE_DESC* target);
            HRESULT(HX_D3D_CALL* GetContainingOutput)(void* self, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* GetFrameStatistics)(void* self, DXGI_FRAME_STATISTICS* stats);
            HRESULT(HX_D3D_CALL* GetLastPresentCount)(void* self, UINT* count);
            HRESULT(HX_D3D_CALL* GetDesc1)(void* self, DXGI_SWAP_CHAIN_DESC1* desc);
            HRESULT(HX_D3D_CALL* GetFullscreenDesc)(void* self, DXGI_SWAP_CHAIN_FULLSCREEN_DESC* desc);
            HRESULT(HX_D3D_CALL* GetHwnd)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* GetCoreWindow)(void* self, const GUID& riid, void** window);
            HRESULT(HX_D3D_CALL* Present1)(void* self, UINT syncInterval, UINT flags, const DXGI_PRESENT_PARAMETERS* parameters);
            BOOL(HX_D3D_CALL* IsTemporaryMonoSupported)(void* self);
            HRESULT(HX_D3D_CALL* GetRestrictToOutput)(void* self, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* SetBackgroundColor)(void* self, const DXGI_RGBA* color);
            HRESULT(HX_D3D_CALL* GetBackgroundColor)(void* self, DXGI_RGBA* color);
            HRESULT(HX_D3D_CALL* SetRotation)(void* self, DXGI_MODE_ROTATION rotation);
            HRESULT(HX_D3D_CALL* GetRotation)(void* self, DXGI_MODE_ROTATION* rotation);
            HRESULT(HX_D3D_CALL* SetSourceSize)(void* self, UINT width, UINT height);
            HRESULT(HX_D3D_CALL* GetSourceSize)(void* self, UINT* width, UINT* height);
            HRESULT(HX_D3D_CALL* SetMaximumFrameLatency)(void* self, UINT maxLatency);
            HRESULT(HX_D3D_CALL* GetMaximumFrameLatency)(void* self, UINT* maxLatency);
            HANDLE(HX_D3D_CALL* GetFrameLatencyWaitableObject)(void* self);
            HRESULT(HX_D3D_CALL* SetMatrixTransform)(void* self, const DXGI_MATRIX_3X2_F* matrix);
            HRESULT(HX_D3D_CALL* GetMatrixTransform)(void* self, DXGI_MATRIX_3X2_F* matrix);
        };

        HRESULT SetSourceSize(UINT width, UINT height) { return static_cast<const Vtbl*>(vtbl_)->SetSourceSize(this, width, height); }
        HRESULT GetSourceSize(UINT* width, UINT* height) { return static_cast<const Vtbl*>(vtbl_)->GetSourceSize(this, width, height); }
        HRESULT SetMaximumFrameLatency(UINT maxLatency) { return static_cast<const Vtbl*>(vtbl_)->SetMaximumFrameLatency(this, maxLatency); }
        HRESULT GetMaximumFrameLatency(UINT* maxLatency) { return static_cast<const Vtbl*>(vtbl_)->GetMaximumFrameLatency(this, maxLatency); }
        HANDLE GetFrameLatencyWaitableObject() { return static_cast<const Vtbl*>(vtbl_)->GetFrameLatencyWaitableObject(this); }
        HRESULT SetMatrixTransform(const DXGI_MATRIX_3X2_F* matrix) { return static_cast<const Vtbl*>(vtbl_)->SetMatrixTransform(this, matrix); }
        HRESULT GetMatrixTransform(DXGI_MATRIX_3X2_F* matrix) { return static_cast<const Vtbl*>(vtbl_)->GetMatrixTransform(this, matrix); }
    };

    struct IDXGISwapChain3 : IDXGISwapChain2
    {
        static constexpr GUID Iid = {0x94d99bdb, 0xf1f8, 0x4ab0, {0xb2, 0x36, 0x7d, 0xa0, 0x17, 0x0e, 0xda, 0xb1}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* GetDevice)(void* self, const GUID& riid, void** device);
            HRESULT(HX_D3D_CALL* Present)(void* self, UINT syncInterval, UINT flags);
            HRESULT(HX_D3D_CALL* GetBuffer)(void* self, UINT index, const GUID& riid, void** surface);
            HRESULT(HX_D3D_CALL* SetFullscreenState)(void* self, BOOL fullscreen, IDXGIOutput* target);
            HRESULT(HX_D3D_CALL* GetFullscreenState)(void* self, BOOL* fullscreen, IDXGIOutput** target);
            HRESULT(HX_D3D_CALL* GetDesc)(void* self, DXGI_SWAP_CHAIN_DESC* desc);
            HRESULT(HX_D3D_CALL* ResizeBuffers)(void* self, UINT count, UINT width, UINT height, DXGI_FORMAT format, UINT flags);
            HRESULT(HX_D3D_CALL* ResizeTarget)(void* self, const DXGI_MODE_DESC* target);
            HRESULT(HX_D3D_CALL* GetContainingOutput)(void* self, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* GetFrameStatistics)(void* self, DXGI_FRAME_STATISTICS* stats);
            HRESULT(HX_D3D_CALL* GetLastPresentCount)(void* self, UINT* count);
            HRESULT(HX_D3D_CALL* GetDesc1)(void* self, DXGI_SWAP_CHAIN_DESC1* desc);
            HRESULT(HX_D3D_CALL* GetFullscreenDesc)(void* self, DXGI_SWAP_CHAIN_FULLSCREEN_DESC* desc);
            HRESULT(HX_D3D_CALL* GetHwnd)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* GetCoreWindow)(void* self, const GUID& riid, void** window);
            HRESULT(HX_D3D_CALL* Present1)(void* self, UINT syncInterval, UINT flags, const DXGI_PRESENT_PARAMETERS* parameters);
            BOOL(HX_D3D_CALL* IsTemporaryMonoSupported)(void* self);
            HRESULT(HX_D3D_CALL* GetRestrictToOutput)(void* self, IDXGIOutput** output);
            HRESULT(HX_D3D_CALL* SetBackgroundColor)(void* self, const DXGI_RGBA* color);
            HRESULT(HX_D3D_CALL* GetBackgroundColor)(void* self, DXGI_RGBA* color);
            HRESULT(HX_D3D_CALL* SetRotation)(void* self, DXGI_MODE_ROTATION rotation);
            HRESULT(HX_D3D_CALL* GetRotation)(void* self, DXGI_MODE_ROTATION* rotation);
            HRESULT(HX_D3D_CALL* SetSourceSize)(void* self, UINT width, UINT height);
            HRESULT(HX_D3D_CALL* GetSourceSize)(void* self, UINT* width, UINT* height);
            HRESULT(HX_D3D_CALL* SetMaximumFrameLatency)(void* self, UINT maxLatency);
            HRESULT(HX_D3D_CALL* GetMaximumFrameLatency)(void* self, UINT* maxLatency);
            HANDLE(HX_D3D_CALL* GetFrameLatencyWaitableObject)(void* self);
            HRESULT(HX_D3D_CALL* SetMatrixTransform)(void* self, const DXGI_MATRIX_3X2_F* matrix);
            HRESULT(HX_D3D_CALL* GetMatrixTransform)(void* self, DXGI_MATRIX_3X2_F* matrix);
            UINT(HX_D3D_CALL* GetCurrentBackBufferIndex)(void* self);
            HRESULT(HX_D3D_CALL* CheckColorSpaceSupport)(void* self, DXGI_COLOR_SPACE_TYPE colorSpace, UINT* support);
            HRESULT(HX_D3D_CALL* SetColorSpace1)(void* self, DXGI_COLOR_SPACE_TYPE colorSpace);
            HRESULT(HX_D3D_CALL* ResizeBuffers1)(void* self, UINT count, UINT width, UINT height, DXGI_FORMAT format, UINT flags, const UINT* nodeMasks, IUnknown* const* queues);
        };

        UINT GetCurrentBackBufferIndex() { return static_cast<const Vtbl*>(vtbl_)->GetCurrentBackBufferIndex(this); }
        HRESULT CheckColorSpaceSupport(DXGI_COLOR_SPACE_TYPE colorSpace, UINT* support) { return static_cast<const Vtbl*>(vtbl_)->CheckColorSpaceSupport(this, colorSpace, support); }
        HRESULT SetColorSpace1(DXGI_COLOR_SPACE_TYPE colorSpace) { return static_cast<const Vtbl*>(vtbl_)->SetColorSpace1(this, colorSpace); }
        HRESULT ResizeBuffers1(UINT count, UINT width, UINT height, DXGI_FORMAT format, UINT flags, const UINT* nodeMasks, IUnknown* const* queues) { return static_cast<const Vtbl*>(vtbl_)->ResizeBuffers1(this, count, width, height, format, flags, nodeMasks, queues); }
    };

    struct IDXGIFactory : IDXGIObject
    {
        static constexpr GUID Iid = {0x7b7166ec, 0x21c7, 0x44ae, {0xb2, 0x1a, 0xc9, 0xae, 0x32, 0x1a, 0xe3, 0x69}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumAdapters)(void* self, UINT index, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* MakeWindowAssociation)(void* self, HWND hwnd, UINT flags);
            HRESULT(HX_D3D_CALL* GetWindowAssociation)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* CreateSwapChain)(void* self, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swapChain);
            HRESULT(HX_D3D_CALL* CreateSoftwareAdapter)(void* self, HMODULE module, IDXGIAdapter** adapter);
        };

        HRESULT EnumAdapters(UINT index, IDXGIAdapter** adapter) { return static_cast<const Vtbl*>(vtbl_)->EnumAdapters(this, index, adapter); }
        HRESULT MakeWindowAssociation(HWND hwnd, UINT flags) { return static_cast<const Vtbl*>(vtbl_)->MakeWindowAssociation(this, hwnd, flags); }
        HRESULT GetWindowAssociation(HWND* hwnd) { return static_cast<const Vtbl*>(vtbl_)->GetWindowAssociation(this, hwnd); }
        HRESULT CreateSwapChain(IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swapChain) { return static_cast<const Vtbl*>(vtbl_)->CreateSwapChain(this, device, desc, swapChain); }
        HRESULT CreateSoftwareAdapter(HMODULE module, IDXGIAdapter** adapter) { return static_cast<const Vtbl*>(vtbl_)->CreateSoftwareAdapter(this, module, adapter); }
    };

    struct IDXGIFactory1 : IDXGIFactory
    {
        static constexpr GUID Iid = {0x770aae78, 0xf26f, 0x4dba, {0xa8, 0x29, 0x25, 0x3c, 0x83, 0xd1, 0xb3, 0x87}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumAdapters)(void* self, UINT index, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* MakeWindowAssociation)(void* self, HWND hwnd, UINT flags);
            HRESULT(HX_D3D_CALL* GetWindowAssociation)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* CreateSwapChain)(void* self, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swapChain);
            HRESULT(HX_D3D_CALL* CreateSoftwareAdapter)(void* self, HMODULE module, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* EnumAdapters1)(void* self, UINT index, IDXGIAdapter1** adapter);
            BOOL(HX_D3D_CALL* IsCurrent)(void* self);
        };

        HRESULT EnumAdapters1(UINT index, IDXGIAdapter1** adapter) { return static_cast<const Vtbl*>(vtbl_)->EnumAdapters1(this, index, adapter); }
        BOOL IsCurrent() { return static_cast<const Vtbl*>(vtbl_)->IsCurrent(this); }
    };

    struct IDXGIFactory2 : IDXGIFactory1
    {
        static constexpr GUID Iid = {0x50c83a1c, 0xe072, 0x4c48, {0x87, 0xb0, 0x36, 0x30, 0xfa, 0x36, 0xa6, 0xd0}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumAdapters)(void* self, UINT index, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* MakeWindowAssociation)(void* self, HWND hwnd, UINT flags);
            HRESULT(HX_D3D_CALL* GetWindowAssociation)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* CreateSwapChain)(void* self, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swapChain);
            HRESULT(HX_D3D_CALL* CreateSoftwareAdapter)(void* self, HMODULE module, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* EnumAdapters1)(void* self, UINT index, IDXGIAdapter1** adapter);
            BOOL(HX_D3D_CALL* IsCurrent)(void* self);
            BOOL(HX_D3D_CALL* IsWindowedStereoEnabled)(void* self);
            HRESULT(HX_D3D_CALL* CreateSwapChainForHwnd)(void* self, IUnknown* device, HWND hwnd, const DXGI_SWAP_CHAIN_DESC1* desc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreenDesc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* CreateSwapChainForCoreWindow)(void* self, IUnknown* device, IUnknown* window, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* GetSharedResourceAdapterLuid)(void* self, HANDLE resource, LUID* luid);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterStereoStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterOcclusionStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* CreateSwapChainForComposition)(void* self, IUnknown* device, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
        };

        BOOL IsWindowedStereoEnabled() { return static_cast<const Vtbl*>(vtbl_)->IsWindowedStereoEnabled(this); }
        HRESULT CreateSwapChainForHwnd(IUnknown* device, HWND hwnd, const DXGI_SWAP_CHAIN_DESC1* desc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreenDesc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain) { return static_cast<const Vtbl*>(vtbl_)->CreateSwapChainForHwnd(this, device, hwnd, desc, fullscreenDesc, restrictToOutput, swapChain); }
        HRESULT CreateSwapChainForCoreWindow(IUnknown* device, IUnknown* window, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain) { return static_cast<const Vtbl*>(vtbl_)->CreateSwapChainForCoreWindow(this, device, window, desc, restrictToOutput, swapChain); }
        HRESULT GetSharedResourceAdapterLuid(HANDLE resource, LUID* luid) { return static_cast<const Vtbl*>(vtbl_)->GetSharedResourceAdapterLuid(this, resource, luid); }
        HRESULT RegisterStereoStatusWindow(HWND hwnd, UINT message, DWORD* cookie) { return static_cast<const Vtbl*>(vtbl_)->RegisterStereoStatusWindow(this, hwnd, message, cookie); }
        HRESULT RegisterStereoStatusEvent(HANDLE event, DWORD* cookie) { return static_cast<const Vtbl*>(vtbl_)->RegisterStereoStatusEvent(this, event, cookie); }
        void UnregisterStereoStatus(DWORD cookie) { static_cast<const Vtbl*>(vtbl_)->UnregisterStereoStatus(this, cookie); }
        HRESULT RegisterOcclusionStatusWindow(HWND hwnd, UINT message, DWORD* cookie) { return static_cast<const Vtbl*>(vtbl_)->RegisterOcclusionStatusWindow(this, hwnd, message, cookie); }
        HRESULT RegisterOcclusionStatusEvent(HANDLE event, DWORD* cookie) { return static_cast<const Vtbl*>(vtbl_)->RegisterOcclusionStatusEvent(this, event, cookie); }
        void UnregisterOcclusionStatus(DWORD cookie) { static_cast<const Vtbl*>(vtbl_)->UnregisterOcclusionStatus(this, cookie); }
        HRESULT CreateSwapChainForComposition(IUnknown* device, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain) { return static_cast<const Vtbl*>(vtbl_)->CreateSwapChainForComposition(this, device, desc, restrictToOutput, swapChain); }
    };

    struct IDXGIFactory3 : IDXGIFactory2
    {
        static constexpr GUID Iid = {0x25483823, 0xcd46, 0x4c7d, {0x86, 0xca, 0x47, 0xaa, 0x95, 0xb8, 0x37, 0xbd}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumAdapters)(void* self, UINT index, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* MakeWindowAssociation)(void* self, HWND hwnd, UINT flags);
            HRESULT(HX_D3D_CALL* GetWindowAssociation)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* CreateSwapChain)(void* self, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swapChain);
            HRESULT(HX_D3D_CALL* CreateSoftwareAdapter)(void* self, HMODULE module, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* EnumAdapters1)(void* self, UINT index, IDXGIAdapter1** adapter);
            BOOL(HX_D3D_CALL* IsCurrent)(void* self);
            BOOL(HX_D3D_CALL* IsWindowedStereoEnabled)(void* self);
            HRESULT(HX_D3D_CALL* CreateSwapChainForHwnd)(void* self, IUnknown* device, HWND hwnd, const DXGI_SWAP_CHAIN_DESC1* desc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreenDesc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* CreateSwapChainForCoreWindow)(void* self, IUnknown* device, IUnknown* window, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* GetSharedResourceAdapterLuid)(void* self, HANDLE resource, LUID* luid);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterStereoStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterOcclusionStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* CreateSwapChainForComposition)(void* self, IUnknown* device, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            UINT(HX_D3D_CALL* GetCreationFlags)(void* self);
        };

        UINT GetCreationFlags() { return static_cast<const Vtbl*>(vtbl_)->GetCreationFlags(this); }
    };

    struct IDXGIFactory4 : IDXGIFactory3
    {
        static constexpr GUID Iid = {0x1bc6ea02, 0xef36, 0x464f, {0xbf, 0x0c, 0x21, 0xca, 0x39, 0xe5, 0x16, 0x8a}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumAdapters)(void* self, UINT index, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* MakeWindowAssociation)(void* self, HWND hwnd, UINT flags);
            HRESULT(HX_D3D_CALL* GetWindowAssociation)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* CreateSwapChain)(void* self, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swapChain);
            HRESULT(HX_D3D_CALL* CreateSoftwareAdapter)(void* self, HMODULE module, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* EnumAdapters1)(void* self, UINT index, IDXGIAdapter1** adapter);
            BOOL(HX_D3D_CALL* IsCurrent)(void* self);
            BOOL(HX_D3D_CALL* IsWindowedStereoEnabled)(void* self);
            HRESULT(HX_D3D_CALL* CreateSwapChainForHwnd)(void* self, IUnknown* device, HWND hwnd, const DXGI_SWAP_CHAIN_DESC1* desc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreenDesc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* CreateSwapChainForCoreWindow)(void* self, IUnknown* device, IUnknown* window, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* GetSharedResourceAdapterLuid)(void* self, HANDLE resource, LUID* luid);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterStereoStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterOcclusionStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* CreateSwapChainForComposition)(void* self, IUnknown* device, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            UINT(HX_D3D_CALL* GetCreationFlags)(void* self);
            HRESULT(HX_D3D_CALL* EnumAdapterByLuid)(void* self, LUID luid, const GUID& riid, void** adapter);
            HRESULT(HX_D3D_CALL* EnumWarpAdapter)(void* self, const GUID& riid, void** adapter);
        };

        HRESULT EnumAdapterByLuid(LUID luid, const GUID& riid, void** adapter) { return static_cast<const Vtbl*>(vtbl_)->EnumAdapterByLuid(this, luid, riid, adapter); }
        HRESULT EnumWarpAdapter(const GUID& riid, void** adapter) { return static_cast<const Vtbl*>(vtbl_)->EnumWarpAdapter(this, riid, adapter); }
    };

    struct IDXGIFactory5 : IDXGIFactory4
    {
        static constexpr GUID Iid = {0x7632e1f5, 0xee65, 0x4dca, {0x87, 0xfd, 0x84, 0xcd, 0x75, 0xf8, 0x83, 0x8d}};

        struct Vtbl
        {
            HRESULT(HX_D3D_CALL* QueryInterface)(void* self, const GUID& riid, void** object);
            ULONG(HX_D3D_CALL* AddRef)(void* self);
            ULONG(HX_D3D_CALL* Release)(void* self);
            HRESULT(HX_D3D_CALL* SetPrivateData)(void* self, const GUID& name, UINT dataSize, const void* data);
            HRESULT(HX_D3D_CALL* SetPrivateDataInterface)(void* self, const GUID& name, const IUnknown* unknown);
            HRESULT(HX_D3D_CALL* GetPrivateData)(void* self, const GUID& name, UINT* dataSize, void* data);
            HRESULT(HX_D3D_CALL* GetParent)(void* self, const GUID& riid, void** parent);
            HRESULT(HX_D3D_CALL* EnumAdapters)(void* self, UINT index, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* MakeWindowAssociation)(void* self, HWND hwnd, UINT flags);
            HRESULT(HX_D3D_CALL* GetWindowAssociation)(void* self, HWND* hwnd);
            HRESULT(HX_D3D_CALL* CreateSwapChain)(void* self, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swapChain);
            HRESULT(HX_D3D_CALL* CreateSoftwareAdapter)(void* self, HMODULE module, IDXGIAdapter** adapter);
            HRESULT(HX_D3D_CALL* EnumAdapters1)(void* self, UINT index, IDXGIAdapter1** adapter);
            BOOL(HX_D3D_CALL* IsCurrent)(void* self);
            BOOL(HX_D3D_CALL* IsWindowedStereoEnabled)(void* self);
            HRESULT(HX_D3D_CALL* CreateSwapChainForHwnd)(void* self, IUnknown* device, HWND hwnd, const DXGI_SWAP_CHAIN_DESC1* desc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreenDesc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* CreateSwapChainForCoreWindow)(void* self, IUnknown* device, IUnknown* window, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            HRESULT(HX_D3D_CALL* GetSharedResourceAdapterLuid)(void* self, HANDLE resource, LUID* luid);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterStereoStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterStereoStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusWindow)(void* self, HWND hwnd, UINT message, DWORD* cookie);
            HRESULT(HX_D3D_CALL* RegisterOcclusionStatusEvent)(void* self, HANDLE event, DWORD* cookie);
            void(HX_D3D_CALL* UnregisterOcclusionStatus)(void* self, DWORD cookie);
            HRESULT(HX_D3D_CALL* CreateSwapChainForComposition)(void* self, IUnknown* device, const DXGI_SWAP_CHAIN_DESC1* desc, IDXGIOutput* restrictToOutput, IDXGISwapChain1** swapChain);
            UINT(HX_D3D_CALL* GetCreationFlags)(void* self);
            HRESULT(HX_D3D_CALL* EnumAdapterByLuid)(void* self, LUID luid, const GUID& riid, void** adapter);
            HRESULT(HX_D3D_CALL* EnumWarpAdapter)(void* self, const GUID& riid, void** adapter);
            HRESULT(HX_D3D_CALL* CheckFeatureSupport)(void* self, DXGI_FEATURE feature, void* data, UINT dataSize);
        };

        HRESULT CheckFeatureSupport(DXGI_FEATURE feature, void* data, UINT dataSize) { return static_cast<const Vtbl*>(vtbl_)->CheckFeatureSupport(this, feature, data, dataSize); }
    };

    using PFN_D3D11_CREATE_DEVICE = HRESULT(HX_D3D_CALL*)(IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, const D3D_FEATURE_LEVEL*, UINT, UINT,
                                                        ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**);
    using PFN_CREATE_DXGI_FACTORY2 = HRESULT(HX_D3D_CALL*)(UINT, const GUID&, void**);

    bool LoadLibraries();
    void UnloadLibraries();
    HRESULT D3D11CreateDevice(IDXGIAdapter* adapter, D3D_DRIVER_TYPE driverType, HMODULE software, UINT flags,
                              const D3D_FEATURE_LEVEL* levels, UINT levelCount, UINT sdkVersion, ID3D11Device** device,
                              D3D_FEATURE_LEVEL* chosenLevel, ID3D11DeviceContext** context);
    HRESULT CreateDXGIFactory2(UINT flags, const GUID& riid, void** factory);

    template <typename T>
    void SafeRelease(T*& object)
    {
        if (object)
            object->Release();
        object = nullptr;
    }
}
