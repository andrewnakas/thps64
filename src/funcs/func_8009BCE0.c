/* cflags: -O2 */
#include "common.h"

extern void func_800A72C0(u8 *);
extern void func_800A5F10(u8 *);
extern void func_8009BF50(u8 *);

u8 *func_8009BCE0(u8 *a0) {
    func_800A72C0(a0);
    func_800A5F10(a0 + 0xE2C);
    func_8009BF50(a0);
    return a0;
}
