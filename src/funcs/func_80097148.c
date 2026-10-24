#include "common.h"

typedef struct {
    u8 pad0[0x48];
    void *unk48;
} Obj80097148;

extern void func_8004B264(Obj80097148 *, void *);
extern void func_8004B330(Obj80097148 *, s32);
extern void func_8004B4F8(Obj80097148 *);
extern void func_800970F0(Obj80097148 *);
extern u8 D_800207E0[];
extern u8 D_800DC5A0[];

void func_80097148(Obj80097148 *arg0, s32 arg1) {
    arg0->unk48 = D_800207E0;
    func_8004B264(arg0, D_800DC5A0);
    func_800970F0(arg0);
    func_8004B330(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
