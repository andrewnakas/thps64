#include "common.h"

extern void func_8005EA48(s32);
extern void func_8009E334(void *);

void func_8006E954(s32 *arg0, s32 arg1) {
    if (arg0[1] != 0) {
        func_8005EA48(arg0[0]);
    }
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
