#include "common.h"

s32 func_8004B0BC(void *);                      /* extern */
extern void *D_800D6184;

void func_8004B13C(void *arg0, void **arg1) {
    void *temp_v0_2;
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_2;

    temp_v0 = (*(void **)((u8 *)(arg0) + 0x48));
    (*(s32 (**)(void *))((u8 *)(temp_v0) + 0x3C))(arg0 + (*(s16 *)((u8 *)(temp_v0) + 0x38)));
    (*(void ***)((u8 *)(arg0) + 0x4C)) = arg1;
    if (((*(u16 *)((u8 *)(arg0) + 0x52)) & 1) && (arg1 != &D_800D6184)) {
        func_8004B0BC(arg0);
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
    (*(void **)((u8 *)(arg0) + 0x1C)) = D_800D6184;
    (*(void **)((u8 *)(arg0) + 0x30)) = NULL;
    temp_v0_2 = (*(void **)((u8 *)(arg0) + 0x1C));
    D_800D6184 = arg0;
    if (temp_v0_2 != NULL) {
        (*(void **)((u8 *)(temp_v0_2) + 0x30)) = arg0;
    }
    (*(u16 *)((u8 *)(arg0) + 0x52)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x52)) | 1);
}
