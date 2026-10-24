/* cflags: -O2 */
#include "common.h"

extern void func_800A4418(u8 *, f32, f32, f32, f32, f32, f32);
extern void func_800A4D48(u8 *);

void func_800A57E0(u8 *arg0, s32 arg1) {
    s32 i;
    f32 s;

    s = 0.952380955f;
    for (i = 1; i < arg1; i++) {
        s *= 0.95238095238095233;
    }
    func_800A4418(arg0, *(f32 *)(arg0 + 0x160) * s, *(f32 *)(arg0 + 0x164) * s, *(f32 *)(arg0 + 0x168) * s,
                  *(f32 *)(arg0 + 0x16C) * s, *(f32 *)(arg0 + 0x170) * s, *(f32 *)(arg0 + 0x174));
    func_800A4D48(arg0);

}
