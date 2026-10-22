#include "common.h"

typedef struct {
    u8 pad0[0x13];
    u8 unk13;
    u8 pad14[0x154 - 0x14];
} Ent80028348;

void func_8009C8EC(s32, void *);
void func_8009C914(void *, void *, void *);
void func_8009CAD0(s32);
extern Ent80028348 D_800D4D80[];

void func_80028348(u8 *arg0, s32 arg1, s32 arg2) {
    s32 mtx[16];
    s32 off;
    u8 *base;

    switch (arg2) {
    case 0:
        off = D_800D4D80[*(s8 *)(arg0 + 0xF14)].unk13 << 6;
        break;
    case 1:
        off = *(u16 *)(*(u8 **)(arg0 + 0x1B18) + 0x218) << 6;
        break;
    default:
        func_8009CAD0(arg1);
        return;
    }
    base = *(u8 **)(arg0 + 0x214);
    func_8009C914(mtx, arg0 + 0x2290, base + off);
    func_8009C8EC(arg1, mtx);
}
