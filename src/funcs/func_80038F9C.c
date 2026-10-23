#include "common.h"

void *func_80038F9C(void *arg0, s32 arg1) {
    s32 i;
    s32 n;
    void *p;

    i = 0;
    n = *(s32 *)((u8 *)arg0 + 0x10);
    while (1) {
        if (i >= n) {
            return NULL;
        }
        p = (*(void ***)((u8 *)arg0 + 0xC))[i];
        i++;
        if (*(s32 *)((u8 *)(*(void **)((u8 *)p + 4)) + 0x1C) == arg1) {
            return p;
        }
    }
}
