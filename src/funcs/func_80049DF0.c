/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern volatile u32 D_800D6138;

void func_80049DF0(s32 arg0) {
    u32 end;

    end = D_800D6138 + arg0;
    while (D_800D6138 < end) {
    }
}
