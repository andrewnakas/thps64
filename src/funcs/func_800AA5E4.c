/* cflags: -O2 */
#include "common.h"

f32 func_8009F228(void);
void func_800A9958(s32, s32, s32, s32, f32, s32, s32);
void func_800A9D64(s32, s32);
s32 func_800AA1C4(s32);
void func_800AA1E8(s32, s32, s32);

void func_800AA5E4(s32 arg0, s32 arg1, f32 arg2, s32 arg3, ...) {
    f32 t;
    s32 sel;
    s32 i;
    s32 n;
    char *ap;
    u8 *e;

    sel = 0;
    ap = (char *)(&arg3 + 1);
    if (arg2 <= 0.0f) return;
    if (1.0f < arg2) return;
    t = func_8009F228();
    if (!(t <= arg2)) return;
    n = (s32)((t / arg2) * (f32)arg3);
    for (i = 0; i < arg3; i++) {
        ap = (char *)(((s32)ap + 3) & ~3) + 4;
        sel = ((s32 *)ap)[-1];
        if (i == n) break;
    }
    func_800A9D64(arg0, sel);
    e = (u8 *)arg0 + sel * 0x24;
    if (e[0x548] == 0) {
        func_800A9958(arg0, sel, e[0x549], 0x7F, *(f32 *)(e + 0x550), e[0x54A], 0);
    } else if (e[0x548] == 2) {
        if (func_800AA1C4(arg0) == 0) {
            func_800AA1E8(arg0, 1, sel);
        }
    }
}
