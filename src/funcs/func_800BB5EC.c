/* cflags: -O2 */
#include "common.h"

extern void func_80001EC0(void *, void *, s32);
extern u8 *func_800B1850(s32);
extern void func_800BC6E4(void *, void *, void *);
extern u8 D_800F0DD0[];
extern u8 *D_800FC674;
extern void func_800BC7F0(void);

void func_800BB5EC(void) {
    D_800FC674 = func_800B1850(0x58);
    func_80001EC0(D_800FC674 + 8, D_800FC674 + 0x20, 4);
    func_80001EC0(D_800FC674 + 0x30, D_800FC674 + 0x48, 4);
    func_800BC6E4(D_800F0DD0, func_800BC7F0, D_800FC674 + 8);
}
