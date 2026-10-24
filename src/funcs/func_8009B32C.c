/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct Spr_8009B32C {
    f32 x, y, z;
    f32 scale;
    u8 pad10[4];
    f32 a;
    f32 b;
    u8 pad1C_[0];
    struct Spr_8009B32C *next;
    u8 pad20[4];
    s32 mtx;
} Spr_8009B32C;

typedef struct {
    Spr_8009B32C *head;
    u8 pad4[0x504];
    s32 tex;
    u8 pad50C[4];
    u8 mode;
    u8 r, g, b;
    f32 fade;
} Fx_8009B32C;

void func_8009CB68(f32 (*)[4], f32 *);
void func_800B9DE0(s32);
s32 func_800C000C(f32 (*)[4]);
extern s32 D_800EA0D0;
extern Gfx *D_800F36A4;
extern s32 D_800F36C0;
extern s32 *D_800F36C4[];

static __inline__ u32 f2u(Fx_8009B32C *fx, Spr_8009B32C *s, f32 k31, u32 hi) {
    u32 v;
    f32 f = fx->fade * s->a / s->b;

    if (f >= k31) {
        goto big;
    }
    v = (s32)f;
    goto end;
big:
    v = (s32)(f - k31);
    v |= hi;
end:
    return v;
}

void func_8009B32C(Fx_8009B32C *fx) {
    f32 m[4][4];
    f32 sc[3];
    Spr_8009B32C *s;
    u32 alpha;
    u32 hi;
    f32 k31;
    f32 (*pm)[4];
    f32 k, x, y, z;

    if (fx->tex == 0) {
        return;
    }
    s = fx->head;
    if (s == NULL) {
        return;
    }
    func_800B9DE0(fx->tex);
    {
        Gfx *_g = D_800F36A4++;
        _g->w0 = 0xFCFF97FF;
        _g->w1 = 0xFFFDFE38;
    }
    if (fx->mode != 0) {
        Gfx *_g = D_800F36A4++;
        _g->w0 = 0xE200001C;
        _g->w1 = 0x0C184A50;
    } else {
        Gfx *_g = D_800F36A4++;
        _g->w0 = 0xE200001C;
        _g->w1 = 0x0C184240;
    }
    k31 = 2147483648.0f;
    hi = 0x80000000;
    while (1) {
        if (s == NULL) {
            break;
        }
        alpha = f2u(fx, s, k31, hi);
        if (s->mtx != 0) {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0xDA380003;
            _g->w1 = s->mtx;
        } else {
            pm = m;
            k = s->scale;
            sc[0] = k;
            sc[1] = k;
            sc[2] = k;
            func_8009CB68(pm, sc);
            x = s->x;
            y = s->y;
            z = s->z;
            m[3][0] = x;
            m[3][1] = y;
            m[3][2] = z;
            s->mtx = func_800C000C(pm);
            D_800F36C4[D_800F36C0++] = &s->mtx;
        }
        {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
        }
        {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0xFA000000;
            _g->w1 = (fx->r << 24) | (fx->g << 16) | (fx->b << 8) | (alpha & 0xFF);
        }
        {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0x01004008;
            _g->w1 = (u32)&D_800EA0D0;
        }
        {
            Gfx *_g = D_800F36A4++;
            _g->w0 = 0x06000204;
            _g->w1 = 0x406;
        }
        s = s->next;
    }
}
