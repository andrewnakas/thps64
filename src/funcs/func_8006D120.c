#include "common.h"

typedef struct {
    s32 unk0;
    u8 *unk4;
    u8 *unk8;
} Buf8006D120;

u8 *func_8005EAB4(s32, s32, s32);
extern u8 *D_800D275C;
extern Buf8006D120 D_800DC618;
extern Buf8006D120 D_800DC6D8;
extern s32 D_800DE9A8;

void func_8006D120(void) {
    D_800DC618.unk8 = D_800D275C;
    D_800DC618.unk4 = D_800DC618.unk8;
    D_800DC618.unk8 += 0x240;
    if (D_800DE9A8 == 2) {
        D_800DC6D8.unk8 = func_8005EAB4(0x6000, 1, 1);
        D_800DC6D8.unk4 = D_800DC6D8.unk8;
        D_800DC6D8.unk8 += 0x240;
    } else {
        D_800DC6D8.unk8 = NULL;
        D_800DC6D8.unk4 = NULL;
    }
}
