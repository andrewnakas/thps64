#include "common.h"

s32 func_8003B2D8(void *);                      /* extern */
s32 func_8003BF24(void *);                      /* extern */
s32 func_800B1AC4(void *, f32, f32, f32, f32);  /* extern */
s32 func_800BE3D8();                            /* extern */
s32 func_800BE5A4();                            /* extern */
s32 func_800BEF70(s32, s32, s32);   /* extern */

void func_8003B1B8(void *arg0) {
    f32 temp_f20;
    void *temp_v0;
    s32 a, b;
    void *temp_v0_2;

    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4(arg0 + 0x930, 34.0f, 0.0f, 0.925f, 2.0f);
    if (((*(s32 *)((u8 *)(arg0) + 0x48)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x7C)) != 0)) {
        temp_v0 = arg0 + ((*(u8 *)((u8 *)(arg0) + 0x76)) * 6);
        a = *(u16 *)((u8 *)(temp_v0) + 0x4C);
        b = *(u16 *)((u8 *)(temp_v0) + 0x50);
        temp_f20 = 1.0f;
        func_800B1AC4(arg0 + 0x944, (f32) a, (f32) b, temp_f20, temp_f20);
        temp_v0_2 = arg0 + ((*(u8 *)((u8 *)(arg0) + 0x76)) * 6);
        func_800B1AC4(arg0 + 0x958, (f32) (*(u16 *)((u8 *)(temp_v0_2) + 0x4E)), (f32) (*(u16 *)((u8 *)(temp_v0_2) + 0x50)), temp_f20, temp_f20);
    }
    func_8003BF24(arg0 + 0x2C0);
    func_8003B2D8(arg0);
    func_800BE5A4();
}
