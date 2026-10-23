#include "common.h"

s32 func_80039500();                            /* extern */
s32 func_8003A8B4(void *);                   /* extern */
s32 func_8003BDC0(void *);                      /* extern */
s32 func_8003C1A4(void *, s32, void *, s32, void *, s32, void *, s32, void *, s32, void *, s32); /* extern */
s32 func_800B198C(void *);                      /* extern */
s32 func_800B1A80(void *, s32);             /* extern */
extern s32 D_80017390;
extern s32 D_8001739C;
extern s32 D_800173AC;
extern s32 D_800173BC;
extern s32 D_800173CC;
extern s32 D_80017410;
extern s32 D_800D2850;
extern s32 D_800D3F34;
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;

void *func_800290E0(void *arg0) {
    f32 temp_f0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *str;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_80017410;
    temp_s2 = arg0 + 0x38;
    func_8003BDC0(temp_s2);
    temp_s1 = arg0 + 0x6A8;
    func_800B198C(temp_s1);
    temp_s3 = arg0 + 0x6BC;
    func_800B198C(temp_s3);
    temp_s4 = arg0 + 0x6D0;
    func_800B198C(temp_s4);
    (*(s32 *)((u8 *)(arg0) + 0x34)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x30)) = -1;
    func_800B1A80(temp_s1, 0x98);
    temp_f0 = (f32) D_800D2850;
    D_800ECEF0 = temp_f0;
    D_800EA9B0 = temp_f0;
    str = &D_80017390;
    func_8003C1A4(temp_s2, 5, str, 0x48, &D_8001739C, 0x49, &D_800173AC, 0x46, &D_800173BC, 0x47, &D_800173CC, 0x4A);
    (*(f32 *)((u8 *)(arg0) + 0x288)) = (f32) 320.0f;
    (*(s32 *)((u8 *)(arg0) + 0x298)) = 0x14A;
    func_800B1A80(temp_s3, 3);
    (*(s32 *)((u8 *)(arg0) + 0x6C0)) = 1;
    func_800B1A80(temp_s4, 2);
    (*(s32 *)((u8 *)(arg0) + 0x6D4)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x6EC)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x6E4)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x6E8)) = 1;
    (*(s8 *)((u8 *)(arg0) + 0x70E)) = 0;
    (*(s16 *)((u8 *)(arg0) + 0x6F0)) = 0x9A;
    (*(s16 *)((u8 *)(arg0) + 0x6F2)) = 0x1D0;
    (*(s16 *)((u8 *)(arg0) + 0x6F4)) = 0x8A;
    (*(s16 *)((u8 *)(arg0) + 0x6F6)) = 0x78;
    (*(s16 *)((u8 *)(arg0) + 0x6F8)) = 0x1F7;
    (*(s16 *)((u8 *)(arg0) + 0x6FA)) = 0xAD;
    (*(s16 *)((u8 *)(arg0) + 0x6FC)) = 0x90;
    (*(s16 *)((u8 *)(arg0) + 0x6FE)) = 0x1DF;
    (*(s16 *)((u8 *)(arg0) + 0x700)) = 0xCE;
    (*(s16 *)((u8 *)(arg0) + 0x702)) = 0x88;
    (*(s16 *)((u8 *)(arg0) + 0x704)) = 0x1E6;
    (*(s16 *)((u8 *)(arg0) + 0x706)) = 0xF0;
    (*(s16 *)((u8 *)(arg0) + 0x708)) = 0x8C;
    (*(s16 *)((u8 *)(arg0) + 0x70A)) = 0x1E2;
    (*(s16 *)((u8 *)(arg0) + 0x70C)) = 0x111;
    func_8003A8B4(&D_800D3F34);
    return arg0;
}
