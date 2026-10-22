#include "common.h"

void func_800A1EA4(void *, s32, void *, void *, void *, void *, s32, s32, u8 *, s32);
extern s32 D_80019310;
extern s32 D_80019334;
extern s32 D_80019354;
extern u8 D_800D0FC2;
extern u8 *D_800D3128;
extern s32 D_800D3130;

void func_8002B278(u8 *arg0) {
    void *var_a3;
    void *buf;
    void *fmt;
    s32 id;

    if (*D_800D3128 == 'r') {
        var_a3 = &D_80019310;
    } else {
        var_a3 = &D_80019334;
    }
    buf = &D_800D3130;
    id = D_800D0FC2;
    fmt = &D_80019354;
    func_800A1EA4(buf, id, fmt, var_a3, arg0 + 0x50, arg0 + 0x54, 1, 0, D_800D3128, 0);
}
