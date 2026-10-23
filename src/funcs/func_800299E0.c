#include "common.h"

s32 func_80027644(s32, s32, s32, f32); /* extern */
s32 func_80027F60(s32);                         /* extern */
s32 func_800297DC(void *, void *, s32);  /* extern */
s32 func_80029B84(void *, s32);                             /* extern */
s32 func_80039E60(s32, s32, s32);   /* extern */
s32 func_8003FEF4(s32);                              /* extern */
s32 func_800A602C(void *);                      /* extern */
s32 func_800B4264(s32, s32);                     /* extern */
s32 func_800BE3D8();                            /* extern */
s32 func_800BE5A4();                            /* extern */
s32 func_800BEF70(s32, s32, s32);   /* extern */
extern s32 D_800D0FC0;
extern u8 D_800D0FD6;
extern s32 D_800D2860;
extern s32 D_800D2A78;
extern f32 D_800F5668;

s32 func_800299E0(void *arg0) {
    s32 var_s1;
    s32 *q;
    s32 var_s4;
    s32 temp_s2;
    s32 temp_s3;
    u8 *p;

    p = (u8 *)&D_800D0FC0;
    temp_s2 = p[2];
    temp_s3 = p[3];
    (*(f32 *)((u8 *)(arg0) + 0x2AC)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x2AC)) + D_800F5668);
    (*(f32 *)((u8 *)(arg0) + 0x2B0)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x2B0)) + D_800F5668);
    var_s4 = 0;
    if (10.0 < (f64) (*(f32 *)((u8 *)(arg0) + 0x2AC))) {
        (*(s32 *)((u8 *)(arg0) + 0x44)) = func_80029B84(arg0, (*(s32 *)((u8 *)(arg0) + 0x44)));
    }
    func_80027644((*(s32 *)((u8 *)(arg0) + 0x44)), 0, 1, 100.0f);
    if (func_8003FEF4(temp_s2) == 0) {
        func_8003FEF4(temp_s3);
    }
    var_s1 = 0;
    if ((func_800B4264(temp_s2, 0x9000) != 0) || (func_800B4264(temp_s3, 0x9000) != 0)) {
        var_s1 = 1;
    }
    if ((var_s1 != 0) || ((*(s32 *)((u8 *)(arg0) + 0x2C4)) == 1)) {
        func_80039E60(0x93, 0x2710, 0);
        var_s4 = 4;
    }
    func_800BE3D8();
    func_800A602C(arg0 + 0x48);
    func_800BEF70(0, 0, 0);
    func_80027F60((*(s32 *)((u8 *)(arg0) + 0x44)));
    if (D_800D0FD6 == 0) {
        q = &D_800D2A78;
        func_800297DC(arg0, q, 0x18D);
    } else {
        q = &D_800D2860;
        func_800297DC(arg0, q, 0x86);
    }
    func_800BE5A4();
    (*(s32 *)((u8 *)(arg0) + 0x2B8)) = (s32) ((*(f32 *)((u8 *)(arg0) + 0x2B4)) * (*(f32 *)((u8 *)(arg0) + 0x2B0)));
    return var_s4;
}
