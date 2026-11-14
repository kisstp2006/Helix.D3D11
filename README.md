# Helix.D3D11

Direct3D 11.1 to 11.3 and DXGI 1.5 bindings for C++ without the Windows SDK headers, released under CC0.

## Contents

| Path | Content |
|---|---|
| `Source/Helix/D3D11/D3D11.h` | Base Windows types, `GUID`, enums, structs, constants and 58 COM interfaces (D3D11 device, contexts, resources, views, shaders, states, queries, 11.1 extensions, the 11.2 and 11.3 devices (conservative rasterization), user annotations, DXGI objects, adapters, devices, swap chains 0 to 3, factories 0 to 5) |
| `Source/Helix/D3D11/Platform/Win/LoaderWin.cpp` | Runtime loading of `d3d11.dll` and `dxgi.dll` |
| `Tools/Interfaces.py`, `Tools/D3DTypes.py` | Interface, enum and struct descriptions |
| `Tools/GenerateBindings.py` | Generates the header and the layout tests |
| `Tests/` | Layout tests against the Windows SDK and a device test |

Everything lives in `helix::d3d11` and keeps the documented names, so the API reads like the
official one:

```cpp
#include <Helix/D3D11/D3D11.h>
using namespace helix::d3d11;

ID3D11Device* device = nullptr;
ID3D11DeviceContext* context = nullptr;
D3D_FEATURE_LEVEL level;
D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &device, &level, &context);

ID3D11DeviceContext1* context1 = nullptr;
context->QueryInterface(&context1);
```

Every interface is a struct holding the vtable pointer, with inline methods that call through a
`Vtbl` struct; `Iid` is the interface id.

## Verification

The tests compile a translation unit that also includes the Windows SDK headers in C interface
mode and checks with `static_assert` that every vtable slot (by name), every struct size,
alignment and field offset, and every enum value match. Interface ids and constants are compared
at runtime. The SDK is only used by the tests.

## Regenerating

```
python Tools/GenerateBindings.py
```

## Build

```
git clone https://github.com/kisstp2006/Helix.D3D11
git -C Helix.D3D11 submodule update --init
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug
```

On other platforms the target is header only and has no tests.

## License

CC0 1.0 Universal, see `LICENSE`.
