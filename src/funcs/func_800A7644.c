/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x38];
    u16 w;
    u16 h;
    u8 pad3C[0x1C];
    u8 *data;
} Img800A7644;

void func_800A7644(u8 *arg0) {
    Img800A7644 *img;
    s32 x;
    s32 y;
    s32 off;
    u8 *p;
    u8 *data;
    u32 stride;
    u32 v;
    s32 one;

    y = 0;
    one = 1;
    img = *(Img800A7644 **)(arg0 + 0x22C);
    off = 0;
    data = img->data;
    stride = ((u32)(img->w + 0xF) >> one) & 0xFFF8;
    while (1) {
        if (y >= (*(Img800A7644 **)(arg0 + 0x22C))->h) {
            break;
        }
        x = 0;
        while (1) {
            if (x >= (*(Img800A7644 **)(arg0 + 0x22C))->w) {
                break;
            }
            p = data + (x / 2 + off);
            if (x & 1) {
                v = *p >> 4;
            } else {
                v = *p & 0xF;
            }
            if (v == one) {
                if (x & 1) {
                    *p = *p & 0xF;
                } else {
                    *p = *p & 0xF0;
                }
            }
            x++;
        }
        off += stride;
        y++;
    }
}
