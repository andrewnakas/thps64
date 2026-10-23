#include "common.h"

typedef struct {
    u8 pad[0x1A];
    u16 val;
    u8 pad2[0x8];
} Entry_A2;

extern u8 D_800DCC1E;
extern Entry_A2 D_800DCAB4[];
extern s32 D_800DC958;

s32 func_8006E9CC(void) {
    if (D_800DCC1E == 0) {
        return 0;
    }
    return D_800DCAB4[D_800DC958].val;
}
