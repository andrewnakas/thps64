/* cflags: -O2 */
#include "common.h"

void func_800BAC04(void *, u16);
void func_8009E334(u8 *);
extern u8 D_800EECF0[];

void func_8009B114(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x508);
    if (p != NULL) {
        func_800BAC04(D_800EECF0, *(u16 *)(p + 0x66));
    }
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
