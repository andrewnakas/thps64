/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    char *a;
    char *b;
    s32 c;
    s32 d;
} T3CD64;

typedef struct {
    s32 data[0x154 / 4];
} E3CD64;

typedef struct {
    s32 data[0x2C / 4];
} F3CD64;

typedef struct {
    u8 pad0[0x30];
    s32 v30;
    u8 pad34[0x7B0 - 0x34];
    s32 v7B0;
} O3CD64;

extern T3CD64 D_8001A204;
extern s32 D_800D0FC0[];
extern s32 D_800D0FCC;
extern T3CD64 D_800D46B0[];
extern E3CD64 D_800D4D80[];
extern F3CD64 D_800D63F8[];
extern E3CD64 D_800D6FF4;
extern F3CD64 D_800D7148[];
extern u8 D_800DF258;

void func_8003CD64(O3CD64 *o) {
    T3CD64 t;

    if (D_800D0FC0[2] == 1 && D_800D0FC0[3] == 0) {
        o->v7B0 = 11;
    } else if (D_800D0FCC == 1) {
        o->v7B0 = 11;
        t = D_8001A204;
        D_800D46B0[10] = D_8001A204;
        D_800D4D80[10] = D_800D6FF4;
        D_800D63F8[63] = D_800D7148[0];
        D_800D63F8[64] = D_800D7148[1];
        D_800D63F8[65] = D_800D7148[2];
    } else {
        o->v7B0 = 10;
    }
    o->v30 = D_800DF258;
    if (o->v30 < 0) {
        o->v30 = 0;
    } else if (o->v7B0 < o->v30) {
        o->v30 = o->v7B0;
    }
}
