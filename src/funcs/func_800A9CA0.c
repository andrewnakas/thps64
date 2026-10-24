/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 id;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s8 unk14;
    s8 unk15;
    s8 unk16;
    s8 pad17;
    f32 unk18;
    f32 unk1C;
    s32 pad20;
} Ent800A9CA0;

typedef struct {
    s32 active;
    u8 pad4[0x530];
    Ent800A9CA0 ents[200];
} Obj800A9CA0;

s32 func_800A9D64(Obj800A9CA0 *);
f32 func_800ABF14(s32);

void func_800A9CA0(Obj800A9CA0 *arg0, s32 i, s32 arg2, f32 arg3, s8 arg4) {
    if (arg0->active != 0 && func_800A9D64(arg0) != 0) {
        if (arg3 == -12.0f) {
            arg0->ents[i].unk18 = 2.0f * func_800ABF14(arg0->ents[i].id);
        }
        arg0->ents[i].unk8 = arg2;
        arg0->ents[i].unk1C = arg3;
        arg0->ents[i].unk14 = arg4;
    }
}
