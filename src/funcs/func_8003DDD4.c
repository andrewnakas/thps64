#include "common.h"

typedef struct {
    u8 pad0[8];
    u8 x8;
    u8 pad9[0xB];
} Ent;

extern u8 D_800D0FC2;
extern Ent D_800DE9F4[];
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;
s32 func_8003FE90(s32, s32);
void func_8003DF84(u8 *);
s32 func_8003E054(s32);
s32 func_80027644(s32, s32, s32, f32);
void func_8003CFA0(u8 *);
s32 func_8003DBA8(s32, s32);
s32 func_800B4264(s32, s32);
void func_80039E60(s32, s32, s32);

s32 func_8003DDD4(u8 *obj) {
    s32 cur;
    s32 pad;
    s32 ret;
    s32 n;
    Ent *tbl;
    s32 one;
    s32 d;

    pad = D_800D0FC2;
    tbl = D_800DE9F4;
    ret = 0;
    *(s32 *)(obj + 0x7B4) = func_8003FE90(obj[0x33], tbl[*(s32 *)(obj + 0x30)].x8);
    func_8003DF84(obj);
    n = func_80027644(*(s32 *)(obj + 0x4F4), func_8003E054(pad), 1, 100.0f);
    if (n != 0) {
        *(s32 *)(obj + 0x4F0) = 1;
    }
    func_8003CFA0(obj);
    if (n != 0) {
        cur = *(s32 *)(obj + 0x30);
        *(s32 *)(obj + 0x30) = (cur + n + *(s32 *)(obj + 0x7B0)) % *(s32 *)(obj + 0x7B0);
        *(s32 *)(obj + 0x4F4) = func_8003DBA8(*(s32 *)(obj + 0x4F4), *(s32 *)(obj + 0x30));
    }
    if (func_800B4264(pad, 0x4000)) {
        func_80039E60(0x93, 10000, 0);
        if (D_800DE7A0 == 1) {
            ret = 8;
        } else {
            ret = 4;
        }
    } else if (func_800B4264(pad, 0x9000)) {
        func_80039E60(0x91, 10000, 0);
        ret = 11;
        d = D_800DE7A0;
        one = 1;
        if (d == one || d == 0x13) {
            *(s32 *)((u8 *)&tbl[*(s32 *)(obj + 0x30)] + 0x18) = one;
        }
        D_800DE9A8 = 1;
    }
    return ret;
}
