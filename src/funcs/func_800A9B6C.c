#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x20];
} Unk_800A9B6C_Entry;

typedef struct {
    s32 unk0;
    u8 pad4[0x540];
    Unk_800A9B6C_Entry entries[200];
} Unk_800A9B6C;

void func_800A9B6C(Unk_800A9B6C *arg0, s32 arg1, s32 arg2) {
    if (arg0->unk0 != 0 && arg1 < 200) {
        arg0->entries[arg1].unk0 = arg2;
    }
}
