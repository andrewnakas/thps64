/* cflags: -O2 */
#include "common.h"

extern void func_80003010(s32);
extern void func_800114E0(void *);
extern void func_80011550(f32);
extern void func_80011A40(s32);
extern void *func_8009E6B4(void *, s32, s32);
extern void *func_8009EAE0(void *, u32, s32);
extern void func_8009E0F0(void *, s32, s32);
extern void func_800BC29C(void *, void **, s32);
extern void func_800BDCC8(void);
extern void func_800BDD74(void *);
extern void func_800BDD9C(void);
extern u8 D_800124C0[];
extern u8 D_80012D80[];
extern u8 D_800EA110[];
extern u8 D_800F0DD0[];
extern u8 D_800F3150[];
extern u8 D_800F31F0[];
extern u8 D_800F3240[];
extern void *D_800F3290;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern f32 D_800F329C;
extern void *D_800F32A8;
extern s32 D_800F369C;
extern s32 D_800F56BC;
extern u32 D_800F56C0;
extern void *D_800FC890;
extern s32 D_800FC894;
extern void *D_800FC8A0[3];
extern void *D_800FC8B0[2];

void func_800BE144(void) {
    s32 size;
    u8 *end;
    s32 i;
    void *p;
    s32 a;

    if (D_800F369C == 1) {
        return;
    }
    D_800F369C = 1;
    func_800BDCC8();
    D_800F3294 = 640;
    D_800F3298 = 480;
    if (D_800F56C0 > 0x7FFFFF) {
        func_800BDD9C();
        func_800BC29C(D_800F0DD0, D_800FC8A0, 3);
    } else {
        size = 0x96000;
        D_800F32A8 = func_8009EAE0(D_800EA110, 0x80369FC0, 0x96040);
        func_800BDD74(D_800F32A8);
        D_800FC8A0[0] = func_8009EAE0(D_800EA110, 0x8016A000, 0x12E040);
        func_800BDD74(D_800FC8A0[0]);
        D_800FC8A0[1] = (u8 *)D_800FC8A0[0] + size;
        end = (u8 *)D_800FC8A0[1] + size;
        D_800F3290 = end + 0x40;
        D_800FC890 = end + 0x2040;
        func_800BC29C(D_800F0DD0, D_800FC8A0, 2);
    }
    D_800FC894 = 0xFA00;
    for (i = 0; i < 2; i++) {
        D_800FC8B0[i] = func_8009E6B4(D_800EA110, D_800FC894, 8);
        func_800BDD74(D_800FC8B0[i]);
        func_8009E0F0(D_800FC8B0[i], 0xFF, D_800FC894);
    }
    if (D_800F56C0 > 0x7FFFFF) {
        if (D_800F56BC == 0) {
            p = D_800F3150;
        } else if (D_800F56BC == 1) {
            p = D_800F3240;
        } else {
            p = D_800F31F0;
        }
    } else {
        if (D_800F56BC == 0) {
            p = D_800F3150;
        } else if (D_800F56BC == 1) {
            p = D_800124C0;
        } else {
            p = D_80012D80;
        }
    }
    func_80003010(1);
    func_800114E0(p);
    func_80011A40(2);
    if (D_800F56C0 > 0x7FFFFF) {
        a = 0x40;
    } else {
        func_80011A40(0x80);
        a = 0x20;
    }
    func_80011A40(a);
    func_80003010(1);
    if (D_800F56BC == 0 && D_800F56C0 <= 0x7FFFFF) {
        D_800F329C = 0.9f;
        func_80011550(D_800F329C);
    }
}
