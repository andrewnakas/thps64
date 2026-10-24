/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8006A538(void *, s32);
void func_8006EC84(void *);

void func_80045E38(u8 *arg0) {
    s32 i;
    s32 sum;
    s32 n;
    s32 m;
    s32 t;
    s32 u;
    s32 mode;
    u8 *e;

    *(u16 *)(arg0 + 0xC) += 1;
    n = *(s32 *)(arg0 + 0x388);
    sum = 0;
    if (n > 0) {
        i = 0;
        if (i < n) {
            e = arg0;
            do {
                sum += *(s32 *)(e + 0x1FC);
                i++;
                e += 0x14;
            } while (i < n);
        }
        t = *(s32 *)(arg0 + 0x388) * 2;
        mode = *(s32 *)(*(u8 **)arg0 + 0x424);
        if (mode < 3) m = t + mode; else { u = t - 2; m = u + mode * 2; }
        sum = sum * m / 2;
    }
    func_8006A538(*(void **)arg0, -sum);
    if (*(s32 *)(arg0 + 0x154) != 0) {
        *(s32 *)(arg0 + 0x154) = 0;
        *(s32 *)(arg0 + 0x158) = 1;
        func_8006EC84(arg0 + 0x164);
    }
    *(s32 *)(arg0 + 0x388) = 0;
}
