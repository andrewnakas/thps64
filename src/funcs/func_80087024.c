#include "common.h"

typedef struct { u32 unk0, unk4; } Unk80087024;
extern Unk80087024 *D_800F36A4;
void func_800B9DE0(s32);

void func_80087024(s32 arg0, s32 arg1) {
    register Unk80087024 *temp_a0 __asm__("$4");
    register Unk80087024 *temp_v0 __asm__("$2");
    register Unk80087024 *temp_v1 __asm__("$3");

    temp_v0 = D_800F36A4;
    temp_a0 = temp_v0;
    temp_v0 += 1;
    __asm__("" : "+r" (temp_v0), "+r" (temp_a0));
    D_800F36A4 = temp_v0;
    temp_a0->unk0 = 0xE7000000;
    temp_a0->unk4 = 0;
    D_800F36A4 = temp_v0 + 1;
    temp_v0->unk0 = 0xE3000A01;
    temp_v0->unk4 = 0x100000;
    func_800B9DE0(arg1);
    temp_v0 = D_800F36A4;
    temp_v1 = temp_v0;
    temp_v0 += 1;
    __asm__("" : "+r" (temp_v0), "+r" (temp_v1));
    D_800F36A4 = temp_v0;
    temp_v1->unk0 = 0xFCFFFFFF;
    temp_v1->unk4 = 0xFFFCF238;
}
