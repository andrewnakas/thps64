#include "common.h"

void func_8009FD60(void *);                            /* extern */

void func_80086D60(void *arg0) {
    *(f32 *) ((u8 *) arg0 + 0x8) = 20.0f;
    *(f32 *) ((u8 *) arg0 + 0xC) = 20.0f;
    *(f32 *) ((u8 *) arg0 + 0x10) = 0.1f;
    *(f32 *) ((u8 *) arg0 + 0x14) = 0.1f;
    *(s32 *) ((u8 *) arg0 + 0x20) = 0;
    func_8009FD60((u8 *) arg0 + 0x8C);
    *(s32 *) ((u8 *) arg0 + 0x18) = 0;
    *(s32 *) ((u8 *) arg0 + 0x4) = 1;
}
