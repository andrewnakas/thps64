#include "common.h"

s32 func_80027F60(s32);                         /* extern */
s32 func_800297DC(void *, void *, s32);  /* extern */
s32 func_800A602C(s32);                         /* extern */
s32 func_800BE3D8();                            /* extern */
s32 func_800BE5A4();                            /* extern */
s32 func_800BEF70(s32, s32, s32);   /* extern */
extern u8 D_800D0FD6;
extern s32 D_800D2860;
extern s32 D_800D2A78;

void func_80029D74(void *arg0) {
    s32 *p;

    func_800BE3D8();
    func_800A602C(arg0 + 0x48);
    func_800BEF70(0, 0, 0);
    func_80027F60((*(s32 *)((u8 *)(arg0) + 0x44)));
    if (D_800D0FD6 == 0) {
        p = &D_800D2A78;
        func_800297DC(arg0, p, 0x18D);
    } else {
        p = &D_800D2860;
        func_800297DC(arg0, p, 0x86);
    }
    func_800BE5A4();
}
