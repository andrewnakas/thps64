/* cflags: -O2 */
#include "common.h"

extern s32 D_800EA550;

void func_800A21C4(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x474) != 0) {
        *(s32 *)(arg0 + 8) = 0x14;
        return;
    }
    D_800EA550 = *(s32 *)(arg0 + 0x420);
}
