#include "common.h"

void func_80079364(void *arg0) {
    *(s32 *) ((u8 *) arg0 + 0x5DC) = (s32) *(s32 *) ((u8 *) arg0 + 0x5EC);
    *(u16 *) ((u8 *) arg0 + 0x5E2) = (u16) *(u16 *) ((u8 *) arg0 + 0x5F2);
    *(u16 *) ((u8 *) arg0 + 0x5E4) = (u16) *(u16 *) ((u8 *) arg0 + 0x5F4);
}
