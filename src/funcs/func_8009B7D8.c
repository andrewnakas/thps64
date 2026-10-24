/* cflags: -O2 */
#include "common.h"

s32 func_8009B988(void *, s32);                     /* extern */
s32 func_8009E6B4(s32 *, s32, s32);         /* extern */
s32 func_800B2CF0(s32, s32, s32, s32);          /* extern */
extern s32 D_800EA110;

s32 func_8009B7D8(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s3;
    s32 temp_v0;

    temp_s3 = (*(s32 *)((u8 *)arg1 + 4)) + func_8009B988(arg1, arg2);
    temp_s0 = func_8009B988(arg1, arg2 + 1);
    temp_s0_2 = ((temp_s0 - func_8009B988(arg1, arg2)) + 1) & ~1;
    temp_v0 = func_8009E6B4(&D_800EA110, temp_s0_2, arg3);
    if (temp_v0 != 0) {
        func_800B2CF0(arg0 + 0xC, temp_s3, temp_s0_2, temp_v0);
    }
    return temp_v0;
}
