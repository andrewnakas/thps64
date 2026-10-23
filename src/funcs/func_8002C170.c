#include "common.h"

s32 func_80039500();                            /* extern */
s32 func_8003A8B4(void *);                   /* extern */
s32 func_8003BDC0(void *);                      /* extern */
s32 func_8003C1A4(void *, s32, char *, s32, char *, s32, char *, s32); /* extern */
s32 func_800B198C(void *);                      /* extern */
s32 func_800B1A80(void *, s32);             /* extern */

extern s32 D_800194A0;
extern char D_80019460[];
extern char D_8001946C[];
extern char D_8001947C[];
extern s32 D_800D3680;
extern s32 D_800D3F34;
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;

void *func_8002C170(void *arg0) {
    f32 temp_f0;
    char *name;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_800194A0;
    temp_s4 = arg0 + 0x34;
    func_800B198C(temp_s4);
    temp_s1 = arg0 + 0x48;
    func_8003BDC0(temp_s1);
    temp_s2 = arg0 + 0x6B8;
    func_800B198C(temp_s2);
    temp_s3 = arg0 + 0x6CC;
    func_800B198C(temp_s3);
    func_8003A8B4(&D_800D3F34);
    (*(s8 *)((u8 *)(arg0) + 0x30)) = -1;
    temp_f0 = (f32) D_800D3680;
    D_800ECEF0 = temp_f0;
    D_800EA9B0 = temp_f0;
    name = D_80019460;
    func_8003C1A4(temp_s1, 3, name, 0xFF, D_8001946C, 0x100, D_8001947C, 0x101);
    (*(f32 *)((u8 *)(arg0) + 0x298)) = (f32) 280.0f;
    (*(s32 *)((u8 *)(arg0) + 0x2A8)) = 0x14A;
    func_800B1A80(temp_s4, 0x98);
    func_800B1A80(temp_s2, 3);
    (*(s32 *)((u8 *)(arg0) + 0x6BC)) = 1;
    func_800B1A80(temp_s3, 2);
    (*(s32 *)((u8 *)(arg0) + 0x6D0)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x6E8)) = 0;
    (*(f32 *)((u8 *)(arg0) + 0x6E0)) = (f32) 0.5f;
    (*(s32 *)((u8 *)(arg0) + 0x6E4)) = 1;
    (*(s8 *)((u8 *)(arg0) + 0x6FE)) = 0;
    (*(s16 *)((u8 *)(arg0) + 0x6EC)) = 0xC8;
    (*(s16 *)((u8 *)(arg0) + 0x6EE)) = 0x1A4;
    (*(s16 *)((u8 *)(arg0) + 0x6F0)) = 0xB4;
    (*(s16 *)((u8 *)(arg0) + 0x6F2)) = 0x99;
    (*(s16 *)((u8 *)(arg0) + 0x6F4)) = 0x1D4;
    (*(s16 *)((u8 *)(arg0) + 0x6F6)) = 0xD4;
    (*(s16 *)((u8 *)(arg0) + 0x6F8)) = 0xDC;
    (*(s16 *)((u8 *)(arg0) + 0x6FA)) = 0x190;
    (*(s16 *)((u8 *)(arg0) + 0x6FC)) = 0xF6;
    return arg0;
}
