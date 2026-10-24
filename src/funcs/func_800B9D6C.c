/* cflags: -O2 */
#include "common.h"

extern s32 D_800EECD8;
extern s32 D_800EECDC;
extern f32 D_800F30E0;

void func_800B9D6C(void) {
    f32 v;
    if (D_800EECD8 != 0) {
        v = D_800F30E0;
        if (D_800EECDC != 0) {
            if (v < 1.5f) {
                D_800EECDC = 0;
            }
        } else if (v > 1.8f) {
            D_800EECDC = 1;
        }
    } else {
        D_800EECDC = 0;
    }

}
