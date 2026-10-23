#include "common.h"

void func_8004A204(void *, s32, s32, s32, s32);
void func_8004C9E8(void *);
void func_8004D048(void *, s32, s32);
s32 func_8004D2D4(void *);

void func_8005BF44(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x82C) == 2) {
        func_8004D048(arg0, 1, 0x1031);
    } else {
        func_8004D048(arg0, 1, 0x1037);
        func_8004C9E8(arg0);
        *(s32 *)(arg0 + 0x420) = 0;
        *(s32 *)(arg0 + 0x424) = 0;
        *(s32 *)(arg0 + 0x454) = 0;
        *(s32 *)(arg0 + 0x838) = 1;
        if (*(s32 *)(arg0 + 0x450) == 0) {
            *(s32 *)(arg0 + 0x228) = 0x10000;
            if (*(s32 *)(arg0 + 0x834) != 0) {
                func_8004D2D4(arg0);
                func_8004A204(arg0, 0x1A, 0, -1, -1);
            } else {
                func_8004D2D4(arg0);
                func_8004A204(arg0, 0x1B, 0, -1, -1);
            }
        }
    }
}
