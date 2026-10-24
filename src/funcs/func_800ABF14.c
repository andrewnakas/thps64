/* cflags: -O2 */
#include "common.h"

typedef struct { u8 a; u8 idx; } Ent_ABF14;
typedef struct { Ent_ABF14 *e; s32 pad; } Slot_ABF14;
typedef struct { u8 pad0[0x14]; u16 *tbl; Slot_ABF14 slots[1]; } Obj_ABF14;
typedef struct { u8 pad0[4]; s32 v; } Item_ABF14;
typedef struct { u8 pad0[0x2C]; Item_ABF14 **items; } Ctx_ABF14;

extern Obj_ABF14 *D_800FC324;
extern Ctx_ABF14 *D_800FC318;
extern f32 D_800ECB40;

f32 func_800ABF14(s32 i) {
    Obj_ABF14 *o;
    Ent_ABF14 *e;
    s32 k;
    f32 t;

    if (i < 0) {
        return 0.0f;
    }
    o = D_800FC324;
    if (o == NULL) {
        return 0.0f;
    }
    e = o->slots[i].e;
    if (e == NULL) {
        return 0.0f;
    }
    k = o->tbl[e->idx];
    t = (f32)D_800FC318->items[k]->v * 2.0f / D_800ECB40;
    if (t > 1000.0f || t < 0.0f) {
        return 0.0f;
    }
    return t;
}
