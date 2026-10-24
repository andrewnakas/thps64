/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800A426C;

typedef struct {
    f32 v[6];
    u16 unk18;
    u8 pad1A[2];
    u8 m1[0x40];
    u8 m2[0x40];
} E800A426C;

typedef struct {
    u8 pad0[0xA0];
    u8 mA0[0x40];
    u8 padE0[0x40];
    u8 m120[0x40];
    f32 v160[6];
    u8 pad178[4];
    s32 unk17C;
    u8 pad180[0x3A0 - 0x180];
    u8 cnt;
    u8 pad3A1[3];
    E800A426C e[2];
    u8 pad4DC[0x650 - 0x3A4 - 2 * 0x9C];
    u16 unk650;
} S800A426C;

void func_8009C8EC(void *, void *);
extern Gfx800A426C *D_800F36A4;

void func_800A426C(S800A426C *arg0) {
    E800A426C *e;

    e = &arg0->e[--arg0->cnt];
    arg0->v160[0] = e->v[0];
    arg0->v160[1] = e->v[1];
    arg0->v160[2] = e->v[2];
    arg0->v160[3] = e->v[3];
    arg0->v160[4] = e->v[4];
    arg0->v160[5] = e->v[5];
    arg0->unk650 = e->unk18;
    func_8009C8EC(arg0->mA0, e->m1);
    func_8009C8EC(arg0->m120, e->m2);
    {
        Gfx800A426C *_g = D_800F36A4++;
        _g->w0 = 0xDA380007;
        _g->w1 = arg0->unk17C;
    }
    {
        Gfx800A426C *_g = D_800F36A4++;
        _g->w0 = 0xDB0E0000;
        _g->w1 = arg0->unk650;
    }
}
