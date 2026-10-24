/* cflags: -O2 */
#include "common.h"

typedef struct { u32 w0, w1; } Gfx8;
extern Gfx8 *func_800B15E0(void);
extern u8 *D_800ECC34;

Gfx8 *func_800B1590(void) {
    Gfx8 *g = func_800B15E0();
    {
        Gfx8 *_g = g++;
        _g->w0 = 0xD000000;
    }
    {
        Gfx8 *_g = g++;
        _g->w0 = 0x62E0000;
        _g->w1 = *(u32 *)(D_800ECC34 + 0x5C);
    }
    return g;
}
