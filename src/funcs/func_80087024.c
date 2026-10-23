#include "common.h"

typedef struct {
    u32 unk0;
    u32 unk4;
} Unk80087024;

extern Unk80087024 *D_800F36A4;
void func_800B9DE0(s32);

void func_80087024(s32 arg0, s32 arg1) {
    Unk80087024 *cmd;
    Unk80087024 *cmd2;

    cmd = D_800F36A4++;
    cmd->unk0 = 0xE7000000;
    cmd->unk4 = 0;
    cmd = D_800F36A4++;
    cmd->unk0 = 0xE3000A01;
    cmd->unk4 = 0x100000;
    func_800B9DE0(arg1);
    cmd2 = D_800F36A4++;
    cmd2->unk0 = 0xFCFFFFFF;
    cmd2->unk4 = 0xFFFCF238;
}
