#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0xB8];
    u32 unkBC;
} Unk800DC618;

extern Unk800DC618 D_800DC618;

s32 func_8006CD84(void) {
    s32 ret;

    ret = 0;
    if (D_800DC618.unk0 == 2) {
        ret = D_800DC618.unkBC != 0;
    }
    return ret;
}
