/* Include guard */
#ifndef TF_6502_H
#define TF_6502_H

/* For C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* Base */
#include "base.h"

/* Consts */
/* The maximum amount of RAM in bytes supported by the 6502 */
#define MAX_RAM_6502      64*C_KiB

/* 6502 cpu struct */
typedef struct {
  u16 pc;   /* The program counter */
  u8 sp;    /* The stack pointer (mem addr = sp + 0x0100) */
  u16 acc;  /* The accumulator */
  u16 irx;  /* The index register x */
  u16 iry;  /* The index register y */
  union {
    u16 val; /* In number form */
    struct {
      bool C: 1; /* Carry flag */
      bool Z: 1; /* Zero flag */
      bool I: 1; /* Interrupt disable flag */
      bool D: 1; /* Decimal mode flag */
      bool B: 1; /* Break flag */
      bool V: 1; /* Overflow flag */
      bool N: 1; /* Negative flag */
    } flags; /* The actual flags */
  } status; /* The state of the cpu */
  u16* ram; /* The ram used by the cpu (not controlled within this emulator) */
  /* How many cycles behind the cpu is (this allows the emulation to be
   * accurate to the cycle */
  u64 cycles_behind;
} cpu_6502_t;

/* Reset a 6502 cpu */
extern void reset_6502(cpu_6502_t* cpu);
/* Perform one cycle on a 6502 cpu */
extern void step_6502(cpu_6502_t* cpu);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: TF_6502_H */
