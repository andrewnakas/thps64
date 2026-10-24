/* cflags: -O2 */
#include "common.h"

extern void func_80010650(void *, s32, s32);
extern void func_800B18A4(s32, s32, s32);
extern void *D_800ECEE0;
extern u8 D_800FC340[];

void func_800B17F0(s32 arg0, s32 arg1) {
    func_800B18A4(arg0, 0, arg1);
    func_80010650(D_800FC340, arg0, arg1);
    D_800ECEE0 = D_800FC340;
}
