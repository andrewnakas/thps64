#include "common.h"

typedef struct Table80072B2C {
    u8 pad0[0x40];
    s16 unk40;
    u8 pad42[2];
    s32 (*unk44)(void *, s32);
    s16 unk48;
    u8 pad4A[2];
    void (*unk4C)(void *, s32);
} Table80072B2C;

typedef struct State80072B2C {
    u8 pad0[0x48];
    Table80072B2C *unk48;
    u8 pad4C[0x248];
    u8 unk294;
    u8 pad295[0x13];
    u16 *unk2A8;
} State80072B2C;

void func_80072B2C(State80072B2C *arg0, u16 *arg1) {
    s32 command;
    u16 *cursor;
    u16 raw;
    Table80072B2C *queryTable;
    Table80072B2C *actionTable;

    arg0->unk2A8 = arg1;
    while (1) {
        cursor = arg0->unk2A8;
        raw = *cursor;
        command = raw & 0xFFFF;
        if (command != 0x4100) {
            arg0->unk2A8 = (u16 *) (cursor + 1);
            if (raw & 0x4000) {
                queryTable = arg0->unk48;
                if (queryTable->unk44((u8 *)arg0 + queryTable->unk40, command) != 0) {
                    continue;
                }
            } else {
                if (raw & 0x2000) {
                    actionTable = arg0->unk48;
                    actionTable->unk4C((u8 *)arg0 + actionTable->unk48, command);
                }
                continue;
            }
        } else {
            arg0->unk294 = 0;
        }
        break;
    }
}
