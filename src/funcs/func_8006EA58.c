#include "common.h"

typedef struct {
    u8 pad[0x18];
    u8 unk18;
    u8 pad2[0x24 - 0x19];
} Unk6EA58;
extern Unk6EA58 D_800DCAB4[];
extern s32 D_800DC958;

void func_8006EA58(s32 arg0) {
    D_800DCAB4[D_800DC958].unk18 = arg0;
}
