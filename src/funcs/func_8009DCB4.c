/* cflags: -O2 */
/* cflags: -O2 -Wa,-no-m4100 */
#include "common.h"

void func_8009DCB4(void) {
    s32 i, j;

    i = 0;
    while (1) {
        if (i >= 4) break;
        j = 4;
        while (--j >= 0) {
        }
        i++;
    }
}
