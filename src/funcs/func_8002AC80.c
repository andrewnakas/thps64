#include "common.h"

s32 func_8003BF24(s32);                         /* extern */
s32 func_800B1AC4(void *, f32, f32, f32, f32);  /* extern */
s32 func_800BE3D8();                            /* extern */
s32 func_800BE5A4();                            /* extern */
s32 func_800BEF70(s32, s32, s32);   /* extern */

void func_8002AC80(void *arg0) {
    f32 temp_f20;
    void *temp_v0;
    s32 a;
    s32 b;
    void *temp_v0_2;

    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4(arg0 + 0x6A4, 34.0f, 0.0f, 0.925f, 2.0f);
    func_8003BF24(arg0 + 0x30);
    if (((*(s32 *)((u8 *)(arg0) + 0x6E8)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x6E4)) != 0)) {
        temp_v0 = arg0 + ((*(u8 *)((u8 *)(arg0) + 0x6FE)) * 6);
        a = *(u16 *)((u8 *)(temp_v0) + 0x6EC);
        b = *(u16 *)((u8 *)(temp_v0) + 0x6F0);
        temp_f20 = 1.0f;
        func_800B1AC4(arg0 + 0x6B8, (f32) a, (f32) b, temp_f20, temp_f20);
        temp_v0_2 = arg0 + ((*(u8 *)((u8 *)(arg0) + 0x6FE)) * 6);
        func_800B1AC4(arg0 + 0x6CC, (f32) (*(u16 *)((u8 *)(temp_v0_2) + 0x6EE)), (f32) (*(u16 *)((u8 *)(temp_v0_2) + 0x6F0)), temp_f20, temp_f20);
    }
    func_800BE5A4();
}
