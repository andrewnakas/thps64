#include "common.h"
typedef struct { u32 unk0; u32 unk4; } Unk80084C00;
extern s32 D_800F32B8;
extern Unk80084C00 *D_800F36A4;
void func_800B6E3C(s32, s32, void *);
void func_80084C00(void *arg0) {
    u8 *temp_v1 = (u8 *) arg0 + D_800F32B8 * 0x600;
    Unk80084C00 *temp_a2 = D_800F36A4++;
    temp_a2->unk0 = 0xDB060004;
    temp_a2->unk4 = (u32) temp_v1;
    func_800B6E3C(*(s32 *) ((u8 *) arg0 + 0xC04), -1, temp_a2);
}
