#include "common.h"

s32 func_8005EA48(void *);                      /* extern */
extern s32 D_8001B420;
extern s32 D_8001B460;
extern s32 D_8001B4A0;

void func_8004A11C(void *arg0, s32 arg1) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_v0;
    void *temp_v1;

    (*(void **)((u8 *)(arg0) + 0x48)) = &D_8001B420;
    temp_a0 = (*(void **)((u8 *)(arg0) + 0x27C));
    if (temp_a0 != NULL) {
        func_8005EA48(temp_a0);
    }
    temp_a0_2 = (*(void **)((u8 *)(arg0) + 0x280));
    if (temp_a0_2 != NULL) {
        func_8005EA48(temp_a0_2);
    }
    temp_a0_3 = (*(void **)((u8 *)(arg0) + 0x210));
    if (temp_a0_3 != NULL) {
        func_8005EA48(temp_a0_3);
    }
    temp_a0_4 = (*(void **)((u8 *)(arg0) + 0x214));
    if (temp_a0_4 != NULL) {
        func_8005EA48(temp_a0_4);
    }
    temp_a0_5 = (*(void **)((u8 *)(arg0) + 0x20C));
    if (temp_a0_5 != NULL) {
        func_8005EA48(temp_a0_5);
    }
    (*(void **)((u8 *)(arg0) + 0x48)) = &D_8001B460;
    temp_v1 = (*(void **)((u8 *)(arg0) + 0x14C));
    if (temp_v1 != NULL) {
        temp_v0 = (*(void **)((u8 *)(temp_v1) + 0x44));
        (*(s32 (**)(void *, s32))((u8 *)(temp_v0) + 0xC))(temp_v1 + (*(s16 *)((u8 *)(temp_v0) + 8)), 3);
    }
    (*(void **)((u8 *)(arg0) + 0x48)) = &D_8001B4A0;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
