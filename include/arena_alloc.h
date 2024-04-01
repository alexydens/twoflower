/* Include guard */
#ifndef TF_ARENA_ALLOC_H
#define TF_ARENA_ALLOC_H

/* For C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* Base */
#include "base.h"

/* Arena allocator - a.k.a linear allocator - can't free individually. */
typedef struct {
  void* base;
  void* ptr;
  u64 size;
  bool own_alloc;
} arena_alloc_t;

/* Create an arena allocator of size bytes - if !base, allocate using malloc */
extern arena_alloc_t create_arena(void* base, u64 size);
/* Free all memory on an arena allocator */
extern void arena_free(arena_alloc_t* arena);
/* Allocate size bytes on arena allocator if no space, return NULL */
extern void* arena_alloc(arena_alloc_t* arena, u64 size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: TF_ARENA_ALLOC_H */
