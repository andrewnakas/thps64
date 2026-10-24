#include "common.h"

typedef struct { u8 pad[0xC]; s32 v; u8 pad2[0x68]; } Ent78;
extern Ent78 D_800D5C1C[];
extern s32 D_800C0E20;
extern s32 D_800DE7A0;

s32 func_80096268(void) {
    if (D_800D5C1C[D_800C0E20].v != 0 && D_800DE7A0 == 1) {
        return 1;
    }
    return 0;
}
