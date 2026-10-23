#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec59AA0;

s32 func_80022E54(void *, Vec59AA0 *);
void func_80046FBC(Vec59AA0 *, void *, void *);
void func_8004733C(Vec59AA0 *);
s32 func_800474C8(void *);
void func_8004D398(void *, s32);
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;

#define OBJ(p) (*(u8 **)((u8 *)(p) + 0x2CC))
#define F450(p) (*(s32 *)((u8 *)(p) + 0x450))

void func_80059AA0(u8 *arg0) {
    Vec59AA0 a;
    Vec59AA0 b;
    Vec59AA0 *pa;
    u8 *q;
    s32 r1;
    s32 r2;
    s32 m;

    if (D_800DE9A8 != 1 && D_800DE7A0 != 7 && F450(arg0) == 0 && F450(OBJ(arg0)) == 0) {
        func_80046FBC(&a, OBJ(arg0) + 4, arg0 + 4);
        if (func_800474C8(&a) < 0x3C) {
            func_80046FBC(&b, OBJ(arg0) + 4, arg0 + 0x16C);
            pa = &a;
            a = b;
            func_8004733C(pa);
            q = arg0 + 0x84;
            r1 = func_80022E54(q, pa);
            r2 = func_80022E54(OBJ(arg0) + 0x84, pa);
            if (r1 > 0) {
                if (r2 > 0) {
                    func_8004D398(OBJ(arg0), 0);
                } else {
                    m = func_800474C8(OBJ(arg0) + 0x84);
                    if (func_800474C8(q) < m) {
                        func_8004D398(arg0, 0);
                    } else {
                        func_8004D398(OBJ(arg0), 0);
                    }
                }
            } else if (r2 <= 0) {
                func_8004D398(arg0, 0);
            }
        }
    }
}
