/*
 *    kinetis_sysinit.c - Default init routines for
 *                     		Kinetis ARM systems
 *    Copyright � 2010 Freescale semiConductor Inc. All Rights Reserved.
 */

#include "kinetis_sysinit.h"
#include "derivative.h"

typedef void (*const tIsrFunc)(void);
typedef struct {
  uint32_t * __ptr;
  tIsrFunc __fun[7];
} tVectorTable;

extern void isr_default(void);
extern uint32_t __stacktop[];
extern uint32_t flashProgramHeader[];

#pragma define_section vectortable ".vectortable" far_abs R
static __declspec(vectortable) tVectorTable __vect_table = { /* Interrupt vector table */
  flashProgramHeader,                                      /* 0  (0x00000000) (prior: -) */
  {
   (tIsrFunc)isr_default,                                  /* 1  (0x00000004) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 2  (0x00000008) (prior: -2) */
   (tIsrFunc)isr_default,                                  /* 3  (0x0000000C) (prior: -1) */
   (tIsrFunc)isr_default,                                  /* 4  (0x00000010) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 5  (0x00000014) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 6  (0x00000018) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 7  (0x0000001C) (prior: -) */
   }
};
