#include "common.h"

extern u8 D_800DCC1E;
extern s16 D_800DCAAC;
void func_8006EA0C(s32);

void func_8006F23C(s32 arg0) {
    if (D_800DCC1E != 0) {
        func_8006EA0C(arg0);
    } else {
        D_800DCAAC = arg0;
    }
}
