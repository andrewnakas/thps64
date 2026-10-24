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
} Ent800AA0F4;

typedef struct {
    u8 pad0[0x6C];
    s32 state;
    f32 unk70;
    f32 unk74;
    s32 track[200];
    u8 pad398;
    u8 cur;
    u8 pad39A[0x19A];
    Ent800AA0F4 ents[200];
} Obj800AA0F4;

void func_800A96BC(Obj800AA0F4 *, s32);
s32 func_800A9D64(Obj800AA0F4 *, s32);

void func_800AA0F4(Obj800AA0F4 *arg0) {
    if (arg0->state == 0) {
        if (func_800A9D64(arg0, arg0->track[arg0->cur]) != 0) {
            arg0->state = 3;
            func_800A96BC(arg0, arg0->track[arg0->cur]);
            arg0->unk74 = arg0->ents[arg0->track[arg0->cur]].unk18;
            return;
        }
        if (arg0->track[arg0->cur] == -2) {
            arg0->state = 4;
            arg0->unk70 = 0.5f;
        } else if (arg0->track[arg0->cur] == -1) {
            arg0->state = 0;
        }
    }
}
