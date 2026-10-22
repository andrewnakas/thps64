#include "common.h"

typedef struct { s32 unk0, unk4, unk8; } Unk80079684;

void func_80079684(void *arg0, Unk80079684 *arg1) {
    *(s32 *) ((u8 *) arg0 + 0x4F0) = 0;
    *(Unk80079684 *) ((u8 *) arg0 + 0x500) = *arg1;
    *(s32 *) ((u8 *) arg0 + 0x4EC) = 0;
    *(s32 *) ((u8 *) arg0 + 0x4CC) = 1;
}
