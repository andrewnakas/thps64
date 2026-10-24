#include "common.h"

void func_8009BF0C(void *arg0, s32 arg1) {
    void *temp_v1;

    if (arg1 != -1) {
        temp_v1 = arg0 + (arg1 * 0x17C);
        if ((*(u8 *)((u8 *)temp_v1 + 0x250)) != 0) {
            (*(u16 *)((u8 *)arg0 + 0xE20)) = (u16) ((*(u16 *)((u8 *)arg0 + 0xE20)) - 1);
        }
        (*(u8 *)((u8 *)temp_v1 + 0x250)) = 0U;
    }
}
