#include "common.h"

typedef struct {
    u16 unk0;
    u8 pad2[0xE];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u16 unk16;
    u8 pad18[3];
    u8 unk1B;
    u8 pad1C[0x84 - 0x1C];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 pad90[0xB8 - 0x90];
    s16 unkB8;
    s16 unkBA;
    s16 unkBC;
    u8 padBE[0xCC - 0xBE];
    s16 unkCC;
    s16 unkCE;
    s16 unkD0;
    u8 padD2[0x296 - 0xD2];
    u8 unk296;
    u8 pad297[0x2A8 - 0x297];
    u16 *unk2A8;
} Unk80065310;

void func_80033590(s32, Unk80065310 *, s32, s32, s32);
u16 func_80063654(s32, u8);
void func_80071C88(Unk80065310 *, u16);
s32 func_80072ACC(Unk80065310 *);

void func_80065310(Unk80065310 *arg0, u16 arg1) {
    s32 *p;
    s16 a;
    s16 b;
    s16 c;
    s32 x;
    s32 y;
    s32 z;

    switch (arg1) {
    case 0x2123:
        arg0->unk296 = *arg0->unk2A8++;
        break;
    case 0x2124:
        arg0->unk16 = *arg0->unk2A8++;
        break;
    case 0x212F:
        p = (s32 *)(((s32)arg0->unk2A8 + 3) & ~3);
        func_80033590(*p, arg0, -1, -1, 0);
        arg0->unk16 = func_80063654(*p++, arg0->unk1B);
        arg0->unk0 &= 0xFFFE;
        arg0->unk2A8 = (u16 *)p;
        break;
    case 0x2134:
        x = func_80072ACC(arg0);
        y = func_80072ACC(arg0);
        z = func_80072ACC(arg0);
        x = (x << 16) >> 4;
        y = (y << 16) >> 4;
        z = (z << 16) >> 4;
        arg0->unk84 = x;
        arg0->unk88 = y;
        arg0->unk8C = z;
        break;
    case 0x2137:
        a = func_80072ACC(arg0);
        b = func_80072ACC(arg0);
        c = func_80072ACC(arg0);
        arg0->unk10 = a;
        arg0->unk12 = b;
        arg0->unk14 = c;
        break;
    case 0x2127:
        a = func_80072ACC(arg0);
        b = func_80072ACC(arg0);
        c = func_80072ACC(arg0);
        arg0->unkB8 = a;
        arg0->unkBA = b;
        arg0->unkBC = c;
        break;
    case 0x2128:
        a = func_80072ACC(arg0);
        b = func_80072ACC(arg0);
        c = func_80072ACC(arg0);
        arg0->unkCC = a;
        arg0->unkCE = b;
        arg0->unkD0 = c;
        break;
    default:
        func_80071C88(arg0, arg1);
        break;
    }
}
