#include "common.h"

void func_8007DB68(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s32 *)(arg0 + 0x58) = (0x32000000 | ((arg3 & 0xFF) << 16)) | ((arg2 & 0xFF) << 8) | (arg1 & 0xFF);
}
