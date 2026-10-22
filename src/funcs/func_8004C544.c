#include "common.h"

s32 func_8004AEE0();                                /* extern */

void func_8004C544(void *arg0) {
    if (func_8004AEE0() == 0) {
        (*(u16 *)((u8 *)(arg0) + 0x52)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x52)) | 0x40);
        (*(u16 *)((u8 *)(arg0) + 0)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0)) | 1);
    }
}
