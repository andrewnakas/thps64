#include "common.h"

extern s32 D_800DAD98;
extern u8 D_800DADA4[][25];

void func_80062F48(u8 *a, u8 *b) {
    u8 (*base)[25];
    u8 *d;
    u8 c;

    base = D_800DADA4;
    d = base[D_800DAD98];
    while ((c = *a) != 0) {
        *d = c;
        a++;
        d++;
    }
    while ((c = *b) != 0) {
        *d = c;
        b++;
        d++;
    }
    *d = 0;
}
