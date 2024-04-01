/* Implements the functions for handling arena allocators in arena_alloc.h */
#include <arena_alloc.h>

/* libc headers */
#include <stdlib.h>

/* Create an arena allocator of size bytes - if !base, allocate using malloc */
arena_alloc_t create_arena(void* base, u64 size) {
  arena_alloc_t arena;
  if (!base) {
    arena.base = malloc(size);
    arena.own_alloc = true;
  } else {
    arena.base = base;
    arena.own_alloc = false;
  }
  arena.size = size;
  arena.ptr = arena.base;
  ASSERT(arena.ptr);
  return arena;
}
/* Free all memory on an arena allocator */
void arena_free(arena_alloc_t* arena) {
  if (arena->own_alloc) free(arena->base);
  arena->base = NULL;
  arena->ptr = NULL;
  arena->size = 0;
  arena->own_alloc = false;
}
/* Allocate size bytes on arena allocator if no space, return NULL */
void* arena_alloc(arena_alloc_t* arena, u64 size) {
  if (((char*)arena->ptr + size) > ((char*)arena->base + arena->size))
    return NULL;
  void* res = arena->ptr;
  arena->ptr = (void*)((char*)arena->ptr + size);
  return res;
}
