/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 data[0x17C];
    u8 *slots[4];
} St800660C4;

extern St800660C4 D_800D49E0[];
extern s32 D_800DF384[][4];

void func_800660C4(void) {
    St800660C4 *e;
    s32 *kinds;
    s32 *k;
    s32 j;
    s32 i;
    u8 *cur;

    i = 0;
    while (1) {
        if (i >= 2) {
            break;
        }
        {
            St800660C4 *p = &D_800D49E0[i];
            kinds = D_800DF384[i];
            e = p;
        }
        for (j = 0, cur = (u8 *)e, k = kinds; j < 4; j++) {
            switch (*k) {
            case 0:
                e->slots[0] = cur;
                break;
            case 1:
                e->slots[1] = cur;
                break;
            case 2:
                e->slots[2] = cur;
                break;
            case 3:
                e->slots[3] = cur;
                break;
            }
            cur += 0x10;
            k++;
        }
        i++;
    }
}
