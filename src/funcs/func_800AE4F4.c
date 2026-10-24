/* cflags: -O2 */
#include "common.h"

extern s32 func_80002B20(s32);
extern u8 *D_800ECC34;

void func_800AE4F4(u8 *arg0) {
    s32 s;
    u8 *m;

    s = func_80002B20(1);
    m = D_800ECC34;
    *(s32 *)(arg0 + 0x10) = *(s32 *)(m + 0x34);
    *(u8 **)arg0 = *(u8 **)m;
    *(u8 **)m = arg0;
    if (*(u8 **)(m + 4) == NULL) {
        *(u8 **)(m + 4) = arg0;
    } else if (*(u8 **)(m + 8) == NULL) {
        *(u8 **)(m + 8) = arg0;
    }
    func_80002B20(s);

}
