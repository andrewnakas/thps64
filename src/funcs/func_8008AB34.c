/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { u8 pad_000[0xEC]; f32 field_0EC; s32 field_0F0; } State8008AB34;
typedef struct { u8 pad_000[2]; u8 field_002; u8 field_003; } Context8008AB34;

void func_80039E60(s32, s32, s32);
void func_8008A338(void *);
void func_8008A8A4(void *);
void func_800B1AC4(void *, f32, f32, f32, f32);
s32 func_800B4264(s32, s32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern Context8008AB34 D_800D0FC0;
extern s8 D_800D0FE3;
extern s32 D_800DE7A0;
extern f32 D_800F5668;

s32 func_8008AB34(State8008AB34 *arg0) {
    f32 temp_f0;
    f64 temp_f0_2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    u32 temp_s3;
    u32 temp_s4;

    temp_s3 = D_800D0FC0.field_002;
    temp_s4 = D_800D0FC0.field_003;
    temp_f0 = arg0->field_0EC + D_800F5668;
    arg0->field_0EC = temp_f0;
    temp_f0_2 = (f64) temp_f0;
    var_s2 = 0;
    if (1.0 < temp_f0_2) {
        arg0->field_0EC = (f32) (temp_f0_2 - 1.0);
        arg0->field_0F0 = (s32) (arg0->field_0F0 == 0);
    }
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    temp_v1 = D_800DE7A0;
    if (temp_v1 == 1) {
        func_8008A338(arg0);
    }
    temp_v1 = D_800DE7A0;
    if ((temp_v1 == 2) || (temp_v1 == 4) || (temp_v1 == 3) || (temp_v1 == 8) || (temp_v1 == 5) || (temp_v1 == 7)) {
        func_8008A8A4(arg0);
    }
    if (arg0->field_0F0 != 0) {
        func_800B1AC4((u8 *)arg0 + 0xD8, 162.0f, 420.0f, 1.0f, 1.8f);
    }
    var_s0 = 0;
    func_800BE5A4();
    if ((func_800B4264(temp_s3, 0x8000) != 0) || (func_800B4264(temp_s4, 0x8000) != 0)) {
        var_s0 = 1;
    }
    if (var_s0 != 0) {
        func_80039E60(0x90, 0x2710, 0);
        var_s2 = 0x21;
        D_800D0FE3 = 1;
    } else {
        var_s0_2 = 0;
        if ((func_800B4264(temp_s3, 0x4000) != 0) || (func_800B4264(temp_s4, 0x4000) != 0)) {
            var_s0_2 = 1;
        }
        if (var_s0_2 != 0) {
            func_80039E60(0x93, 0x2710, 0);
            var_s2 = 0xE;
        }
    }
    return var_s2;
}
