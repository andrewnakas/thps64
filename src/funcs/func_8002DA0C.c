#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    char *name; /* 0x2C */
    u8 pad30[0x124];
} Entry2DA0C;

typedef struct {
    char *name;
    u8 pad4[0x10];
} Item2DA0C;

typedef struct {
    u8 pad0[0x5C0];
    s32 idx; /* 0x5C0 */
    u8 pad5C4[0x10];
    Item2DA0C items[1]; /* 0x5D4 */
} Obj2DA0C;

void func_80027F60(s32);
void func_8002DC34(void *);
void func_8002DDDC(void *);
void func_8002DF84(void *);
void func_800A602C(void *);
void func_800A7B28(void *, s32, s32, s32, s32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern u8 D_800D0FD4;
extern Entry2DA0C D_800D4D80[];

void func_8002DA0C(u8 *arg0) {
    f32 f;
    s32 n;
    u8 *p;

    func_800BE3D8();
    func_800A602C(arg0 + 0x110);
    n = *(s32 *)(arg0 + 0x5C4);
    if (n < 4) {
        *(s32 *)(arg0 + 0x5C4) = n + 1;
        func_800BEF70(0, 0, 0);
    }
    f = 0.925f;
    func_800B1AC4(arg0 + 0x30, 34.0f, 0.0f, f, 2.0f);
    func_800B1AC4(arg0 + 0x44, *(s32 *)(arg0 + 0x5B0), *(s32 *)(arg0 + 0x5B4), f, 1.5f);
    func_80027F60(*(s32 *)(arg0 + 0x10C));
    func_8002DF84(arg0);
    n = *(s32 *)(arg0 + 0x5CC);
    if (n == 0) {
        func_8002DC34(arg0);
    } else if (n == 1) {
        func_8002DDDC(arg0);
    }
    p = arg0 + 0x130;
    func_800A7B28(p, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A8678(p, D_800D4D80[D_800D0FD4].name, *(s32 *)(arg0 + 0x5B8), *(s32 *)(arg0 + 0x5BC), 2, 0, 5.0f, 0xAA, 0x50, 0, 0, 0, 0, 0);
    func_800A8678(p, ((Obj2DA0C *)arg0)->items[((Obj2DA0C *)arg0)->idx].name, *(s32 *)(arg0 + 0x5B8), *(s32 *)(arg0 + 0x5BC) - 250, 2, 0, 5.0f, 0xAA, 0x50, 0, 0, 0, 0, 0);
    func_800BE5A4();
}
