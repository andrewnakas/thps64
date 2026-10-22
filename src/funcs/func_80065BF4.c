#include "common.h"

s32 func_8004B204(void *, s32);                     /* extern */
s32 func_8004B22C(void *, s32);                 /* extern */
s32 func_8004B30C(void *, void *);           /* extern */
s32 func_8004B468(void *, s32);                 /* extern */
s32 func_80072DFC();                            /* extern */
extern s32 D_8001CB18;
extern s32 D_800D6180;
extern s32 D_800D61A0;
extern s32 D_800DACB8;

void *func_80065BF4(void *arg0, s32 arg1, s16 arg2) {
    void *head;

    func_80072DFC();
    (*(void **)((u8 *)(arg0) + 0x48)) = &D_8001CB18;
    (*(s32 *)((u8 *)(arg0) + 0x310)) = (s32) D_800D61A0;
    func_8004B468(arg0, D_800DACB8);
    head = &D_800D6180;
    func_8004B30C(arg0, head);
    (*(u16 *)((u8 *)(arg0) + 0)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0)) | 0x111) & 0xFFFD);
    (*(s16 *)((u8 *)(arg0) + 0x324)) = 0x192;
    (*(s32 *)((u8 *)(arg0) + 0x2A8)) = func_8004B204(arg0, func_8004B22C(arg0, arg1));
    (*(s16 *)((u8 *)(arg0) + 0x15E)) = arg2;
    (*(s32 *)((u8 *)(arg0) + 0x340)) = -1;
    (*(s16 *)((u8 *)(arg0) + 0x2CC)) = 0x20;
    (*(s8 *)((u8 *)(arg0) + 0x294)) = 1;
    return arg0;
}
