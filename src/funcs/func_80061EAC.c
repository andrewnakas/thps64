#include "common.h"

extern s32 D_800FB750[256];
extern void *D_800DACC0;
void func_8005EA48(void *);

void func_80061EAC(void) {
    s32 i;
    s32 *p;
    void *q;
    void *n;
    p = D_800FB750;
    i = 255;
    p += 255;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
    q = D_800DACC0;
    while (1) {
        if (q == NULL) {
            break;
        }
        n = *(void **)((u8 *)q + 0x14);
        func_8005EA48(q);
        q = n;
    }
    D_800DACC0 = NULL;
}
