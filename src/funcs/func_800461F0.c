#include "common.h"

extern void func_80045A70(void *);

void func_800461F0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x388) != 0) {
        *(s32 *)((u8 *)arg0 + 0x14C) = 1;
        *(s32 *)((u8 *)arg0 + 0x150) = 0;
        func_80045A70(arg0);
    } else {
        *(s32 *)((u8 *)arg0 + 0x14C) = 0;
    }
}
