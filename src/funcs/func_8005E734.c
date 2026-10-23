#include "common.h"

extern s16 D_800D9D6C[];
extern s32 D_800D9D60;
void func_8005E6B4(s32, s32);
void func_8005E5CC(s32, s32, s32);

void func_8005E734(void) {
    s32 i, j;
    s16 *p;
    func_8005E6B4(0x200, 0xF0);
    func_8005E5CC(0xA, 0x1770, 0x800);
    p = D_800D9D6C;
    for (i = 15; i >= 0; i--) {
        for (j = 0xFC0; j >= 0; j -= 0x40) {
            *p++ = 0;
        }
    }
    D_800D9D60 = 0x80000000;
}
