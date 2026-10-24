/* cflags: -O2 */
#include "common.h"

extern void func_80010D6C(void *);
extern void func_80010EFC(void *);

void func_800BCFF0(u8 *a0, void *a1) {
    func_80010D6C(a1);
    func_80010EFC(a1);
    *(void **)(a0 + 0x264) = a1;
}
