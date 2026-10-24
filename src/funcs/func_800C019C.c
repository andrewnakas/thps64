/* cflags: -O2 */
#include "common.h"

s32 func_80003010(s32); /* extern */
s32 func_80011680(f32); /* extern */
extern s32 D_800F30B0;

void func_800C019C(void) {
    D_800F30B0 = 0;
    func_80011680(1.0f);
    func_80003010(1);
    while (1) {
    }
}
