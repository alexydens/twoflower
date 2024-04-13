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
## Define
- `ENABLE_ASSERT` for assertions.
- `ENABLE_LOGGING` for logging.
- `DEBUG` for logging and assertions.
## Projects
### Base
- [x] typedefs for unsigned integers: `u8`, `u16`, `u32`, `u64`.
- [x] typedefs for signed integers: `i8`, `i16`, `i32`, `i64`.
- [x] typedefs for floating point values: `f32`, `f64`.
- [x] typedefs for booleans: `bool` - ifndef.
- [x] utility macros: `MIN(A,B)`, `MAX(A,B)`, `SWAP(A,B)`, `LERP(A,B,V)`.
- [x] assertions: `ASSERT(EXPR)`, `ASSERT_ONFAIL(EXPR, LINE, FILE)`, enabled if
`ENABLE_ASSERT` defined.
- [x] macro consts: `NULL` - ifndef, `C_PI`, `C_E`, `C_KiB`, `C_MiB`, `C_GiB`,
`C_TiB`.
- [x] context cracking: os, compiler, architecture.
### Platform:
#### Memory:
- [ ] allocate memory on the heap: `void* heap_alloc(u64 size)`.
- [ ] re-size memory on the heap: `void* heap_realloc(void* ptr, u64 size)`.
- [ ] free memory on the heap: `void heap_free(void* ptr)`.
- [ ] copy buffer: `void buff_copy(void* src, void* dest, u64 size)`.
- [ ] set buffer to u8: `void buff_set(void* buff, u64 size, u8 val)`.
#### Console I/O:
- [ ] put text to console: `void puts_console(char* str)`.
- [ ] put buffer to console: `void putn_console(char* buff, u64 size)`.
- [ ] read buffer from console: `void getn_console(char* buff, u64 size)`.
#### File I/O:
- [ ] put text to file: `void puts_file(char* str, char* path)`.
- [ ] put buffer to file: `void putn_file(char* buff, u64 size, char* path)`.
- [ ] read buffer from file: `void getn_file(char* buff, u64 size, char* path)`.
#### Misc:
- [ ] get time: `time_t get_time(void)`.
- [ ] get date: `date_t get_date(void)`.
#### To Strings:
- [ ] tostrings: `cstr_<TYPE>(<TYPE> val)`.
- [ ] tostrings: `cstr_<TYPE>(char* buff, u64 size, <TYPE> val)`.
### Other Types:
- [x] time struct: `time_t`.
- [x] date struct: `date_t`.
- [x] weekday enum: `weekday_t`, tostring.
- [x] month enum: `month_t`, tostring.
- [x] ip address enum: `ip_addr_type_t`, tostring (ipv4, ipv6).
- [ ] error type enum: `error_t`, tostring (or use errno and strerror?).
### Logging:
- [ ] perhaps ought to be in base (to ensure propper assertion behavior in all
files).
- [ ] enabled if `ENABLE_LOGGING` defined.
- [ ] log functions: `log_<success, info, warn, error, fatal>()`.
- [ ] redefine `ASSERT_ONFAIL` to use log, including filepath, time and error
in string form.
### Arena Allocator:
- [ ] arena allocator struct: `arena_alloc_t`.
- [ ] create, free and allocate on an arena.
### Chunk Allocator:
- [ ] chunk allocator struct: `chunk_alloc_t`.
- [ ] create, free and allocate on the chunk allocator.
### String Slices
- [ ] string slice struct: `str_t`.
- [ ] string from literal.
- [ ] string from stdin.
- [ ] string from file.
- [ ] string from part of file.
- [ ] string from other string (copy).
- [ ] string from two others strings (concatenate).
- [ ] write string to file.
- [ ] append string to file.
- [ ] print string to stdout.
- [ ] compare two strings.
- [ ] c string from string.
### 3d Math Library
- [ ] float vector structs: `vec2_t`, `vec3_t`, `vec4_t`.
- [ ] integer vector structs: `vec2i_t`, `vec3i_t`, `vec4i_t`.
- [ ] 4x4 matrix struct (interop opengl): `mat4`.
- [ ] add, subtract, dot product, cross product and lerp vectors.
- [ ] normalize and scale vectors.
- [ ] matrix multiply with other matrix and vector.
- [ ] rotation, translation, scale, projection and identity matrices.
### Networking
- [ ] http client and server structs.
- [ ] handle real-time data for something like a video game.
- [ ] support both ipv4 and ipv6.
### Windowing
- [ ] supporting Wayland, x11, Win32 API.
- [ ] supporting OpenGL, Vulkan and DirectX.
- [ ] capture keyboard and mouse input, draw to screen.
- [ ] callbacks for close and resize.
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
### C Compiler
- Eventually, this may be able to compiler itself.
