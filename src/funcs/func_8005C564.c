#include "common.h"

extern void func_8004D2D4(s32, s32, s32);
extern void func_8004A204(s32, s32, s32, s32, s32);

void func_8005C564(s32 a0, s32 a1, s32 a2) {
    func_8004D2D4(a0, a1, a2);
    func_8004A204(a0, a1, a2, -1, -1);
}
