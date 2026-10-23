#include "common.h"

extern u8 D_800D0FC0[];
extern u8 D_800EECF0[];
void func_800BAC04(void *, s32);
void *func_800BAB04(void *, s32);

void func_80042068(s32 arg0) {
    u8 *p;
    u8 *cur;

    p = D_800D0FC0;
    cur = *(u8 **)(p + 0xECC);
    if (cur != NULL) {
        if (arg0 == *(u16 *)(cur + 0x66)) {
            return;
        }
        func_800BAC04(D_800EECF0, *(u16 *)(cur + 0x66));
        *(u8 **)(p + 0xECC) = NULL;
    }
    if (arg0 != -1) {
        *(s32 *)(p + 0xECC) = *(s32 *)((u8 *)func_800BAB04(D_800EECF0, arg0) + 4);
    }
}
