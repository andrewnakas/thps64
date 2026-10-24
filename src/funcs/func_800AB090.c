/* cflags: -O2 */
#include "common.h"

u8 *func_800AB090(u8 *a0, u8 *a1) {
    a0[0xD8] = *a1++;
    a0[0xCE] = *a1++;
    a0[0xCF] = *a1;
    return a1 + 1;
}
