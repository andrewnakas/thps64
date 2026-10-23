/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern void func_80039E60(s32, s32, s32);
extern void func_800B1A80(void *, s32);
extern s32 D_80019C38;
extern s32 D_80019C3C;
extern s32 D_80019C40;

void func_80032B18(s32 a0, u8 *a1, void *a2, s16 *a3) {
    func_80039E60(0x90, 10000, 0);
    switch (*a3) {
    case 1:
        if (*a1 == 0) {
            *a1 = 1;
            func_800B1A80(a2, D_80019C3C);
        } else if (*a1 == 1) {
            *a1 = 2;
            func_800B1A80(a2, D_80019C40);
        } else {
            *a1 = 0;
            func_800B1A80(a2, D_80019C38);
        }
        break;
    case 2:
        if (*a1 == 0) {
            *a1 = 2;
            func_800B1A80(a2, D_80019C40);
        } else if (*a1 == 1) {
            *a1 = 0;
            func_800B1A80(a2, D_80019C38);
        } else {
            *a1 = 1;
            func_800B1A80(a2, D_80019C3C);
        }
        break;
    }
}
