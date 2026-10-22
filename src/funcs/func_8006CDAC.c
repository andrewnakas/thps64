#include "common.h"

typedef struct {
    s32 active;
    u8 pad4[0xC];
    s32 *ptr;
    s32 bits;
    s32 count;
} Buf8006CDAC;

void func_8006ACC4(s32);
extern s32 D_800D61A8;
extern s32 D_800DC614;
extern Buf8006CDAC D_800DC618;
extern Buf8006CDAC D_800DC6D8;
extern s32 D_800DE9AC;

void func_8006CDAC(s32 arg0) {
    s32 cur;
    Buf8006CDAC *b;

    cur = D_800D61A8;
    if (D_800DE9AC == 1) {
        if (arg0 == cur) {
            b = &D_800DC618;
        } else {
            b = &D_800DC6D8;
        }
        if (b->active == 1 && b->count != 0x20) {
            *b->ptr++ = b->bits;
            b->bits = 0;
            b->count = 0x20;
        }
        b->active = 0;
        D_800DC614 = 0;
    } else {
        func_8006ACC4(arg0);
    }
}
