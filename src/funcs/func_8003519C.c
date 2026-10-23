/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s32 D_800D36F4;
extern s32 D_800FA550[];

void func_8003519C(s32 arg0) {
    s32 i;
    s32 j;

    i = 0;
    while (1) {
        if (i >= D_800D36F4) break;
        if (D_800FA550[i] == arg0) {
            for (j = i + 1; j < D_800D36F4; j++) {
                D_800FA550[j - 1] = D_800FA550[j];
            }
            D_800D36F4--;
            return;
        }
        i++;
    }
}
