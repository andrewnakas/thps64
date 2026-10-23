/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s32 D_800DACC4;
extern void func_8005EA48(s32);

void func_800619B8(void) {
    if (D_800DACC4 != 0) {
        func_8005EA48(D_800DACC4);
    }
    D_800DACC4 = 0;
}
