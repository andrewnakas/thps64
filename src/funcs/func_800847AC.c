#include "common.h"

void func_8009B6C0(void *);                               /* extern */
void func_800A5A2C(void *);                            /* extern */
void func_800B2BAC(void *);                            /* extern */
extern s32 D_800E8A20[];

void func_800847AC(void) {
    s32 *temp_s0 = D_800E8A20;

    func_8009B6C0(temp_s0);
    func_800B2BAC((u8 *) temp_s0 + 0xC);
    func_800A5A2C((u8 *) temp_s0 + 0x18);
}
