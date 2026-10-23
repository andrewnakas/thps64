#include "common.h"
typedef struct { u32 field_0, field_4; } Entry80087024;
extern Entry80087024 *D_800F36A4;
void func_800B9DE0(s32);

void func_80087024(s32 arg0, s32 arg1) {
    Entry80087024 *gfx;
    Entry80087024 *last;

    gfx = D_800F36A4++;
    gfx->field_0 = 0xE7000000;
    gfx->field_4 = 0;
    gfx = D_800F36A4++;
    gfx->field_0 = 0xE3000A01;
    gfx->field_4 = 0x100000;
    func_800B9DE0(arg1);
    last = D_800F36A4++;
    last->field_0 = 0xFCFFFFFF;
    last->field_4 = 0xFFFCF238;
}
