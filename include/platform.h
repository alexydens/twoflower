/* Include guard */
#ifndef TF_PLATFORM_H
#define TF_PLATFORM_H

/* Base */
#include "base.h"
#include "types.h"

/* MEMORY */
/* Allocate size bytes on the heap */
extern void* heap_alloc(u64 size);
/* Re-size pointer ptr to own size bytes on the heap */
extern void* heap_realloc(void* ptr, u64 size);
/* Free memory on the heap */
extern void heap_free(void* ptr);
/* Copy memory on the heap */
extern void buff_copy(void* src, void* dest, u64 size);
/* Set buffer to u8 */
extern void buff_set(void* buff, u64 size, u8 val);

/* CONSOLE I/O */
/* Put text to console */
extern void puts_console(char* str);
/* Put buffer to console */
extern void putn_console(char* buff, u64 size);
/* Read buffer from console */
extern void getn_console(char* buff, u64 size);

/* FILE I/O */
/* TODO: ensure works with append */

/* MISC */
/* Get current time */
extern time_t get_time(void);
/* Get current date */
extern date_t get_date(void);

/* TO STRINGS */
/* Null-terminated string from u8 */
extern const char* cstr_u8(char* buff, u64 size, u8 val);
/* Null-terminated string (hex) from u8 */
extern const char* cstr_hex_u8(u8 val);
/* Null-terminated string from u16 */
extern const char* cstr_u16(char* buff, u64 size, u16 val);
/* Null-terminated string (hex) from u16 */
extern const char* cstr_hex_u16(u16 val);
/* Null-terminated string from u32 */
extern const char* cstr_u32(char* buff, u64 size, u32 val);
/* Null-terminated string (hex) from u32 */
extern const char* cstr_hex_u32(u32 val);
/* Null-terminated string from u64 */
extern const char* cstr_u64(char* buff, u64 size, u64 val);
/* Null-terminated string (hex) from u64 */
extern const char* cstr_hex_u64(u64 val);

/* Null-terminated string from i8 */
extern const char* cstr_i8(char* buff, u64 size, i8 val);
/* Null-terminated string from i16 */
extern const char* cstr_i16(char* buff, u64 size, i16 val);
/* Null-terminated string from i32 */
extern const char* cstr_i32(char* buff, u64 size, i32 val);
/* Null-terminated string from i64 */
extern const char* cstr_u64(char* buff, u64 size, u64 val);

/* Null-terminated string from f32 */
extern const char* cstr_f32(char* buff, u64 size, f32 val);
/* Null-terminated string from f64 */
extern const char* cstr_f64(char* buff, u64 size, f64 val);

/* Null-terminated string from bool */
extern const char* cstr_bool(bool val);
/* Null-terminated string from bool red/green (ansi escape) */
extern const char* cstr_col_bool(bool val);

/* Null-terminated string from date */
extern const char* cstr_date(date_t date);
/* Null-terminated string from time */
extern const char* cstr_time(time_t time);
/* Null-terminated string from weekday */
extern const char* cstr_weekday(weekday_t day);
/* Null-terminated string from month */
extern const char* cstr_month(month_t month);
/* Null-terminated string from ip address type */
extern const char* cstr_ipaddrtype(ip_addr_type_t type);

#endif /* end of include guard: TF_PLATFORM_H */
