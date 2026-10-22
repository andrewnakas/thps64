#include "common.h"

void func_8004B584(void *arg0) {
    (*(u16 *)((u8 *)(arg0) + 0x22C)) = (u16) (*(u16 *)((u8 *)(arg0) + 0x21C));
    (*(u8 *)((u8 *)(arg0) + 0x230)) = (u8) (*(u8 *)((u8 *)(arg0) + 0x21F));
    (*(u8 *)((u8 *)(arg0) + 0x231)) = (u8) (*(u8 *)((u8 *)(arg0) + 0x221));
}
