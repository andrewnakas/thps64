#include "common.h"

void func_8003C870(void *arg0, s32 arg1) {
    (*(s8 *)((u8 *)(arg0) + 0x245)) = 6;
    (*(s32 *)((u8 *)(arg0) + 0x248)) = arg1;
    if ((*(s8 *)((u8 *)(arg0) + 0x240)) == -1) {
        (*(s8 *)((u8 *)(arg0) + 0x240)) = 0;
    }
}
