/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 idx;
    u8 pad4[0x14];
    f32 unk18;
    s32 unk1C;
    s32 pad20;
} Chan_800A9068;

typedef struct {
    s32 unk0;
    u8 pad4[0x44];
    s32 count;
    u8 pad4C[8];
    s32 unk54;
    s32 *unk58;
    u32 unk5C;
    s8 unk60;
    u8 pad61[0x534 - 0x61];
    Chan_800A9068 ch[1];
} Obj_800A9068;

s32 func_8009E6B4(s32 *, u32, s32);
s32 func_800AAA40(s32 *, s32);
void func_800AB48C(void *);
void func_800AB734(s32, s32);
f32 func_800ABF14(s32);
s32 func_800AC770(void *, Obj_800A9068 *, s32, s32, s32, s32);
extern s32 D_800EA110;
extern s32 D_800F5678;

s32 func_800A9068(Obj_800A9068 *o, s32 arg1, s32 arg2, s32 arg3, s32 *list, s32 n, s32 arg6) {
    s32 i;
    u32 sz;
    s32 v;
    s32 *p;

    o->unk5C = 0;
    if (n > 0) {
        o->unk58 = (s32 *)func_8009E6B4(&D_800EA110, n * 4, 4);
        i = 0;
        p = list;
        while (1) {
            if (i >= n) break;
            o->unk58[i] = *p;
            v = *p;
            sz = func_800AAA40(&D_800F5678, v + 1) - func_800AAA40(&D_800F5678, v);
            if (sz & 1) {
                sz++;
            }
            if (sz <= o->unk5C) {
                sz = o->unk5C;
            }
            o->unk5C = sz;
            p++;
            i++;
        }
        o->unk60 = n;
        o->unk54 = func_8009E6B4(&D_800EA110, o->unk5C, 0x20);
    }
    if (func_800AC770((u8 *)o + 8, o, arg1, arg2, arg3, arg6) != 0) {
        func_800AB48C((u8 *)o + 8);
    }
    for (i = 0; i < o->count; i++) {
        o->ch[i].idx = i;
        o->ch[i].unk18 = func_800ABF14(i);
        o->ch[i].unk1C = 0;
    }
    o->unk0 = 1;
    func_800AB734(2, 20000);
    func_800AB734(1, 20000);
    return 1;
}
