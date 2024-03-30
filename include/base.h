/* Include guard */
#ifndef TF_BASE_H
#define TF_BASE_H

/* For C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* Unsigned integer types */
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
/* Signed integer types */
typedef signed char         i8;
typedef signed short        i16;
typedef signed int          i32;
typedef signed long long    i64;
/* Float types */
typedef float               f32;
typedef double              f64;
/* Booleans */
#ifdef __cplusplus  /* C++ - no _Bool */
typedef u8 bool;
#else               /* C - use _Bool */
#ifndef bool        /* Check no stdbool.h def */
typedef _Bool bool;
enum { false, true };
#endif
#endif
/* Size type */
#ifndef _STDDEF_H_
typedef u64 size_t;
#endif

/* Consts */
#ifndef _STDDEF_H_
#define NULL        ((void*)0)            /* A null pointer */
#endif
#define C_PI        3.14159265358979      /* Mathematical constant pi */
#define C_E         2.71828182845905      /* Euler's number */
#define C_KiB       (1024)                /* 1 KiB in Bytes */
#define C_MiB       (1024*1024)           /* 1 MiB in Bytes */
#define C_GiB       (1024*1024*1024)      /* 1 GiB in Bytes */
#define C_TiB       (1024*1024*1024*1024) /* 1 TiB in Bytes */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: TF_BASE_H */
