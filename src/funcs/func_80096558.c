/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { s16 off; s16 pad; void (*fn)(void *, s32); } VEnt80096558;
typedef struct { u8 pad[8]; VEnt80096558 e; } VTbl80096558;
typedef struct { u8 pad[0x13B0]; VTbl80096558 *vt; } Obj80096558;

void func_8009E334(void *);
extern void *D_800FC2E0;
extern void *D_800FC2E4;
extern Obj80096558 *D_800E9280;

void func_80096558(void) {
    Obj80096558 *o;

    func_8009E334(D_800FC2E0);
    func_8009E334(D_800FC2E4);
    D_800FC2E4 = 0;
    D_800FC2E0 = 0;
    o = D_800E9280;
    if (o != 0) {
        o->vt->e.fn((u8 *)o + o->vt->e.off, 3);
    }
    D_800E9280 = 0;
}
