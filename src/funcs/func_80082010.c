/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 x, y, z;
} SVec2010;

typedef struct {
    s32 x, y, z;
} Vec2010;

typedef struct {
    u8 pad0[4];
    Vec2010 pos;
    u8 pad10[0x48 - 0x10];
    void *vt;
    u8 pad4C[0x84 - 0x4C];
    Vec2010 pos84;
    u8 pad90[0xB5 - 0x90];
    u8 b5, b6, b7;
    u8 padB8[2];
    s16 unkBA;
    u8 padBC[0x15C - 0xBC];
    s16 unk15C;
    u8 pad15E[0x20C - 0x15E];
    u8 unk20C;
    u8 pad20D[0x214 - 0x20D];
    s32 unk214;
    Vec2010 pos218;
    s32 magic;
    s32 unk228;
    s32 unk22C;
    s32 unk230;
    f32 unk234;
    s32 unk238;
    u8 pad23C[2];
    s16 unk23E;
    s16 unk240;
    s16 unk242;
} Obj2010;

typedef struct {
    u8 pad0[4];
    Vec2010 pos;
} Cam2010;

void *func_8004B514(s32);
void func_8004A08C(Obj2010 *);
s32 func_80049D60(s32);
extern Cam2010 *D_800D8430;
extern u8 D_8001E730[];

#define INIT(o, k, m)                                \
    o = func_8004B514(0x248);                        \
    func_8004A08C(o);                                \
    o->vt = D_8001E730;                              \
    o->unk214 = 0;                                   \
    o->unk238 = 0;                                   \
    o->unk230 = 0;                                   \
    o->unk20C = 100;                                 \
    o->pos218 = w;                                   \
    o->pos = w;                                      \
    o->pos84 = w;                                    \
    o->b5 = k;                                       \
    o->b6 = k;                                       \
    o->b7 = k;                                       \
    o->unk242 = func_80049D60(20) + 90;              \
    o->unk240 = o->unk23E = 50;                      \
    o->unk15C = 300;                                 \
    o->unkBA = 50;                                   \
    o->magic = m;

Obj2010 *func_80082010(s32 type, s32 x, s32 y, s32 z, f32 f, s32 v) {
    SVec2010 sv;
    Vec2010 t;
    Vec2010 w;
    Obj2010 *o;

    sv.x = x;
    sv.y = y;
    sv.z = z;
    w.x = t.x + (D_800D8430->pos.x << 12);
    w.y = t.y + (D_800D8430->pos.y << 12);
    w.z = t.z + (D_800D8430->pos.z << 12);
    switch (type) {
    case 5:
        INIT(o, type, 0x54636518);
        break;
    case 6:
        INIT(o, 5, 0xBA6D0434);
        break;
    case 7:
        INIT(o, 5, 0x2364558E);
        break;
    }
    o->unk240 = v;
    o->unk23E = v;
    o->unk228 = x;
    o->unk22C = y;
    o->unk234 = f;
    return o;
}
