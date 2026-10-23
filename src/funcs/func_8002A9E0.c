#include "common.h"

extern void func_800BE3D8(void);
extern void func_800BEF70(s32, s32, s32);
extern void func_8002A054(s32);
extern void func_800BE5A4(void);

void func_8002A9E0(s32 arg0) {
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_8002A054(arg0);
    func_800BE5A4();
}
