/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    void *unk1C;
    u8 pad20[0x184 - 0x20];
    s32 unk184;
    u8 pad188[0x6D8 - 0x188];
    s32 unk6D8;
} Obj;

void func_8009ECF8(void *, s32);
void func_800A5FD0(Obj *, s32);
extern u8 D_80021810[];
extern u8 D_800EA110[];

void func_800A415C(Obj *arg0, s32 arg1) {
    arg0->unk1C = D_80021810;
    func_8009ECF8(D_800EA110, arg0->unk6D8);
    func_8009ECF8(D_800EA110, arg0->unk184);
    func_800A5FD0(arg0, arg1);
}
