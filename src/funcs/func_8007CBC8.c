#include "common.h"

s32 func_80079E9C();                            /* extern */
extern u8 D_8001E170;

void *func_8007CBC8(void *arg0) {
    func_80079E9C();
    (*(u8 **)((u8 *)arg0 + 0x44)) = &D_8001E170;
    return arg0;
}
