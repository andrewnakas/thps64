/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x4C];
    s32 unk50;
    u8 pad54[0x2104];
    s32 unk2158;
    f32 unk215C;
    f32 unk2160;
    f32 unk2164;
} Seq;

s32 func_800ABE14(s32, s32);
void func_800A96BC(Seq *, s32);
extern f32 D_800F5668;

s32 func_800A9460(Seq *arg0, s32 arg1, f32 arg2, s32 arg3) {
    f32 k;
    f32 rate;

    if (arg0->unk0 == 0) {
        return 0;
    }
    arg0->unk2158 = 0;
    if (arg3 >= 0) {
        func_800ABE14(arg0->unk50, 0);
        func_800A96BC(arg0, arg3);
    }
    if (arg1 > 0) {
        return func_800ABE14(arg0->unk50, arg1);
    }
    if (arg1 < 0) {
        return 0;
    }
    if (arg2 < 0.0f) {
        return 0;
    }
    if (arg1 == 0 && arg2 == 0.0f) {
        return func_800ABE14(arg0->unk50, 0);
    }
    rate = 0.03333f;
    k = 128.0f;
    arg0->unk2158 = 1;
    arg0->unk215C = arg2;
    arg0->unk2160 = k;
    if (D_800F5668 > 0.0) {
        rate = D_800F5668;
    }
    arg0->unk2164 = k / (arg2 / rate);
    return 1;
}
