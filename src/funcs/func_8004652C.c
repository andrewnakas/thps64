#include "common.h"

extern char D_8001B1A4[];
extern s32 D_800D60D4;
extern s32 func_800626B4(char *);

void func_8004652C(void) {
    D_800D60D4 = func_800626B4(D_8001B1A4);
}
