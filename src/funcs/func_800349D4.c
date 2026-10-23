/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { s16 delta; s16 idx; void (*fn)(void *); } VEnt;
typedef struct { u8 pad[0x10]; VEnt e; } VTbl;
typedef struct { VTbl *vt; } VObj;

void func_800BAAFC(void *);
void func_8003460C(void);
void func_80039124(void *);
void func_8009B28C(void *);
extern u8 D_800EECF0[];
extern s32 D_800D36F4;
extern VObj *D_800FA550[];
extern u8 D_800FA350[];
extern u8 D_800D36F8[];
extern f32 D_800FA590;
extern f32 D_800F5668;

void func_800349D4(void) {
    s32 i;
    VObj *o;
    f32 f;

    func_800BAAFC(D_800EECF0);
    func_8003460C();
    for (i = 0; i < D_800D36F4; i++) {
        o = D_800FA550[i];
        o->vt->e.fn((u8 *)o + o->vt->e.delta);
    }
    func_80039124(D_800FA350);
    func_8009B28C(D_800D36F8);
    D_800FA590 = f = D_800FA590 + D_800F5668;
    if (f > 1.0f) {
        D_800FA590 = f - 1.0f;
    }
}
