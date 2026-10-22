#include "common.h"

void func_800B4888(void *, s32);                          /* extern */
extern s32 D_800ECFE0[];

void func_80084EA0(void *arg0) {
    if (*(s32 *) ((u8 *) arg0 + 0xC04) != 0) {
        func_800B4888(&D_800ECFE0, *(s32 *) ((u8 *) arg0 + 0xC08));
        *(s32 *) ((u8 *) arg0 + 0xC08) = -1;
        *(s32 *) ((u8 *) arg0 + 0xC04) = 0;
    }
}
