#include "common.h"

typedef struct Table80072ACC {
    u8 pad0[0x50];
    s16 unk50;
    u8 pad52[2];
    s32 (*unk54)(void *, u16);
} Table80072ACC;
typedef struct State80072ACC {
    u8 pad0[0x48];
    Table80072ACC *unk48;
    u8 pad4C[0x25C];
    u16 *unk2A8;
} State80072ACC;

s32 func_80072ACC(State80072ACC *arg0) {
    u16 value;
    Table80072ACC *table;

    value = *arg0->unk2A8++;
    if (value & 0x8000) {
    } else if (value & 0x2000) {
        table = arg0->unk48;
        value = table->unk54((u8 *)arg0 + table->unk50, value);
    }
    return value;
}
