/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800C000C;

extern void func_80001A30(s32, s32);
extern s32 func_800BD9F4(void);
extern Gfx800C000C *D_800F36A4;

s32 func_800C000C(s32 arg0) {
    s32 m;

    m = func_800BD9F4();
    func_80001A30(arg0, m);
    {
        Gfx800C000C *_g = D_800F36A4++;
        _g->w0 = 0xDA380003;
        _g->w1 = (u32)m;
    }
    return m;
}
