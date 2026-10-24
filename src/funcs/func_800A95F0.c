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
} Ent800A95F0;

typedef struct {
    s32 active;
    s32 time;
    u8 pad8[0x52C];
    Ent800A95F0 ents[200];
} Obj800A95F0;

s32 func_800A9D64(Obj800A95F0 *);
s32 func_800ABEC4(s32);

s32 func_800A95F0(Obj800A95F0 *arg0, s32 i) {
    s32 j = i;

    if (arg0->active == 0 || func_800A9D64(arg0) == 0) {
        return 0;
    }
    func_800ABEC4(arg0->ents[j].unk4);
    if (arg0->ents[j].unk8 == 0xF && arg0->ents[j].unkC + 0xF < arg0->time && func_800ABEC4(arg0->ents[j].unk4) == 0) {
        return 0;
    }
    return arg0->ents[j].unk8 + arg0->ents[j].unkC >= arg0->time;
}