/* cflags: -O2 */

#include "common.h"

typedef struct {
    u8 pad0[0x38];
    u16 width;
    u16 height;
    u8 pad3C[3];
    u8 bits;
    u8 pad40[0x58 - 0x40];
    u32 *data;
} Tex800A73EC;

typedef struct {
    u8 pad0[4];
    Tex800A73EC *tex;
} Res800A73EC;

typedef struct {
    u8 pad0[8];
    s32 avg;
    s32 count;
    u8 pad10[4];
    s32 id;
    u8 pad18[4];
    s32 unk1C;
    u8 pad20[4];
    s16 ends[64];
    s16 starts[64];
    u8 pad124[0x22C - 0x124];
    Tex800A73EC *tex;
} Font800A73EC;

extern void func_800A73AC(Font800A73EC *);
extern void func_800A7708(Font800A73EC *, s32);
extern Res800A73EC *func_800BAB04(void *, s32);
extern u8 D_800EECF0[];

void func_800A73EC(Font800A73EC *arg0, s32 arg1) {
    Tex800A73EC *tex;
    s32 per;
    s32 x;
    s32 in;
    s32 n;
    s32 col;
    s32 cols;
    s32 y;
    s32 idx;
    u32 mask;
    s32 j;
    s32 h;
    u32 *data;
    s32 i;
    s32 last;
    s32 end;

    func_800A73AC(arg0);
    arg0->tex = func_800BAB04(D_800EECF0, arg1)->tex;
    arg0->id = arg1;
    tex = arg0->tex;
    per = 32 / tex->bits;
    x = 0;
    in = 1;
    n = 0;
    col = 0;
    h = tex->height;
    data = tex->data;
    cols = tex->width / per;
    arg0->starts[0] = 1;
    while (1) {
        if (col >= cols) {
            break;
        }
        mask = 0;
        if (col != 0) {
            y = 0;
            while (1) {
                if (y >= h) {
                    break;
                }
                idx = col + y * cols;
                if (y & 1) {
                    if (col & 1) {
                        idx--;
                    } else {
                        idx++;
                    }
                }
                mask |= data[idx];
                if (mask == 0xFFFFFFFF) {
                    break;
                }
                y++;
            }
        } else {
            mask = 0xFFFFFFFF;
        }
        for (j = 0; j < 8; j++) {
            if (mask & (0xF << ((7 - x++ % 8) * 4))) {
                if (in == 0) {
                    in = 1;
                    arg0->starts[n] = x - 1;
                }
            } else {
                end = x - 2;
                if (in != 0) {
                    in = 0;
                    arg0->ends[n] = end;
                    n++;
                }
            }
        }
        col++;
    }
    arg0->avg = 0;
    last = n - 1;
    for (i = 0; i < last; i++) {
        arg0->avg += arg0->ends[i] - arg0->starts[i] + 1;
    }
    if (n >= 2) {
        arg0->avg /= n - 1;
    }
    arg0->count = n;
    func_800A7708(arg0, arg0->unk1C);
}
