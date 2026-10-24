/* cflags: -O2 */
#include "common.h"

void func_800BAA04(void *, s32);
void func_800B2860(void *);
extern u8 D_800EECA0[];

void func_800BA9B0(void) {
    func_800BAA04(D_800EECA0, 0);
    func_800B2860(D_800EECA0 + 0xC);
    *(s32 *)(D_800EECA0 + 8) = 0;
}
