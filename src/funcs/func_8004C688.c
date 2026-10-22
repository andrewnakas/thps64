#include "common.h"

s32 func_80039F88(s32);                         /* extern */
s32 func_8004A11C(void *, s32);             /* extern */
s32 func_8004B264(void *, void *);           /* extern */
s32 func_8004B4F8(void *);                      /* extern */
s32 func_8004C53C(void *);                      /* extern */
s32 func_8005EA48(s32);                         /* extern */
s32 func_8006ECEC(void *, s32);             /* extern */
extern s32 D_8001B4E8;
extern s32 D_800D61A4;
extern s32 D_800D61A8;

void func_8004C688(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    void *head;

    (*(void **)((u8 *)(arg0) + 0x48)) = &D_8001B4E8;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x7C0));
    if (temp_a0 != 0) {
        func_80039F88(temp_a0);
        (*(s32 *)((u8 *)(arg0) + 0x7C0)) = 0;
    }
    temp_a0_2 = (*(s32 *)((u8 *)(arg0) + 0x7C4));
    if (temp_a0_2 != 0) {
        func_80039F88(temp_a0_2);
        (*(s32 *)((u8 *)(arg0) + 0x7C4)) = 0;
    }
    temp_a0_3 = (*(s32 *)((u8 *)(arg0) + 0x234));
    if (temp_a0_3 != 0) {
        func_8005EA48(temp_a0_3);
    }
    temp_a0_4 = (*(s32 *)((u8 *)(arg0) + 0x238));
    if (temp_a0_4 != 0) {
        func_8005EA48(temp_a0_4);
    }
    head = &D_800D61A8;
    func_8004B264(arg0, head);
    D_800D61A4 -= 1;
    func_8004C53C(arg0);
    func_8006ECEC(arg0 + 0xBCC, 2);
    func_8006ECEC(arg0 + 0xB80, 2);
    func_8004A11C(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
