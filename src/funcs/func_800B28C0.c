/* cflags: -O2 */
#include "common.h"

extern void func_80004ED0(void *, s32, s32);
extern void func_80005070(void *, s32, s32);
extern u8 D_800ECF54[];
extern s32 D_800ECF74;
extern s32 D_800ECF7C;
extern s32 D_800ECF80;
extern u8 D_800ECF84[];
extern s32 D_800ECFA4;

void func_800B28C0(void) {
    func_80005070(D_800ECF54, 0, 1);
    D_800ECF74 = 1;
    if (D_800ECF80 != 0) {
        func_80004ED0(D_800ECF84, 0, 1);
        D_800ECFA4 = 0;
        D_800ECF80 = 0;
        D_800ECF7C = 0;
    }
    func_80004ED0(D_800ECF54, 0, 1);
}
