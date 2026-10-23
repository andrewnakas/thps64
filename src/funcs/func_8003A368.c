#include "common.h"

void func_800A8E90(void *, s32);
void func_800A9068(void *, s32, s32, s32, void *, s32, s32);
void func_800A9B98(void *, s32, s32);
extern u8 D_800EA9C0[];

void func_8003A368(void *arg0) {
    u8 *p;

    p = D_800EA9C0;
    func_800A9068(p, 0xF, 0xE, 0, (u8 *)arg0 + 0xD8, *((u8 *)arg0 + 0x104) + 1, 0x5622);
    func_800A9B98(p, 0x6F, 0x78);
    func_800A8E90(p, *(s32 *)((u8 *)arg0 + 0x100));
}
