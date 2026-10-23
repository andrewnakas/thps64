#include "common.h"

void func_800230A8(f32 *, s32);
void func_80041EC0(f32 *, f32 *);
void func_8009CAD0(f32 *);
void func_8009D1BC(f32 *, f32);
void func_8009D3F0(f32 *, f32);
void func_8009D624(f32 *, f32);

void func_800232DC(s16 *arg0, s32 arg1) {
    f32 m[16];
    f32 out[8];
    f32 scale;

    scale = 0.00153396f;
    func_8009CAD0(m);
    if (arg0[1] != 0) {
        func_8009D3F0(m, arg0[1] * scale);
    }
    if (arg0[0] != 0) {
        func_8009D1BC(m, arg0[0] * scale);
    }
    if (arg0[2] != 0) {
        func_8009D624(m, arg0[2] * scale);
    }
    func_80041EC0(out, m);
    func_800230A8(out, arg1);
}
