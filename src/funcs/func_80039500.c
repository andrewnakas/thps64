#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x2C - 0x8];
    void *unk2C;
} Obj39500;

void func_800A5F10(void *);
extern u8 D_80019EB0[];

Obj39500 *func_80039500(Obj39500 *arg0) {
    arg0->unk2C = D_80019EB0;
    func_800A5F10(arg0->unk8);
    arg0->unk0 = 0;
    arg0->unk4 = -1;
    return arg0;
}
