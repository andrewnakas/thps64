/* cflags: -O2 */
#include "common.h"

extern void func_80003010(s32);
extern void func_800114E0(void *);
extern void func_80011550(f32);
extern void func_80011A40(s32);
extern void *func_8009E6B4(void *, s32, s32);
extern void *func_8009EAE0(void *, u32, s32);
extern void func_800BC29C(void *, void **, s32);
extern void func_800BDCC8(void);
extern void func_800BDD74(void *);
extern void func_800BDD9C(void);
extern u8 D_80012290[];
extern u8 D_80012B50[];
extern u8 D_800EA110[];
extern u8 D_800F0DD0[];
extern u8 D_800F3100[];
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

void func_800BDEA8(s32 arg0) {
    s32 size;
    u8 *end;
    s32 i;
    void *p;

    if (D_800F369C == 0) {
        return;
    }
    D_800F369C = 0;
    func_800BDCC8();
    D_800FC8A0[2] = NULL;
    D_800F3294 = 320;
    D_800F3298 = 240;
    if (D_800F56C0 > 0x7FFFFF) {
        func_800BDD9C();
        func_800BC29C(D_800F0DD0, D_800FC8A0, 3);
    } else {
        size = 0x25800;
        if (arg0 != 0) {
            D_800FC8A0[0] = func_8009EAE0(D_800EA110, 0x801DA800, 0x4B040);
            func_800BDD74(D_800FC8A0[0]);
            D_800FC8A0[1] = (u8 *)D_800FC8A0[0] + size;
            D_800FC8A0[2] = func_8009EAE0(D_800EA110, 0x802BA7C0, 0x45840);
            func_800BDD74(D_800FC8A0[2]);
            end = (u8 *)D_800FC8A0[2] + size + 0x40;
        } else {
            D_800FC8A0[0] = func_8009EAE0(D_800EA110, 0x801DA800, 0x6B040);
            func_800BDD74(D_800FC8A0[0]);
            D_800FC8A0[1] = (u8 *)D_800FC8A0[0] + size;
            end = (u8 *)D_800FC8A0[1] + size + 0x40;
        }
        D_800F3290 = end;
        D_800FC890 = end + 0x20000;
        D_800F32A8 = func_8009EAE0(D_800EA110, 0x803FFFC0 - size, size | 0x40);
        func_800BDD74(D_800F32A8);
        func_800BC29C(D_800F0DD0, D_800FC8A0, D_800FC8A0[2] != NULL ? 3 : 2);
    }
    D_800FC894 = 0xFA00;
    for (i = 0; i < 2; i++) {
        D_800FC8B0[i] = func_8009E6B4(D_800EA110, D_800FC894, 8);
        func_800BDD74(D_800FC8B0[i]);
    }
    if (D_800F56BC == 0) {
        p = D_800F3100;
    } else if (D_800F56BC == 1) {
        p = D_80012290;
    } else {
        p = D_80012B50;
    }
    func_80003010(1);
    func_800114E0(p);
    func_80011A40(2);
    func_80011A40(0x40);
    func_80003010(1);
    if (D_800F56BC == 0 && D_800F56C0 <= 0x7FFFFF) {
        D_800F329C = 1.0f;
        func_80011550(D_800F329C);
    }
}
