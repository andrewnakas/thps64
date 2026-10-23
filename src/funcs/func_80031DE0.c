#include "common.h"

s32 func_80031240(void *);                      /* extern */
s32 func_80031804(void *);                      /* extern */
s32 func_80032450(void *);                      /* extern */
s32 func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_800B1AC4(void *, f32, f32, f32, f32); /* extern */
s32 func_800BE3D8();                            /* extern */
s32 func_800BE5A4();                            /* extern */
s32 func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_800BEF70(s32, s32, s32);   /* extern */

void func_80031DE0(void *arg0) {
    f32 temp_f22;
    s32 temp_v1;
    s32 h;
    void *temp_s3;

    func_800BE3D8();
    temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x624));
    if (temp_v1 < 4) {
        (*(s32 *)((u8 *)(arg0) + 0x624)) = (s32) (temp_v1 + 1);
        func_800BEF70(0, 0, 0);
    } else {
        func_800BE7D0(0, 0x280, 0x177, 0x1A9, 0, 0, 0, 0xFF);
    }
    func_800B1AC4(arg0 + 0x548, 40.0f, 15.0f, 0.925f, 1.9f);
    temp_s3 = arg0 + 0x58;
    h = *(s16 *)((u8 *)(arg0) + 0x642);
    temp_f22 = 406.0f;
    func_800A8678(temp_s3, arg0 + 0x4D8, (f32) h, temp_f22, 0, 0, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    func_800A8678(temp_s3, arg0 + 0x4E8, (f32) (*(s16 *)((u8 *)(arg0) + 0x644)), temp_f22, 0, 0, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    func_80031804(arg0);
    func_80031240(arg0);
    func_80032450(arg0);
    func_800BE5A4();
}
