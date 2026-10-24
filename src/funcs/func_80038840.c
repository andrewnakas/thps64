/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    f32 x0;
    u8 pad10[4];
    f32 z0;
    f32 x1;
    u8 pad1C[4];
    f32 z1;
} Ob_80038840;

typedef struct {
    u8 pad0[0xC];
    Ob_80038840 **objs;
    s32 nobj;
    u8 pad14[0x30 - 0x14];
    u16 **lists;
    f32 minx;
    f32 maxx;
    f32 minz;
    f32 maxz;
    f32 cw;
    f32 ch;
    s32 nx;
    s32 nz;
} Grid_80038840;

void func_8009E0F0(u16 *, s32, s32);
void *func_8009E6B4(void *, s32, s32);
u16 *func_8009E8F0(void *, s32, s32);
void func_8009ECF8(void *, u16 *);
extern u8 D_800EA110[];

static inline void cell(Grid_80038840 *g, f32 x, f32 z, s32 *px, s32 *pz) {
    if (g->cw != 0.0f) {
        *px = (x - g->minx) / g->cw;
    }
    if (g->ch != 0.0f) {
        *pz = (z - g->minz) / g->ch;
    }
    if (*px >= g->nx) {
        *px = g->nx - 1;
    } else if (*px < 0) {
        *px = 0;
    }
    if (*pz >= g->nz) {
        *pz = g->nz - 1;
    } else if (*pz < 0) {
        *pz = 0;
    }
}

void func_80038840(Grid_80038840 *g) {
    s32 x0, z0, x1, z1;
    s32 n;
    s32 i, j, k;
    s32 idx;
    u16 *cnt;
    Ob_80038840 *o;

    g->nx = 0x14;
    g->nz = 0x14;
    g->cw = (s32)(g->maxx - g->minx) / g->nx;
    g->ch = (s32)(g->maxz - g->minz) / g->nz;
    n = g->nx * g->nz;
    g->lists = func_8009E6B4(D_800EA110, n * 4, 4);
    cnt = func_8009E8F0(D_800EA110, n * 2, 4);
    func_8009E0F0(cnt, 0, n * 2);
    k = 0;
    while (1) {
        if (k >= g->nobj) {
            break;
        }
        o = g->objs[k];
        cell(g, o->x0, o->z0, &x0, &z0);
        cell(g, o->x1, o->z1, &x1, &z1);
        for (j = z0; j <= z1; j++) {
            for (i = x0; i <= x1; i++) {
                cnt[j * g->nx + i]++;
            }
        }
        k++;
    }
    for (k = 0; k < n; k++) {
        g->lists[k] = func_8009E6B4(D_800EA110, (cnt[k] + 1) * 2, 4);
        cnt[k] = 0;
    }
    k = 0;
    while (1) {
        if (k >= g->nobj) {
            break;
        }
        o = g->objs[k];
        cell(g, o->x0, o->z0, &x0, &z0);
        cell(g, o->x1, o->z1, &x1, &z1);
        j = z0;
        while (1) {
            if (j > z1) {
                break;
            }
            i = x0;
            while (1) {
                if (i > x1) {
                    break;
                }
                idx = j * g->nx + i;
                g->lists[idx][cnt[idx]] = k;
                cnt[idx]++;
                i++;
            }
            j++;
        }
        k++;
    }
    for (k = 0; k < n; k++) {
        g->lists[k][cnt[k]] = 0xFFFF;
    }
    func_8009ECF8(D_800EA110, cnt);
}
