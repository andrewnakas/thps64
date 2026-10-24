#include "common.h"

extern u8 D_800D0FD4;
extern u8 D_800DE9F4[][20];

void func_8002EC18(u8 *arg0) {
    u8 *e;
    s32 v;

    u8 (*t)[20] = D_800DE9F4;
    e = t[D_800D0FD4];
    if ((e[15] & 0x20) && (e[18] & 0x20) && (e[20] & 0x20)) {
        v = D_800D0FD4 == 0 ? 0x1D : 0x1C;
    } else {
        v = 0x19;
    }
    *(s32 *) (arg0 + 0x5C8) = v;
}
