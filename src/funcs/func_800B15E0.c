/* cflags: -O2 */
#include "common.h"

typedef struct { u32 w0, w1; } G800B15E0;
typedef struct { u8 pad[4]; G800B15E0 *(*fn)(void *, G800B15E0 *); } VE800B15E0;
typedef struct { u8 pad[0x44]; VE800B15E0 *e; } C800B15E0;

extern C800B15E0 *D_800ECC34;

G800B15E0 *func_800B15E0(void *arg0, G800B15E0 *g) {
    G800B15E0 *h;

    { G800B15E0 *_g = g++; _g->w0 = 0x020004E0; _g->w1 = 0x2E0; }
    h = D_800ECC34->e->fn(arg0, g);
    { G800B15E0 *_g = h++; _g->w0 = 0x0C007FFF; _g->w1 = 0x07C004E0; }
    { G800B15E0 *_g = h++; _g->w0 = 0x0C007FFF; _g->w1 = 0x09300650; }
    return h;
}
