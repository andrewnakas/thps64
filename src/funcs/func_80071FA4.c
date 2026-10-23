#include "common.h"

typedef struct Table80071FA4 {
    u8 pad0[0x50];
    s16 unk50;
    u8 pad52[2];
    u16 (*unk54)(void *, u16, void *);
} Table80071FA4;
typedef struct Value80071FA4 { u16 unk0, unk2; } Value80071FA4;
typedef struct Vec80071FA4 { s32 x, y, z; } Vec80071FA4;
typedef struct State80071FA4 {
    u8 pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x38];
    Table80071FA4 * unk48;
    u8 pad4C[0x112];
    u16 unk15E;
    u8 pad160[0x2];
    s16 unk162;
    u8 pad164[0x133];
    u8 unk297;
    u8 unk298;
    u8 pad299[0x7];
    u16 unk2A0;
    u8 pad2A2[0x6];
    u8 * unk2A8;
    u8 pad2AC[0x36];
    s16 unk2E2;
    s16 unk2E4;
} State80071FA4;

s32 func_80048E68(void *, void *);      /* extern */
u32 func_80049B4C(void *, void *);             /* extern */
s32 func_80049D60(s32);                /* extern */
Value80071FA4 *func_80061904(s32);                      /* extern */
extern State80071FA4 *D_800D61A8;
extern s32 D_800DE4CC;

s32 func_80071FA4(State80071FA4 *arg0, s32 arg1) {
    Vec80071FA4 position;
    s32 query;
    u8 cursorIndex;
    s32 cursorValue;
    u16 code;
    u32 distance;
    u8 *cursor0;
    Value80071FA4 *value;
    u8 *cursor2;
    Table80071FA4 *table;
    u8 *cursor1;

    query = arg1 & 0xFFFF;
    switch (query) {
    case 0x2136:
        return D_800DE4CC;
    case 0x2132:
        if (D_800D61A8 != NULL) {
            distance = func_80049B4C(&arg0->unk4, &D_800D61A8->unk4);
            if (distance >= 0x2000U) {
                distance = 0x1FFF;
            }
            return (s32) distance;
        }
        return 0x1FFF;
    case 0x2133:
        if (D_800D61A8 != NULL) {
            position = *(Vec80071FA4 *)&arg0->unk4;
            position.y -= arg0->unk2E2 << 0xC;
            return func_80048E68(&position, &D_800D61A8->unk4);
        }
        return 0;
    case 0x212E:
        return (s32) arg0->unk2A0;
    case 0x212C:
        return (s32) arg0->unk298;
    case 0x212D:
        return (s32) arg0->unk297;
    case 0x2140:
        return (s32) arg0->unk4 >> 0xC;
    case 0x2141:
        return (s32) arg0->unk8 >> 0xC;
    case 0x2142:
        return (s32) arg0->unkC >> 0xC;
    case 0x2150:
        if (D_800D61A8 != NULL) {
            return (s32) D_800D61A8->unk4 >> 0xC;
        }
        return 0;
    case 0x2151:
        if (D_800D61A8 != NULL) {
            return (s32) D_800D61A8->unk8 >> 0xC;
        }
        return 0;
    case 0x2152:
        if (D_800D61A8 != NULL) {
            return (s32) D_800D61A8->unkC >> 0xC;
        }
        return 0;
    case 0x2100:
        return (s32) arg0->unk162;
    case 0x2129:
        cursor0 = arg0->unk2A8;
        cursorValue = *(u16 *)cursor0;
        arg0->unk2A8 = cursor0 + 2;
        return func_80049D60(cursorValue);
    case 0x2120:
        cursor1 = arg0->unk2A8;
        cursorIndex = *(u16 *)cursor1;
        arg0->unk2A8 = cursor1 + 2;
        return (s32) *(s16 *)((u8 *)arg0 + ((cursorIndex & 0xFF) << 1) + 0x2E4);
    case 0x212A:
        return (s32) arg0->unk15E;
    case 0x212B:
        cursor2 = arg0->unk2A8;
        code = *(u16 *)cursor2;
        arg0->unk2A8 = (void *) (cursor2 + 2);
        if (code & 0x2000) {
            table = arg0->unk48;
            code = table->unk54((u8 *)arg0 + table->unk50, code & 0xFFFF, arg0);
        }
        value = func_80061904(code & 0xFFFF);
        if (value->unk0 != 0) {
            return (s32) value->unk2;
        }
    default:
        return 0;
    }
}
