#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0xC];
} Elem;

typedef struct {
    u8 pad0[0x2C];
    void *vtbl;
    Elem unk30;
    Elem unk44[3];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
} Obj;

void func_80039500(Obj *);
void func_800242CC(void);
void func_80097B44(Obj *);
void func_800B198C(Elem *);
void func_800B1A80(Elem *, s32);
s32 func_800B4240(u8, s32);
extern u8 D_80020860[];
extern u8 D_800D0FC2;
extern u16 D_800D0FD8;

Obj *func_800976C0(Obj *arg0) {
    Elem *p;
    s32 i;
    s32 id;
    s32 x;
    Elem *e;

    func_80039500(arg0);
    arg0->vtbl = D_80020860;
    func_800B198C(&arg0->unk30);
    p = arg0->unk44;
    i = 2;
    do {
        func_800B198C(p);
        i--;
        p++;
    } while (i != -1);
    func_800242CC();
    if (D_800D0FD8 == 2) {
        func_800B1A80(&arg0->unk30, 0x99);
    } else {
        func_800B1A80(&arg0->unk30, 0x98);
    }
    arg0->unk30.unk4 = 1;
    func_800B1A80(&arg0->unk44[0], 0xDF);
    func_800B1A80(&arg0->unk44[1], 0xE0);
    func_800B1A80(&arg0->unk44[2], 0xE1);
    arg0->unk8C = 0;
    arg0->unk88 = 0;
    arg0->unk80 = 0;
    arg0->unk84 = 1;
    arg0->unk90 = func_800B4240(D_800D0FC2, 0x1000);
    if (arg0->unk90 == 0) {
        func_80097B44(arg0);
    }
    arg0->unk94 = 0;
    return arg0;
}
