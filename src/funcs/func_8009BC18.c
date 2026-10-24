/* cflags: -O2 */

#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx8009BC18;

typedef struct {
    s32 x, y, z;
} Vec8009BC18;

typedef struct {
    s32 m[12];
    Vec8009BC18 t;
    s32 w;
} Mtx8009BC18;

void func_8009C8EC(Mtx8009BC18 *, s32);
void func_8009D8B4(Mtx8009BC18 *, f32 *);
void func_800C000C(Mtx8009BC18 *);
extern Gfx8009BC18 *D_800F36A4;

typedef struct {
    u8 pad0[4];
    Vec8009BC18 pos;
    u32 unk10;
    f32 unk14;
    f32 unk18;
} Obj8009BC18;

void func_8009BC18(Obj8009BC18 *arg0, s32 arg1) {
    Mtx8009BC18 mtx;
    f32 scale[3];
    Mtx8009BC18 *pm;
    f32 t;
    f32 x;
    Gfx8009BC18 *h;
    Gfx8009BC18 *g;

    pm = &mtx;
    func_8009C8EC(pm, arg1 + 0x60);
    x = arg0->unk14;
    t = arg0->unk18;
    scale[0] = x;
    scale[1] = t;
    scale[2] = t;
    func_8009D8B4(pm, scale);
    mtx.t = arg0->pos;
    func_800C000C(pm);
    g = D_800F36A4++;
    g->w0 = 0x01004008;
    g->w1 = arg0->unk10;
    h = D_800F36A4++;
    h->w0 = 0x06000204;
    h->w1 = 0x406;
}
