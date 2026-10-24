/* cflags: -O2 */
#include "common.h"

extern void func_800A6A0C(void *);
extern void func_8009E334(void *);

void func_800A6944(void *a0, s32 a1) {
    func_800A6A0C(a0);
    if (a1 & 1) {
        func_8009E334(a0);
    }
}
