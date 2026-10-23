/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern u8 *D_800D61A8;
extern s32 D_800DC610;
extern s32 D_800DDC60;
extern s32 D_800D6180;
void func_8004AD90(s32);
void func_8006B78C(void *, s32);
void func_8004ACF0(void *);
void func_8004A89C(void *);

void func_8006D034(s32 n) {
    u8 *a;
    void *b;
    s32 i;

    a = D_800D61A8;
    b = *(void **)(a + 0x1C);
    D_800DC610 = 1;
    for (i = 0; i < n; i++) {
        func_8004AD90(D_800DDC60);
        func_8004AD90(D_800D6180);
        func_8006B78C(a, -1);
        if (b != NULL) {
            func_8006B78C(b, -1);
        }
        func_8004ACF0(&D_800D6180);
        func_8004A89C(&D_800DDC60);
    }
    D_800DC610 = 0;
}
