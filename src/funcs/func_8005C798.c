#include "common.h"

typedef struct {
    u8 pad[0x520];
    u32 unk520[1];
} S8005C798;

s32 func_8005C798(S8005C798 *arg0, s32 arg1, s32 arg2) {
    s32 t;

    switch (arg0->unk520[arg1]) {
    case 0:
    case 1:
        break;
    case 2:
        t = arg2 * 75;
        arg2 = t / 100;
        break;
    case 3:
        arg2 = arg2 / 2;
        break;
    case 4:
        arg2 = arg2 / 4;
        break;
    default:
        arg2 = arg2 / 10;
        break;
    }
    return arg2;
}
