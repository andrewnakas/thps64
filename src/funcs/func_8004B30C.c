#include "common.h"

void func_8004B30C(void *arg0, void **arg1) {
    void *temp_v0;

    (*(void **)((u8 *)(arg0) + 0x1C)) = (void *) *arg1;
    (*(s32 *)((u8 *)(arg0) + 0x30)) = 0;
    *arg1 = arg0;
    temp_v0 = (*(void **)((u8 *)(arg0) + 0x1C));
    if (temp_v0 != NULL) {
        (*(void **)((u8 *)(temp_v0) + 0x30)) = arg0;
    }
}
