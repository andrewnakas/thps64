#include "common.h"

s32 func_800392E4(void *);                   /* extern */
s32 func_8009B0A0(void *);                   /* extern */
s32 func_8009B9B0(void *);                      /* extern */
s32 func_800A3FB0(void *);                   /* extern */
s32 func_800A68A0(void *);                      /* extern */
extern s32 D_800D36F8;
extern s32 D_800F65E0;
extern s32 D_800F78C0;
extern s32 D_800FA140;
extern s32 D_800FA350;

void func_80034F50(void) {
    void *var_s0_2;
    void *var_s1;
    s32 var_s0;
    s32 var_s1_2;
    s32 var_v0;

    func_800392E4(&D_800FA350);
    var_s1 = &D_800FA140;
    var_s0 = 5;
    do {
        func_800392E4(var_s1);
        var_s0 -= 1;
        var_s1 += 0x58;
    } while (var_s0 != -1);
    var_s0_2 = &D_800F78C0;
    var_s1_2 = 0x2F;
    do {
        func_800A68A0(var_s0_2 + 0x10);
        func_8009B9B0(var_s0_2 + 0xA4);
        var_s1_2 -= 1;
        var_s0_2 += 0xD8;
    } while (var_s1_2 != -1);
    var_v0 = 0x2F;
    do {
        var_v0 -= 1;
    } while (var_v0 != -1);
    func_800A3FB0(&D_800F65E0);
    func_8009B0A0(&D_800D36F8);
}
