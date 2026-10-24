/* cflags: -O2 */
#include "common.h"

s32 func_8000B470(u8 *, s32, s32);
void func_800A04D8(u8 *, s32);
void func_800A08F0(u8 *, s32, s32, s32);
void func_800A0E74(u8 *, s32, s32);
extern s32 D_800EA550;

s32 func_800A1504(u8 *arg0, s32 arg1) {
    s32 r;
    s32 st;

    r = func_8000B470(arg0 + 0x3EC, arg1, *(s32 *)(arg0 + 0x434));
    while (1) {
        if (r != 2) break;
        func_800A04D8(arg0, *(s32 *)(arg0 + 0x434));
        r = func_8000B470(arg0 + 0x3EC, arg1, *(s32 *)(arg0 + 0x434));
    }
    switch (r) {
    case 0:
        return 1;
    case 10:
        func_800A0E74(arg0, 1, D_800EA550);
        st = 0xB;
        break;
    default:
        func_800A08F0(arg0, r, D_800EA550, *(s32 *)(arg0 + 0x418));
        st = 0xA;
        break;
    }
    *(s32 *)arg0 = st;
    return 0;
}
