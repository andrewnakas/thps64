/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
    s32 unk38;
    u8 pad3C[0x34];
    f32 unk70;
    u8 pad74[0x2E];
    u16 unkA2;
    u16 unkA4;
    u8 padA6[0x16];
    u8 unkBC;
    u8 padBD[0x1E];
    u8 unkDB;
    u8 padDC[4];
    u8 *unkE0[4];
    s32 unkF0[4];
    s32 unk100[4];
    u16 unk110[4];
    u16 unk118[4];
    u8 unk120[4];
    u8 unk124[4];
    u8 unk128[4];
} Seq;

u8 *func_800AAF4C(Seq *arg0, u8 *arg1) {
    u8 c = *arg1++;
    s32 d = arg0->unkDB;
    f32 f;
    u32 v;
    Seq *q;

    arg0->unk120[d] = c;
    arg0->unkE0[d] = arg1;
    arg0->unkF0[d] = arg0->unk38;
    arg0->unk100[d] = arg0->unk34;
    arg0->unk124[d] = arg0->unkBC;
    q = (Seq *)((u8 *)arg0 + d);
    f = arg0->unk70;
    if (f >= 2147483648.0f) {
        goto big;
    }
    v = (s32)f;
    goto end;
big:
    v = (s32)(f - 2147483648.0f);
    v |= 0x80000000;
end:
    q->unk128[0] = v;
    arg0->unk110[d] = arg0->unkA2;
    arg0->unk118[d] = arg0->unkA4;
    arg0->unkDB++;
    return arg1;
}
