/* cflags: -O2 */
#include "common.h"

s32 func_800A6758(void); /* extern */
extern s32 D_800EA580;
extern s32 D_800EA584;

void func_800A6864(s32 *arg0) {
    s32 a;
    s32 b;

    func_800A6758();
    a = D_800EA580;
    b = D_800EA584;
    arg0[1] = a;
    arg0[0] = b;
}
