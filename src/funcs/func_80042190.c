#include "common.h"

s32 func_80039500();                            /* extern */
s32 func_8003BDC0(void *);                      /* extern */
s32 func_8003C1A4(void *, s32, ...);
s32 func_800B198C(void *);                      /* extern */
s32 func_800B1A80(void *, s32);             /* extern */
extern char D_8001A640[];
extern char D_8001A64C[];
extern char D_8001A65C[];
extern char D_8001A66C[];
extern char D_8001A678[];
extern char D_8001A684[];
extern s32 D_8001A770;
extern s32 D_800D4860;
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;

void *func_80042190(void *arg0) {
    f32 temp_f0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    char *s;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_8001A770;
    temp_s2 = arg0 + 0x34;
    func_8003BDC0(temp_s2);
    temp_s1 = arg0 + 0x6A4;
    func_800B198C(temp_s1);
    temp_s3 = arg0 + 0x6B8;
    func_800B198C(temp_s3);
    temp_s4 = arg0 + 0x6CC;
    func_800B198C(temp_s4);
    (*(s32 *)((u8 *)(arg0) + 0x30)) = -1;
    func_800B1A80(temp_s1, 0x98);
    (*(s32 *)((u8 *)(arg0) + 0x6A8)) = 1;
    temp_f0 = (f32) D_800D4860;
    D_800ECEF0 = temp_f0;
    D_800EA9B0 = temp_f0;
    s = D_8001A640;
    func_8003C1A4(temp_s2, 6, s, 9, D_8001A64C, 0xA, D_8001A65C, 0xB, D_8001A66C, 0xC, D_8001A678, 0xD, D_8001A684, 0xE);
    (*(f32 *)((u8 *)(arg0) + 0x284)) = (f32) 335.0f;
    (*(s32 *)((u8 *)(arg0) + 0x294)) = 0x14A;
    func_800B1A80(temp_s3, 3);
    (*(s32 *)((u8 *)(arg0) + 0x6BC)) = 1;
    func_800B1A80(temp_s4, 2);
    (*(s32 *)((u8 *)(arg0) + 0x6D0)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x6E8)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x6E0)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x6E4)) = 1;
    (*(s8 *)((u8 *)(arg0) + 0x710)) = 0;
    (*(s16 *)((u8 *)(arg0) + 0x6EC)) = 0xA2;
    (*(s16 *)((u8 *)(arg0) + 0x6EE)) = 0x1CC;
    (*(s16 *)((u8 *)(arg0) + 0x6F0)) = 0x7E;
    (*(s16 *)((u8 *)(arg0) + 0x6F2)) = 0x85;
    (*(s16 *)((u8 *)(arg0) + 0x6F4)) = 0x1E4;
    (*(s16 *)((u8 *)(arg0) + 0x6F6)) = 0x9F;
    (*(s16 *)((u8 *)(arg0) + 0x6F8)) = 0x8E;
    (*(s16 *)((u8 *)(arg0) + 0x6FA)) = 0x1DB;
    (*(s16 *)((u8 *)(arg0) + 0x6FC)) = 0xC1;
    (*(s16 *)((u8 *)(arg0) + 0x6FE)) = 0x96;
    (*(s16 *)((u8 *)(arg0) + 0x700)) = 0x1D7;
    (*(s16 *)((u8 *)(arg0) + 0x702)) = 0xE3;
    (*(s16 *)((u8 *)(arg0) + 0x704)) = 0x99;
    (*(s16 *)((u8 *)(arg0) + 0x706)) = 0x1D4;
    (*(s16 *)((u8 *)(arg0) + 0x708)) = 0x105;
    (*(s16 *)((u8 *)(arg0) + 0x70A)) = 0x78;
    (*(s16 *)((u8 *)(arg0) + 0x70C)) = 0x1F4;
    (*(s16 *)((u8 *)(arg0) + 0x70E)) = 0x126;
    return arg0;
}
