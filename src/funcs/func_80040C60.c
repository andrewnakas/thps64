/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} Track40C60;

typedef struct {
    u8 pad0[0xC];
    u8 flags[20][20];
} State40C60;

typedef struct {
    u8 pad0[0x14];
    u8 unk14;
} Game40C60;

typedef struct {
    u8 pad0[0x2AC];
    u16 x;
    u16 y;
    u8 pad2B0[0x2F0 - 0x2B0];
    f32 scale;
    u8 pad2F4[0x394 - 0x2F4];
    u8 spr394[0x14];
    u8 spr3A8[0x850 - 0x3A8];
    u8 spr850[0x14];
    u8 spr864[0x14];
    u8 spr878[0x14];
} Hud40C60;

void func_800B1AC4(void *, f32, f32, f32, f32);
extern s32 D_800C0E20;
extern Track40C60 D_800D5C1C[];
extern State40C60 D_800DE9F4;
extern Game40C60 D_800D0FC0;

#define FLAGS() (D_800DE9F4.flags[D_800D0FC0.unk14][D_800C0E20])

void func_80040C60(Hud40C60 *arg0) {
    s32 i;
    s32 x;

    if (D_800D5C1C[D_800C0E20].unkC == 0) {
        x = 250;
        for (i = 0; i < 5; i++) {
            if ((FLAGS() >> i) & 1) {
                func_800B1AC4(arg0->spr3A8, x, arg0->y, 1.0f, 1.0f);
            } else {
                func_800B1AC4(arg0->spr394, x, arg0->y, 1.0f, 1.0f);
            }
            x += 50;
        }
        return;
    }
    if ((FLAGS() & 0x80) && !(FLAGS() & 0x40) && !(FLAGS() & 0x20)) {
        func_800B1AC4(arg0->spr850, arg0->x, arg0->y, arg0->scale, arg0->scale);
    } else if ((FLAGS() & 0x40) && !(FLAGS() & 0x20)) {
        func_800B1AC4(arg0->spr864, arg0->x, arg0->y, arg0->scale, arg0->scale);
    } else if (FLAGS() & 0x20) {
        func_800B1AC4(arg0->spr878, arg0->x, arg0->y, arg0->scale, arg0->scale);
    }
}
