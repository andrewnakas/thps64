/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    char *a;
    char *b;
    s32 c;
    s32 d;
} T2EFA0;

typedef struct {
    s32 data[0x154 / 4];
} E2EFA0;

typedef struct {
    s32 data[0x2C / 4];
} F2EFA0;

typedef struct {
    u8 pad0[0x78C];
    s32 v78C;
    s32 v790;
    s32 v794;
} O2EFA0;

extern T2EFA0 D_80019A10;
extern s32 D_800D0FC0[];
extern s32 D_800D0FCC;
extern T2EFA0 D_800D46B0[];
extern E2EFA0 D_800D4D80[];
extern F2EFA0 D_800D63F8[];
extern E2EFA0 D_800D6FF4;
extern F2EFA0 D_800D7148[];
extern u8 D_800DF258;
extern u8 D_800DF259;

void func_8002EFA0(O2EFA0 *o) {
    T2EFA0 t;

    if (D_800D0FC0[2] == 1 && D_800D0FC0[3] == 0) {
        o->v794 = 11;
    } else if (D_800D0FCC == 1) {
        o->v794 = 11;
        t = D_80019A10;
        D_800D46B0[10] = D_80019A10;
        D_800D4D80[10] = D_800D6FF4;
        D_800D63F8[63] = D_800D7148[0];
        D_800D63F8[64] = D_800D7148[1];
        D_800D63F8[65] = D_800D7148[2];
    } else {
        o->v794 = 10;
    }
    o->v78C = D_800DF258;
    if (o->v78C < 0) {
        o->v78C = 0;
    } else if (o->v794 < o->v78C) {
        o->v78C = o->v794;
    }
    o->v790 = D_800DF259;
    if (o->v790 == o->v78C) {
        o->v790 = D_800DF259 + 1;
    }
    if (o->v790 < 0) {
        o->v790 = 0;
    } else if (o->v794 < o->v790) {
        o->v790 = o->v794 - 1;
    }
}
