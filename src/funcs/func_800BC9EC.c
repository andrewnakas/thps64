/* cflags: -O2 */
#include "common.h"

extern void func_800BD680(u8 *);
extern void func_800BD05C(u8 *);

void func_800BC9EC(u8 *a0) {
    func_800BD680(a0 + 0x1EC);
    func_800BD05C(a0);
}
