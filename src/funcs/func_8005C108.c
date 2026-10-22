#include "common.h"

void func_8005C108(void *arg0, s32 *arg1) {
    u32 temp_a1;

    temp_a1 = *arg1 & 0xFFF00000;
    (*(s32 *)((u8 *)(arg0) + 0x37C)) = (s32) ((temp_a1 >> 0x14) & 1);
    (*(s32 *)((u8 *)(arg0) + 0x380)) = (s32) ((temp_a1 >> 0x15) & 1);
    (*(s32 *)((u8 *)(arg0) + 0x2E4)) = (s32) ((temp_a1 >> 0x1A) & 1);
    if ((*(s32 *)((u8 *)(arg0) + 0x37C)) != 0) {
        (*(s32 *)((u8 *)(arg0) + 0x41C)) = 0;
    }
    if (temp_a1 & 0x800000) {
        (*(s32 *)((u8 *)(arg0) + 0x460)) = (s32) (((((*(s32 *)((u8 *)(arg0) + 0x460)) & 0xFFFFFF) | 0x80000000) & ~0x4000) | 0x2000);
    }
    (*(s32 *)((u8 *)(arg0) + 0x3E8)) = (s32) ((temp_a1 >> 0x18) & 1);
    (*(s32 *)((u8 *)(arg0) + 0x3EC)) = (s32) ((temp_a1 >> 0x16) & 1);
}
