#include "common.h"

extern void func_8004D2D4(void);
extern void func_8004A204(s32, s32, s32, s32, s32);

void func_8005C494(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_8004D2D4();
    func_8004A204(a0, a1, a2, a3, a4);
}
