/* cflags: -O2 */
#include "common.h"

extern void func_80001EC0(void *, void *, s32);
extern u8 *func_8009FF00(u8 *);
extern u8 D_800220B0[];

static __inline__ u8 *tail(u8 *p) {
    *(s32 *)(p + 0x218) = 0;
    *(s32 *)(p + 0x214) = 0;
    *(s32 *)(p + 0x210) = 0;
    *(s32 *)(p + 0x21C) = 0;
    *(s32 *)(p + 0x1C8) = 1;
    return p;
}

u8 *func_800BB230(u8 *arg0) {
    func_8009FF00(arg0);
    *(u8 **)(arg0 + 0x1C4) = D_800220B0;
    func_80001EC0(arg0 + 0x1CC, arg0 + 0x1FC, 4);
    func_80001EC0(arg0 + 0x1E4, arg0 + 0x20C, 1);
    return tail(arg0);
}
