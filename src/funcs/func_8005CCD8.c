#include "common.h"

s32 func_80082CB0();                            /* extern */
extern void *D_800D6180;
extern u16 D_800D7234;
extern void *D_800DAD8C;

void func_8005CCD8(void *arg0) {
    u16 temp_v0;
    void *var_v0;
    void *var_v0_2;

    (*(s32 *)((u8 *)(arg0) + 0x68)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x80)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x40)) = 0x7FFFFFFF;
    (*(s32 *)((u8 *)(arg0) + 0x8C)) = 0x7FFFFFFF;
    (*(s32 *)((u8 *)(arg0) + 0x84)) = -1;
    (*(s8 *)((u8 *)(arg0) + 0x88)) = 0;
    (*(s8 *)((u8 *)(arg0) + 0x89)) = 0;
    temp_v0 = D_800D7234 + 1;
    D_800D7234 = temp_v0;
    if (!(temp_v0 & 0xFFFF)) {
        D_800D7234 = 1;
        var_v0 = D_800DAD8C;
        if (var_v0 != NULL) {
            do {
                (*(s16 *)((u8 *)(var_v0) + 2)) = 0;
                var_v0 = (*(void **)((u8 *)(var_v0) + 0x1C));
            } while (var_v0 != NULL);
        }
        var_v0_2 = D_800D6180;
        if (var_v0_2 != NULL) {
            do {
                (*(s16 *)((u8 *)(var_v0_2) + 2)) = 0;
                var_v0_2 = (*(void **)((u8 *)(var_v0_2) + 0x1C));
            } while (var_v0_2 != NULL);
        }
    }
    (*(u16 *)((u8 *)(arg0) + 0x8A)) = (u16) D_800D7234;
    func_80082CB0();
}
