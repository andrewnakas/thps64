/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x4];
    u32 unk4;
} Ent8007DAA8;

typedef struct {
    u8 pad0[0x4C];
    Ent8007DAA8 *unk4C;
    u32 unk50;
} Obj8007DAA8;

void func_8007DAA8(Obj8007DAA8 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    u32 i;
    u32 v;
    Ent8007DAA8 *base;

    v = arg4 << 16;
    arg3 = ((arg3 & 0xFF) << 8) | 0x3A000000;
    v |= arg3;
    arg2 = v | (arg2 & 0xFF);
    base = &arg0->unk4C[arg1 * arg0->unk50];
    for (i = 0; i < arg0->unk50; i++) {
        base[i].unk4 = arg2;
    }
}
