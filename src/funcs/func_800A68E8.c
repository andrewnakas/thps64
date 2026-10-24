/* cflags: -O2 */
#include "common.h"

void func_8009CAD0(f32 *);
void func_800A6D38(void *, s32, f32 *);

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x10];
    f32 unk20;
} Obj;

void func_800A68E8(Obj *arg0) {
    f32 m[16];

    func_8009CAD0(m);
    func_800A6D38(arg0, 0, m);
    arg0->unk0 = 0;
    arg0->unkC = 0;
    arg0->unk6 = 1;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk20 = 1.0f;
}
