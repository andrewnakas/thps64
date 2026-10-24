/* cflags: -O2 */
#include "common.h"

void func_800AD9B8(s32);
extern s32 D_800FC318;

void func_800AC234(s32 arg0) {
    func_800AD9B8(arg0);
    if (D_800FC318 == 0) {
        D_800FC318 = arg0;
    }
}
