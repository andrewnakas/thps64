/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern void func_8006DF40(s32, s32, u8 *, s32, s32, s32, s32);
extern void func_8006F1A8(s32, s32, s32, s32);
extern void func_8006F23C(s32);
extern void func_8006F274(s32);
extern u8 D_8001FD74[];
extern u8 D_8001FD80[];
extern u8 D_800DF3F4[];

void func_8008C000(s32 *arg0) {
    u8 buf[0x20];
    s32 i;
    s32 n;
    u8 *src;
    u8 *dst;

    func_8006F23C(0x100);
    func_8006F274(0);
    i = 0;
    while (1) {
        src = D_800DF3F4;
        if (i >= 2) break;
        n = arg0[i];
        dst = buf;
        while (*src != 0) {
            if (n != 0) {
                n--;
                *dst++ = *src++;
            } else {
                *dst++ = '-';
                src++;
            }
        }
        *dst = 0;
        if (i == 0) {
            func_8006F1A8(0x50, 0x50, 0x80, 0);
            func_8006DF40(0x56, 0x20, D_8001FD74, 0, 0, 0x100, 0);
        } else {
            func_8006F1A8(0x80, 0x50, 0x50, 0);
            func_8006DF40(0x1AA, 0x20, D_8001FD80, 0, 0, 0x100, 0);
        }
        func_8006DF40(0x1AA - (1 - i) * 0x154, 0x30, buf, 0, 0, 0x100, 0);
        i++;
    }
}
