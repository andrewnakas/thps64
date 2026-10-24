/* cflags: -O2 */
#include "common.h"

extern void func_800A73EC(s32);
extern void func_800A7AF8(s32, s32, s32, s32, s32);
extern void func_800A7B10(s32, s32, s32, s32, s32);

void func_8009C348(s32 arg0) {
    func_800A73EC(arg0);
    func_800A7AF8(arg0, 0, 0, 0, 0xFF);
    func_800A7B10(arg0, 0, 0, 0, 0xFF);
}
