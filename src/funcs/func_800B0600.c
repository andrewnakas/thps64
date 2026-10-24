/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x4];
    s32 *unk1C;
} List800B0600;

typedef struct {
    u8 pad0[0x48];
    List800B0600 *unk48;
} Clk800B0600;

extern u32 *func_800AE7D0(s32, s32, u32 *);
extern Clk800B0600 *D_800ECC34;

u32 *func_800B0600(s32 arg0, u32 *arg1) {
    u32 *g;
    u32 *h;
    List800B0600 *l;
    s32 i;
    s32 *q;

    g = arg1;
    h = g;
    g += 2;
    l = D_800ECC34->unk48;
    q = l->unk1C;
    h[0] = 0x020007C0;
    h[1] = 0x2E0;
    for (i = 0; i < l->unk14; i++) {
        g = func_800AE7D0(q[i], arg0, g);
    }
    return g;
}
