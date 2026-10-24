/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 123/312 positional instructions; target 313. Aligned
 * comparison pairs 299/313 equally. Remaining: chain-index lowering and the
 * load order of copied endpoint coordinates. Claude G7 draft, audited by Codex.
 * Corrected node layout: next is +20 (68E24), final word +24 (68E10), with
 * a previously omitted word at +1C. Object next remains +1C (68E30).
 * 689D4..68B64: object/node gates and expanded bounds; 68B64..68CD8: chain
 * selection and segment bounds; 68CD8..68E18: hit/normal/endpoint checks and
 * conditional result writes. IDs are unsigned u16, node type signed s16.
 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80068988;

typedef struct Nd_80068988 {
    s32 unk0;
    V3_80068988 min;
    V3_80068988 max;
    s32 unk1C;
    struct Nd_80068988 *next;
    s32 unk24;
} Nd_80068988;

typedef struct Ob_80068988 {
    u8 pad0[4];
    V3_80068988 pos;
    u8 pad10[0x1C - 0x10];
    struct Ob_80068988 *next;
    u8 pad20[0x84 - 0x20];
    u8 unk84[0x16C - 0x84];
    V3_80068988 prev;
    u8 pad178[0x308 - 0x178];
    s32 unk308;
    u8 pad30C[0x40C - 0x30C];
    s32 unk40C;
    u8 pad410[0x450 - 0x410];
    s32 unk450;
    u8 pad454[0x7D4 - 0x454];
    s32 unk7D4;
    s32 unk7D8;
    u8 pad7DC[4];
    s32 unk7E0;
    s32 unk7E4;
    s32 unk7E8;
    V3_80068988 unk7EC;
    V3_80068988 unk7F8;
    s32 unk804;
    s32 unk808;
    u8 pad80C[0x82C - 0x80C];
    s32 unk82C;
    u8 pad830[0x964 - 0x830];
    u8 *unk964;
} Ob_80068988;

void func_80022964(V3_80068988 *);
s32 func_80022E54(V3_80068988 *, void *);
void func_80046D28(V3_80068988 *, V3_80068988 *);
void func_80046FBC(V3_80068988 *, V3_80068988 *, V3_80068988 *);
s32 func_800470A8(V3_80068988 *, V3_80068988 *);
s32 func_8005D674(V3_80068988 *, V3_80068988 *, V3_80068988 *, V3_80068988 *, V3_80068988 *, s32 *, V3_80068988 *, s32 *);
void func_800617B8(V3_80068988 *, s32);
u16 *func_80061904(s32);
extern Ob_80068988 *D_800D61A8;
extern s16 **D_800DACB0;
extern Nd_80068988 *D_800DC5C0;

void func_80068988(void) {
    V3_80068988 p;
    V3_80068988 q;
    V3_80068988 a;
    V3_80068988 b;
    V3_80068988 r;
    V3_80068988 hit;
    V3_80068988 c;
    V3_80068988 c2;
    s32 u;
    s32 t;
    s32 lx, ly, lz;
    struct { s32 index; } nxt;
    V3_80068988 *pb;
    V3_80068988 *pa;
    V3_80068988 *pc;
    Ob_80068988 *o;
    Ob_80068988 *oo;
    Nd_80068988 *n;
    u16 *e;
    s32 hx, hy, hz;
    s32 cur;
    s32 d;
    s32 fail;

    o = D_800D61A8;
    pb = &b;
    pa = &a;
    pc = &c;
    while (1) {
        if (o == NULL) {
            break;
        }
        oo = o;
        if (*o->unk964 == 0) {
            o->unk40C = 0;
            goto nexto;
        }
        if (o->unk7D4 != 0 || o->unk450 != 0 || o->unk40C != 0) {
            goto nexto;
        }
        lx = o->prev.x;
        ly = o->prev.y;
        lz = o->prev.z;
        hx = o->pos.x;
        hy = o->pos.y;
        hz = o->pos.z;
        if (hx < lx) {
            t = lx;
            lx = hx;
            hx = t;
        }
        if (hy < ly) {
            t = ly;
            ly = hy;
            hy = t;
        }
        if (hz < lz) {
            t = lz;
            lz = hz;
            hz = t;
        }
        lx -= 0x64000;
        hx += 0x64000;
        ly -= 0x64000;
        hy += 0x64000;
        lz -= 0x64000;
        hz += 0x64000;
        n = D_800DC5C0;
        while (1) {
            if (n == NULL) {
                break;
            }
            if (hx >= n->min.x && n->max.x >= lx && hy >= n->min.y && n->max.y >= ly && hz >= n->min.z &&
                n->max.z >= lz && (oo->unk804 <= 0 || oo->unk808 != n->unk0)) {
                cur = n->unk0;
                while (1) {
                    e = func_80061904(cur);
                    if (e[0] == 0) {
                        break;
                    }
                    func_800617B8(&a, cur);
                    nxt.index = (e[-1] == 0xB && *D_800DACB0[e[1]] != 0xA) ? e[2] : e[1];
                    func_800617B8(pb, nxt.index);
                    p = a;
                    q = b;
                    if (q.x < p.x) {
                        t = p.x;
                        p.x = q.x;
                        q.x = t;
                    }
                    if (q.y < p.y) {
                        t = p.y;
                        p.y = q.y;
                        q.y = t;
                    }
                    if (q.z < p.z) {
                        t = p.z;
                        p.z = q.z;
                        q.z = t;
                    }
                    if (hx >= p.x && q.x >= lx && hy >= p.y && q.y >= ly && hz >= p.z && q.z >= lz) {
                        d = func_8005D674(&oo->prev, &oo->pos, pa, pb, &r, &u, &hit, &t);
                        if (d < oo->unk7E8 && ((oo->unk82C != 0 && oo->unk82C != 2) || hit.y >= oo->pos.y)) {
                            fail = 0;
                            func_80046FBC(pc, pb, pa);
                            func_80022964(pc);
                            if (func_80022E54(pc, oo->unk84) >= 0) {
                                oo->unk7F8 = c;
                                fail = func_800470A8(&hit, pb) != 0;
                            } else {
                                func_80046D28(&c2, pc);
                                oo->unk7F8 = c2;
                                if (func_800470A8(&hit, pa) != 0) {
                                    fail = 1;
                                }
                            }
                            if (fail == 0) {
                                oo->unk7E8 = d;
                                oo->unk7D8 = 1;
                                oo->unk7E0 = n->unk0;
                                oo->unk7E4 = cur;
                                oo->unk7EC = hit;
                                oo->unk308 = n->unk24;
                            }
                        }
                    }
                    cur = nxt.index;
                }
            }
            n = (Nd_80068988 *)n->next;
        }
    nexto:
        o = o->next;
    }
}
