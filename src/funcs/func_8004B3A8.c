#include "common.h"

typedef struct {
    u16 flags;
    u8 pad2[0x1E];
    u32 color;
    u8 pad24[0x10];
    u32 nextColor;
    u8 pad38[8];
    u16 timer;
    s16 db;
    s16 dg;
    s16 dr;
} Obj8004B3A8;

void func_8004B3A8(Obj8004B3A8 *arg0) {
    u32 c;
    s32 b;
    s32 g;
    s32 r;

    if (arg0->timer != 0) {
        arg0->flags |= 0x400;
        c = arg0->color;
        b = c & 0xFF;
        g = (c >> 8) & 0xFF;
        r = (c >> 16) & 0xFF;
        b += arg0->db;
        g += arg0->dg;
        r += arg0->dr;
        arg0->color = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
        arg0->timer--;
        if (arg0->timer == 0) {
            if (arg0->nextColor & 0x02000000) {
                arg0->flags |= 0x400;
            } else {
                arg0->flags &= ~0x400;
            }
            arg0->color = arg0->nextColor;
            arg0->nextColor = 0;
        }
    }
}
