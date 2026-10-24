/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x8];
    s32 unk18;
    u8 pad1C[0x408];
    s32 unk424;
    u8 pad428[0x54];
    s32 unk47C;
} Obj800A1DE4;

extern void func_800A0E74(Obj800A1DE4 *, s32, s32);
extern void func_800A1E70(Obj800A1DE4 *);
extern s32 D_800EA550;

void func_800A1DE4(Obj800A1DE4 *arg0) {
    s32 s = arg0->unk18;

    switch (s) {
    case 1:
        arg0->unk47C = s;
        func_800A0E74(arg0, 0, D_800EA550);
    case 0:
        arg0->unkC = 0x1E;
        break;
    case 2:
        D_800EA550 = arg0->unk424;
        func_800A1E70(arg0);
        break;
    }
}
