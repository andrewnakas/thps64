/* cflags: -O2 */
#include "common.h"

void func_8009B6C0(void *);
void func_800B2BAC(void *);
void func_800A5A2C(void *);
extern u8 D_800ECFE0[];

void func_800B7090(void) {
    func_8009B6C0(D_800ECFE0);
    func_800B2BAC(D_800ECFE0 + 0xC);
    func_800A5A2C(D_800ECFE0 + 0x18);
}
