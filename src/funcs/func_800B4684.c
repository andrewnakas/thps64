/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    s16 off;
    u8 pad1A[2];
    s32 (*fn)(void *);
} Vt;

typedef struct {
    u8 pad0[0x1C4];
    Vt *vt;
} Obj;

typedef struct {
    s32 unk0;
    s32 unk4;
} Tbl;

void func_8009B650(s32, s32);
s32 func_800B713C(Tbl *, s32);
extern Obj *D_800F5660;
extern Tbl D_800F566C;

void func_800B4684(s32 arg0) {
    Obj *o = D_800F5660;

    func_8009B650(arg0, D_800F566C.unk4 + func_800B713C(&D_800F566C, o->vt->fn((void *)((s32)o + o->vt->off))));
}
