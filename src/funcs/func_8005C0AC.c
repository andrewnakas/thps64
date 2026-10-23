#include "common.h"

s32 func_8005C0AC(s32 a, s32 b) {
    s32 s;
    s32 d;

    if (a == b) {
        return a;
    }
    b -= a;
    s = (b < 0) ? -1 : 1; d = b; if (d < 0) { d = -d; }  if (d >= 13) { return a + s * 5; } else if (d >= 4) { return a + s * 3; } return a + s;
}
