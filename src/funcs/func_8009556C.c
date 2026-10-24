#include "common.h"

s32 func_8005EDD0();                                  /* extern */
s32 func_80061CC4(s32 *);                               /* extern */
extern s32 D_800200C8;
extern s32 D_800C0E20;
extern s32 D_800DACAC;

void func_8009556C(void) {
    s32 temp_s1;

    if (D_800C0E20 == 8) {
        temp_s1 = D_800DACAC;
        func_80061CC4(&D_800200C8);
        func_8005EDD0();
        D_800DACAC = temp_s1;
    }
}
