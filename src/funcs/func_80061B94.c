#include "common.h"

void func_80061B94(void *arg0, s32 arg1) {
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            if ((*(u16 *)((u8 *)(var_a0) + 0x15E)) == arg1) {
                (*(u16 *)((u8 *)(var_a0) + 0x50)) = (u16) ((*(u16 *)((u8 *)(var_a0) + 0x50)) | 1);
            }
            var_a0 = (*(void **)((u8 *)(var_a0) + 0x1C));
        } while (var_a0 != NULL);
    }
}
