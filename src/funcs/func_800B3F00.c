/* cflags: -O2 */
#include "common.h"

void func_80002C40(s32, s32);
void func_80004ED0(void *, void *, s32);
void func_80007650(s32, s32);
s32 func_80010690(void *);
void func_80010754(s32);
extern s32 D_800ECFC0;
extern u8 D_800ECFC8[];
extern s32 D_800F30E4;
extern s32 D_800FC640[];

s32 func_800B3F00(s32 arg0, s32 arg1) {
    void *msg;
    s32 *p;
    s32 *b;

    if (D_800F30E4 == 0 && (D_800ECFC0 != 0 || arg1 != 0)) {
        b = D_800FC640;
        p = &b[arg0];
        func_80002C40(*p, 0x18);
        if (func_80010690(D_800ECFC8) & ~4) {
            return 0;
        }
        func_80004ED0(D_800ECFC8, &msg, 1);
        func_80007650(*p, 0x18);
        func_80010754(*p);
    }
    return 1;
}
