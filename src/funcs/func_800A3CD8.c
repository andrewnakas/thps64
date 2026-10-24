/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    s32 sel;
    u8 pad1C[0x1AC - 0x1C];
    u8 text[0x10];
    u8 unk1BC;
    u8 pad1BD[0x434 - 0x1BD];
    s32 unk434;
    u8 pad438[0x460 - 0x438];
    s32 big;
    u8 pad464[4];
    s32 unk468;
} Menu800A3CD8;

extern s32 func_800A0670(Menu800A3CD8 *, s32, s32);
extern void func_800A773C(void *, f32, f32);
extern void func_800A7B28(void *, s32, s32, s32, s32);
extern void func_800A8678(void *, s32, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_800F3294;
extern s32 D_800F3298;

void func_800A3CD8(Menu800A3CD8 *arg0, s32 *arg1, s32 arg2) {
    f32 scale;
    f32 sel;
    f32 w0;
    f32 h0;
    f32 h1;
    f32 w1;
    s32 y;
    s32 i;
    s32 off;

    scale = 0.85f;
    y = D_800F3298 / 2 - 0x14;
    if (arg0->big != 0) {
        scale = 1.0f;
    }
    w0 = scale * 0.8;
    sel = scale * 1.2f;
    w1 = sel * 0.8;
    h0 = scale;
    h1 = sel;
    i = 0;
    while (1) {
        if (i >= arg2) break;
        off = 0;
        if (i == arg0->sel) {
            func_800A773C(arg0->text, w1, h1);
            func_800A7B28(arg0->text, 0xFF, 0xFA, 0x44, 0xFF);
            if (arg0->unk468 != 0) {
                off = (func_800A0670(arg0, arg0->unk434, 0x8000) != 0) * 2;
            }
        } else {
            func_800A773C(arg0->text, w0, h0);
            func_800A7B28(arg0->text, 0xD3, 0xD3, 0xD3, 0xFF);
        }
        arg0->unk1BC = 0;
        func_800A8678(arg0->text, arg1[i], D_800F3294 / 2 + off, y - off, 2, 2, 1.0f, 0xFF, 0x64, 1, 0, 0, 0, 0);
        i++;
        y += (s32)(scale * -30.0f);
    }
    func_800A773C(arg0->text, 1.0f, 1.0f);
}
