#include "common.h"

s32 *func_80063454(u8 *arg0) {
    s32 *p;
    s32 n;

    p = (s32 *)(arg0 + *(s32 *)(arg0 + 4));
    while (1) {
        if (*p == -1) break;
        p++;
        n = *p;
        p++;
        p = (s32 *)((u8 *)p + n);
    }
    return p + 1;
}
