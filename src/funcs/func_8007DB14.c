#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Unk_8007DB14;

void func_8007DB14(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 i;
    s32 color;

    color = ((arg3 & 0xFF) << 16) | ((arg2 & 0xFF) << 8) | (arg1 & 0xFF);
    for (i = 0; i < *(u32 *)(arg0 + 0x50); i++) {
        (*(Unk_8007DB14 **)(arg0 + 0x48))[i].unk4 = color;
    }
}
