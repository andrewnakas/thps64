/* cflags: -O2 */
#include "common.h"

extern void func_800B18C8(u8 *, void *, s32);
extern s32 D_800FC330;
extern s32 D_800FC334;
extern s32 D_800FC338;
extern u8 *D_800FC33C;

s32 func_800AC6D4(void *arg0) {
    s32 next;

    next = (D_800FC334 + 1) % D_800FC338;
    if (next == D_800FC330) {
        return 0;
    }
    func_800B18C8(D_800FC33C + D_800FC334 * 8, arg0, 8);
    D_800FC334 = next;
    return 1;
}
