#include "common.h"

typedef struct {
    u8 pad0[0x184];
    s32 unk184;
    s32 unk188;
} Obj3B95C;

void func_800394A8(void *, s32);
void func_8003C894(void *, s32);
void func_800A735C(void *, s32);
void func_800B19C0(void *, s32);
extern u8 D_8001A060[];
extern Obj3B95C D_800DC3F8;

void func_8003B95C(u8 *arg0, s32 arg1) {
    *(void **) (arg0 + 0x2C) = D_8001A060;
    D_800DC3F8.unk184 = *(s32 *) (arg0 + 0x34);
    D_800DC3F8.unk188 = *(s32 *) (arg0 + 0x38);
    func_800B19C0(arg0 + 0x958, 2);
    func_800B19C0(arg0 + 0x944, 2);
    func_800B19C0(arg0 + 0x930, 2);
    func_8003C894(arg0 + 0x2C0, 2);
    func_800A735C(arg0 + 0x80, 2);
    func_800394A8(arg0, arg1);
}
