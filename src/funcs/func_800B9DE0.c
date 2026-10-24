/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
} Tex_800B9DE0;

typedef struct {
    u8 pad0[2];
    s8 type;
    u8 pad3;
    f32 phase;
    Tex_800B9DE0 tex;
} Anim_800B9DE0;

typedef struct Mat_800B9DE0 {
    u8 pad0[0x38];
    u16 w;
    u16 h;
    u8 pad3C[0x10];
    u8 alpha;
    u8 pad4D[3];
    u32 dl;
    u8 pad54[8];
    u32 flags;
    u8 pad60[6];
    u16 id;
    u8 pad68[8];
    u32 rmode;
    s32 unk74;
    void *tex0;
    Anim_800B9DE0 *anim;
    struct Mat_800B9DE0 *next;
} Mat_800B9DE0;

f32 func_80001CA0(f32);
u32 func_800B8E24(Mat_800B9DE0 *);
void func_800B9AE8(void *, u16, u16, s32);
extern s32 D_800EECDC;
extern s32 D_800EECE0;
extern s32 D_800EECE8;
extern u32 D_800F5628;
extern Gfx *D_800F36A4;
extern f32 D_800F5668;

s32 func_800B9DE0(Mat_800B9DE0 *m) {
    Tex_800B9DE0 *a;
    f32 f;
    u32 v;
    u32 clr;
    u32 set;
    u32 fl;
    u32 hi;
    u32 rm;

    if (D_800EECE8 == m->id) {
        return 0;
    }
    D_800EECE8 = m->id;
    {
        Gfx *_g = D_800F36A4++;
        _g->w0 = 0xDE000000;
        _g->w1 = m->dl;
    }
    if (D_800EECE0 == 0) {
        if (m->tex0 != NULL) {
            func_800B9AE8(m->tex0, m->w, m->h, 1);
        }
        if (m->next != NULL && m->next->tex0 != NULL) {
            func_800B9AE8(m->next->tex0, m->next->w, m->next->h, 2);
        }
        if (m->anim != NULL) {
            a = &m->anim->tex;
            if (a->unk10 == 0 && m->anim->type == 1) {
                m->anim->phase += D_800F5668 * 3.0f;
                f = func_80001CA0(m->anim->phase) * 50.0f + 128.0f;
                if (f >= 2147483648.0f) {
                    goto big;
                }
                v = (s32)f;
                goto end;
            big:
                v = (s32)(f - 2147483648.0f);
                v |= 0x80000000;
            end:
                {
                    Gfx *_g = D_800F36A4++;
                    _g->w0 = 0xEC000000;
                    _g->w1 = v & 0xFF;
                }
            }
            func_800B9AE8(a, m->w, m->h, 2);
        }
    }
    set = 0;
    if (D_800F5628 != 0x170000) {
        if (D_800F5628 & 0x40000) {
            clr = set;
            set = 0x20000;
        } else {
            clr = 0x20000;
        }
        if (D_800F5628 & 0x20000) {
            set |= 0x10000;
        } else {
            clr |= 0x10000;
        }
        if (D_800F5628 & 0x100000) {
            set |= 0x400;
        } else {
            clr |= 0x400;
        }
        if (D_800F5628 & 0x200000) {
            set |= 0x40000;
        } else {
            clr |= 0x40000;
        }
        if (clr != 0) {
            Gfx *_g = D_800F36A4++;
            _g->w0 = (~clr & 0xFFFFFF) | 0xD9000000;
            _g->w1 = 0;
        }
        if (set != 0) {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0xD9FFFFFF;
            _g->w1 = set;
        }
        fl = m->flags;
        if (D_800F5628 & 0x80000) {
            m->flags = fl | 3;
        }
        hi = 0x0C080000;
        if (D_800F5628 & 0x20000) {
            hi = 0xC8000000;
        }
        if (D_800F5628 & 0x10000) {
            rm = func_800B8E24(m);
            if (D_800EECDC != 0 && m->alpha == 0xFF && !(fl & 1)) {
                rm = 0x112038;
            }
        } else {
            rm = m->rmode;
            if (D_800EECDC != 0 && m->alpha == 0xFF && !(fl & 1)) {
                rm = 0x112008;
            }
        }
        m->flags = fl;
        {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0xE200001C;
            _g->w1 = hi | rm;
        }
    } else if (D_800EECDC != 0) {
        if (m->alpha != 0xFF) {
            return 1;
        }
        if (m->flags & 1) {
            return 1;
        }
        {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0xE200001C;
            _g->w1 = 0xC8112038;
        }
    }
    return 1;
}
