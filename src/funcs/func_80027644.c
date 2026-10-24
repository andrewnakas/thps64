/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec27644;

typedef struct {
    f32 m[12];
    Vec27644 pos;
} Frame27644;

#define F(o) (*(f32 *)((u8 *)arg0 + (o)))
#define I(o) (*(s32 *)((u8 *)arg0 + (o)))

void func_80039E60(s32, s32, s32);
void func_8009CC10(void *, f32);
void func_800A4624(void *, Frame27644 *);
void func_8004A314(void *);
void func_80026D2C(void *);
extern f32 D_800F5668;

s32 func_80027644(u8 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    Vec27644 t;
    Frame27644 fr;
    s32 ret;
    f32 k;
    f32 a;
    f32 b;
    s32 c;
    f32 z;

    ret = 0;
    if (arg1 != 0 && F(0x2260) == 0.0f) {
        func_80039E60(0x90, 10000, 0);
        F(0x2264) = arg1;
        F(0x2260) = F(0x2264) * -0.001f;
        I(0x226C) = arg1;
    }
    c = *(s8 *)(arg0 + 0xF14);
    k = -1.0f;
    if (c == 0) {
        k = 1.0f;
    }
    if (arg2 != 0) {
        F(0x2268) += D_800F5668 * (k * -1.5707964f);
    }
    func_8009CC10(arg0 + 0x2208, F(0x2268));
    t.x = 0.0f;
    t.y = arg3;
    t.z = 0.0f;
    *(Vec27644 *)(arg0 + 0x2238) = t;
    a = F(0x2264);
    b = F(0x2260);
    if (a * b < 0.0f) {
        if (arg2 != 0) {
            F(0x2260) = b - a * (D_800F5668 * 0.8f);
        }
        if (F(0x2264) * F(0x2260) < -0.2f) {
            F(0x2260) = F(0x2264) * 0.2f;
            ret = I(0x226C);
        }
    } else if (0.0f < a * b) {
        if (arg2 != 0) {
            F(0x2260) = b - a * (D_800F5668 * 0.8f);
        }
        if (F(0x2264) * F(0x2260) < 0.0f) {
            F(0x2260) = 0.0f;
        }
    }
    func_8009CC10(&fr, F(0x2260));
    z = -55.0f;
    t.x = 0.0f;
    t.y = 0.0f;
    t.z = z;
    fr.pos = t;
    func_800A4624(arg0 + 0x1B28, &fr);
    if (I(0x3E0) == 0) {
        I(0x208) &= ~2;
    } else {
        I(0x208) |= 2;
    }
    func_8004A314(arg0);
    func_80026D2C(arg0);
    return ret;
}
