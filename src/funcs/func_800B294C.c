/* cflags: -O2 */
#include "common.h"

s32 func_80001EC0(s32 *, s32 *, s32); /* extern */
s32 func_80004ED0(s32 *, s32, s32); /* extern */
s32 func_80005070(s32 *, s32, s32); /* extern */
s32 func_800B2A10();                            /* extern */
s32 func_800B2BF4(s32, s32 *, s32 *, s32);  /* extern */
extern s32 D_800ECF40;
extern s32 D_800ECF50;
extern s32 D_800ECF54;
extern s32 D_800ECF70;
extern s32 D_800ECF78;
extern s32 D_800ECF84;
extern s32 D_800ECF9C;

s32 func_800B294C(s32 arg0, s32 arg1) {
    s32 temp_s0;

    func_800B2A10();
    func_80005070(&D_800ECF54, 0, 1);
    func_80001EC0(&D_800ECF84, &D_800ECF9C, 1);
    (*(s32 *)((u8 *)(&D_800ECF40) + 0)) = 8;
    (*(s32 *)((u8 *)(&D_800ECF40) + 4)) = 0xC;
    D_800ECF78 = arg0;
    (*(s32 *)((u8 *)(&D_800ECF40) + 0xC)) = 0;
    (*(s32 *)((u8 *)(&D_800ECF40) + 8)) = 0;
    D_800ECF70 = arg1;
    temp_s0 = func_800B2BF4(arg0, &D_800ECF40, &D_800ECF50, arg1);
    func_80004ED0(&D_800ECF54, 0, 1);
    return temp_s0;
}
