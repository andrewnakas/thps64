/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x4C];
    s32 unk50;
    s32 unk54;
    u8 pad58[0xC];
    s32 unk64;
    u8 pad68[0x2158 - 0x68];
    s32 unk2158;
    f32 unk215C;
    f32 unk2160;
    f32 unk2164;
    s32 unk2168;
} Obj_800A9220;

s32 func_800A901C(Obj_800A9220 *, s32);
void func_800A93B0(Obj_800A9220 *, s32);
s32 func_800A9D64(Obj_800A9220 *, s32);
s32 func_800AB75C(s32);
s32 func_800AB9E0(s32);
void func_800ABE14(s32, s32);
s32 func_800ABEC4(s32);
void func_800ABFC4(s32, u8);
extern f32 D_800F5668;

s32 func_800A9220(Obj_800A9220 *o, s32 arg1, f32 arg2) {
    f32 f;
    u32 v;

    if (o->unk0 == 0 || arg1 < 0) {
        return 0;
    }
    if (arg2 <= 0.0) {
        if (func_800ABEC4(o->unk50) > 0) {
            func_800ABE14(o->unk50, 0);
        }
        if (func_800A901C(o, arg1) != 0) {
            func_800A93B0(o, arg1);
            o->unk50 = func_800AB75C(o->unk54);
        } else if (func_800A9D64(o, arg1) != 0) {
            o->unk50 = func_800AB9E0(arg1);
            f = (f32)o->unk64 / 32767.0f * 255.0f;
            if (f >= 2147483648.0f) {
                goto big;
            }
            v = (s32)f;
            goto end;
        big:
            v = (s32)(f - 2147483648.0f);
            v |= 0x80000000;
        end:
            func_800ABFC4(o->unk50, v);
        }
        func_800ABEC4(o->unk50);
    } else {
        f32 d;

        o->unk2158 = 2;
        o->unk215C = arg2;
        o->unk2160 = 128.0f;
        d = 0.03333f;
        if (D_800F5668 > 0.0) {
            d = D_800F5668;
        }
        o->unk2164 = 128.0f / (arg2 / d);
        o->unk2168 = arg1;
    }
    return 1;
}
