#include "common.h"

void func_8004B2F0(void *arg0) {
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            var_a0 = (*(void **)((u8 *)(var_a0) + 0x1C));
        } while (var_a0 != NULL);
    }
}
