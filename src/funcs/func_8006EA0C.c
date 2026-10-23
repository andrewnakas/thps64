#include "common.h"

typedef struct {
    u8 pad[0x1A];
    s16 x1A;
    u8 pad2[8];
} Elem24;

extern u8 D_800DCC1E;
extern s16 D_800DCAAC;
extern Elem24 D_800DCAB4[];
extern s32 D_800DC958;

void func_8006EA0C(s32 arg0) {
    s32 pad[4];

    if (D_800DCC1E == 0) {
        D_800DCAAC = arg0;
    } else {
        D_800DCAB4[D_800DC958].x1A = arg0;
    }
}
