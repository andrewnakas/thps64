/* cflags: -Wa,-O0 */
#include "common.h"

extern f32 D_800D0FEC;

typedef struct {
    u8 pad0[0x109];
    u8 div;
} S8003A78C;

u8 func_8003A78C(S8003A78C *arg0, u16 arg1) {
    s32 n;

    n = arg1 / arg0->div;
    if (n >= 0x100) {
        f32 c;
        f32 t;
        u32 v;
        u32 m;

        t = D_800D0FEC * 255.0f;
        if (!(t >= (c = 2147483648.0f))) {
            v = (s32) t;
        } else {
            f32 d = t - c;
            m = 0x80000000;
            v = (s32) d | m;
        }
        return v;
    }
    if (n < 0) {
        return 0;
    }
    {
        f32 c;
        f32 t;
        u32 v;
        u32 m;

        c = n;
        t = D_800D0FEC;
        t = t * c;
        if (!(t >= (c = 2147483648.0f))) {
            v = (s32) t;
        } else {
            f32 d = t - c;
            m = 0x80000000;
            v = (s32) d | m;
        }
        return v;
    }
}
