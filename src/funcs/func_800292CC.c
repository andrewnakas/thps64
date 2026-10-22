#include "common.h"

void func_8003BF24(void *);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);

void func_800292CC(u8 *arg0) {
    s32 temp_v1;
    u8 *temp_v0;
    u8 *temp_v0_2;
    s32 a, b;
    f32 temp_f20;

    func_800BE3D8();
    temp_v1 = *(s32 *)(arg0 + 0x34);
    if (temp_v1 < 3) {
        *(s32 *)(arg0 + 0x34) = temp_v1 + 1;
        func_800BEF70(0, 0, 0);
    }
    func_800B1AC4(arg0 + 0x6A8, 34.0f, 0.0f, 0.925f, 2.0f);
    if ((*(s32 *)(arg0 + 0x6EC) != 0) && (*(s32 *)(arg0 + 0x6E8) != 0)) {
        temp_v0 = arg0 + arg0[0x70E] * 6;
        a = *(u16 *)(temp_v0 + 0x6F0);
        b = *(u16 *)(temp_v0 + 0x6F4);
        temp_f20 = 1.0f;
        func_800B1AC4(arg0 + 0x6BC, (f32)a, (f32)b, temp_f20, temp_f20);
        temp_v0_2 = arg0 + arg0[0x70E] * 6;
        func_800B1AC4(arg0 + 0x6D0, (f32)*(u16 *)(temp_v0_2 + 0x6F2), (f32)*(u16 *)(temp_v0_2 + 0x6F4), temp_f20, temp_f20);
    }
    func_8003BF24(arg0 + 0x38);
    func_800BE5A4();
}
