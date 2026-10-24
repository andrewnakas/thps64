/* cflags: -O2 */
#include "common.h"

void func_800BB514(void *);
void func_80002E00(s32, void *, s32);
extern u8 D_800F0B10[];

void func_800A059C(u8 *arg0) {
    func_800BB514(D_800F0B10);
    func_80002E00(5, arg0 + 0x3EC, 0);
}
