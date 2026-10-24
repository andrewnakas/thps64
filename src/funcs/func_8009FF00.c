/* cflags: -O2 */
#include "common.h"

extern void func_800A02AC(void *, void *);
extern u8 D_80020A00[];
extern u8 D_800EA540[];

u8 *func_8009FF00(u8 *a0) {
    *(void **)(a0 + 0x1C4) = D_80020A00;
    *(s32 *)(a0 + 0x1B0) = 0;
    *(s32 *)(a0 + 0x1B4) = 0;
    *(s32 *)(a0 + 0x1B8) = 0;
    func_800A02AC(D_800EA540, a0);
    return a0;
}
