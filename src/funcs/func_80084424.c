/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x24];
    f32 x;
    f32 y;
    f32 z;
} Obj80084424;

typedef struct {
    u8 pad0[0xC];
    Obj80084424 **objs;
    u8 pad10[0x30 - 0x10];
    u16 **cells;
    u8 pad34[0x4C - 0x34];
    s32 width;
} Grid80084424;

typedef struct {
    f32 dist;
    u8 pad4[0x34];
} Hit80084424;

typedef struct {
    u8 pad0[0x54];
    Hit80084424 *best;
} Sub80084424;

typedef struct {
    u8 pad0[0xCC];
    s32 minX;
    s32 padD0;
    s32 minZ;
    s32 maxX;
    s32 padDC;
    s32 maxZ;
} Sk80084424;

extern void func_80038FDC(Grid80084424 *, s32, s32, s32 *, s32 *);
extern void func_80084274(Sk80084424 *, Obj80084424 *, f32 *, s32);
extern Grid80084424 *D_800E8A10;
extern Hit80084424 D_800FBD40[];
extern u8 D_800FC0C0;

void func_80084424(Sk80084424 *arg0) {
    f32 pos[3];
    s32 c0[2];
    s32 c1[2];
    Grid80084424 *grid;
    Sub80084424 *sub;
    u16 *cell;
    s32 idx;
    f32 px;
    f32 py;
    f32 pz;
    Hit80084424 *b;
    Obj80084424 *o;
    s32 x;
    s32 z;
    Hit80084424 *best;
    f32 min;
    s32 i;

    grid = D_800E8A10;
    sub = (Sub80084424 *)((u8 *)arg0 + 0xA4);
    func_80038FDC(grid, arg0->minX, arg0->minZ, &c0[0], &c0[1]);
    func_80038FDC(D_800E8A10, arg0->maxX, arg0->maxZ, &c1[0], &c1[1]);
    z = c0[1];
    while (1) {
        if (z > c1[1]) break;
        x = c0[0];
        while (1) {
            if (x > c1[0]) break;
            cell = D_800E8A10->cells[z * D_800E8A10->width + x];
            while (1) {
                idx = *cell++;
                if (idx == 0xFFFF) break;
                o = grid->objs[idx];
                px = o->x;
                py = o->y;
                pz = o->z;
                pos[0] = px;
                pos[1] = py;
                pos[2] = pz;
                func_80084274(arg0, o, pos, 0);
            }
            x++;
        }
        z++;
    }
    if (D_800FC0C0 == 0) {
        best = NULL;
    } else {
        min = 1000000.0f;
        b = NULL;
        for (i = 0; i < D_800FC0C0; i++) {
            if (D_800FBD40[i].dist < min) {
                min = D_800FBD40[i].dist;
                b = &D_800FBD40[i];
            }
        }
        best = b;
    }
    sub->best = best;
}
