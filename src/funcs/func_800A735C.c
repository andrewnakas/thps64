/* cflags: -O2 */
#include "common.h"

void func_800A73AC(u8 *);
void func_8009E334(u8 *);
extern u8 D_80021BB0[];

void func_800A735C(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x23C) = D_80021BB0;
    func_800A73AC(arg0);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
