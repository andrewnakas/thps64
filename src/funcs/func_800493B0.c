#include "common.h"

void func_800493B0(void *arg0) {
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            if (!((*(u16 *)((u8 *)(var_a0) + 0x52)) & 0x40)) {
                (*(u16 *)((u8 *)(var_a0) + 0x50)) = (u16) ((*(u16 *)((u8 *)(var_a0) + 0x50)) | 4);
            }
            var_a0 = (*(void **)((u8 *)(var_a0) + 0x1C));
        } while (var_a0 != NULL);
    }
}
