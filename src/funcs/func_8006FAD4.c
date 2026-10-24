#include "common.h"

extern char *D_800DDC30;

void func_8006FAD4(s32 n) {
    s32 started;
    s32 d;
    s32 q;

    if (n < 0) {
        n = -n;
        *D_800DDC30++ = '-';
    }
    started = 0;
    d = 1000000000;
    while (1) {
        if (d <= 0) {
            break;
        }
        if (n >= d) {
            q = n / d;
            *D_800DDC30++ = q + '0';
            n -= q * d;
            started = 1;
        } else if (started || d == 1) {
            *D_800DDC30++ = '0';
        }
        d /= 10;
    }
    *D_800DDC30++ = 0;
}
