#include "common.h"

typedef struct {
    u8 pad0[0x4C];
    u32 unk4C;
} Obj8007CB20;

typedef struct {
    u8 pad0[0x48];
    s32 unk48;
    u8 pad4C[0x10];
    Obj8007CB20 **unk5C;
} Grp8007CB20;

void func_8007CB20(Grp8007CB20 *arg0, s32 r, s32 g, s32 b) {
    s32 i;

    i = 0;
    while (1) {
        if (i >= arg0->unk48) break;
        arg0->unk5C[i]->unk4C = (arg0->unk5C[i]->unk4C & 0xFF000000) | ((b & 0xFF) << 16) | ((g & 0xFF) << 8) | (r & 0xFF);
        i++;
    }
}
