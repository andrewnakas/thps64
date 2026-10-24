#include "common.h"

typedef struct {
    u8 data[0x240];
} Elem;

typedef struct {
    u8 pad0[0x114];
    u8 unk114[0x14];
    u8 unk128[0x14];
    u8 unk13C[0x14];
    u8 unk150[0x14];
    u8 unk164[0x24];
    Elem unk188[8];
} Obj;

void func_8009E334(Obj *);
void func_800A735C(void *, s32);
void func_800B19C0(void *, s32);

void func_80087234(Obj *arg0, s32 arg1) {
    if (arg0->unk188 != NULL) {
        Elem *p = &arg0->unk188[8];
        while (arg0->unk188 != p) {
            p--;
            func_800A735C(p, 2);
        }
    }
    func_800B19C0(arg0->unk164, 2);
    func_800B19C0(arg0->unk150, 2);
    func_800B19C0(arg0->unk13C, 2);
    func_800B19C0(arg0->unk128, 2);
    func_800B19C0(arg0->unk114, 2);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
