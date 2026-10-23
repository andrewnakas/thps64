#include "common.h"

s32 func_8002AFF4(void *);                          /* extern */
s32 func_80039500();                            /* extern */
s32 func_8003A8B4(void *);                   /* extern */
s32 func_8003BDC0(void *);                      /* extern */
s32 func_8003C1A4(void *, s32, ...);
s32 func_8003C838(void *, s32, s32);    /* extern */
s32 func_800B198C(void *);                      /* extern */
s32 func_800B1A80(void *, s32);             /* extern */
extern s32 D_800192B0;
extern s32 D_800192C0;
extern s32 D_800192CC;
extern s32 D_800192F0;
extern s32 D_800D3110;
extern s32 D_800D3F34;
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;

void *func_8002AAD0(void *arg0) {
    f32 temp_f0;
    void *temp_s0;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *str;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_800192F0;
    temp_s0 = arg0 + 0x30;
    func_8003BDC0(temp_s0);
    temp_s2 = arg0 + 0x6A4;
    func_800B198C(temp_s2);
    temp_s3 = arg0 + 0x6B8;
    func_800B198C(temp_s3);
    temp_s4 = arg0 + 0x6CC;
    func_800B198C(temp_s4);
    func_8003A8B4(&D_800D3F34);
    temp_f0 = (f32) D_800D3110;
    D_800ECEF0 = temp_f0;
    D_800EA9B0 = temp_f0;
    (*(s8 *)((u8 *)(arg0) + 0x6A0)) = -1;
    str = &D_800192B0;
    func_8003C1A4(temp_s0, 3, str, 0xFA, &D_800192C0, 0xFB, &D_800192CC, 0xFC);
    (*(f32 *)((u8 *)(arg0) + 0x280)) = (f32) 280.0f;
    (*(s32 *)((u8 *)(arg0) + 0x290)) = 0x14A;
    if (func_8002AFF4(arg0) == 0) {
        func_8003C838(temp_s0, 0, 3);
    }
    func_800B1A80(temp_s2, 0x98);
    func_800B1A80(temp_s3, 3);
    (*(s32 *)((u8 *)(arg0) + 0x6BC)) = 1;
    func_800B1A80(temp_s4, 2);
    (*(s32 *)((u8 *)(arg0) + 0x6D0)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x6E8)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x6E0)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x6E4)) = 1;
    (*(s8 *)((u8 *)(arg0) + 0x6FE)) = 0;
    (*(s16 *)((u8 *)(arg0) + 0x6EC)) = 0x82;
    (*(s16 *)((u8 *)(arg0) + 0x6EE)) = 0x1E8;
    (*(s16 *)((u8 *)(arg0) + 0x6F0)) = 0xB4;
    (*(s16 *)((u8 *)(arg0) + 0x6F2)) = 0xB2;
    (*(s16 *)((u8 *)(arg0) + 0x6F4)) = 0x1BA;
    (*(s16 *)((u8 *)(arg0) + 0x6F6)) = 0xD4;
    (*(s16 *)((u8 *)(arg0) + 0x6F8)) = 0xAC;
    (*(s16 *)((u8 *)(arg0) + 0x6FA)) = 0x1C0;
    (*(s16 *)((u8 *)(arg0) + 0x6FC)) = 0xF6;
    return arg0;
}
