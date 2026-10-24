/* cflags: -O2 */
#include "common.h"

extern void func_800A3194(void);
extern s32 D_800EA550;

s32 func_800A0D4C(s32 *arg0) {
    s32 s;

    s = D_800EA550;
    switch (s) {
    case 1:
        s = *arg0;
        if (s == 10 || s == 12) {
            func_800A3194();
            D_800EA550 = 0;
            return 1;
        }
        return 0;
    case 3:
        break;
    case 0:
        return 1;
    default:
        return 0;
    }
    func_800A3194();
    D_800EA550 = 0;
    return 1;
}
