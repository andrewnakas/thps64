#include "common.h"

void func_8002C660(void);
void func_80039E60(s32, s32, s32);
s32 func_800B4264(u8, s32);
extern u8 D_800D0FC0[];
extern s32 D_800D3694;
extern s32 D_800D3698;
extern s32 D_800EA550;

s32 func_8002C7C0(void) {
    s32 ret;
    s32 flag;
    u8 *p;

    ret = 0;
    func_8002C660();
    flag = 0;
    p = D_800D0FC0;
    if (func_800B4264(p[2], 0x4000) != 0 || func_800B4264(p[3], 0x4000) != 0) {
        flag = 1;
    }
    if (flag != 0) {
        D_800EA550 = 0;
        ret = D_800D3694;
        func_80039E60(0x93, 0x2710, 0);
        return ret;
    }
    if (D_800EA550 == 0) {
        ret = D_800D3698;
    }
    return ret;
}
