/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x70];
    f32 level;
    f32 timer;
    u8 on;
    u8 pad79[3];
    f32 acc;
} Chan;

void func_80005070(void *, s32, s32);
void func_80004ED0(void *, s32, s32);
void func_800B345C(s32, s32);
void func_800B3420(s32, s32);
void func_800B3690(s32);
extern u8 D_800FC371;
extern u8 D_800FC350[];
extern Chan D_800FC380[];
extern f32 D_800F5668;
extern s32 D_800ECFB0;
extern s32 D_800ECFB4;
extern s32 D_800F30E4;

void func_800B34DC(void) {
    s32 i;
    Chan *e;
    s32 c;
    s32 x;

    if (D_800FC371 == 0) {
        return;
    }
    i = 0;
    while (1) {
        if (i >= 4) break;
        e = &D_800FC380[i];
        if (e->timer != 0.0f) {
            if (e->timer < 0.0f) {
                func_80005070(D_800FC350, 0, 1);
                e->timer = e->level = e->acc = 0.0f;
                func_80004ED0(D_800FC350, 0, 1);
                func_800B345C(i, 1);
                e->on = 0;
            } else {
                c = e->level + e->acc > 0.5f;
                e->acc += e->level - (u8)c;
                if (e->on != (u8)c) {
                    e->on = c;
                    x = D_800ECFB0 ^ 1;
                    if ((u8)c) {
                        func_800B3420(i, x);
                    } else {
                        func_800B345C(i, x);
                    }
                }
                e->timer -= D_800F5668;
                if (e->timer == 0.0f) {
                    e->timer = -D_800F5668;
                }
            }
        }
        i++;
    }
    if (D_800ECFB0 == 0 || D_800F30E4 != 0) {
        if (D_800ECFB4 == 0) {
            func_800B3690(1);
            D_800ECFB4 = 1;
        }
    } else {
        D_800ECFB4 = 0;
    }
}
