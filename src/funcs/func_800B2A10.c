/* cflags: -O2 */
#include "common.h"

void func_80005070(void *, s32, s32);
void func_80004ED0(void *, s32, s32);
void func_800B2A5C(void);
extern u8 D_800ECF54[];

void func_800B2A10(void) {
    func_80005070(D_800ECF54, 0, 1);
    func_800B2A5C();
    func_80004ED0(D_800ECF54, 0, 1);
}
