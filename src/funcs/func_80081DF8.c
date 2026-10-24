#include "common.h"

typedef struct {
    u8 pad0[0xC0];
    s32 unkC0;
    u8 padC4[0x4C];
    u32 unk110;
} Hud80081DF8;

extern void func_8006DF40(s32, s32, s32, s32, s32, s32, s32);
extern void func_8006F1A8(s32, s32, s32, s32);
extern void func_8006F23C(s32);
extern void func_8006F274(s32);
extern Hud80081DF8 D_800DE640;

void func_80081DF8(void) {
    Hud80081DF8 *h = &D_800DE640;
    s32 x;

    if (h->unkC0 != 0) {
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        func_8006F23C(0x100);
        func_8006F274(1);
        if (h->unk110 > 0x300) {
            h->unk110 = 0;
        }
        x = h->unk110;
        func_8006DF40(0x200 - x, 0xC8, h->unkC0, 0, 0, 0x100, 0);
        h->unk110 += 5;
    }
}
