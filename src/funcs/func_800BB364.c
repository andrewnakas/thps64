#include "common.h"

extern void func_800B411C(s32, s32);

void func_800BB364(u8 *a0) {
    if (*(s32 *)(a0 + 0x210) != 0) {
        func_800B411C(*(s32 *)(a0 + 0x21C), 0);
    }
}
