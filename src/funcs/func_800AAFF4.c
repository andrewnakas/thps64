/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x24];
    f32 unk24;
    u8 pad28[0xC];
    s32 unk34;
    s32 unk38;
    u8 pad3C[0x30];
    f32 unk6C;
    f32 unk70;
    u8 pad74[0x2E];
    u16 unkA2;
    u16 unkA4;
    u8 padA6[0x16];
    u8 unkBC;
    u8 padBD[0x1E];
    u8 unkDB;
    u8 padDC[4];
    s32 unkE0[4];
    s32 unkF0[4];
    s32 unk100[4];
    u16 unk110[4];
    u16 unk118[4];
    u8 unk120[4];
    u8 unk124[4];
    u8 unk128[4];
} S;

s32 func_800AAFF4(S *arg0, s32 arg1) {
    s32 i;
    f32 f;

    i = arg0->unkDB - 1;
    if (arg0->unk120[i] != 0xFF) {
        if (--arg0->unk120[i] == 0) {
            arg0->unkDB = i;
            i = -1;
        }
    }
    if (i >= 0) {
        arg1 = arg0->unkE0[i];
        arg0->unk38 = arg0->unkF0[i];
        arg0->unk34 = arg0->unk100[i];
        arg0->unkBC = arg0->unk124[i];
        f = arg0->unk128[i];
        arg0->unk70 = f;
        arg0->unkA2 = arg0->unk110[i];
        arg0->unkA4 = arg0->unk118[i];
        arg0->unk24 = f * arg0->unk6C;
    }
    return arg1;

}
