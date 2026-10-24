/* cflags: -O2 */
#include "common.h"

extern s32 D_800ECC30;
extern s32 D_800ECC34;
void func_800AFA30(void);

void func_800AE59C(void) {
    if (D_800ECC30 != 0) {
        func_800AFA30();
        D_800ECC30 = 0;
        D_800ECC34 = 0;
    }
}
