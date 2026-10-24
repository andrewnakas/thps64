/* cflags: -O2 -fno-strength-reduce -fno-schedule-insns -fno-schedule-insns2 -Wa,-O0 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    u8 n;
    u8 pad9[3];
    u8 flags[8];
} Ent3D410;

void func_800057E4(char *, char *, ...);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
extern char D_8001A214[];
extern char D_8001A230[];
extern s32 D_800DE7A0;
extern u8 D_800D0FC0[];
extern Ent3D410 D_800DE9F4[];

void func_8003D410(u8 *o) {
    char buf[8];
    s32 n;
    s32 i;
    s32 step;
    s32 y;
    f32 k;
    Ent3D410 *e;
    Ent3D410 *base;

    if (D_800DE7A0 != 1 || D_800D0FC0[0x16] != 0x1F) {
        return;
    }
    base = D_800DE9F4;
    e = &base[*(s32 *)(o + 0x30)];
    if (*(s32 *)((u8 *)e + 0x18) != 0) {
        n = base[D_800D0FC0[0x14]].n;
        if (n >= 10) {
            func_800057E4(buf, D_8001A214, n);
        } else {
            func_800057E4(buf, D_8001A230, n);
        }
        step = 3;
        k = 0.95f;
        func_800B1AC4(o + 0x558, 405.0f, 312.0f, 0.925f, k);
        func_800A8678(o + 0x56C, buf, 495.0f, 107.0f, 2, 0, 1.0f, 0, 0, 1, 1, 0, 0, 0);
        y = 0x148;
        i = step;
        do {
            if ((D_800DE9F4[D_800D0FC0[0x14]].flags[i] & 0x80) && !(D_800DE9F4[D_800D0FC0[0x14]].flags[i] & 0x40) &&
                !(D_800DE9F4[D_800D0FC0[0x14]].flags[i] & 0x20)) {
                func_800B1AC4(o + 0x51C, 578.0f, (s16)y, 0.925f, k);
            } else if ((D_800DE9F4[D_800D0FC0[0x14]].flags[i] & 0x40) && !(D_800DE9F4[D_800D0FC0[0x14]].flags[i] & 0x20)) {
                func_800B1AC4(o + 0x530, 578.0f, (s16)y, 0.925f, k);
            } else if (D_800DE9F4[D_800D0FC0[0x14]].flags[i] & 0x20) {
                func_800B1AC4(o + 0x544, 578.0f, (s16)y, 0.925f, k);
            }
            y += 0x19;
            i += step;
            step--;
        } while (i < 9);
    }
}
