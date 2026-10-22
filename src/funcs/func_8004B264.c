#include "common.h"

s32 func_8004B0BC();                            /* extern */
extern s32 D_800D6184;

void func_8004B264(void *arg0, void **arg1) {
    void *temp_v1;
    void *temp_v1_2;

    if (((*(u16 *)((u8 *)(arg0) + 0x52)) & 1) && (arg1 != &D_800D6184)) {
        func_8004B0BC();
    }
    temp_v1 = (*(void **)((u8 *)(arg0) + 0x1C));
    if (temp_v1 != NULL) {
        (*(void **)((u8 *)(temp_v1) + 0x30)) = (void *) (*(void **)((u8 *)(arg0) + 0x30));
    }
    temp_v1_2 = (*(void **)((u8 *)(arg0) + 0x30));
    if (temp_v1_2 != NULL) {
        (*(void **)((u8 *)(temp_v1_2) + 0x1C)) = (void *) (*(void **)((u8 *)(arg0) + 0x1C));
    }
    if (*arg1 == arg0) {
        *arg1 = (*(void **)((u8 *)(arg0) + 0x1C));
    }
}
