"""Generates the Helix.D3D11 header and its layout tests from tools/interfaces.py and tools/types.py.

Usage: python tools/generate.py
"""

import re
from pathlib import Path

from Interfaces import INTERFACES
from D3DTypes import CONSTANTS, ENUMS, STRUCTS

ROOT = Path(__file__).resolve().parent.parent
ENUM_ALIASES = {"D3D_SRV_DIMENSION": "D3D11_SRV_DIMENSION", "D3D_PRIMITIVE_TOPOLOGY": "D3D11_PRIMITIVE_TOPOLOGY"}

PRELUDE = """    using BOOL = int;
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
"""


def parse_method(text):
    m = re.match(r"\s*(.+?)\s+(\w+)\((.*)\)\s*$", text)
    ret, name, params = m.group(1), m.group(2), m.group(3).strip()
    out = []
    if params:
        for p in params.split(","):
            p = p.strip()
            pm = re.match(r"(.+?)(\w+)$", p)
            out.append((pm.group(1).strip(), pm.group(2)))
    return ret, name, out


def flatten(name, by_name):
    chain = []
    while name:
        chain.append(name)
        name = by_name[name][1]
    methods = []
    for n in reversed(chain):
        methods.extend(parse_method(t) for t in by_name[n][3])
    return methods


def guid_literal(text):
    p = text.split("-")
    d4 = p[3] + p[4]
    bytes_ = ", ".join(f"0x{d4[i:i + 2]}" for i in range(0, 16, 2))
    return f"{{0x{p[0]}, 0x{p[1]}, 0x{p[2]}, {{{bytes_}}}}}"


def field_lines(fields, indent):
    out = []
    for t, n in fields:
        if t == "union":
            out.append(indent + "union")
            out.append(indent + "{")
            out.extend(field_lines(n, indent + "    "))
            out.append(indent + "};")
        else:
            out.append(f"{indent}{t} {n};")
    return out


def plain_fields(fields):
    for t, n in fields:
        if t == "union":
            yield from plain_fields(n)
        else:
            yield n.split("[")[0]


def main():
    by_name = {i[0]: i for i in INTERFACES}
    h = ["#pragma once", "", "#include <cstddef>", "", "#ifndef HX_D3D_CALL", "#define HX_D3D_CALL __stdcall", "#endif", "",
         "namespace helix::d3d11", "{", PRELUDE]
    for name, members in ENUMS:
        h.append(f"    enum {name} : int")
        h.append("    {")
        for m, v in members:
            h.append(f"        {m} = {v},")
        h.append("    };")
        if name in ENUM_ALIASES:
            h.append(f"    using {ENUM_ALIASES[name]} = {name};")
        h.append("")
    for t, n, v in CONSTANTS:
        h.append(f"    inline constexpr {t} {n} = {v};")
    h.append("")
    for name, fields in STRUCTS:
        h.append(f"    struct {name}")
        h.append("    {")
        h.extend(field_lines(fields, "        "))
        h.append("    };")
        h.append("")
    for name, _, _, _ in INTERFACES:
        h.append(f"    struct {name};")
    h.append("")
    for name, base, iid, _ in INTERFACES:
        methods = flatten(name, by_name)
        own = [parse_method(t) for t in by_name[name][3]]
        h.append(f"    struct {name}" + (f" : {base}" if base else ""))
        h.append("    {")
        h.append(f"        static constexpr GUID Iid = {guid_literal(iid)};")
        h.append("")
        h.append("        struct Vtbl")
        h.append("        {")
        for ret, mname, params in methods:
            ps = ", ".join(["void* self"] + [f"{t} {p}" for t, p in params])
            h.append(f"            {ret}(HX_D3D_CALL* {mname})({ps});")
        h.append("        };")
        h.append("")
        for ret, mname, params in own:
            ps = ", ".join(f"{t} {p}" for t, p in params)
            args = ", ".join(["this"] + [p for _, p in params])
            r = "" if ret == "void" else "return "
            h.append(f"        {ret} {mname}({ps}) {{ {r}static_cast<const Vtbl*>(vtbl_)->{mname}({args}); }}")
        if not base:
            h.append("")
            h.append("        template <typename T>")
            h.append("        HRESULT QueryInterface(T** object) { return QueryInterface(T::Iid, reinterpret_cast<void**>(object)); }")
            h.append("")
            h.append("    protected:")
            h.append("        const void* vtbl_;")
        h.append("    };")
        h.append("")
    h.append("    using PFN_D3D11_CREATE_DEVICE = HRESULT(HX_D3D_CALL*)(IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, const D3D_FEATURE_LEVEL*, UINT, UINT,")
    h.append("                                                        ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**);")
    h.append("    using PFN_CREATE_DXGI_FACTORY2 = HRESULT(HX_D3D_CALL*)(UINT, const GUID&, void**);")
    h.append("")
    h.append("    bool LoadLibraries();")
    h.append("    void UnloadLibraries();")
    h.append("    HRESULT D3D11CreateDevice(IDXGIAdapter* adapter, D3D_DRIVER_TYPE driverType, HMODULE software, UINT flags,")
    h.append("                              const D3D_FEATURE_LEVEL* levels, UINT levelCount, UINT sdkVersion, ID3D11Device** device,")
    h.append("                              D3D_FEATURE_LEVEL* chosenLevel, ID3D11DeviceContext** context);")
    h.append("    HRESULT CreateDXGIFactory2(UINT flags, const GUID& riid, void** factory);")
    h.append("")
    h.append("    template <typename T>")
    h.append("    void SafeRelease(T*& object)")
    h.append("    {")
    h.append("        if (object)")
    h.append("            object->Release();")
    h.append("        object = nullptr;")
    h.append("    }")
    h.append("}")
    h.append("")
    (ROOT / "Source" / "Helix" / "D3D11").mkdir(parents=True, exist_ok=True)
    (ROOT / "Source" / "Helix" / "D3D11" / "D3D11.h").write_text("\n".join(h), encoding="ascii", newline="\n")

    t = ["#include <Helix/D3D11/D3D11.h>", "", "#define D3D11_NO_HELPERS", "#define CINTERFACE", "#define COBJMACROS", "#include <d3d11_3.h>", "#include <d3d11sdklayers.h>",
         "#include <dxgi1_5.h>", "", "#include <cstddef>", "", "namespace hx = helix::d3d11;", ""]
    for name, base, iid, _ in INTERFACES:
        if name == "IUnknown":
            continue
        methods = flatten(name, by_name)
        t.append(f"static_assert(sizeof(hx::{name}::Vtbl) == sizeof(::{name}Vtbl));")
        for _, mname, _ in methods:
            t.append(f"static_assert(offsetof(hx::{name}::Vtbl, {mname}) == offsetof(::{name}Vtbl, {mname}));")
    for name, fields in STRUCTS:
        t.append(f"static_assert(sizeof(hx::{name}) == sizeof(::{name}) && alignof(hx::{name}) == alignof(::{name}));")
        for f in plain_fields(fields):
            t.append(f"static_assert(offsetof(hx::{name}, {f}) == offsetof(::{name}, {f}));")
    for name, members in ENUMS:
        for m, _ in members:
            t.append(f"static_assert(int(hx::{m}) == int(::{m}));")
    t.append("")
    t.append("bool HelixD3D11SdkIidsMatch()")
    t.append("{")
    t.append("    bool ok = true;")
    for name, _, _, _ in INTERFACES:
        t.append(f"    ok &= std::memcmp(&hx::{name}::Iid, &IID_{name}, sizeof(GUID)) == 0;")
    t.append("    return ok;")
    t.append("}")
    t.append("")
    t.append("void HelixD3D11SdkConstants(unsigned long long* out)")
    t.append("{")
    for i, (_, n, _) in enumerate(CONSTANTS):
        t.append(f"    out[{i}] = (unsigned long long)({n});")
    t.append("}")
    t.append("")
    o = ["#include <Helix/D3D11/D3D11.h>", "", f"int HelixD3D11ConstantCount() {{ return {len(CONSTANTS)}; }}", "",
         "void HelixD3D11OurConstants(unsigned long long* out, const char** names)", "{"]
    for i, (_, n, _) in enumerate(CONSTANTS):
        o.append(f"    out[{i}] = (unsigned long long)(helix::d3d11::{n});")
        o.append(f'    names[{i}] = "{n}";')
    o.append("}")
    o.append("")
    gen = ROOT / "Tests" / "Generated"
    gen.mkdir(parents=True, exist_ok=True)
    (gen / "SdkLayout.cpp").write_text("\n".join(["#include <cstring>"] + t), encoding="ascii", newline="\n")
    (gen / "OurConstants.cpp").write_text("\n".join(o), encoding="ascii", newline="\n")
    print(f"{len(INTERFACES)} interfaces, {sum(len(flatten(i[0], by_name)) for i in INTERFACES)} vtable slots, "
          f"{len(STRUCTS)} structs, {sum(len(e[1]) for e in ENUMS)} enum values, {len(CONSTANTS)} constants")


if __name__ == "__main__":
    main()
