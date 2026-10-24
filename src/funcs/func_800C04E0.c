/* cflags: -O2 */
#include "common.h"

extern void func_8009B6C0(void *);
extern void func_800B2BAC(void *);
extern void func_800A5A2C(void *);
extern u8 D_800F5684[];
extern u8 D_800F5678[];
extern u8 D_800F566C[];

void func_800C04E0(void) {
    u8 *p = D_800F5684;
    func_8009B6C0(p);
    func_800B2BAC(p + 0xC);
    func_800A5A2C(p + 0x18);
    func_800A5A2C(D_800F5678);
    func_800A5A2C(D_800F566C);
}
