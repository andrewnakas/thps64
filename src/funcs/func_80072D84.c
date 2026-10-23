#include "common.h"

typedef struct State80072D84 {
    u8 pad0[0x48];
    void *unk48;
    u8 pad4C[0x2BC];
    s32 unk308;
} State80072D84;

void func_80039F88(s32);
void func_8004A11C(void *, s32);
void func_8004B4F8(void *);
extern u8 D_8001D2E0;
extern s32 D_800DDC50;

void func_80072D84(State80072D84 *arg0, s32 arg1) {
    s32 handle;

    arg0->unk48 = &D_8001D2E0;
    D_800DDC50 -= 1;
    handle = arg0->unk308;
    if (handle != 0) {
        func_80039F88(handle);
    }
    func_8004A11C(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
