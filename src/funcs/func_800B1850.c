/* cflags: -O2 */
#include "common.h"

s32 func_80010480(s32, s32, s32 *, s32, s32);                 /* extern */
extern s32 D_800FC340;

void func_800B1850(s32 arg0) {
    func_80010480(0, 0, &D_800FC340, 1, arg0);
}
