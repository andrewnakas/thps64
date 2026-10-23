/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { s16 delta; s16 idx; void (*fn)(void *, s32); } VEnt;
typedef struct { u8 pad[8]; VEnt e; } VTbl;
typedef struct { VTbl *vt; } VObj;

typedef struct { u8 pad[0x58]; } Ent58;
typedef struct { u8 pad[0x94]; u8 b[0xD8 - 0x94]; } EntD8;

void func_800BC0F4(void *);
void func_80037C84(void *);
void func_800A69C0(void *, s32);
void func_8009BB40(void *, s32);
extern u8 D_800F0DD0[];
extern s32 D_800D36D4;
extern s32 D_800D36D0;
extern s32 D_800D36E4;
extern s32 D_800D36EC;
extern s32 D_800D36F4;
extern s32 D_800D36F0;
extern u8 D_800FA350[];
extern Ent58 D_800FA140[];
extern EntD8 D_800F78D0[];
extern VObj *D_800FA550[];
extern u8 D_800FA600[];

void func_80033A58(void) {
    s32 i;
    s32 j;
    VObj *o;

    func_800BC0F4(D_800F0DD0);
    if (D_800D36D4 != -1) {
        func_80037C84(D_800FA350);
        D_800D36D4 = -1;
    }
    for (i = 0; i < D_800D36D0; i++) {
        func_80037C84(&D_800FA140[i]);
    }
    D_800D36D0 = 0;
    D_800D36E4 = 0;
    for (j = 0; j < D_800D36EC; j++) {
        func_800A69C0(&D_800F78D0[j], -1);
        func_8009BB40(D_800F78D0[j].b, -1);
    }
    for (j = 0; j < D_800D36F4; j++) {
        o = D_800FA550[j];
        if (o != 0) {
            o->vt->e.fn((u8 *)o + o->vt->e.delta, 3);
        }
    }
    D_800D36F4 = 0;
    D_800D36F0 = 0;
    D_800FA600[1] = 0;
    D_800FA600[0] = 0;
    D_800D36EC = 0;
}
