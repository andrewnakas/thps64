#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VEnt66C40;

typedef struct {
    u8 pad0[0x10];
    VEnt66C40 e10;
    u8 pad18[0x20];
    VEnt66C40 e38;
} VTbl66C40;

typedef struct {
    u16 unk0;
    u8 pad2[0x46];
    VTbl66C40 *vt;
    u8 pad4C[0x1DE];
    u16 unk22A;
    s16 unk22C;
    u8 pad22E[2];
    u16 unk230;
    u8 pad232[2];
    s32 unk234;
} Obj66C40;

extern s32 D_800DE808;

void func_80066C40(Obj66C40 *arg0) {
    u16 t;
    s32 u;

    arg0->unk234++;
    u = arg0->unk230;
    if ((u16)u != 0xFFFF) {
        if ((u16)u != 0) {
            arg0->unk230 = u - 1;
        }
        if ((t = arg0->unk230) < 60) {
            arg0->unk22C = (arg0->unk22A * arg0->unk230) / 60;
        }
        if ((u32)(arg0->unk230 - 31) < 29) {
            if (D_800DE808 & 2) {
                arg0->unk0 &= 0xFFFE;
            } else {
                arg0->unk0 |= 0x41;
                arg0->vt->e38.fn((u8 *)arg0 + arg0->vt->e38.off);
            }
        }
        if (arg0->unk230 < 31) {
            if (D_800DE808 & 1) {
                arg0->unk0 &= 0xFFFE;
            } else {
                arg0->unk0 |= 0x41;
                arg0->vt->e38.fn((u8 *)arg0 + arg0->vt->e38.off);
            }
        }
        if (arg0->unk230 == 0) {
            arg0->vt->e10.fn((u8 *)arg0 + arg0->vt->e10.off);
        }
    }
}
