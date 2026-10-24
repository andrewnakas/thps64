/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800C0070;

extern Gfx800C0070 *D_800F36A4;
extern u8 D_800FC8D0[];

void func_800C0070(void) {
    Gfx800C0070 *g;

    g = D_800F36A4++;
    g->w0 = 0xDA380003;
    g->w1 = (u32) D_800FC8D0;
}
