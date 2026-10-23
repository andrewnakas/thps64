#include "common.h"

typedef struct {
    u8 pad[0xD0];
    s32 unkD0;
    u8 pad2[4];
    s32 unkD8[11];
    u8 unk104;
    u8 unk105;
} Struct8003A410;

void func_800A8EF0(void *, s32);
void func_800A9220(void *, s32, f32);
void func_800A9460(void *, s32, f32, s32);
extern s32 D_800D0FF0;
extern s32 D_800EA9C0;

void func_8003A410(Struct8003A410 *arg0, f32 arg1, s32 arg2) {
    s32 *p;

    arg0->unk105++;
    arg0->unk105 = arg0->unk105 % arg0->unk104;
    if (arg2 >= 0) {
        func_800A9460(&D_800EA9C0, 0, 0.0f, arg2);
    }
    p = &D_800EA9C0;
    func_800A9220(p, arg0->unkD8[arg0->unk105], arg1);
    func_800A8EF0(p, D_800D0FF0);
    arg0->unkD0 = 1;
}
