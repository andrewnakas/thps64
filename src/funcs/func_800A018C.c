/* cflags: -O2 */
#include "common.h"

s32 func_80007410(u8 *);
extern u8 *D_800EA548;

u8 *func_800A018C(s32 arg0) {
    u8 *p;

    p = D_800EA548;
    while (1) {
        if (p == NULL) {
            return NULL;
        }
        if (func_80007410(p) == arg0) {
            return p;
        }
        p = *(u8 **)(p + 0x1C0);
    }
}
