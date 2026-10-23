#include "common.h"
extern void func_8005F634(u16);
void func_80061BC8(u16 *arg0) {
    s32 i;
    u16 *p;
    p = arg0 + 1;
    i = 0;
    if (*arg0 != 0) {
        s32 n = *arg0;
        do {
            i++;
            func_8005F634(*p);
            p++;
        } while (i < n);
    }
}
