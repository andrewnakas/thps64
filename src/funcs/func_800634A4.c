#include "common.h"

extern void *D_800DBAE0[];

void *func_800634A4(s32 arg0) {
    void *p;

    p = D_800DBAE0[arg0 & 0x1FF];
    while (p != NULL) {
        if (*(s32 *)((u8 *)p + 0x14) == arg0) {
            break;
        }
        p = *(void **)((u8 *)p + 0x20);
    }
    return p;
}
