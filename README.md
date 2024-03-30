# Twoflower (utils)
A library that contains some projects written in C, which should all be able to
work together alright. Conforms to standard C99.
## Platforms
- Linux (tested for each new feature).
- Windows (tested less frequently).
## Dependencies
- GNU make & a C compiler that supports C99.
- For OpenGL, OpenGL (maybe I will add a way to install easily for different
platforms).
- For DirectX, the DirectX12 SDK.
- For Wayland, a display manager that supports wayland and the libwayland
packages.
- For X11, the libx11 packages.
- YK what, I'll include a guide for installing various projects. I'll try to
make it so that if you aren't using a platform/technology's project, you don't
need it installed.
## Projects
### Base
- typedefs for unsigned integers: `u8`, `u16`, `u32`, `u64`.
- typedefs for signed integers: `i8`, `i16`, `i32`, `i64`.
- typedefs for floating point values: `f32`, `f64`.
- typedefs for booleans: `bool` - ifndef.
- typedef for sizes: `size_t` - ifndef.
- utility macros: `MIN(A,B)`, `MAX(A,B)`, `SWAP(A,B)`, `LERP(A,B)`.
- assertions: `ASSERT(EXPR)`, `ASSERT_ONFAIL()`.
- to string for each type: `<TYPE>_tostr(size_t maxsize)`.
- macro consts: `NULL` - ifndef, `C_PI`, `C_E`, `C_KiB`, `C_MiB`, `C_GiB`,
`C_TiB`.
### Other Types:
- weekday enum: `weekday_t`, tostring.
- month enum: `month_t`, tostring.
- ip address enum: `ip_addr_t`, tostring (ipv4, ipv6).
- error type enum: `error_t`, tostring (or use errno and strerror?).
### Logging:
- log functions: `log_<success, info, warn, error, fatal>()`.
- redefine assert_onfail to use log, including filepath, time and stringified
error.
### Arena Allocator:
- arena allocator struct: `arena_alloc_t`.
- create, free and allocate on an arena.
### Chunk Allocator:
- chunk allocator struct: `chunk_alloc_t`.
- create, free and allocate on the chunk allocator.
### String Slices
- string slice struct: `str_t`.
- string from literal.
- string from stdin.
- string from file.
- string from part of file.
- string from other string (copy).
- string from two others strings (concatenate).
- string from variable (wrapper for `<TYPE>_tostr(size_t maxsize)`).
- write string to file.
- append string to file.
- print string to stdout.
- compare two strings.
### 3d Math Library
- float vector structs: `vec2_t`, `vec3_t`, `vec4_t`.
- integer vector structs: `vec2i_t`, `vec3i_t`, `vec4i_t`.
- 4x4 matrix struct (interop opengl): `mat4`.
- add, subtract, dot product, cross product and lerp vectors.
- normalize and scale vectors.
- matrix multiply with other matrix and vector.
- rotation, translation, scale, projection and identity matrices.
### Networking
- http client and server structs.
- handle real-time data for something like a video game.
- support both ipv4 and ipv6.
### Windowing
- supporting Wayland, x11, Win32 API.
- supporting OpenGL, Vulkan and DirectX.
- capture keyboard and mouse input, draw to screen.
- callbacks for close and resize.
### OpenGL
- v4.6 if possible, else v3.3. If 3.3 not present, fail.
### Vulkan
- Most likely won't happen.
### DirectX
- Most likely won't happen.
### Rasterizer
- This could get quite far, I've made something similar before, just less
organized.
### RISC-V Emulator
- Emulate a risc-v CPU: rv32i.
### 6502 Emulator
- Emulate a 6502 CPU.