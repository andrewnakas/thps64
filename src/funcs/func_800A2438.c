/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxA2438;

typedef struct {
    u8 pad0[0x3A];
    u16 h;
} TexA2438;

typedef struct {
    f32 scale;
    f32 th;
    u8 pad8[0x22C - 0x8];
    TexA2438 *tex;
} FontA2438;

typedef struct {
    s32 size;
    u8 pad4[0x20 - 0x4];
    s32 num;
    s32 used;
} EntA2438;

typedef struct {
    s16 off;
    s16 pad;
    void *fn;
} VEntA2438;

typedef struct {
    u8 pad0[8];
    VEntA2438 prev;
    VEntA2438 next;
    VEntA2438 cancel;
    VEntA2438 pick;
    u8 pad28[0x40 - 0x28];
    VEntA2438 name;
    VEntA2438 need;
} VtA2438;

typedef struct {
    u8 pad0[0x14];
    s32 count;
    s32 sel;
    u8 pad1C[0x1AC - 0x1C];
    FontA2438 font;
    u8 pad1DC[0x3EC - 0x1AC - sizeof(FontA2438)];
    u8 ctrl[0x41C - 0x3EC];
    s32 unk41C;
    u8 pad420[0x434 - 0x420];
    s32 port;
    u8 pad438[0x440 - 0x438];
    s32 unk440;
    u8 pad444[0x468 - 0x444];
    s32 unk468;
    s32 unk46C;
    s32 unk470;
    u8 pad474[0x498 - 0x474];
    char *title;
    u8 pad49C[4];
    u8 unk4A0[0x14];
    EntA2438 *list;
    EntA2438 cur;
    u8 pad4E0[0x4F8 - 0x4E0];
    VtA2438 *vt;
} MenuA2438;

typedef struct {
    u8 pad0[2];
    u8 status;
    u8 err;
} PadA2438;

void func_80004ED0(void *, s32, s32);
void func_800057E4(char *, char *, ...);
void func_800074F0(void *);
void func_80007574(PadA2438 *);
void func_800A059C(void);
void func_800A05D8(MenuA2438 *);
s32 func_800A05F8(MenuA2438 *, s32, s32);
s32 func_800A0670(MenuA2438 *, s32, s32);
s32 func_800A06E8(MenuA2438 *, s32, s32);
void func_800A0B0C(MenuA2438 *, void *, void *, s32);
void func_800A773C(FontA2438 *, f32, f32);
void func_800A7B28(FontA2438 *, s32, s32, s32, s32);
void func_800A8678(FontA2438 *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
extern char D_80020EC8[];
extern char D_80020F90[];
extern char D_80020FA0[];
extern char D_80020FB4[];
extern char D_80020FBC[];
extern char D_80020FC4[];
extern char D_80020FC8[];
extern s32 D_800EA550;
extern s32 D_800EECE8;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern GfxA2438 *D_800F36A4;

static inline void failA2438(MenuA2438 *m) {
    m->sel = -1;
    D_800EA550 = m->unk41C;
    func_800A05D8(m);
}

void func_800A2438(MenuA2438 *m) {
    PadA2438 pads[4];
    char buf[0x18];
    char num[0x20];
    char sz[0x38];
    s32 big;
    s32 step;
    s32 y;
    s32 lock;
    s32 i;
    s32 pg;
    s32 v;
    PadA2438 *p;
    EntA2438 *e;
    s32 dy;
    u8 st;

    func_800A059C();
    func_800074F0(m->ctrl);
    func_80004ED0(m->ctrl, 0, 1);
    func_80007574(pads);
    p = &pads[m->port];
    if (p->err != 0) {
        goto fail;
    }
    st = p->status;
    if (!(st & 1)) {
        goto fail;
    }
    if (st & 6) {
    fail:
        failA2438(m);
        return;
    } else {
        D_800EECE8 = -1;
        {
            GfxA2438 *_g = D_800F36A4++;
            _g->w0 = 0xE7000000;
            _g->w1 = 0;
        }
        {
            GfxA2438 *_g = D_800F36A4++;
            _g->w0 = 0xE3000A01;
            _g->w1 = 0x100000;
        }
        lock = 0;
        if (m->unk468 == 0) {
            v = 0;
            if (func_800A0670(m, m->port, 0x8000) == 0) {
                v = func_800A0670(m, m->port, 0x4000) == 0;
            }
            m->unk468 = v;
            if (v != 0) {
                lock = 1;
            }
        }
        y = D_800F3298 - 38;
        if (m->title != NULL) {
            func_800A7B28(&m->font, 0xD3, 0xD3, 0xD3, 0xFF);
            func_800A773C(&m->font, 1.18f, 1.18f);
            func_800A8678(&m->font, m->title, D_800F3294 / 2, y, 2, 0, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
            func_800A773C(&m->font, 1.0f, 1.0f);
            if (m->unk470 != 0) {
                v = (m->unk440 + 0xFF) / 256;
                func_800057E4(buf, D_80020F90, v);
                func_800A8678(&m->font, buf, 70.0f, 87.0f, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0);
                v = (((s32 (*)(void *))m->vt->need.fn)((u8 *)m + m->vt->need.off) + 0xFF) / 256;
                func_800057E4(buf, D_80020FA0, v);
                func_800A8678(&m->font, buf, D_800F3294 - 70, 87.0f, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0);
            }
        }
        big = 0;
        if (m->unk46C != 0) {
            big = m->count < 12;
        }
        if (big) {
            func_800A773C(&m->font, 1.4f, 1.4f);
        }
        if (m->unk470 != 0) {
            FontA2438 *f = &m->font;
            f32 h = f->tex->h * f->th;
            step = h * -1.1f;
            y -= (s32)(h * 2.75f);
            func_800A7B28(f, 0, 0x80, 0xFF, 0xFF);
            func_800A8678(f, D_80020FB4, 70.0f, y, 0, 2, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
            func_800A8678(f, D_80020FBC, 135.0f, y, 0, 2, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
            func_800A8678(f, D_80020EC8, D_800F3294 - 70, y, 1, 2, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
            y += (s32)(step * 1.15f);
        } else {
            {
                FontA2438 *f = &m->font;
                step = f->tex->h * f->th * -1.3f;
            }
            y = D_800F3298 - (D_800F3298 - (m->count - 1) * -step) / 2;
        }
        if (m->count != 0) {
            if (m->sel == -1) {
                m->sel = 0;
                if (m->list[0].used == 0) {
                    do {
                        m->sel = (m->sel + 1) % m->count;
                    } while (m->list[m->sel].used == 0);
                }
            }
            if (m->count >= 2) {
                i = 0;
                if (m->unk468 == 0) {
                    goto loop;
                }
                if (func_800A05F8(m, m->port, 0x800) != 0) {
                    do {
                        m->sel = (m->sel + m->count - 1) % m->count;
                    } while (m->list[m->sel].used == 0);
                    ((void (*)(void *))m->vt->prev.fn)((u8 *)m + m->vt->prev.off);
                } else {
                    i = 0;
                    if (m->unk468 == 0) {
                        goto loop;
                    }
                    if (func_800A05F8(m, m->port, 0x400) != 0) {
                        do {
                            m->sel = (m->sel + 1) % m->count;
                        } while (m->list[m->sel].used == 0);
                        ((void (*)(void *))m->vt->next.fn)((u8 *)m + m->vt->next.off);
                    }
                }
            }
        }
        i = 0;
        if (m->unk468 != 0) {
            if (lock == 0 && func_800A06E8(m, m->port, 0x8000) != 0) {
                D_800EA550 = m->unk41C;
                if (m->count != 0) {
                    m->cur = m->list[m->sel];
                    func_800A0B0C(m, (u8 *)&m->cur + 0xE, m->unk4A0, 0x10);
                } else {
                    m->sel = -1;
                }
                ((void (*)(void *))m->vt->pick.fn)((u8 *)m + m->vt->pick.off);
            } else {
                i = 0;
                if (m->unk468 != 0 && func_800A05F8(m, m->port, 0x4000) != 0) {
                    m->sel = -1;
                    D_800EA550 = m->unk41C;
                    ((void (*)(void *))m->vt->cancel.fn)((u8 *)m + m->vt->cancel.off);
                }
            }
            i = 0;
        }
    loop:
        i = 0;
        while (1) {
            dy = 0;
            if (i >= m->count) {
                break;
            }
            e = &m->list[i];
            if (m->sel == i) {
                func_800A7B28(&m->font, 0xFF, 0xFA, 0x44, 0xFF);
                if (m->unk468 != 0) {
                    dy = (func_800A0670(m, m->port, 0x8000) != 0) * 2;
                }
            } else {
                if (e->used != 0) {
                    func_800A7B28(&m->font, 0xD3, 0xD3, 0xD3, 0xFF);
                } else {
                    func_800A7B28(&m->font, 0x69, 0x69, 0x69, 0xFF);
                }
            }
            if (e->used != 0) {
                ((void (*)(void *, s32, char *, char *))m->vt->name.fn)((u8 *)m + m->vt->name.off, i, buf, sz);
            }
            if (m->unk470 != 0) {
                func_800057E4(num, D_80020FC4, e->num);
                func_800A8678(&m->font, num, 70.0f, y, 0, 2, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
                func_800A8678(&m->font, e->used ? buf : D_80020FC8, 135.0f, y, 0, 2, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
                pg = e->used ? (u32)(e->size + 0xFF) >> 8 : 0;
                func_800057E4(num, D_80020FC4, pg);
                func_800A8678(&m->font, num, D_800F3294 - 70, y, 1, 2, 1.0f, 0xFF, 0, 0, 1, 0, 0, 0);
            } else {
                func_800A8678(&m->font, buf, D_800F3294 / 2 + dy, y - dy, 2, 2, 0, 0, 0, 0, 1, 0, 0, 0);
            }
            y += step;
            i++;
        }
        if (big) {
            func_800A773C(&m->font, 1.0f, 1.0f);
        }
    }
    func_800A05D8(m);
}
