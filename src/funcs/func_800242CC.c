/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
typedef struct {
    u8 count;
    u8 num;
    u8 first;
    u8 second;
    u8 pad4[0x20];
    u8 present[2];
    u8 list[2];
} Ctl800242CC;
s32 func_800B3CF0(s32);
extern Ctl800242CC D_800D0FC0;
void func_800242CC(void) {
    s32 i;

    D_800D0FC0.count = 0;
    D_800D0FC0.num = 0;
    D_800D0FC0.first = 4;
    D_800D0FC0.second = 4;
    for (i = 0; i < 2; i++) {
        if (func_800B3CF0(i) != 0) {
            if (i < D_800D0FC0.first) {
                D_800D0FC0.first = i;
            } else if (i < D_800D0FC0.second) {
                D_800D0FC0.second = i;
            }
            D_800D0FC0.count++;
            D_800D0FC0.list[D_800D0FC0.num++] = i;
            D_800D0FC0.present[i] = 1;
        } else {
            D_800D0FC0.present[i] = 0;
        }
    }
}
