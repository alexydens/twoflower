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

/* Consts */
#ifndef NULL
#define NULL        ((void*)0)            /* A null pointer */
#endif
#define C_PI        3.14159265358979      /* Mathematical constant pi */
#define C_E         2.71828182845905      /* Euler's number */
#define C_KiB       (1024)                /* 1 KiB in Bytes */
#define C_MiB       (1024*1024)           /* 1 MiB in Bytes */
#define C_GiB       (1024*1024*1024)      /* 1 GiB in Bytes */
#define C_TiB       (1024*1024*1024*1024) /* 1 TiB in Bytes */

/* Utility macros */
/* Make into string */
#define STRING(A)     #A
/* Concatenate */
#define CONCAT(A,B)   A##B
/* The smallest value out of A or B */
#define MIN(A,B)      ((A) > (B) ? (A) : (B))
/* The largest value out of A or B */
#define MAX(A,B)      ((A) < (B) ? (A) : (B))
/* A value between A and B, where V is how much inbetween (e.g. 0.5 would be
 * halfway between A and B */
#define LERP(A,B,V)   (MIN(A,B) + V * (MAX(A,B)-MIN(A,B)))
/* Swap the values of A and B (A and B must be variables) */
#define SWAP(A,B)     do{__typeof__(A) TMP = A; A = B; B = TMP;}while(0)

/* Assertions */
#ifdef DEBUG
#define ENABLE_ASSERT
#endif
#ifdef ENABLE_ASSERT
/* What to do when assert failed */
#ifndef ASSERT_ONFAIL
#define ASSERT_ONFAIL(EXPR, LINE, FILE) (*(char*)NULL) = 0;
#endif
/* Assertions themselves */
#define ASSERT(EXPR)  do{\
  if (!(EXPR))\
    ASSERT_ONFAIL(EXPR, __LINE__, __FILE__);\
  } while(0)
#else
#define ASSERT(EXPR)
#endif

/* Context cracking */
/* Operating system */
#ifdef __gnu_linux__  /* For GNU/Linux */
#define OS_LINUX        1
#else
#define OS_LINUX        0
#endif
#ifdef _WIN32         /* For Windows */
#define OS_WINDOWS      1
#else
#define OS_WINDOWS      0
#endif
/* Compiler */
#ifdef __clang__      /* For Clang */
#define COMPILER_CLANG  1
#else
#define COMPILER_CLANG  0
#endif
#ifdef __GNUC__       /* For GNU Compiler Collection */
#define COMPILER_GCC    1
#else
#define COMPILER_GCC    0
#endif
#ifdef _MSC_VER       /* For Microsoft Visual C/C++ */
#define COMPILER_MSVC   1
#else
#define COMPILER_MSVC   0
#endif
/* Architecture */
#if defined(__amd64__) || defined(_M_AMD64)/* For x86 */
#define CPU_AMD64       1
#else
#define CPU_AMD64       0
#endif
#if defined(__arm__) || defined(_M_ARM)/* For Arm */
#define CPU_ARM         1
#else
#define CPU_ARM         0
#endif
#if defined(__aarch64__) || defined(_M_ARM64)/* For Arm64 */
#define CPU_ARM64       1
#else
#define CPU_ARM64       0
#endif
/* THE RISC-V ARCHTIECTURES MAY NOT WORK FOR MSVC/C++ COMPILERS */
#if __riscv_xlen == 32/* For RISC-V (32-bit) */
#define CPU_RV32        1
#else
#define CPU_RV32        0
#endif
#if __riscv_xlen == 64/* For RISC-V (64-bit) */
#define CPU_RV64        1
#else
#define CPU_RV64        0
#endif
/* Make sure a supported operating system is detected */
#if !OS_LINUX && !OS_WINDOWS
#error Twoflower: Unsupported Operating System!
#endif
/* Make sure a supported compiler is detected */
#if !COMPILER_GCC && !COMPILER_MSVC && !COMPILER_CLANG
#error Twoflower: Unsupported Compiler!
#endif
/* Make sure a supported architecture is detected */
#if !CPU_ARM && !CPU_ARM64 && !CPU_RV32 && !CPU_RV64 && !CPU_AMD64
#error Twoflower: Unsupportec Architecture!
#endif

/* Type to string conversion functions */
/* Unsigned ints */
/* Convert u8 to string, put in buff */
extern void cstr_u8(char* buff, u64 size, u8 val);
/* Convert u16 to string, put in buff */
extern void cstr_u16(char* buff, u64 size, u16 val);
/* Convert u32 to string, put in buff */
extern void cstr_u32(char* buff, u64 size, u32 val);
/* Convert u64 to string, put in buff */
extern void cstr_u64(char* buff, u64 size, u64 val);
/* Signed ints */
/* Convert i8 to string, put in buff */
extern void cstr_i8(char* buff, u64 size, i8 val);
/* Convert i16 to string, put in buff */
extern void cstr_i16(char* buff, u64 size, i16 val);
/* Convert i32 to string, put in buff */
extern void cstr_i32(char* buff, u64 size, i32 val);
/* Convert i64 to string, put in buff */
extern void cstr_i64(char* buff, u64 size, i64 val);
/* Floats */
/* Convert f32 to string, put in buff */
extern void cstr_f32(char* buff, u64 size, f32 val);
/* Convert f64 to string, put in buff */
extern void cstr_f64(char* buff, u64 size, f64 val);
/* Bools */
/* Convert bool to string, put in buff */
extern char* cstr_bool(bool val);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: TF_BASE_H */
