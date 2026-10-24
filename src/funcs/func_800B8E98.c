/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx8E98;

typedef struct {
    s8 unk0;
    s8 unk1;
} Anim8E98;

typedef struct Mat8E98 {
    u8 pad0[0x38];
    u16 unk38;
    u16 unk3A;
    s8 unk3C;
    s8 unk3D;
    u8 unk3E;
    u8 unk3F;
    u8 pad40[4];
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    u8 unk4B;
    u8 unk4C;
    u8 pad4D[3];
    void *unk50;
    u32 unk54;
    s32 unk58;
    s32 unk5C;
    u32 unk60;
    u16 unk64;
    u8 pad66[2];
    u32 unk68;
    u32 unk6C;
    u8 pad70[0xC];
    Anim8E98 *unk7C;
    struct Mat8E98 *unk80;
} Mat8E98;

void func_80005720(void *, void *, s32);
void *func_8009E6B4(void *, s32, s32);
void func_800B8A00(Mat8E98 *, s32, s32, s32, s32, s32, s32, Gfx8E98 **);
void func_800B8BD8(Mat8E98 *, s32, s32, Gfx8E98 **);
u32 func_800B8E24(Mat8E98 *, u32);
extern u8 D_800EA110[];

#define G(a, b)                     \
    {                               \
        Gfx8E98 *_g = gp++;         \
        _g->w0 = a;                 \
        _g->w1 = b;                 \
    }

void func_800B8E98(Mat8E98 *m, Gfx8E98 **out) {
    Gfx8E98 buf[0x30];
    Gfx8E98 *gp;
    s32 t;
    u8 sv3F;
    u8 sv3E;
    s32 w;
    s32 pad;
    s32 off;
    s32 sv58;
    s32 size;
    u32 rm;
    Gfx8E98 *g0;

    t = 1;
    if (out != NULL) {
        gp = *out;
    } else {
        gp = buf;
    }
    G(0xE7000000, 0);
    G((t << 8) | 0xD7000002, -1);
    G(0xE3000C00, 0x80000);
    G(0xE3000F00, 0);
    G(0xE3001201, m->unk60);
    G(0xE3000D01, 0);
    if (m->unk5C & 4) {
        G(0xFB000000, (m->unk44 << 24) | (m->unk45 << 16) | (m->unk46 << 8) | m->unk47);
    }
    if (m->unk5C & 8) {
        G(0xFA000000, (m->unk48 << 24) | (m->unk49 << 16) | (m->unk4A << 8) | m->unk4B);
    }
    sv3F = m->unk3F;
    if (sv3F == 0x14) {
        m->unk3F = 0x10;
        func_800B8BD8(m, 0, t, &gp);
        func_800B8A00(m, 0, t, 0, 0, 0, 0, &gp);
        w = m->unk38 * 2;
        pad = 8 - w % 8;
        if (pad != 8) {
            w += pad;
        }
        sv3E = m->unk3E;
        m->unk3F = 4;
        m->unk3E = 4;
        off = w * m->unk3A;
        sv58 = m->unk58;
        m->unk58 = sv58 + off / 2 * 2;
        G(0xE6000000, 0);
        G(0xE8000000, 0);
        func_800B8BD8(m, off, t + 1, &gp);
        func_800B8A00(m, off, t + 1, 0, 0, 0, 0, &gp);
        m->unk3E = sv3E;
        m->unk58 = sv58;
        m->unk3F = sv3F;
    } else {
        func_800B8BD8(m, 0, t, &gp);
        func_800B8A00(m, 0, t, 0, 0, 0, 0, &gp);
    }
    if (m->unk80 != NULL) {
        G(0xE6000000, 0);
        G(0xE8000000, 0);
        func_800B8BD8(m->unk80, m->unk64, t + 1, &gp);
        func_800B8A00(m->unk80, m->unk64, t + 1, m->unk80->unk3C, m->unk80->unk3D, 0, 0, &gp);
    }
    if (m->unk7C != NULL) {
        func_800B8A00(m, 0, t + 1, m->unk7C->unk0, m->unk7C->unk1, 0, 0, &gp);
    }
    if (m->unk3E == 2) {
        G(0xFD100000, m->unk54);
        G(0xE8000000, 0);
        G(0xF5000100, 0x07000000);
        G(0xE6000000, 0);
        G(0xF0000000, 0x0703C000);
        G(0xE7000000, 0);
        G(0xE3001001, 0x8000);
    } else {
        G(0xE3001001, 0);
    }
    g0 = gp;
    gp = g0 + 1;
    g0->w0 = m->unk68;
    g0->w1 = m->unk6C;
    rm = func_800B8E24(m, g0->w1);
    G(0xE200001C, rm | 0xC8000000);
    if (m->unk4C == 0xFF) {
        G(0xE2001E01, 0);
    } else {
        G(0xE2001E01, 1);
        G(0xF9000000, m->unk4C | ~0xFF);
    }
    if (out != NULL) {
        *out = gp;
        return;
    }
    G(0xDF000000, 0);
    size = (u8 *)gp - (u8 *)buf;
    m->unk50 = func_8009E6B4(D_800EA110, size, 8);
    func_80005720(m->unk50, buf, size);
}
