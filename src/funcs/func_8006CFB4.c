#include "common.h"

typedef struct {
    s32 unk0;
    s32 pad4[3];
    s32 *unk10;
    s32 unk14;
    s32 unk18;
} Unk8006CFB4;

extern s32 D_800D61A8;
extern s32 D_800DC614;
extern Unk8006CFB4 D_800DC618;
extern Unk8006CFB4 D_800DC6D8;

void func_8006CFB4(s32 arg0) {
    Unk8006CFB4 *p;

    if (arg0 == D_800D61A8) {
        p = &D_800DC618;
    } else {
        p = &D_800DC6D8;
    }
    if (p->unk0 == 1 && p->unk18 != 0x20) {
        *p->unk10++ = p->unk14;
        p->unk14 = 0;
        p->unk18 = 0x20;
    }
    p->unk0 = 0;
    D_800DC614 = 0;
}
