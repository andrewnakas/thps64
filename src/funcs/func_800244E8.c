#include "common.h"

s32 func_80042068(s32);                     /* extern */
s32 func_8008B2C0(s32, s32);            /* extern */
s32 func_8009F0EC(void *, s32);          /* extern */
s32 func_8009F150(void *);                   /* extern */
extern s8 D_800D0FE3;
extern s32 D_800D6180;
extern s32 D_800DC5A0;
extern s32 D_800DDC60;
extern s32 D_800DE7A4;
extern s32 D_800DE820;
extern s32 D_800E9038;
extern s32 D_800EA110;

void func_800244E8(void) {
    s32 *p;
    func_8008B2C0(1, 0);
    D_800E9038 = 0;
    D_800DE820 = 0;
    func_80042068(-1);
    p = &D_800EA110;
    func_8009F150(p);
    func_8009F0EC(p, 0);
    D_800D0FE3 = 1;
    D_800DC5A0 = 0;
    D_800DE7A4 = 0;
    D_800D6180 = 0;
    D_800DDC60 = 0;
}
