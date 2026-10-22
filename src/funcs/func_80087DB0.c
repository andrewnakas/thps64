#include "common.h"
typedef struct {
    u8 pad_000[0x528];
    s32 field_528;
    u8 pad_52C[9];
    u8 field_535[4];
    u8 field_539[4];
    u8 pad_53D[0x13];
    s32 field_550;
    s32 field_554;
} State80087DB0;
typedef struct { u8 pad_000[0x120]; s32 field_120[4]; } Entry80087DB0;
extern u8 D_800D0FC0[];
extern u8 D_800DC3F8[];
void func_80087DB0(State80087DB0 *state) {
    register u8 *table __asm__("$7") = D_800DC3F8;
    register u8 *context __asm__("$6") = D_800D0FC0;
    u32 index;
    /* Preserve the original full-address bases in A3/A2; unconstrained locals choose A2/A1.
       This constraint emits no instructions. */
    __asm__("" : "+r" (table), "+r" (context));
    index = context[0x16] * 0x10;
    ((Entry80087DB0 *)((u32)index + (u32)table))->field_120[0] = 0;
    state->field_539[0] = 0;
    state->field_535[0] = 0;
    index = context[0x16] * 0x10;
    ((Entry80087DB0 *)((u32)index + (u32)table))->field_120[1] = 1;
    state->field_539[1] = 1;
    state->field_535[1] = 1;
    index = context[0x16] * 0x10;
    ((Entry80087DB0 *)((u32)index + (u32)table))->field_120[2] = 2;
    state->field_539[2] = 2;
    state->field_535[2] = 2;
    index = context[0x16] * 0x10;
    ((Entry80087DB0 *)((u32)index + (u32)table))->field_120[3] = 3;
    state->field_539[3] = 3;
    state->field_535[3] = 3;
    state->field_550 = 1;
    state->field_554 = 1;
    state->field_528 = 1;
}
