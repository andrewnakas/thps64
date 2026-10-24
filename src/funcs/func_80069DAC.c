#include "common.h"

typedef struct {
    s16 x, y, z, pad;
} Vtx_80069DAC;

typedef struct {
    u16 unk0;
    u16 nverts;
    u16 nunk4;
    u16 nfaces;
    u8 pad8[0x1C - 8];
    Vtx_80069DAC verts[1];
} Model_80069DAC;

typedef struct {
    u8 pad0[0x18];
    Model_80069DAC **tbl;
    u8 pad1C[0x48 - 0x1C];
} Ent_80069DAC;

void func_80069A9C(s32, s32, s32, s32, s32);
extern Ent_80069DAC D_800DAF98[];

#define VTX(o) ((s16 *)((*(u16 *)(f + (o)) & 0xFFF8) + (s32)verts))

void func_80069DAC(u8 *arg0, s32 arg1) {
    s32 ox;
    s32 oz;
    s32 n;
    Vtx_80069DAC *verts;
    s32 i;
    s32 k;
    u8 *p;
    s32 x0, z0, x1, z1, x2, z2, x3, z3;
    Model_80069DAC *m;
    u8 *f;
    s16 *v;

    m = D_800DAF98[arg0[0x1B]].tbl[*(u16 *)(arg0 + 0x16)];
    ox = *(s32 *)(arg0 + 4) >> 12;
    oz = *(s32 *)(arg0 + 0xC) >> 12;
    n = m->nfaces;
    k = m->nunk4;
    p = (u8 *)&m->verts[m->nverts];
    verts = m->verts;
    f = p + k * 8;
    i = 0;
    while (1) {
        if (i >= n) {
            break;
        }
        x0 = VTX(4)[0] + ox;
        z0 = VTX(4)[2] + oz;
        x1 = VTX(6)[0] + ox;
        z1 = VTX(6)[2] + oz;
        x2 = VTX(8)[0] + ox;
        z2 = VTX(8)[2] + oz;
        if ((x0 != x2 || z0 != z2) && (x0 != x1 || z0 != z1) && (x2 != x1 || z2 != z1)) {
            if (!(*(u16 *)f & 0x10)) {
                x3 = VTX(0xA)[0] + ox;
                z3 = VTX(0xA)[2] + oz;
                func_80069A9C(x0, z0, x1, z1, arg1);
                func_80069A9C(x1, z1, x3, z3, arg1);
                func_80069A9C(x2, z2, x3, z3, arg1);
                func_80069A9C(x2, z2, x0, z0, arg1);
            } else {
                func_80069A9C(x0, z0, x1, z1, arg1);
                func_80069A9C(x1, z1, x2, z2, arg1);
                func_80069A9C(x2, z2, x0, z0, arg1);
            }
        }
        i++;
        f += *(u16 *)f & 0xFFFC;
    }
}
