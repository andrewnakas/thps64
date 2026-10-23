/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800696B0(s32, void *, s32);

void func_8005C2EC(u8 *arg0) {
    s32 i;
    s32 n;
    s32 sum;
    s32 t;
    s32 mode;
    s32 prod;
    u8 *e;
    s32 unused[2];

    if (*(s32 *)(arg0 + 0x510) != 0 && *(s32 *)(arg0 + 0x514) != 0) {
        i = 0;
        n = *(s32 *)(arg0 + 0xDA4);
        sum = 0;
        if (n > 0) {
            e = arg0;
            do {
                sum += *(s32 *)(e + 0xC18);
                i++;
                e += 0x14;
            } while (i < n);
        }
        t = *(s32 *)(arg0 + 0xDA4) * 2;
        mode = *(s32 *)(arg0 + 0x424);
        if (mode < 3) {
            sum = (sum * (t + mode)) / 2;
        } else {
            prod = t - 2;
            sum = (sum * (prod + mode * 2)) >> 1;
        }
        if (sum > 0) {
            func_800696B0(*(s32 *)(arg0 + 0x510), arg0, sum);
        }
    }
}
