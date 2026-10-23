/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Entry7B734 { u8 pad0[0x10]; u16 unk10, unk12; u8 pad14[0x10]; } Entry7B734;

typedef struct State8007B734 {
    u8 pad0[0x3C];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[0x5];
    void * unk44;
    u8 unk48;
    u8 pad49[0x13];
    s32 unk5C;
    u8 pad60[0x4];
    s32 unk64;
    Entry7B734 * unk68;
} State8007B734;

void *func_8005EAB4(s32, s32, s32);
extern u8 D_8001E1A8;
extern u8 D_8001E388;
extern s32 D_800DE520;

void *func_8007B734(State8007B734 *arg0, s32 arg1, s8 arg2) {
    s32 var_v1;
    Entry7B734 *temp_v0;

    arg0->unk44 = &D_8001E388;
    arg0->unk3C = 1;
    arg0->unk3D = 1;
    arg0->unk3E = 1;
    D_800DE520 += 1;
    arg0->unk44 = &D_8001E1A8;
    arg0->unk64 = arg1;
    arg0->unk68 = func_8005EAB4(arg1 * 0x24, 0, 1);
    for (var_v1 = 0; var_v1 < arg0->unk64; var_v1++) {
        temp_v0 = (Entry7B734 *)((var_v1 * 0x24) + (s32)arg0->unk68);
        temp_v0->unk12 = 0;
        temp_v0->unk10 = 0;
    }
    arg0->unk48 = arg2;
    arg0->unk5C = 8;
    return arg0;
}
