/* cflags: -O2 */
#include "common.h"

extern void func_80003010(s32);
extern void func_80011550(f32);
extern void func_80011680(f32);
extern void func_800BCA1C(u8 *, u8 *, s32);

void func_800BCAA8(u8 *arg0) {
    f32 k;

    k = 1.0f;
    func_80011550(k);
    func_80011680(k);
    func_80003010(1);
    *(s32 *)(arg0 + 0x2314) = 1;
    *(s32 *)(arg0 + 0x22E0) = 0;
    func_800BCA1C(arg0, arg0 + 0x1C8, 4);
}
