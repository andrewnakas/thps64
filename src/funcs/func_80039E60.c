#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Ent39E60;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} Slot39E60;

void func_800398F8(u8 *, u8, s32, u16, u16);
void func_800A96BC(void *, s32);
extern s32 D_800C0E20;
extern u8 D_800D3F34;
extern Ent39E60 D_800D4040[];
extern u8 D_800D45B8[];
extern Slot39E60 D_800D5C1C[];
extern s32 D_800DE7A0;
extern u8 D_800EA9C0[];

s32 func_80039E60(u32 arg0, u16 arg1, u16 arg2) {
    u32 s;
    u8 *p;

    if (arg0 >= 0xAF) {
        return 0x29;
    }
    s = D_800D45B8[arg0];
    if (s == 0xFF) {
        return 0;
    }
    if (D_800D4040[arg0].unk0 < 0) {
        p = &D_800D3F34;
        func_800398F8(p, arg0, s, arg1, arg2);
        return s;
    }
    if (D_800D5C1C[D_800C0E20].unkC == 0) {
        if (arg0 - 0x2F < 4) {
            return s;
        }
    } else if (D_800DE7A0 != 1 && arg0 - 0x2F < 4) {
        return s;
    }
    if (s == 0x6F) {
        func_800A96BC(D_800EA9C0, 0x80);
    }
    func_800A96BC(D_800EA9C0, s);
    D_800D3F34 = s;
    return s;
}
