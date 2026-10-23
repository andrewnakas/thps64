/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 a;
    s32 key;
} Pair;

extern s32 D_800D36F0;
extern Pair D_800FA3D0[];
extern u8 D_800FA5A0[][0x30];
extern u8 D_800FA600[];

void func_8003546C(s32 arg0, s32 arg1) {
    s32 i;

    i = 0;
    if (D_800D36F0 != 0) {
        while (1) {
            if (i >= D_800D36F0) break;
            if (D_800FA3D0[i].key == arg0) {
                D_800FA5A0[arg1][D_800FA600[arg1]++] = i;
                return;
            }
            i++;
        }
    }
}
