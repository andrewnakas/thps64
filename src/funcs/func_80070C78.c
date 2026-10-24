#include "common.h"

void func_8004B264(void *, void *);
void func_8004B4F8(void *);
void func_80072D84(void *, s32);
extern u8 D_8001CFC0[];
extern u8 D_800DDC60[];

typedef struct {
    u8 pad0[0x48];
    void *unk48;
} Obj;

void func_80070C78(Obj *arg0, s32 arg1) {
    arg0->unk48 = D_8001CFC0;
    func_8004B264(arg0, D_800DDC60);
    func_80072D84(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
