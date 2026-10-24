/* cflags: -O2 */
#include "common.h"

typedef struct { void (*fn)(s32, s32); s32 arg; void *obj; } C800BC764;
void func_80005070(void *, s32, s32);

void func_800BC764(s32 arg0, C800BC764 *arg1) {
    arg1->fn(arg0, arg1->arg);
    func_80005070(arg1->obj, 0, 1);
}
