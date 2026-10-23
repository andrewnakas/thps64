/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0xD0];
    s32 unkD0;
} D3F34;

void func_800242CC(void);
void func_80039500(void);
void func_8003A880(D3F34 *);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
void func_8008BB50(void *);
void func_800A72C0(void *);
void func_800A73EC(void *, s32);
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A9460(void *, s32, f32, s32);
void func_800B198C(void *);
void func_800B1A80(void *, s32);
extern u8 D_8001A090[];
extern u8 D_800D0FC0[];
extern D3F34 D_800D3F34;
extern s32 D_800D4690;
extern f32 D_800EA9B0;
extern u8 D_800EA9C0[];
extern f32 D_800ECEF0;

u8 *func_8003BA00(u8 *arg0) {
    u8 *obj;
    s32 a;
    u8 sp18[8];
    f32 f;
    f32 g;
    D3F34 *st;

    func_80039500();
    *(u8 **)(arg0 + 0x2C) = D_8001A090;
    func_800B198C(arg0 + 0x30);
    func_800A72C0(arg0 + 0x44);
    st = &D_800D3F34;
    if (st->unkD0 != 0) {
        func_800A9460(D_800EA9C0, 0, 2.0f, -1);
    } else {
        func_8003A880(st);
    }
    f = D_800D4690;
    D_800ECEF0 = f;
    D_800EA9B0 = f;
    func_8008BB50(sp18);

    func_800242CC();
    D_800D0FC0[1] = 1;
    D_800D0FC0[0x14] = 0;
    D_800D0FC0[0x15] = 1;
    func_800A73EC(arg0 + 0x44, 0x501);
    func_8008B490(sp18, arg0 + 0x44, 0x501);
    arg0[0x54] = 0;
    a = 0xFF;
    func_800A7AF8(arg0 + 0x44, 0xF4, 0x92, 0x1E, a);
    func_800A7B10(arg0 + 0x44, 0xF4, 0x92, 0x1E, a);
    g = 1.5f;
    func_800A773C(arg0 + 0x44, g, g);
    func_800B1A80(arg0 + 0x30, 0);
    *(s32 *)(arg0 + 0x34) = 1;
    func_8008BB2C(sp18, 2);
    return arg0;
}
