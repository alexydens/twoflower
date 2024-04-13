/* Implements platform.h */
#include <platform.h>

/* libc headers */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

/* MEMORY */
/* Allocate size bytes on the heap */
void* heap_alloc(u64 size) {
  return malloc(size);
}
/* Re-size pointer ptr to own size bytes on the heap */
void* heap_realloc(void* ptr, u64 size) {
  return realloc(ptr, size);
}
/* Free memory on the heap */
void heap_free(void* ptr) {
  free(ptr);
}
/* Copy memory on the heap */
void buff_copy(void* src, void* dest, u64 size) {
  memcpy(dest, src, size);
}
/* Set buffer to u8 */
void buff_set(void* buff, u64 size, u8 val) {
  memset(buff, val, size);
}

/* CONSOLE I/O */
/* Put text to console */
void puts_console(char* str) {
  puts(str);
}
/* Put buffer to console */
void putn_console(char* buff, u64 size) {
  write(STDOUT_FILENO, buff, size);
}
/* Read buffer from console */
void getn_console(char* buff, u64 size) {
  read(STDIN_FILENO, buff, size);
}

/* FILE I/O */

/* MISC */
/* Get current time */
time_t get_time(void);
/* Get current date */
date_t get_date(void);

/* TO STRINGS */
/* Null-terminated string from u8 */
const char* cstr_u8(char* buff, u64 size, u8 val);
/* Null-terminated string (hex) from u8 */
const char* cstr_hex_u8(u8 val);
/* Null-terminated string from u16 */
const char* cstr_u16(char* buff, u64 size, u16 val);
/* Null-terminated string (hex) from u16 */
const char* cstr_hex_u16(u16 val);
/* Null-terminated string from u32 */
const char* cstr_u32(char* buff, u64 size, u32 val);
/* Null-terminated string (hex) from u32 */
const char* cstr_hex_u32(u32 val);
/* Null-terminated string from u64 */
const char* cstr_u64(char* buff, u64 size, u64 val);
/* Null-terminated string (hex) from u64 */
const char* cstr_hex_u64(u64 val);

/* Null-terminated string from i8 */
const char* cstr_i8(char* buff, u64 size, i8 val);
/* Null-terminated string from i16 */
const char* cstr_i16(char* buff, u64 size, i16 val);
/* Null-terminated string from i32 */
const char* cstr_i32(char* buff, u64 size, i32 val);
/* Null-terminated string from i64 */
const char* cstr_u64(char* buff, u64 size, u64 val);

/* Null-terminated string from f32 */
const char* cstr_f32(char* buff, u64 size, f32 val);
/* Null-terminated string from f64 */
const char* cstr_f64(char* buff, u64 size, f64 val);

/* Null-terminated string from bool */
const char* cstr_bool(bool val);
/* Null-terminated string from bool red/green (ansi escape) */
const char* cstr_col_bool(bool val);

/* Null-terminated string from date */
const char* cstr_date(date_t date);
/* Null-terminated string from time */
const char* cstr_time(time_t time);
/* Null-terminated string from weekday */
const char* cstr_weekday(weekday_t day);
/* Null-terminated string from month */
const char* cstr_month(month_t month);
/* Null-terminated string from ip address type */
const char* cstr_ipaddrtype(ip_addr_type_t type);

