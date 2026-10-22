#include "common.h"

void func_8009FD60(void *);                            /* extern */
#define D_8001EDD4 (*(const f32 *) 0x8001EDD4)
#define D_8001EDD8 (*(const f32 *) 0x8001EDD8)

void func_80086D60(void *arg0) {
    *(f32 *) ((u8 *) arg0 + 0x8) = (f32) D_8001EDD4;
    *(f32 *) ((u8 *) arg0 + 0xC) = (f32) D_8001EDD4;
    *(f32 *) ((u8 *) arg0 + 0x10) = (f32) D_8001EDD8;
    *(f32 *) ((u8 *) arg0 + 0x14) = (f32) D_8001EDD8;
    *(s32 *) ((u8 *) arg0 + 0x20) = 0;
    func_8009FD60(arg0 + 0x8C);
    *(s32 *) ((u8 *) arg0 + 0x18) = 0;
    *(s32 *) ((u8 *) arg0 + 0x4) = 1;
}
