#include "common.h"
typedef struct { s16 a; s16 b; void *c; s16 off; s16 pad; void (*fn)(void *, s32); } VtE_F2;
typedef struct { u8 pad[0x44]; VtE_F2 *vt; } Obj_F2;
void func_8004AF30(void *);
void func_800672A0(void *arg0) {
    Obj_F2 *o;
    func_8004AF30(arg0);
    o = *(Obj_F2 **)((u8 *)arg0 + 0x208);
    if (o != NULL) {
        o->vt->fn((u8 *)o + o->vt->off, 3);
    }
    *(Obj_F2 **)((u8 *)arg0 + 0x208) = NULL;
}
