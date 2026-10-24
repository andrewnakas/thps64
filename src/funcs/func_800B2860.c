/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Sub;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Sub2;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Sub unkC;
    Sub2 unk18;
} Obj;

void func_800B3124(Sub *, s32);

Obj *func_800B2860(Obj *arg0) {
    Sub *s = &arg0->unkC;
    Sub2 *t;

    func_800B3124(s, 0);
    s->unk8 = 0;
    arg0->unk18.unk0 = 8;
    t = &arg0->unk18;
    t->unk4 = 0xC;
    t->unkC = 0;
    t->unk8 = 0;
    arg0->unk8 = 0;
    return arg0;
}
