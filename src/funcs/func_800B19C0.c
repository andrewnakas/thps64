/* cflags: -O2 */
#include "common.h"

void func_800B1A44(u8 *);
void func_8009E334(u8 *);
extern u8 D_80021F08[];

void func_800B19C0(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x10) = D_80021F08;
    func_800B1A44(arg0);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
