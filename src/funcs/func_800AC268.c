#include "common.h"

extern u8 *D_800FC314;

u8 *func_800AC268(u8 *arg0) {
    if (arg0 != NULL && *(s32 *)(arg0 + 0x10) < 0) {
        D_800FC314 = arg0;
    }
    return D_800FC314;
}
