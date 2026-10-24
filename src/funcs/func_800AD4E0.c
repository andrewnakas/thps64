/* cflags: -O2 */
#include "common.h"

void func_800AD4E0(u8 *arg0) {
    arg0[0xD9] = 0;
    *(s32 *)(arg0 + 0x94) = *(s32 *)(arg0 + 0x40);
    arg0[0xDA] = arg0[0xBD] & 0x40;
}
