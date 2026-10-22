#include "common.h"

void func_8002EA7C(u8 *arg0) {
    s32 i;
    s16 *p;
    s16 v;

    v = -0x2D;
    i = 4;
    p = (s16 *)arg0 + i;
    do {
        *(s16 *)((u8 *)p + 0x828) = v;
        i--;
        p--;
    } while (i >= 0);
}
