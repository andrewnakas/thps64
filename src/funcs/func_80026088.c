#include "common.h"

void func_8009E334(void *);
void func_800A6944(void *, s32);
extern s32 D_80017160;
extern s32 D_80017188;

void func_80026088(u8 *arg0, s32 arg1) {
    u8 *p;
    u8 *q;

    *(s32 **)arg0 = &D_80017160;
    if (arg0 + 8 != NULL) {
        p = arg0 + 0xB88;
        if (arg0 + 8 != p) {
            q = arg0 + 8;
            do {
                p -= 0xB8;
                func_800A6944(p, 2);
            } while (q != p);
        }
    }
    *(s32 **)arg0 = &D_80017188;
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
