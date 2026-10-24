/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x1C8];
    u8 unk1C8[0xC];
    u8 unk1D4[0xC];
    u8 unk1E0[0xC];
    u8 unk1EC[0x1C];
    u8 unk208[0x1C];
    u8 unk224[0x1C];
    u8 unk240[0x1C];
} Sys800BD3AC;

extern void func_8009FF4C(Sys800BD3AC *, s32);
extern void func_800BD550(void *, s32);
extern Sys800BD3AC D_800F0DD0;

void func_800BD3AC(void) {
    Sys800BD3AC *p = &D_800F0DD0;

    func_800BD550(p->unk240, 2);
    func_800BD550(p->unk224, 2);
    func_800BD550(p->unk208, 2);
    func_800BD550(p->unk1EC, 2);
    func_800BD550(p->unk1E0, 2);
    func_800BD550(p->unk1D4, 2);
    func_800BD550(p->unk1C8, 2);
    func_8009FF4C(p, 2);
}
