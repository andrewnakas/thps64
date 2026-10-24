/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s16 off8;
    s16 pad;
    void (*fnC)(void *, s32);
    s16 off10;
    s16 pad12;
    s32 (*fn14)(void *);
} VT2A348;

typedef struct {
    u8 pad0[0x2C];
    VT2A348 *vt;
} Child2A348;

typedef struct {
    u8 pad0[0x30];
    u8 a30[0x14];
    u8 a44[0x14];
    u8 a58[0x14];
    u8 a6C[0x14];
    u8 pad80[0x2E0 - 0x80];
    Child2A348 *child;
    s32 v2E4;
    s32 v2E8;
    u8 pad2EC[0x300 - 0x2EC];
    s32 v300;
} O2A348;

typedef struct {
    s32 a;
    s32 b;
} Pair2A348;

void func_80024570(s32);
void func_800244E8(s32);
Child2A348 *func_80035720(void *);
void func_80086D58(s32);
void func_80086D60(s32, s32);
void func_80097688(void *, s32);
void func_800971E0(void *, s32);
void func_800976B4(void *);
void *func_8009E30C(s32);
void func_800B1A44(void *);
s32 func_800B4264(s32, s32);
void func_800BDEA8(s32);
extern s32 D_800D0FC0[];
extern Pair2A348 D_800D30B0[];

#define G_EC8 (D_800D0FC0[0xEC8 / 4])

s32 func_8002A348(O2A348 *o) {
    u8 buf[8];
    s32 r;
    s32 hit;
    Child2A348 *c;
    u8 *p;

    if (o->v2E8 == -1) {
        func_800B1A44(o->a30);
        func_800B1A44(o->a44);
        func_800B1A44(o->a58);
        func_800B1A44(o->a6C);
        o->v2E8 = 0;
        func_80086D60(G_EC8, D_800D30B0[o->v2E8].b);
        func_800BDEA8(0);
        func_800976B4(buf);
        func_80086D60(G_EC8, D_800D30B0[o->v2E8].b);
        func_800971E0(buf, D_800D30B0[o->v2E8].a);
        func_80024570(o->v2E4);
        o->child = func_80035720(func_8009E30C(0x2BC));
        func_80097688(buf, 2);
    }
    c = o->child;
    r = c->vt->fn14((u8 *)c + c->vt->off10);
    hit = 0;
    p = (u8 *)D_800D0FC0;
    if (func_800B4264(p[2], 0x1000) || func_800B4264(p[3], 0x1000)) {
        hit = 1;
    }
    if (hit) {
        o->v300 = 1;
    }
    if (r) {
        func_80086D58(G_EC8);
        c = o->child;
        if (c != NULL) {
            c->vt->fnC((u8 *)c + c->vt->off8, 3);
        }
        o->child = NULL;
        func_800244E8(o->v2E4);
        if (++o->v2E8 == 10 || o->v300) {
            return 3;
        }
        func_800976B4(buf);
        func_80086D60(G_EC8, D_800D30B0[o->v2E8].b);
        func_800971E0(buf, D_800D30B0[o->v2E8].a);
        func_80024570(o->v2E4);
        o->child = func_80035720(func_8009E30C(0x2BC));
        func_80097688(buf, 2);
    }
    return 0;
}
