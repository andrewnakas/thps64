#include "common.h"

void func_80046D00(void *arg0) {
    (*(u16 *)((u8 *)(arg0) + 0)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0)) & 0xFFF);
    (*(u16 *)((u8 *)(arg0) + 2)) = (u16) ((*(u16 *)((u8 *)(arg0) + 2)) & 0xFFF);
    (*(u16 *)((u8 *)(arg0) + 4)) = (u16) ((*(u16 *)((u8 *)(arg0) + 4)) & 0xFFF);
}
