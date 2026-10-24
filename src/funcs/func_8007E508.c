#include "common.h"

extern void func_800472C0(void *, void *);
extern void func_800470E0(void *, void *);

void func_8007E508(u8 *a0) {
    u8 *p = a0 + 0x24;
    func_800472C0(a0 + 0x18, p);
    func_800472C0(p, a0 + 0x30);
    func_800470E0(p, a0 + 0x3C);
}
