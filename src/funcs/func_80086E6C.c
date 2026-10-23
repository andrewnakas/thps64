#include "common.h"

u32 func_8000574C(s32);                             /* extern */
void func_800862F4(u16 *, s32, f32, f32, f32, s32, u32, s32, s32); /* extern */
void func_80086DC0(void *, f32 *, f32 *, f32, f32, f32, f32, f32, f32); /* extern */
void func_800B4264(s32, s32);            /* extern */
#define D_8001EDE0 (*(const f32 *) 0x8001EDE0)
#define D_8001EDE4 (*(const f32 *) 0x8001EDE4)
#define D_8001EDE8 (*(const f32 *) 0x8001EDE8)
#define D_8001EDEC (*(const f32 *) 0x8001EDEC)
#define D_8001EDF0 (*(const f32 *) 0x8001EDF0)
extern s32 D_800DE83C;
extern s32 D_800E8D70;

void func_80086E6C(u16 *arg0, f32 arg1, f32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 var_s1;
    f32 temp_f2;
    f32 temp_f4;
    u32 var_s0;

    var_s0 = arg4;
    var_s1 = arg5;
    if (D_800E8D70 != 0) {
        var_s1 = D_800E8D70;
    }
    if ((D_800DE83C != 0) || ((u32) (var_s0 - 5) >= 2U)) {
        if (var_s0 >= 8U) {
            var_s0 = 2;
        }
        if ((func_8000574C(var_s1) >= 0x80U) || ((u16) *arg0 >= 0x50U)) {
            func_8000574C(var_s1);
        }
        func_800B4264(0, 0x2000);
        func_80086DC0(arg0, &arg1, &arg2, 15.0f, D_8001EDE0, D_8001EDE4, D_8001EDE8, D_8001EDEC, D_8001EDF0);
        temp_f2 = arg1;
        temp_f4 = arg2;
        func_800862F4(arg0, var_s1, temp_f2, temp_f4, (f32) arg3, arg6, var_s0, arg7, arg8);
    }
}
