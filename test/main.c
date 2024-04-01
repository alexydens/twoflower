/* Twoflower headers */
#include <base.h>
#include <types.h>
#include <arena_alloc.h>
#include <str.h>

/* libc headers */
#include <stdio.h>

/* Entry point */
int main(void) {
  arena_alloc_t arena = create_arena(NULL, 512*C_KiB);
#ifdef TEST_BASE
#endif
#ifdef TEST_TYPES
#endif
#ifdef TEST_ARENA_ALLOC
#endif
#ifdef TEST_STR
  str_t literal = string_from(&arena, "Hello world!\n");
  str_t input = string_input(&arena, 8);
  str_t file = string_file(&arena, ".ccls");
  str_t file_part = string_file_part(&arena, "Makefile", 12);
  str_t copy = string_copy(&arena, literal);
  str_t concat = string_concat(&arena, literal, input);
  print_string(literal);
  printf("\n");
  print_string(input);
  printf("\n");
  print_string(file);
  printf("\n");
  print_string(file_part);
  printf("\n");
  print_string(copy);
  printf("\n");
  print_string(concat);
  printf("\n");
  ASSERT(string_compare(literal, copy));
  file_write_string("test.txt", literal);
  file_append_string("test.txt", file);
#endif
  arena_free(&arena);
  return 0;
}
