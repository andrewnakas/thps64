#include "common.h"

void func_8004AD90(void *arg0) {
    void *var_a0;
    void *var_v1;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        var_v1 = (*(void **)((u8 *)(var_a0) + 0x1C));
loop_2:
        (*(u16 *)((u8 *)(var_a0) + 0x50)) = (u16) ((*(u16 *)((u8 *)(var_a0) + 0x50)) & 1);
        var_a0 = var_v1;
        if (var_v1 != NULL) {
            var_v1 = (*(void **)((u8 *)(var_v1) + 0x1C));
            goto loop_2;
        }
    }
}
