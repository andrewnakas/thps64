#include "common.h"

typedef struct {
    u8 pad[0x14];
    s32 *list;
    u32 *countp;
    u8 pad2[0x2C];
} Elem48;

extern Elem48 D_800DAF98[];

s32 func_80063654(s32 arg0, s32 arg1) {
    Elem48 *e;
    Elem48 *base;
    s32 *p;
    u32 n;
    u32 i;

    base = D_800DAF98;
    e = &base[arg1];
    n = e->countp[-1];
    p = e->list;
    for (i = 0; i < n; i++) {
        if (*p == arg0) {
            return i;
        }
        p++;
    }
}
