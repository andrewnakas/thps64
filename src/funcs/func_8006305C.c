#include "common.h"

extern s32 D_800DAD70[2];
extern s32 D_800DAD90;
extern void func_80062548(s32, s32, s32);
extern void func_800620D8(void);

void func_8006305C(void) {
    s32 *p;

    p = D_800DAD70;
    func_80062548(p[0], 0, 0);
    func_80062548(p[1], 0, 0);
    p[0] = -1;
    p[1] = -1;
    func_800620D8();
    D_800DAD90 = 0;
}
