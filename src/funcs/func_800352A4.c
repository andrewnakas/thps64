#include "common.h"

extern s32 D_800FA350;
extern void *func_80038F9C(void *, s32);

s32 func_800352A4(s32 arg0) {
    void *p;

    p = func_80038F9C(&D_800FA350, arg0);
    if (p == NULL) {
        return 0;
    }
    return *(s32 *)((u8 *)p + 4);
}
