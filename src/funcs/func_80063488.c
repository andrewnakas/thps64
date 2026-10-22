#include "common.h"

extern s32 D_800DBAE0;
extern s32 D_800FBB50;
extern s32 D_800FBB54;

void func_80063488(void) {
    D_800FBB50 = 0;
    D_800FBB54 = D_800DBAE0;
}
