#include "common.h"

s32 func_800B477C(void *, s32);                        /* extern */
void func_800B4888(void *, s32);                          /* extern */
extern s32 D_800ECFE0[];

void func_80084DBC(void *arg0, s32 arg1) {
    if (*(s32 *) ((u8 *) arg0 + 0xC04) != 0) {
        func_800B4888(&D_800ECFE0, *(s32 *) ((u8 *) arg0 + 0xC08));
        *(s32 *) ((u8 *) arg0 + 0xC08) = -1;
        *(s32 *) ((u8 *) arg0 + 0xC04) = 0;
    }
    *(s32 *) ((u8 *) arg0 + 0xC04) = func_800B477C(&D_800ECFE0, arg1);
    *(s32 *) ((u8 *) arg0 + 0xC08) = arg1;
}
