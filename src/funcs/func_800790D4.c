#include "common.h"

__asm__(".set noreorder");

typedef struct { s32 unk0[8]; } Unk800790D4;

void func_800790D4(void *arg0, Unk800790D4 *arg1) {
    *arg1 = *(Unk800790D4 *) ((u8 *) arg0 + 0x88);
}
