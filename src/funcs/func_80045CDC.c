/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0xC];
} Elem14;

typedef struct {
    u8 *unk0;
    s32 unk4;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    u8 unk14[0x64];
    u8 unk78[0x64];
    u8 unkDC[0x64];
    s32 unk140;
    s32 unk144;
    s32 unk148;
    s32 unk14C;
    s32 unk150;
    s32 unk154;
    s32 unk158;
    u8 pad15C[0x1F8 - 0x15C];
    Elem14 elems[20];
    s32 unk388;
    u8 unk38C[0x64];
    u8 unk3F0[0x64];
    u8 unk454[0x64];
    u8 pad4B8[0x4F4 - 0x4B8];
    s32 unk4F4;
} Obj;

void func_8006A538(void *, s32);
void func_8009FD60(void *, void *);
extern s32 D_800DE7A0;
extern s32 D_800DF3EC;

void func_80045CDC(Obj *arg0) {
    s32 i;
    s32 n;
    s32 k;
    s32 lvl;
    u32 v;
    s32 *q;
    s32 m;

    arg0->unk154 = 0;
    arg0->unk158 = 0;
    if (arg0->unk388 > 0) {
        arg0->unkA += ((u16 *)&arg0->unk388)[1];
        arg0->unk144 = 0;
        for (i = 0; i < arg0->unk388; i++) {
            arg0->unk144 += arg0->elems[i].unk4;
        }
        q = &arg0->unk148;
        k = arg0->unk388 * 2;
        lvl = *(s32 *)(arg0->unk0 + 0x424);
        if (lvl < 3) m = k + lvl; else { n = k - 2; m = n + lvl * 2; }
        *q = m;
        v = (u32)(arg0->unk144 * arg0->unk148) >> 1;
        arg0->unk140 += v;
        if (arg0->unk10 < v) {
            arg0->unk10 = v;
            arg0->unkE = ((u16 *)&arg0->unk388)[1];
            func_8009FD60(arg0->unk14, arg0->unk38C);
            func_8009FD60(arg0->unk78, arg0->unk3F0);
            func_8009FD60(arg0->unkDC, arg0->unk454);
        }
        arg0->unk388 = 0;
        arg0->unk4F4 = 0x28;
        if (D_800DF3EC == 0) {
            arg0->unk4F4 = 0;
        }
        if (D_800DE7A0 == 2 && arg0->unk144 != 0) {
            arg0->unk4 = 0;
        }
    }
    func_8006A538(arg0->unk0, arg0->unk140);
}
