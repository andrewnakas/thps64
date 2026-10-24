#include "common.h"

typedef struct {
    u8 pad0[0x4C];
    u8 unk4C;
    u8 pad4D[0xF];
    s32 unk5C;
    u8 pad60[0x10];
    s32 unk70;
} Obj;

s32 func_800B8E24(Obj *arg0) {
    s32 r;

    if (arg0->unk4C == 0xFF) {
        if (arg0->unk5C & 1) {
            if (arg0->unk5C & 2) {
                r = 0x104B50;
                arg0->unk70 = 0x104340;
            } else {
                r = 0x103078;
                arg0->unk70 = 0x103048;
            }
        } else {
            r = 0x112078;
            arg0->unk70 = 0x112048;
        }
    } else {
        r = 0x1051F8;
    }
    return r;
}
