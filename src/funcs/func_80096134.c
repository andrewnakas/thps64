/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
#include "types/object.h"

void func_80096134(MenuList *arg0) {
    s32 cnt;
    s32 i;
    s32 sum;

    cnt = 0;
    sum = 0;
    for (i = 0; i < arg0->unk5; i++) {
        if (arg0->rows[i].unkD != 0) {
            sum += arg0->rows[i].unkC;
            cnt++;
        }
    }
    arg0->unkC = (0xF0 - ((cnt - 1) * arg0->unk10 + sum)) / 2;
}
