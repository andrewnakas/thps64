/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    s32 *hdr;
    u8 *base;
} Chunk_800B6B80;

typedef struct {
    s32 **tex;
    u32 flags;
} Mat_800B6B80;

typedef struct {
    u8 **items;
    s32 count;
} Model_800B6B80;

s32 func_800B713C(Chunk_800B6B80 *, s32);
void func_800B7160(Chunk_800B6B80 *, void *);
void func_800B9DE0(s32 *);
extern u8 D_800ECFE0[];
extern s32 D_800EECE8;
extern Gfx *D_800F36A4;

static __inline__ Mat_800B6B80 *read_(Chunk_800B6B80 *c, u8 *base) {
    func_800B7160(c, base);
    return (Mat_800B6B80 *)(c->base + func_800B713C(c, 0));
}

static __inline__ u8 *addr_(Chunk_800B6B80 *c) {
    return c->base + func_800B713C(c, 1);
}

void func_800B6B80(Model_800B6B80 *m, s32 sel) {
    Chunk_800B6B80 c0;
    Chunk_800B6B80 c1;
    Chunk_800B6B80 c2;
    s32 i;
    Chunk_800B6B80 *pc0;
    s32 j;
    s32 n;
    Mat_800B6B80 *mat;
    u32 fl;
    u32 clr;
    u32 set;
    s32 all;
    u8 *cfg;
    u8 *addr;

    cfg = D_800ECFE0;
    i = 0;
    all = -1;
    pc0 = &c0;
    while (1) {
        if (i >= m->count) {
            break;
        }
        if (sel != all) {
            i = sel;
        }
        func_800B7160(pc0, m->items[i]);
        func_800B7160(&c1, pc0->base + func_800B713C(pc0, 1));
        j = 0;
        n = *c1.hdr;
        while (1) {
            if (j >= n) break;
            mat = read_(&c2, c1.base + func_800B713C(&c1, j));
            fl = mat->flags;
            if (fl & 0x8000) {
                goto next;
            }
            if (fl & 0x800) {
                goto next;
            }
            set = 0;
            clr = 0;
            if (fl & 1) {
                if (mat->tex != NULL) {
                    func_800B9DE0(mat->tex[1]);
                }
            } else {
                D_800EECE8 = all;
                {
                    Gfx *_g = D_800F36A4++;
                    _g->w0 = 0xE7000000;
                    _g->w1 = 0;
                }
                {
                    Gfx *_g = D_800F36A4++;
                    _g->w0 = 0xD7000000;
                    _g->w1 = 0;
                }
                {
                    Gfx *_g = D_800F36A4++;
                    _g->w0 = 0xE200001C;
                    _g->w1 = 0x0C184B50;
                }
                {
                    Gfx *_g = D_800F36A4++;
                    _g->w0 = 0xD9FEFFFF;
                    _g->w1 = 0;
                }
                {
                    Gfx *_g = D_800F36A4++;
                    _g->w0 = 0xFCFFFFFF;
                    _g->w1 = 0xFFFE7838;
                }
            }
            if (fl & 0x400) {
                clr |= 0x20000;
            }
            if (*(s32 *)(cfg + 0x38) != 0) {
                set |= 0x200;
                clr |= 0x400;
            } else {
                set |= 0x400;
                clr |= 0x200;
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
            addr = addr_(&c2);
            {
                Gfx *_g = D_800F36A4++;
                _g->w0 = 0xDE000000;
                _g->w1 = (u32)addr;
            }
        next:
            j++;
        }
        i++;
        if (sel != all) {
            break;
        }
    }
}
