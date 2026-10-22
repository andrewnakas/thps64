#include "common.h"

void func_8004B5D0(void *arg0) {
    (*(u16 *)((u8 *)(arg0) + 0x52)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x52)) & 0xFFEF);
}
