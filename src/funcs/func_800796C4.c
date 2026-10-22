#include "common.h"

typedef struct { s32 unk0, unk4, unk8; } Unk800796C4;

void func_800796C4(void *arg0, Unk800796C4 *arg1) {
    *(s32 *) ((u8 *) arg0 + 0x4BC) = 0;
    *(Unk800796C4 *) ((u8 *) arg0 + 0x4D0) = *arg1;
    *(s32 *) ((u8 *) arg0 + 0x4CC) = 1;
    *(s32 *) ((u8 *) arg0 + 0x4B4) = 0;
}
