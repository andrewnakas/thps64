/* cflags: -O2 */
#include "common.h"

s32 func_8009B6C0(u8 *);                               /* extern */
s32 func_800A5A2C(u8 *);                            /* extern */
s32 func_800B2BAC(u8 *);                            /* extern */
extern u8 D_800EECA0[];

void func_800BA974(void) {
    func_8009B6C0(D_800EECA0);
    func_800B2BAC(D_800EECA0 + 0xC);
    func_800A5A2C(D_800EECA0 + 0x18);
}
