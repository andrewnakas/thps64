#include "common.h"

void func_80046CB0(void *arg0) {
    if ((u32) (((*(u16 *)((u8 *)(arg0) + 0)) + 1) & 0xFFFF) < 3U) {
        (*(u16 *)((u8 *)(arg0) + 0)) = 0U;
    }
    if ((u32) (((*(u16 *)((u8 *)(arg0) + 2)) + 1) & 0xFFFF) < 3U) {
        (*(u16 *)((u8 *)(arg0) + 2)) = 0U;
    }
    if ((u32) (((*(u16 *)((u8 *)(arg0) + 4)) + 1) & 0xFFFF) < 3U) {
        (*(u16 *)((u8 *)(arg0) + 4)) = 0U;
    }
}
