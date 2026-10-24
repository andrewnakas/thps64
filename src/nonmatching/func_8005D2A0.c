/* cflags: -O2 -fno-schedule-insns2 */
/* NON_MATCHING: aln 0.647. Equivalent C; -O2 spill/register allocation of the matrix-stack walk and the stack layout (game: stack at sp+0x14, tmp at sp+0xC0, frame 0x118) differ. Review fix: the anim-table entries are 8 bytes (the draft used a 10-byte struct, wrong index stride). */
/* Z3: C4 draft with -O2 -fno-schedule-insns2 (sched1 on): 121/245 paired (C4's flags 113). Still far: -O2 spill and
   register allocation of the matrix-stack walk, and the 4-aligned stack array at 0x14 (X1). */
/* C4 draft 113/245 (-O2 nosched). Game frame 0x118: stack entries {MtxS m; u32 idx} start at sp+0x14 (s0=&stack[0], bound s5=sp+0x30), tmp at sp+0xC0, spills out/base/cnt/n/o/tbl at 0xD8-0xEC; o kept in a1. Ours: stack at 0x10, frame 0x108. Index loops over node[i]/bone[i] give the game's fp/s6/s7 givs. */
/* DRAFT (not close): logic believed right; -O2 reg alloc/spills and stack layout (stack at sp+0x14, tmp at 0xC0) differ. */
#include "common.h"

typedef struct {
    s16 m[3][3];
    s16 t[3];
} MtxS;

typedef struct {
    MtxS m;
    u32 idx;
} StkEnt;

typedef struct {
    s16 x, y, z;
    s16 pad[3];
} Bone;

typedef struct {
    u16 id;
    u8 pad2[8];
    u16 parent;
} Node;

/* 8-byte animation entries; like matched sibling func_8005CF38, the u16 tested lies 8 bytes past entry k */
typedef struct {
    u8 pad0[8];
} AnimTbl;

typedef struct {
    u8 pad0[0x20];
    AnimTbl *tbl;
    u8 pad24[0x38 - 0x24];
    u16 n;
    u8 pad3A[0x48 - 0x3A];
} Model;

typedef struct {
    u16 flags;
    u8 pad2[0x1B - 2];
    u8 model;
    u8 pad1C[0x21E - 0x1C];
    u16 anim;
    u8 pad220[0x27C - 0x220];
    MtxS *out;
    Bone *bones;
    Node *nodes;
} Obj5D2A0;

void func_80023260(MtxS *, MtxS *, MtxS *);
void func_80023268(MtxS *, MtxS *, MtxS *);
void func_800232DC(Bone *, MtxS *);
MtxS *func_8007EBE4(Obj5D2A0 *);
extern Model D_800DAF98[];

void func_8005D2A0(Obj5D2A0 *o) {
    StkEnt stack[6];
    MtxS tmp;
    MtxS *out;
    Node *node;
    Bone *bone;
    Model *mdl;
    s32 n;
    AnimTbl *tbl;
    s32 cnt;
    MtxS *base;
    StkEnt *sp;
    s32 i;
    s32 j;
    s32 k;
    u16 id;
    MtxS *dst;
    MtxS *src;

    out = o->out;
    node = o->nodes;
    bone = o->bones;
    if (!(o->flags & 4) || out == NULL || bone == NULL) {
        return;
    }
    mdl = &D_800DAF98[o->model];
    n = mdl->n;
    tbl = mdl->tbl;
    for (i = 0; i < n; i++) {
        out[i].m[0][0] = -0x8000;
    }
    cnt = ((u16 *)node)[-1];
    base = func_8007EBE4(o);
    sp = &stack[0];
    for (i = 0; i < cnt; i++) {
        id = node[i].id;
        while (sp >= &stack[1] && node[i].parent < sp->idx) {
            sp--;
        }
        if (bone[i].x != 0 || bone[i].y != 0 || bone[i].z != 0) {
            func_800232DC(&bone[i], &tmp);
            tmp.t[2] = 0;
            tmp.t[1] = 0;
            tmp.t[0] = 0;
            func_80023260(&tmp, &base[id], &tmp);
            if (sp >= &stack[1]) {
                func_80023260(&tmp, &sp->m, &tmp);
            }
            sp++;
            func_80023268(&sp->m, &tmp, &base[id]);
            sp->idx = i;
            dst = &out[id];
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    dst->m[j][k] = tmp.m[j][k];
                }
                dst->t[j] = tmp.t[j];
            }
        } else if (sp >= &stack[1]) {
            func_80023260(&out[id], &sp->m, &base[id]);
        } else {
            dst = &out[id];
            src = &base[id];
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    dst->m[j][k] = src->m[j][k];
                }
                dst->t[j] = src->t[j];
            }
        }
    }
    if (*(u16 *)((u8 *)&tbl[o->anim] + 8) == 0) {
        for (i = 0; i < n; i++) {
            if (out[i].m[0][0] == -0x8000) {
                out[i] = base[i];
            }
        }
    }
}
