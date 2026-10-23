#include "common.h"

typedef struct Table80071C88 {
    u8 pad0[0x50];
    s16 unk50;
    u8 pad52[2];
    s32 (*unk54)(void *, u16);
} Table80071C88;
typedef struct State80071C88 {
    u16 unk0;
    u8 pad2[0x2];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x6];
    u16 unk16;
    u8 pad18[0x3];
    u8 unk1B;
    u8 pad1C[0x2C];
    Table80071C88 * unk48;
    u8 pad4C[0x110];
    u16 unk15C;
    u8 pad15E[0x4];
    u16 unk162;
    u8 pad164[0xC4];
    s32 unk228;
    u8 pad22C[0x6B];
    u8 unk297;
    u8 unk298;
    u8 pad299[0x7];
    u16 unk2A0;
    u8 pad2A2[0x6];
    u8 * unk2A8;
    u8 pad2AC[0x34];
    u16 unk2E0;
    u8 pad2E2[0xE];
    u16 unk2F0;
    u16 unk2F2;
    u8 pad2F4[0x4];
    s32 unk2F8;
} State80071C88;

void func_80033590(s32, void *, s32, s32, s32);            /* extern */
s16 func_80063654(s32, u8);                         /* extern */

void func_80071C88(State80071C88 *arg0, s32 arg1) {
    switch (arg1 & 0xFFFF) {
    case 0x2135:
    {
        s32 * aligned;
        aligned = (s32 *)(((s32)arg0->unk2A8 + 3) & ~3);
        arg0->unk2F8 = *aligned;
        arg0->unk2A8 = (u8 *)(aligned + 1);
        break;
    }
    case 0x212F:
    {
        s32 * aligned;
        aligned = (s32 *)(((s32)arg0->unk2A8 + 3) & ~3);
        func_80033590(*aligned, arg0, -1, -1, 0);
        arg0->unk16 = func_80063654(*aligned, arg0->unk1B);
        arg0->unk2A8 = (u8 *)(aligned + 1);
        break;
    }
    /* Preserve the two flag tests: combining them changes the original branches. */
    case 0x2140:
    {
        u16 value;
        Table80071C88 * table;
        value = *(u16 *)arg0->unk2A8;
        arg0->unk2A8 += 2;
        if (value & 0x8000) {
        } else if (value & 0x2000) {
            table = arg0->unk48;
            value = table->unk54((u8 *)arg0 + table->unk50, value);
        }
        arg0->unk4 = (s16)value << 12;
        break;
    }
    case 0x2141:
    {
        u16 value;
        Table80071C88 * table;
        value = *(u16 *)arg0->unk2A8;
        arg0->unk2A8 += 2;
        if (value & 0x8000) {
        } else if (value & 0x2000) {
            table = arg0->unk48;
            value = table->unk54((u8 *)arg0 + table->unk50, value);
        }
        arg0->unk8 = (s16)value << 12;
        break;
    }
    case 0x2142:
    {
        u16 value;
        Table80071C88 * table;
        value = *(u16 *)arg0->unk2A8;
        arg0->unk2A8 += 2;
        if (value & 0x8000) {
        } else if (value & 0x2000) {
            table = arg0->unk48;
            value = table->unk54((u8 *)arg0 + table->unk50, value);
        }
        arg0->unkC = (s16)value << 12;
        break;
    }
    case 0x2131:
    {
        u16 value;
        value = *(u16 *)arg0->unk2A8;
        arg0->unk2A8 += 2;
        if (value) {
            arg0->unk0 |= 8;
        } else {
            arg0->unk0 &= 0xFFF7;
        }
        break;
    }
    case 0x212E:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk2A0 = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    case 0x212C:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk298 = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    case 0x212D:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk297 = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    case 0x2100:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk162 = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    case 0x2101:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk15C = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    case 0x2125:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        u16 index;
        index = *cursor;
        cursor++;
        arg0->unk2A8 = (u8 *)cursor;
        *(u16 *)((u8 *)arg0 + ((index & 0xFFFF) << 1) + 0x2CC) = *cursor;
        cursor++;
        arg0->unk2A8 = (u8 *)cursor;
        break;
    }
    case 0x2114:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk2F0 = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    case 0x2115:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk2F2 = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    case 0x2120:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        u16 value;
        u16 index;
        Table80071C88 * table;
        index = *cursor;
        cursor++;
        arg0->unk2A8 = (u8 *)cursor;
        value = *cursor;
        cursor++;
        arg0->unk2A8 = (u8 *)cursor;
        if (value & 0x8000) {
        } else if (value & 0x2000) {
            table = arg0->unk48;
            value = table->unk54((u8 *)arg0 + table->unk50, value);
        }
        *(u16 *)((u8 *)arg0 + ((index & 0xFF) << 1) + 0x2E4) = value;
        break;
    }
    case 0x2121:
    {
        u16 value;
        value = *(u16 *)arg0->unk2A8;
        arg0->unk2A8 += 2;
        arg0->unk228 = (s16)value;
        break;
    }
    case 0x2122:
    {
        u16 *cursor = (u16 *)arg0->unk2A8;
        arg0->unk2E0 = *cursor;
        arg0->unk2A8 = (u8 *)(cursor + 1);
        break;
    }
    }
}
