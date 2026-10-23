#include "common.h"

typedef struct Table80072760 {
    u8 pad0[0x50];
    s16 unk50;
    u8 pad52[2];
    s32 (*unk54)(void *, u16);
} Table80072760;
typedef struct Vec80072760 { s32 x, y, z; } Vec80072760;
typedef struct State80072760 {
    s32 unk0, unk4, unk8, unkC;
    u8 pad10[0x38];
    Table80072760 *unk48;
    u8 pad4C[0x258];
    s32 unk2A4;
    u8 *unk2A8;
    u8 pad2AC[0x6C];
    u16 unk318;
    u8 pad31A[2];
    u8 *unk31C;
    u8 pad320[4];
    s32 unk324, unk328, unk32C;
} State80072760;


s32 func_80039E60(s32, s32, s32);
void func_80039F88(s32);
s32 func_8003A0C4(s32, void *, s32);
s32 func_80070CE0(void *, s32);
extern s32 D_800D3F30;
extern State80072760 *D_800D61A8;

s32 func_80072760(State80072760 *arg0, s32 arg1) {
    u16 sound;
    u16 *cursor;
    u16 flag;
    s32 handle0;
    s32 handle1;
    s32 handle2;
    s32 command;
    u16 value;
    u8 *soundCursor;
    u8 *flagCursor;
    u8 *valueCursor;
    Table80072760 *table;

    command = arg1 & 0xFFFF;
    switch (command) {                              /* irregular */
    case 0x4507:
        handle0 = arg0->unk324;
        if (handle0 != 0) {
            func_80039F88(handle0);
        }
        soundCursor = arg0->unk2A8;
        sound = *(u16 *)soundCursor;
        arg0->unk2A8 = soundCursor + 2;
        arg0->unk324 = func_80039E60(sound, 0x2710, 0);
        arg0->unk328 = -1;
        arg0->unk32C = (s32) D_800D3F30;
        /* fall through */
    case 0x429F:
        break;
    case 0x4508:
        handle1 = arg0->unk324;
        if (handle1 != 0) {
            func_80039F88(handle1);
        }
        cursor = (u16 *)arg0->unk2A8;
        sound = *cursor++;
        arg0->unk2A8 = (u8 *)cursor;
        arg0->unk328 = *cursor++;
        arg0->unk2A8 = (u8 *)cursor;
        arg0->unk324 = func_8003A0C4(sound, &arg0->unk4, 0);
        arg0->unk32C = D_800D3F30;
        break;
    case 0x4509:
        handle2 = arg0->unk324;
        if (handle2 != 0) {
            func_80039F88(handle2);
        }
        arg0->unk324 = 0;
        break;
    case 0x4506:
        if (D_800D61A8 != NULL) {
            *(Vec80072760 *)&arg0->unk4 = *(Vec80072760 *)&D_800D61A8->unk4;
            return 1;
        }
        break;
    case 0x4700:
        flagCursor = arg0->unk2A8;
        flag = *(u16 *)flagCursor;
        arg0->unk2A8 = flagCursor + 2;
        if (flag & 0xFFFF) {
            arg0->unk2A4 = (s32) (arg0->unk2A4 | 0x100);
        } else {
            {
                s32 mask = ~0x100;
                arg0->unk2A4 &= mask;
            }
        }
        break;
    case 0x4504:
        arg0->unk2A8 = (void *) (arg0->unk2A8 + 8);
        /* fallthrough */
    case 0x42A1:
    case 0x429B:
        arg0->unk2A8 = (void *) (arg0->unk2A8 + 0xC);
        break;
    case 0x4503:
        valueCursor = arg0->unk2A8;
        value = *(u16 *)valueCursor;
        arg0->unk2A8 = (void *) (valueCursor + 2);
        if (value & 0x8000) {
        } else if (value & 0x2000) {
            table = arg0->unk48;
            value = table->unk54((u8 *)arg0 + table->unk50, value & 0xFFFF);
        }
        arg0->unk318 = value;
        arg0->unk31C = 0;
        break;
    default:
        return func_80070CE0(arg0, arg1 & 0xFFFF);
    }
    return 1;
}
