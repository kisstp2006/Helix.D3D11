# Helix.D3D11

Direct3D 11.1 and DXGI 1.5 bindings for C++ without the Windows SDK headers, released under CC0.

## Contents

| Path | Content |
|---|---|
| `include/helix/d3d11/d3d11.h` | Base Windows types, `GUID`, enums, structs, constants and 56 COM interfaces (D3D11 device, contexts, resources, views, shaders, states, queries, 11.1 extensions, user annotations, DXGI objects, adapters, devices, swap chains 0 to 3, factories 0 to 5) |
| `src/platform/windows/loader.cpp` | Runtime loading of `d3d11.dll` and `dxgi.dll` |
| `tools/interfaces.py`, `tools/d3d_types.py` | Interface, enum and struct descriptions |
| `tools/generate.py` | Generates the header and the layout tests |
| `tests/` | Layout tests against the Windows SDK and a device test |

Everything lives in `helix::d3d11` and keeps the documented names, so the API reads like the
official one:

```cpp
#include <helix/d3d11/d3d11.h>
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
python tools/generate.py
```

## Build

```
git clone --recursive https://github.com/kisstp2006/Helix.D3D11
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug
```

On other platforms the target is header only and has no tests.

## License

CC0 1.0 Universal, see `LICENSE`.
