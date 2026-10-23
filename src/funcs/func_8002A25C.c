#include "common.h"

s32 func_800A8678(s32, void *, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_800A8B80(s32, void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern char D_80019134[];
extern char D_8001922C[];
extern s32 D_800F3294;

void func_8002A25C(s32 arg0) {
    f32 temp_f20;
    s32 temp_s3;
    s32 n;
    char *p;

    n = D_800F3294 / 2;
    temp_s3 = arg0 + 0x80;
    p = D_80019134;
    temp_f20 = (f32) n;
    func_800A8B80(temp_s3, p, temp_f20, 330.0f, 1.2f, 2, 0, 0, 0, 0x64, 0, 1, 0);
    p = D_8001922C;
    func_800A8678(temp_s3, p, temp_f20, 75.0f, 2, 0, 0, 0, 0x64, 0, 1, 0, 0, 0);
}
