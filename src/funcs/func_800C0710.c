/* cflags: -O2 */
#include "common.h"

typedef void (*Func_800C0710)(void);

void func_800C0710(s32 start, s32 end) {
    Func_800C0710 f;

    while (start < end) {
        f = *(Func_800C0710 *)start;
        start += 4;
        if (f != NULL) {
            f();
        }
    }
}
