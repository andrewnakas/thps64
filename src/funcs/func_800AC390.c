/* cflags: -O2 */
#include "common.h"

s32 func_800AC360(s32);
extern s32 D_800FC31C;
extern s32 D_800FC320;

s32 func_800AC390(s32 arg0) {
    s32 v;

    v = 1;
    if (arg0 == 0) {
        v = func_800AC360(D_800FC320);
    }
    if (v != 0) {
        D_800FC31C = arg0;
    }
    return v;
}
