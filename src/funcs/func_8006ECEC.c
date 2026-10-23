#include "common.h"

extern void func_8009E334(void *);

void func_8006ECEC(void *arg0, s32 arg1) {
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
