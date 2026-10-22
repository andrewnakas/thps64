#include "common.h"

void *func_80061C20(u8 *arg0) {
    u8 *var_a0;

    var_a0 = arg0;
    if (*var_a0 != 0xFF) {
        do {
            var_a0 += 1;
        } while (*var_a0 != 0xFF);
    }
    return var_a0 + 1;
}
