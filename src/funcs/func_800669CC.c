/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i_669CC;

typedef struct {
    u8 pad0[0x4];
    Vec3i_669CC pos; /* 0x04 */
    u8 sub10[0x74]; /* 0x10 */
    Vec3i_669CC vel; /* 0x84 */
    u8 pad90[0x10];
    s32 accel; /* 0xA0 */
    u8 padA4[0x12];
    u8 drag; /* 0xB6 */
    u8 padB7;
    u8 subB8[0x68]; /* 0xB8 */
    Vec3i_669CC pos120; /* 0x120 */
    u8 pad12C[0x24];
    s16 f150;
    s16 f152;
    u8 pad154[0xBE];
    u8 f212;
    u8 f213;
    u8 f214;
    u8 pad215[3];
    s32 f218;
    Vec3i_669CC base; /* 0x21C */
    u16 phase; /* 0x228 */
    u16 pad22A;
    u16 amp; /* 0x22C */
    u16 speed; /* 0x22E */
} Obj669CC;

f32 func_80001CA0(f32);
void func_80046C1C(void *, void *);
void func_80046D00(void *);
void func_800472C0(Vec3i_669CC *, Vec3i_669CC *);
s32 func_80048DCC(Vec3i_669CC *, s32, s32);
extern s32 D_800DE808;

void func_800669CC(Obj669CC *arg0) {
    s32 r;
    s32 vy;
    s32 vy2;
    s32 t;
    s32 a;
    s32 s;
    s32 m;
    s16 d;

    func_80046C1C(arg0->sub10, arg0->subB8);
    func_80046D00(arg0->sub10);
    if (arg0->f212 != 0) {
        if (arg0->f213 == 0 && arg0->f218 < 0 && arg0->f218 >= -4) {
            if (D_800DE808 & 1) {
                r = func_80048DCC(&arg0->base, 0, 8000);
                if (r == -1) {
                    arg0->f218--;
                    if (arg0->f218 < -4) {
                        arg0->f213 = 1;
                    }
                } else {
                    arg0->f218 = r;
                }
            }
        } else {
            func_800472C0(&arg0->base, &arg0->vel);
            vy = arg0->vel.y + arg0->accel;
            arg0->vel.y = vy;
            vy2 = vy - (vy >> arg0->drag);
            arg0->vel.y = vy2;
            if (arg0->f213 == 0) {
                t = arg0->f218 - (arg0->f214 << 12);
                if (t < arg0->base.y && vy2 > 0) {
                    arg0->base.y = t;
                    arg0->vel.x = 0;
                    arg0->vel.y = 0;
                    arg0->vel.z = 0;
                    arg0->f212 = 0;
                }
            }
            arg0->pos = arg0->base;
        }
    } else {
        arg0->pos = arg0->base;
        a = arg0->phase & 0xFFF;
        if (a == 0) {
            s = 0;
        } else {
            a -= a / 4096 * 4096;
            s = func_80001CA0(a * 0.00024414062f * 6.283185) * 4096.0f;
        }
        m = arg0->amp * s;
        arg0->pos.y += (m / 4096) << 12;
        arg0->phase += arg0->speed;
    }
    arg0->pos120 = arg0->base;
    arg0->pos120.y = arg0->f218;
    d = (arg0->f218 - arg0->pos.y) >> 12;
    arg0->f152 = d;
    if (d != 0) {
        arg0->f150 = 0x8C - d * 60 / 128;
    } else {
        arg0->f150 = 0;
    }
}
