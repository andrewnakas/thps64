/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8003C764(void *);
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);

typedef struct {
    char text[0x30];
    u8 type;
    u8 pad31[0xF];
} Line_8003BF24;

typedef struct {
    u8 pad0[0x241];
    s8 count;
    u8 pad242;
    u8 mode;
    u8 pad244[0x250 - 0x244];
    f32 y;
    f32 unk254;
    u8 pad258[0x260 - 0x258];
    s32 unk260;
    f32 scale;
    f32 unk268;
    Line_8003BF24 lines[1];
} Menu_8003BF24;

void func_8003BF24(Menu_8003BF24 *arg0) {
    f32 twenty;
    f32 dy;
    f32 y;
    f32 scale;
    s32 i;
    s32 t;

    if (arg0->mode == 2) {
        func_8003C764(arg0);
        return;
    }
    twenty = 20.0f;
    dy = -(*(f32 *)((u8 *)arg0 + 0x2A8) + arg0->unk254) * arg0->unk268;
    y = arg0->y;
    scale = arg0->scale * 1.2;
    for (i = 0; i < arg0->count; i++) {
        t = arg0->lines[i].type;
        if (t == 2) {
            func_800A7AF8(arg0, 0xFC, 0xC2, 0x6B, 0xFF);
            func_800A7B10(arg0, 0xFC, 0xC2, 0x6B, 0xFF);
            func_800A773C(arg0, scale, scale);
        } else if (t == 1) {
            func_800A7AF8(arg0, 0x87, 0xC2, 0xF3, 0xFF);
            func_800A7B10(arg0, 0x87, 0xC2, 0xF3, 0xFF);
            func_800A773C(arg0, arg0->scale, arg0->scale);
        } else if (t == 3) {
            func_800A7AF8(arg0, 0xF, 0x4A, 0x7B, 0xFF);
            func_800A7B10(arg0, 0xF, 0x4A, 0x7B, 0xFF);
            func_800A773C(arg0, arg0->scale, arg0->scale);
        }
        if (arg0->mode == 1) {
            func_800A8678(arg0, (char *)arg0 + (i * 0x40 + 0x26C), (f32)arg0->unk260, y, 2, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
        } else {
            func_800A8678(arg0, (char *)arg0 + (i * 0x40 + 0x26C), twenty, y, 0, 0, 6.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
        }
        y += dy;
    }
}
