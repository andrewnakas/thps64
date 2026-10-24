/* cflags: -O2 */
#include "common.h"

s32 func_800ABFC4(s32, s32);                    /* extern */

void func_800A8EF0(void *arg0, f32 arg1) {
    f32 f;
    u32 v;

    if (*(s32 *)arg0 != 0) {
        if (arg1 > 1.0) {
            arg1 = 1.0f;
        }
        if (arg1 < 0.0) {
            arg1 = 0.0f;
        }
        f = arg1 * 255.0f;
        *(s32 *)((u8 *)arg0 + 0x64) = (s32) (arg1 * 32767.0f);
        if (f >= 2147483648.0f) {
            goto big;
        }
        v = (s32) f;
        goto end;
    big:
        v = (s32) (f - 2147483648.0f);
        v |= 0x80000000;
    end:
        func_800ABFC4(*(s32 *)((u8 *)arg0 + 0x50), v & 0xFF);
    }
}
