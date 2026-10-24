#include "common.h"

s32 func_8003FF2C(s32);
s32 func_8003FEF4(s32);
void func_80032B18(u8 *, void *, void *, void *);
void func_80032C0C(u8 *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
s32 func_800B4264(s32, s32);
void func_80039E60(s32, s32, s32);
void func_80033244(u8 *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
void func_80032FBC(u8 *);
void func_80033100(u8 *);
void func_80031DE0(u8 *);
extern u8 D_800D0FC0[];

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))

s32 func_80031F7C(u8 *arg0) {
    s32 r;
    s32 c1;
    s32 c2;
    s32 v;
    u8 *cfg;
    s16 *q;

    r = 0;
    cfg = D_800D0FC0;
    c1 = cfg[2];
    c2 = cfg[3];
    if ((v = func_8003FF2C(c1)) == 1 && S32(arg0, 0x34) == 0) {
        S16(arg0, 0x30) = v;
        func_80032B18(arg0, arg0 + 0x4A, arg0 + 0x5FC, arg0 + 0x30);
    } else if (func_8003FF2C(c1) == -1 && S32(arg0, 0x34) == 0) {
        S16(arg0, 0x30) = 2;
        func_80032B18(arg0, arg0 + 0x4A, arg0 + 0x5FC, arg0 + 0x30);
    } else if (((v = func_8003FEF4(c1)) == 1 && S32(arg0, 0x34) == 0) || ((v = func_8003FEF4(c1)) == -1 && S32(arg0, 0x34) == 0)) {
        q = (s16 *)(arg0 + 0x30);
        *q = v;
        func_80032C0C(arg0, arg0 + 0x4A, arg0 + 0x40, arg0 + 0x3E, q, arg0 + 0x64A, arg0 + 0x650, arg0 + 0x4C, arg0 + 0x3C,
                      arg0 + 0x55C, arg0 + 0x584, arg0 + 0x54, arg0 + 0x46, arg0 + 0x48, arg0 + 0x5D4, arg0 + 0x42, arg0 + 0x44,
                      arg0 + 0x660, arg0 + 0x640, arg0 + 0x5AC, arg0 + 0x646);
    }
    if ((v = func_8003FF2C(c2)) == 1 && S32(arg0, 0x38) == 0) {
        S16(arg0, 0x32) = v;
        func_80032B18(arg0, arg0 + 0x4B, arg0 + 0x610, arg0 + 0x32);
    } else if (func_8003FF2C(c2) == -1 && S32(arg0, 0x38) == 0) {
        S16(arg0, 0x32) = 2;
        func_80032B18(arg0, arg0 + 0x4B, arg0 + 0x610, arg0 + 0x32);
    } else if (((v = func_8003FEF4(c2)) == 1 && S32(arg0, 0x38) == 0) || ((v = func_8003FEF4(c2)) == -1 && S32(arg0, 0x38) == 0)) {
        q = (s16 *)(arg0 + 0x32);
        *q = v;
        func_80032C0C(arg0, arg0 + 0x4B, arg0 + 0x41, arg0 + 0x3F, q, arg0 + 0x652, arg0 + 0x654, arg0 + 0x50, arg0 + 0x3D,
                      arg0 + 0x570, arg0 + 0x598, arg0 + 0x56, arg0 + 0x47, arg0 + 0x49, arg0 + 0x5E8, arg0 + 0x43, arg0 + 0x45,
                      arg0 + 0x662, arg0 + 0x65A, arg0 + 0x5C0, arg0 + 0x648);
    }
    if (func_800B4264(c1, 0x9000)) {
        if (S32(arg0, 0x4C) != 0) {
            func_80039E60(0x91, 10000, 0);
            S32(arg0, 0x34) = 1;
        } else {
            func_80039E60(0x92, 10000, 0);
        }
    }
    if (func_800B4264(c2, 0x9000)) {
        if (S32(arg0, 0x50) != 0) {
            func_80039E60(0x91, 10000, 0);
            S32(arg0, 0x38) = 1;
        } else {
            func_80039E60(0x92, 10000, 0);
        }
    }
    if (S32(arg0, 0x34) != 0 && S32(arg0, 0x38) != 0) {
        if (S32(arg0, 0x4C) != 0 && S32(arg0, 0x50) != 0) {
            r = 14;
        }
    } else if (func_800B4264(c1, 0x4000)) {
        if (S32(arg0, 0x34) != 0) {
            S32(arg0, 0x34) = 0;
        } else {
            func_80039E60(0x93, 10000, 0);
            r = 7;
        }
    }
    if (func_800B4264(c2, 0x4000)) {
        if (S32(arg0, 0x38) != 0) {
            S32(arg0, 0x38) = 0;
        } else {
            func_80039E60(0x93, 10000, 0);
            r = 7;
        }
    }
    func_80033244(arg0, arg0 + 0x30, arg0 + 0x40, arg0 + 0x3E, arg0 + 0x4A, arg0 + 0x42, arg0 + 0x44, arg0 + 0x64A, arg0 + 0x650, arg0 + 0x640, arg0 + 0x660);
    func_80032FBC(arg0);
    func_80033244(arg0, arg0 + 0x32, arg0 + 0x41, arg0 + 0x3F, arg0 + 0x4B, arg0 + 0x43, arg0 + 0x45, arg0 + 0x652, arg0 + 0x654, arg0 + 0x65A, arg0 + 0x662);
    func_80033100(arg0);
    func_80031DE0(arg0);
    return r;
}
