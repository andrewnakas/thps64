/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s32 D_800FA970;
extern s32 D_800FA974;
extern s32 D_800FA978;

void func_80048BB4(u16 *arg0, s32 arg1) {
    s32 i;
    s32 r;
    s32 b;
    s32 c;
    u16 *q;
    u16 tmp;

    i = 0;
    while (1) {
        if (i >= arg1) {
            break;
        }
        tmp = arg0[i];
        r = D_800FA970 * D_800FA974 + D_800FA978;
        D_800FA970 = r;
        b = D_800FA974;
        b ^= r;
        b += r >> 4;
        D_800FA974 = b;
        c = D_800FA978;
        c += 0xEFEFEFF0;
        c += r >> 3;
        D_800FA978 = c;
        q = (u16 *)(((((r & 0xFFFF) * arg1) >> 16) * 2) + (s32)arg0);
        arg0[i] = *q;
        *q = tmp;
        i++;
    }
}
