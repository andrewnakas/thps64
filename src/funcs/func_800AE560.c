/* cflags: -O2 */
#include "common.h"

void func_800AFD80(s32);
extern s32 D_800ECC30;
extern s32 D_800ECC34;

void func_800AE560(s32 arg0, s32 arg1) {
    if (D_800ECC30 == 0) {
        D_800ECC30 = arg0;
        if (D_800ECC34 == 0) {
            D_800ECC34 = arg0;
            func_800AFD80(arg1);
        }
    }
}
