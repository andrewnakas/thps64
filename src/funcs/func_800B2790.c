/* cflags: -O2 */
#include "common.h"

s32 func_800B267C(s32);
void func_800B272C(s32, s32);

void func_800B2790(s32 arg0) {
    func_800B272C(arg0, func_800B267C(arg0));
}
