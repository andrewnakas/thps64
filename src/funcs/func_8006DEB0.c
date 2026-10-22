#include "common.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} Col8006DEB0;

void func_8006EA0C(s32);
extern void *D_800DCA9C;
extern s32 D_800DCAA8;
extern u16 D_800DCAAC;
extern u8 D_800DCC1E;
extern Col8006DEB0 D_800FBB90;

void func_8006DEB0(void *arg0, s32 arg1) {
    Col8006DEB0 *p;
    s32 temp;
    u16 temp2;
    u8 r;
    u8 g;

    if (arg1 != 0) {
        temp = *(u16 *)((u8 *)arg0 + 0x44);
        temp2 = temp;
        if (D_800DCC1E != 0) {
            func_8006EA0C(temp);
        } else {
            D_800DCAAC = temp2;
        }
        r = 0xFF;
        g = 0x30;
        p = &D_800FBB90;
        p->r = r;
        p->g = g;
        p->b = g;
        D_800DCAA8 = 0x2C3030FF;
        D_800DCA9C = arg0;
    } else {
        D_800DCA9C = NULL;
    }
}
