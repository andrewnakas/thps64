#include "common.h"

extern s32 D_800D7348;
extern s32 D_800D734C;
extern s32 D_800D7350;
extern u8 D_800D7394[];

void func_8005CC84(void) {
    u8 *p;
    s32 i;

    D_800D7348 = 0;
    D_800D734C = 0;
    D_800D7350 = -1;
    p = D_800D7394;
    i = 9;
    p += 0x90;
    for (; i >= 0; i--) {
        *(s32 *)p = 0;
        p -= 0x10;
    }
}
