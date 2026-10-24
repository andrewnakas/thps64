/* cflags: -O2 */
#include "common.h"

void func_800A01E0(u8 *);
extern u8 *D_800EA548;

void func_800A021C(void) {
    u8 *p;

    for (p = D_800EA548; p != NULL; p = *(u8 **)(p + 0x1C0)) {
        func_800A01E0(p);
    }
}
