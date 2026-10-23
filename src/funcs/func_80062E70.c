#include "common.h"

typedef struct {
    u8 pad[0x15];
    u8 x15;
    u8 pad2[3];
} Elem19;

extern s32 D_800DE318;
extern Elem19 D_800DADA4[];
extern s32 D_800DAD94;

s32 func_80062E70(void) {
    s32 r;

    r = 0;
    if (D_800DE318 != 0 || D_800DADA4[D_800DAD94].x15 != 0) {
        r = 1;
    }
    return r;
}
