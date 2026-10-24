#include "common.h"

typedef struct {
    u16 x[16];
} Sub3E6E0;
typedef struct {
    u8 pad[0x56];
    Sub3E6E0 sub[7];
    u8 pad2[0x154 - 0x56 - 0xE0];
} Ent3E6E0;

typedef struct {
    u8 pad0[0x2C];
    void *p2C;
    u8 pad30[0x60 - 0x30];
    u8 b60;
    u8 b61;
    u8 pad62[2];
    u8 b64;
    u8 b65;
    u8 pad66[0x74 - 0x66];
    u8 a74[0x2B4 - 0x74];
    u8 objs[12][0x14];
} O3E6E0;

void func_800394A8(O3E6E0 *, s32);
void func_800A735C(void *, s32);
void func_800B19C0(void *, s32);
extern u8 D_8001A430[];
extern u8 D_800D0FC0[];
extern u16 D_800D4788[];
extern u16 D_800D47A8[];
extern u16 D_800D47CC[][3];
extern s32 D_800D4818[6];
extern Ent3E6E0 D_800D4D80[];
extern u8 D_800DE9F4[];
extern s32 D_800EECF0[];

void func_8003E6E0(O3E6E0 *o, s32 arg1) {
    s32 k;
    s32 *e;

    o->p2C = D_8001A430;
    D_800DE9F4[0x866] = D_800D0FC0[0x1B] = o->b61;
    D_800DE9F4[0x86A] = D_800D0FC0[0x1C] = o->b65;
    D_800DE9F4[0x868] = D_800D0FC0[0x1D] = o->b64;
    k = 0;
    if (*(s32 *)(D_800D0FC0 + 0xC) == 1 && *(s32 *)(D_800D0FC0 + 8) == 1) {
        k = o->b60 == 10;
    }
    D_800D4818[0] = D_800D47CC[o->b60 + k][0];
    D_800D4818[2] = D_800D47CC[o->b60 + k][1];
    D_800D4818[4] = D_800D47CC[o->b60 + k][2];
    D_800D4818[1] = D_800D4D80[o->b60].sub[o->b61].x[0];
    D_800D4818[3] = D_800D4788[o->b64];
    D_800D4818[5] = D_800D47A8[o->b64];
    e = D_800EECF0;
    {
        s32 n = 3;
        e[4] = (s32)D_800D4818;
        e[3] = n;
    }
    func_800B19C0(o->objs[11], 2);
    func_800B19C0(o->objs[10], 2);
    func_800B19C0(o->objs[9], 2);
    func_800B19C0(o->objs[8], 2);
    func_800B19C0(o->objs[7], 2);
    func_800B19C0(o->objs[6], 2);
    func_800B19C0(o->objs[5], 2);
    func_800B19C0(o->objs[4], 2);
    func_800B19C0(o->objs[3], 2);
    func_800B19C0(o->objs[2], 2);
    func_800B19C0(o->objs[1], 2);
    func_800B19C0(o->objs[0], 2);
    func_800A735C(o->a74, 2);
    func_800394A8(o, arg1);
}
