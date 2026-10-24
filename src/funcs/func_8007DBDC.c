#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Unk_8007DBDC;

void func_8007DBDC(u8 *arg0, s32 arg1) {
    u32 i;

    for (i = 0; i < *(u32 *)(arg0 + 0x50); i++) {
        (*(Unk_8007DBDC **)(arg0 + 0x48))[i].unk0 = arg1;
    }
}
