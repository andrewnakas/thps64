#include "common.h"

extern char D_8001CF60[];
extern char D_8001CF6C[];
extern s32 D_800DDA20;
extern s32 D_800DDA24;
extern s32 func_800626B4(char *);

void func_8006FA98(void) {
    D_800DDA20 = func_800626B4(D_8001CF60);
    D_800DDA24 = func_800626B4(D_8001CF6C);
}
