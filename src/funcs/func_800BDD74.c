/* cflags: -O2 */
#include "common.h"

extern s32 D_800F36A0;
extern s32 D_800F5630[];

void func_800BDD74(s32 arg0) {
    D_800F5630[D_800F36A0++] = arg0;
}
