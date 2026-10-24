/* cflags: -O2 -fno-schedule-insns */
#include "common.h"

typedef struct {
    u8 pad0[0x21];
    u8 unk21;
    u8 pad22[2];
} Slot;

typedef struct {
    s32 unk0;
    u8 pad4[0x524];
    Slot slots[1];
} Obj;

s32 func_800A9D64(void);

void func_800A9B98(Obj *arg0, s32 arg1, s32 arg2) {
    if (arg0->unk0 != 0 && func_800A9D64() != 0) {
        arg0->slots[arg1].unk21 = arg2;
    }
}
