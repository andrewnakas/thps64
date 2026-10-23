/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x1C];
    s32 grid[20][20];
} Board;

extern Board D_800D7720[];

void func_8005E32C(s32 arg0) {
    s32 i;
    s32 j;

    if (arg0 < 2) {
        D_800D7720[arg0].unk0 = 0;
        i = 0;
        while (1) {
            if (i >= 20) {
                break;
            }
            for (j = 0; j < 20; j++) {
                D_800D7720[arg0].grid[i][j] = 0;
            }
            i++;
        }
    }
}
