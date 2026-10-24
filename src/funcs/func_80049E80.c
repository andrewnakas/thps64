#include "common.h"

typedef struct {
    u16 flags;
    u8 pad2[0x20 - 2];
    u32 color;
    u8 pad24[0x34 - 0x24];
    u32 color2;
    u8 pad38[0x40 - 0x38];
    u16 count;
    s16 dr;
    s16 dg;
    s16 db;
} S80049E80;

void func_80049E80(S80049E80 *o, s32 n, u8 r, u8 g, u8 b) {
    s32 value;

    if (n == 0) {
        o->count = 0;
    } else if (n < 0) {
        o->count = -n;
        o->dr = (r - 0x80) / o->count;
        o->dg = (g - 0x80) / o->count;
        o->db = (b - 0x80) / o->count;
        o->color = 0x808080;
        goto end;
    } else {
        o->count = n + 1;
        o->dr = (0x80 - r) / n;
        o->dg = (0x80 - g) / n;
        value = (0x80 - b) / n;
        o->db = value;
        if (!(o->color2 & 0x1000000)) {
            o->color2 = (o->color & 0xFFFFFF) | 0x1000000;
            if (o->flags & 0x400) {
                o->color2 |= 0x2000000;
            }
        }
    }
    value = b << 16;
    value |= g << 8;
    value |= r;
    o->color = value;
end:
    o->flags |= 0x400;
}
