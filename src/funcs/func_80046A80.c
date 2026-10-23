#include "common.h"

void *func_80046A80(void *arg0, s32 *arg1) {
    (*(s16 *)((u8 *)(arg0) + 0)) = (s16) ((*(s16 *)((u8 *)(arg0) + 0)) << *arg1);
    (*(s16 *)((u8 *)(arg0) + 2)) = (s16) ((*(s16 *)((u8 *)(arg0) + 2)) << *arg1);
    (*(s16 *)((u8 *)(arg0) + 4)) = (s16) ((*(s16 *)((u8 *)(arg0) + 4)) << *arg1);
    return arg0;
}
