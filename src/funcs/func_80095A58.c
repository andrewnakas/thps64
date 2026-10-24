#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_8001FE54;

extern Unk_8001FE54 D_8001FE54;
extern s32 D_800DE7E4;

void func_80095A58(void) {
    Unk_8001FE54 sp0;

    D_800DE7E4 = 0;
    sp0 = D_8001FE54;
    sp0.unk2 = 0x1FF;
    sp0.unk6 = 1;
}
