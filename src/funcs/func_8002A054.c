/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-O0 */
#include "common.h"

typedef struct {
    u8 pad0[0x30];
    u8 spr30[0x14];
    u8 spr44[0x14];
    u8 spr58[2][0x14];
    u8 pad80[0x2C0 - 0x80];
    f32 t;
    u8 pad2C4[3];
    u8 a2C7;
    u8 pad2C8[3];
    u8 a2CB;
    u8 pad2CC[3];
    u8 a2CF;
    u8 pad2D0[0x2F0 - 0x2D0];
    s32 x2F0;
    s32 y2F4;
    s32 y2F8;
    s32 y2FC;
} Obj2A054;

void func_8002A25C(Obj2A054 *);
void func_800B231C(void *, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
extern s32 D_800F3294;

void func_8002A054(Obj2A054 *o) {
    s32 x;
    s32 i;

    if (o->t < 6.0f) {
        func_8002A25C(o);
    } else if (6.0f <= o->t && o->t < 16.0f) {
        func_800B231C(o->spr30, 0xFF, 0xFF, 0xFF, o->a2CB);
        func_800B1AC4(o->spr30, o->x2F0, o->y2F4, 1.0f, 1.0f);
    } else if (16.0f <= o->t && o->t < 26.0f) {
        func_800B231C(o->spr44, 0xFF, 0xFF, 0xFF, o->a2C7);
        func_800B1AC4(o->spr44, o->x2F0, o->y2F8, 1.0f, 1.0f);
    } else if (26.0f <= o->t && o->t < 36.0f) {
        x = (D_800F3294 - 0x240) / 2;
        for (i = 0; i < 2; i++) {
            func_800B231C(o->spr58[i], 0xFF, 0xFF, 0xFF, o->a2CF);
            func_800B1AC4(o->spr58[i], x + i * 0x120, o->y2FC, 1.0f, 1.0f);
        }
    }
}
