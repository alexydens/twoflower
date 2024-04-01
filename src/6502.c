/* Implements 6502.h */
#include <6502.h>

/* Helper macros */
/* Read 16-bit value at RAM address (note little-endian) */
#define VAL_AT(ADDR, RAM) ((RAM)[(ADDR)] | ((RAM)[(ADDR)+1] << 16))

/* Reset a 6502 cpu */
void reset_6502(cpu_6502_t* cpu) {
  /*
   * The initial state of the 6502, accoring to a forum post from 2009:
   * - program counter guaranteed to point to 0xfffc.
   * - stack pointer guaranteed to point to 0x01ff.
   * - interrupt-disable flag guaranteed to be set.
   * - no other guarantees.
   *   +-> often, decimal flag cleared as well as data registers. i am doing
   *   this, but it has been made clear enough that this shouldn't be taken for
   *   granted in any programs one could port.
   * 
   * (see http://forum.6502.org/viewtopic.php?f=8&t=1387&view=next)
   */
  /* Program counter points to 0xfffc */
  cpu->pc = 0xfffc;
  /* Stack pointer points to 0x01ff */
  cpu->sp = 0xff;
  /* Reset data registers */
  cpu->acc = 0x0000;
  cpu->irx = 0x0000;
  cpu->iry = 0x0000;
  /* Interrupt-disable flag is set */
  cpu->status.flags.I = true;
  /* Decimal flag is cleared */
  cpu->status.flags.D = false;
  /* Reset takes 7 cycles */
  cpu->cycles_behind = 7;
}
/* Perform one cycle on a 6502 cpu */
void step_6502(cpu_6502_t* cpu) {
  /* Only execute instruction if caught up cycles */
  if (!cpu->cycles_behind) {
    /* Get next instruction */
    u16 instr = VAL_AT(cpu->pc, cpu->ram);
    /* Increment program counter */
    cpu->pc+=2;
    u8 opcode = instr >> 8;
  } else {
    cpu->cycles_behind--;
  }
}
