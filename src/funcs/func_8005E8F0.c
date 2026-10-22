#include "common.h"

void func_8005E8F0(u8 *dst, u8 *src, s32 len) {
    s32 n;
    s32 rem;

    n = len >> 2;
    rem = len & 3;
    while (n > 0) {
        *(s32 *)dst = *(s32 *)src;
        src += 4;
        n--;
        dst += 4;
    }
    while (rem > 0) {
        *dst = *src;
        src++;
        rem--;
        dst++;
    }
}
