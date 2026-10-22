#include "common.h"

void *func_8004B22C(void *arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_v0 = (*(s32 *)((u8 *)(arg1) + 0)) << 0xC;
    (*(s32 *)((u8 *)(arg0) + 0x184)) = temp_v0;
    (*(s32 *)((u8 *)(arg0) + 4)) = temp_v0;
    temp_v0_2 = (*(s32 *)((u8 *)(arg1) + 4)) << 0xC;
    (*(s32 *)((u8 *)(arg0) + 0x188)) = temp_v0_2;
    (*(s32 *)((u8 *)(arg0) + 8)) = temp_v0_2;
    temp_v0_3 = (*(s32 *)((u8 *)(arg1) + 8)) << 0xC;
    (*(s32 *)((u8 *)(arg0) + 0x18C)) = temp_v0_3;
    (*(s32 *)((u8 *)(arg0) + 0xC)) = temp_v0_3;
    return arg1 + 0xC;
}
