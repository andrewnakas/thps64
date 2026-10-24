/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
extern char D_8001A038[];
extern char D_8001A03C[];

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
    s32 unk38;
    s32 x;
    s32 y0;
    s32 y1;
    u8 pad48[0x80 - 0x48];
    u8 text[1];
} Obj_8003B2D8;

void func_8003B2D8(Obj_8003B2D8 *arg0) {
    if (arg0->unk34 != 0) {
        func_800A7AF8(arg0->text, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(arg0->text, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A8678(arg0->text, D_8001A038, arg0->x, arg0->y0, 0, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    } else {
        func_800A7AF8(arg0->text, 0xF, 0x4A, 0x7B, 0xFF);
        func_800A7B10(arg0->text, 0xF, 0x4A, 0x7B, 0xFF);
        func_800A8678(arg0->text, D_8001A03C, arg0->x, arg0->y0, 0, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    }
    if (arg0->unk38 != 0) {
        func_800A7AF8(arg0->text, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(arg0->text, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A8678(arg0->text, D_8001A038, arg0->x, arg0->y1, 0, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    } else {
        func_800A7AF8(arg0->text, 0xF, 0x4A, 0x7B, 0xFF);
        func_800A7B10(arg0->text, 0xF, 0x4A, 0x7B, 0xFF);
        func_800A8678(arg0->text, D_8001A03C, arg0->x, arg0->y1, 0, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    }
}
