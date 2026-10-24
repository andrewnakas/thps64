/* cflags: -O2 */
#include "common.h"

extern void func_80004ED0(u8 *, s32 *, s32);
extern u8 *D_800FC674;

void func_800BB658(void) {
    s32 sp10;

    do {
        func_80004ED0(D_800FC674 + 8, &sp10, 1);
        func_80004ED0(D_800FC674 + 8, NULL, 0);
    } while (sp10 != 3);
}
