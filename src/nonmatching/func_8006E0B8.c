/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 11/297 positional instructions; target 310. Aligned
 * comparison pairs 190/310 equally. Frame, loop induction, alias reloads and
 * unused stack-rectangle stores differ. Claude B3 draft, audited by Codex.
 * 6E0FC..6E164: slot search/duplicate return; 6E164..6E268: palette/array
 * allocation; 6E268..6E43C: sprite records; 6E43C..6E560: defaults/cleanup.
 * Slot and sprite strides are 0x24; image stride is 0x10. Palette and CLUT accesses
 * are u16, UV/slot+18 are u8; dimensions, offsets and final division are s32.
 * Unused local rectangle stores at 6E20C..6E224 and 6E2C8..6E2DC have no
 * escaped address; omitted to avoid reading the uninitialized saved registers.
 */
#include "common.h"

typedef struct {
    s32 v0;
    s32 v4;
    s32 v8;
    s32 vC;
    s32 v10;
    u8 b14;
    u8 b15;
    u16 h16;
    u8 b18;
    u8 b19;
    u8 pad1A[2];
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 b1F;
    s32 v20;
} Spr6E0B8;

typedef struct {
    u8 pad0[0x10];
    s32 v10;
    Spr6E0B8 *v14;
    u8 b18;
    u8 pad19;
    s16 h1A;
    s32 v1C;
    s32 v20;
} Slot6E0B8;

typedef struct {
    s32 w;
    s32 h;
    s32 v8;
    s32 vC;
} Img6E0B8;

typedef struct {
    s32 n;
    Img6E0B8 img[1];
} Pack6E0B8;

void func_8005EA48(void *);
void *func_8005EAB4(s32, s32, s32);
void func_8006E9C0(s32);
void func_8007F1A0(s32, s32, s32, s32 *, s32 *, s32, s32, s32);
s32 func_8009FD60(Slot6E0B8 *, void *);
s32 func_8009FD8C(Slot6E0B8 *, void *);
extern s32 D_800DC954;
extern s32 D_800DC958;
extern Slot6E0B8 D_800DCAB4[];
extern u16 D_800DCC1C;
extern s32 D_800DE5FC;
extern s32 D_800DE600;

s32 func_8006E0B8(void *name, Pack6E0B8 *pk, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp30;
    s32 sp34;
    s32 i;
    s32 slot;
    Slot6E0B8 *e;
    u16 *pal;
    s32 k;
    s32 w;
    s32 h;
    Img6E0B8 *image;

    func_8006E9C0(1);
    slot = D_800DC954;
    for (i = 0; i < D_800DC954; i++) {
        e = &D_800DCAB4[i];
        if (e->v14 == NULL) {
            slot = i;
        } else if (func_8009FD8C(e, name) == 0) {
            func_8005EA48(pk);
            D_800DC958 = i;
            return 0;
        }
    }
    D_800DE5FC = 1;
    D_800DE600 = 1;
    if (slot == D_800DC954) {
        D_800DC954 = slot + 1;
    }
    e = &D_800DCAB4[slot];
    e->v10 = pk->n;
    func_8009FD60(e, name);
    pal = func_8005EAB4(0x20, 1, 1);
    for (k = 0; k < 16; k++) {
        pal[k] = ((u16 *)((u8 *)pk + (e->v10 << 4) + 4))[k];
    }
    func_8005EA48(pal);
    e = &D_800DCAB4[slot];
    e->v14 = func_8005EAB4(e->v10 * 0x24, 0, 1);
    e->h1A = 0x100;
    for (i = 0, image = pk->img; i < e->v10; i++, image++) {
        w = image->w;
        h = image->h;
        func_8007F1A0(0, w << 2, h, &sp30, &sp34, 4, 0, 0);
        e->v14[i].v8 = sp30;
        e->v14[i].vC = sp34;
        e->v14[i].v0 = w;
        e->v14[i].v4 = h;
        e->v14[i].v10 = image->v8;
        if (arg4 == -1 || (arg4 == 0 && i == 0)) {
            e->v14[i].v20 = image->vC;
        } else if (arg4 == 0) {
            e->v14[i].v20 = e->v14->v20;
        } else {
            e->v14[i].v20 = arg4;
        }
        e->v14[i].b14 = (((u8 *)&sp30)[3] & 0x3F) << 2;
        e->v14[i].b15 = ((u8 *)&sp34)[3];
        e->v14[i].b18 = e->v14[i].b14 + (w << 2);
        e->v14[i].b19 = e->v14[i].b15;
        e->v14[i].b1C = e->v14[i].b14;
        e->v14[i].b1D = e->v14[i].b15 + h;
        e->v14[i].b1E = e->v14[i].b18;
        e->v14[i].b1F = e->v14[i].b1D;
        e->v14[i].h16 = D_800DCC1C;
    }
    func_8005EA48(pk);
    if (arg3 == -1) {
        D_800DCAB4[slot].b18 = D_800DCAB4[slot].v14->v0 >> 1;
    } else {
        D_800DCAB4[slot].b18 = arg3;
    }
    if (arg2 == -1) {
        D_800DCAB4[slot].v1C = D_800DCAB4[slot].v14->v0 >> 2;
    } else {
        D_800DCAB4[slot].v1C = arg2;
    }
    D_800DCAB4[slot].v20 = D_800DCAB4[slot].v14->v0 * 28 / 10;
    D_800DE5FC = 0;
    D_800DE600 = 0;
    D_800DC958 = slot;
    return slot;
}
