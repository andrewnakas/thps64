/* cflags: -O2 */
#include "common.h"

s32 func_80002B20(s32); /* extern */
extern u8 *D_800ECC34;

void func_800AE450(u8 *arg0) {
    s32 mask;
    u8 *p;

    mask = func_80002B20(1);
    p = D_800ECC34;
    *(s32 *)(arg0 + 0x10) = *(s32 *)(p + 0x34);
    *(u8 **)arg0 = *(u8 **)p;
    *(u8 **)p = arg0;
    func_80002B20(mask);
}
