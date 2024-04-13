/* Make sure to use debug, for everything to be tested */
#ifndef DEBUG
#define DEBUG
#endif

/* Twoflower headers */
#include <base.h>
#include <types.h>
#include <arena_alloc.h>
#include <str.h>

/* libc headers */
#include <stdio.h>
#include <string.h>

/* To test */
#define TEST_BASE
#define TEST_TYPES
#define TEST_ARENA_ALLOC
#define TEST_STR

/* Helper macros */
/* String from either success in green or failed in red */
#define STR_RES(A)  ((A) ? "\x1b[32msuccess\x1b[0m" : "\x1b[31mfailed\x1b[0m")
/* String from a bool with colour */
#define STR_BOOL(A) ((A) ? "\x1b[32mtrue\x1b[0m" : "\x1b[31mfalse\x1b[0m")

/* Entry point */
int main(void) {
#ifdef TEST_BASE
  printf("\x1b[1;4;100;96mTESTING BASE:\x1b[0m\n");
  printf("Testing u8 size:\t%s\n", STR_RES(sizeof(u8)==1));
  printf("Testing u16 size:\t%s\n", STR_RES(sizeof(u16)==2));
  printf("Testing u32 size:\t%s\n", STR_RES(sizeof(u32)==4));
  printf("Testing u64 size:\t%s\n", STR_RES(sizeof(u64)==8));
  printf("\n");
  printf("Testing i8 size:\t%s\n", STR_RES(sizeof(i8)==1));
  printf("Testing i16 size:\t%s\n", STR_RES(sizeof(i16)==2));
  printf("Testing i32 size:\t%s\n", STR_RES(sizeof(i32)==4));
  printf("Testing i64 size:\t%s\n", STR_RES(sizeof(i64)==8));
  printf("\n");
  printf("Testing f32 size:\t%s\n", STR_RES(sizeof(f32)==4));
  printf("Testing f64 size:\t%s\n", STR_RES(sizeof(f64)==8));
  printf("\n");
  printf("Value of NULL:\t\t%p\n", NULL);
  printf("Value of C_PI:\t\t%.12lf\n", C_PI);
  printf("Value of C_E:\t\t%.12lf\n", C_E);
  printf("Value of C_KiB:\t\t%u\n", C_KiB);
  printf("Value of C_MiB:\t\t%u\n", C_MiB);
  printf("Value of C_GiB:\t\t%u\n", C_GiB);
  printf("\n");
  printf("Testing STRING(A):\t%s\n", STR_RES(strcmp(STRING(ab c),"ab c") == 0));
  printf("\n");
  printf("Testing MAX(A,B) (1):\t%s\n", STR_RES(MAX(6, 0) == 6));
  printf("Testing MAX(A,B) (2):\t%s\n", STR_RES(MAX(0, 6) == 6));
  printf("Testing MAX(A,B) (3):\t%s\n", STR_RES(MAX(6.0, 1.5) == 6.0));
  printf("Testing MAX(A,B) (4):\t%s\n", STR_RES(MAX(1.5, 6.0) == 6.0));
  printf("\n");
  printf("Testing MIN(A,B) (1):\t%s\n", STR_RES(MIN(6, 0) == 0));
  printf("Testing MIN(A,B) (2):\t%s\n", STR_RES(MIN(0, 6) == 0));
  printf("Testing MIN(A,B) (3):\t%s\n", STR_RES(MIN(6.0, 1.5) == 1.5));
  printf("Testing MIN(A,B) (4):\t%s\n", STR_RES(MIN(1.5, 6.0) == 1.5));
  printf("\n");
  printf("Testing LERP(A,B,V) (1):%s\n", STR_RES(LERP(0, 10, 0.75) == 7.5));
  printf("Testing LERP(A,B,V) (2):%s\n", STR_RES(LERP(10, 0, 0.75) == 7.5));
  printf("\n");
  {
    i32 a = 0, b = 5;
    SWAP(a, b);
    printf("Testing SWAP(A,B):\t%s\n", STR_RES(a == 5 && b == 0));
  }
  printf("\n");
  printf("Value of OS_LINUX:\t%s\n", STR_BOOL(OS_LINUX));
  printf("Value of OS_WINDOWS:\t%s\n", STR_BOOL(OS_WINDOWS));
  printf("\n");
  printf("Value of COMPILER_CLANG:%s\n", STR_BOOL(COMPILER_CLANG));
  printf("Value of COMPILER_GCC:\t%s\n", STR_BOOL(COMPILER_GCC));
  printf("Value of COMPILER_MSVC:\t%s\n", STR_BOOL(COMPILER_MSVC));
  printf("\n");
  printf("Value of CPU_AMD64:\t%s\n", STR_BOOL(CPU_AMD64));
  printf("Value of CPU_ARM:\t%s\n", STR_BOOL(CPU_ARM));
  printf("Value of CPU_ARM64:\t%s\n", STR_BOOL(CPU_ARM64));
  printf("Value of CPU_RV32:\t%s\n", STR_BOOL(CPU_RV32));
  printf("Value of CPU_RV64:\t%s\n", STR_BOOL(CPU_RV64));
  printf("\n");
  printf(
      "\x1b[33;4;1m"
      "TODO:\x1b[0m Test cstr_<TYPE>(char* buff, u64 size, <TYPE> val).\n"
  );
  printf("\n");
#endif
#ifdef TEST_TYPES
  printf("\x1b[1;4;100;96mTESTING TYPES:\x1b[0m\n");
  printf(
      "\x1b[33;4;1m"
      "TODO:\x1b[0m Test cstr_<TYPE>(<TYPE> val).\n"
  );
#endif
#ifdef TEST_ARENA_ALLOC
#endif
#ifdef TEST_STR
  printf("\x1b[1;4;100;96mTESTING STR:\x1b[0m\n");
  arena_alloc_t arena = create_arena(NULL, 64*C_KiB);
  str_t s0 = string_from(&arena, "Hello ");
  str_t s1 = string_input(&arena, 5);
  str_t s2 = string_file(&arena, ".ccls");
  str_t s3 = string_file_part(&arena, ".ccls", 5);
  str_t s4 = string_copy(&arena, s0);
  str_t s5 = string_concat(&arena, s0, s1);
  print_string(s0);
  printf("\n");
  print_string(s1);
  printf("\n");
  print_string(s2);
  printf("\n");
  print_string(s3);
  printf("\n");
  print_string(s4);
  printf("\n");
  print_string(s5);
  printf("\n\n");

  arena_free(&arena);
#endif
  return 0;
}
