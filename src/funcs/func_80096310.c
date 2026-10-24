#include "common.h"

s32 func_8006DF40(s32, s32, s32 *, s32, s32, s32, s32); /* extern */
s32 func_8006E590();                            /* extern */
s32 func_8006EBB0(s32 *, s32, s32, s32); /* extern */
s32 func_8006F1A8(s32, s32, s32, s32); /* extern */
s32 func_8006F23C(s32);                     /* extern */
s32 func_8006F274(s32);                     /* extern */
s32 func_80073280();                            /* extern */
s32 func_800732A0(s32, s32, s32, s32); /* extern */
extern s32 D_8001FD5C;
extern s32 D_8001FD68;
extern s32 D_800DE7E4;

void func_80096310(void) {
    s32 var_s0;

    func_8006EBB0(&D_8001FD5C, -1, -1, -1);
    var_s0 = 0;
    do {
        var_s0 += 1;
        func_80073280();
        D_800DE7E4 = 0;
        func_800732A0(0, 0, 0x280, 0x1E0);
        func_8006F274(0);
        func_8006F23C(0x180);
        func_8006F1A8(0x96, 0x64, 0x19, 0);
        func_8006DF40(0x140, 0xF0, &D_8001FD68, 1, 0, 0x100, 0);
    } while (var_s0 < 2);
    func_8006E590();
}
