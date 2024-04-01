/* Implements the cstr_<TYPE>() functions in base.h */
#include <base.h>

/* libc headers */
#include <stdio.h>

/* Type to string conversion functions */
/* Unsigned ints */
/* Convert u8 to string, put in buff */
extern void cstr_u8(char* buff, u64 size, u8 val) {
  snprintf(buff, size, "%u", val);
}
/* Convert u16 to string, put in buff */
extern void cstr_u16(char* buff, u64 size, u16 val) {
  snprintf(buff, size, "%u", val);
}
/* Convert u32 to string, put in buff */
extern void cstr_u32(char* buff, u64 size, u32 val) {
  snprintf(buff, size, "%u", val);
}
/* Convert u64 to string, put in buff */
extern void cstr_u64(char* buff, u64 size, u64 val) {
  snprintf(buff, size, "%llu", val);
}
/* Signed ints */
/* Convert i8 to string, put in buff */
extern void cstr_i8(char* buff, u64 size, i8 val) {
  snprintf(buff, size, "%d", val);
}
/* Convert i16 to string, put in buff */
extern void cstr_i16(char* buff, u64 size, i16 val) {
  snprintf(buff, size, "%d", val);
}
/* Convert i32 to string, put in buff */
extern void cstr_i32(char* buff, u64 size, i32 val) {
  snprintf(buff, size, "%d", val);
}
/* Convert i64 to string, put in buff */
extern void cstr_i64(char* buff, u64 size, i64 val) {
  snprintf(buff, size, "%lld", val);
}
/* Floats */
/* Convert f32 to string, put in buff */
extern void cstr_f32(char* buff, u64 size, f32 val) {
  snprintf(buff, size, "%f", val);
}
/* Convert f64 to string, put in buff */
extern void cstr_f64(char* buff, u64 size, f64 val) {
  snprintf(buff, size, "%lf", val);
}
/* Bools */
/* Convert bool to string, put in buff */
extern char* cstr_bool(bool val) {
  return val ? "true" : "false";
}
