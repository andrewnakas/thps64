/* cflags: -O2 */
#include "common.h"

extern void func_800BC6E4(u8 *, void *, u8 *);
extern void func_800BC9A4(void);

void func_800BC654(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)(arg1 + 0x80) = 0;
    *(s32 *)(arg1 + 0x84) = arg2;
    *(s32 *)(arg1 + 0x88) = arg3;
    *(s32 *)(arg1 + 0x8C) = arg4;
    *(u8 **)(arg1 + 0x90) = arg0 + (*(s32 *)(arg0 + 0x22B8) * 12 + 0x2288);
    func_800BC6E4(arg0, func_800BC9A4, arg1);
}
