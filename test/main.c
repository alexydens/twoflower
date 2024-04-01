/* Twoflower headers */
#include <base.h>
#include <types.h>
#include <arena_alloc.h>

/* libc headers */
#include <stdio.h>

/* Entry point */
int main(void) {
  arena_alloc_t arena = create_arena(NULL, 3 * sizeof(i32));
  i32* a = arena_alloc(&arena, sizeof(i32));
  i32* b = arena_alloc(&arena, 2*sizeof(i32));
  *a = 0;
  b[0] = 1;
  b[1] = 2;
  for (u8 i = 0; i < 3; i++)
    printf("%d\n", ((i32*)arena.base)[i]);
  arena_free(&arena);
  return 0;
}
