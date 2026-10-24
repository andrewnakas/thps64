/* cflags: -O2 */
#include "common.h"

extern void func_80003010(s32);
extern void func_80011680(f32);
extern void func_8009ECF8(void *, void *);
extern void func_800B28C0(void);
extern void func_800BC0F4(void *);
extern u8 D_800EA110[];
extern u8 D_800F0DD0[];
extern s32 D_800F32A8;
extern s32 D_800F36A0;
extern void *D_800F5630[];

void func_800BDCC8(void) {
    s32 i;

    func_800B28C0();
    func_800BC0F4(D_800F0DD0);
    i = 0;
    func_80011680(1.0f);
    func_80003010(1);
    for (; i < D_800F36A0; i++) {
        func_8009ECF8(D_800EA110, D_800F5630[i]);
    }
    D_800F36A0 = 0;
    D_800F32A8 = 0;
}
