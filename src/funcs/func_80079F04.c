#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Unk80079F04;

extern Unk80079F04 D_800DE56C;
extern Unk80079F04 D_800DE574;
void func_80047980(s32, s32, Unk80079F04 *);
s32 func_80049D60(s32);

void func_80079F04(s32 arg0, s32 arg1) {
    Unk80079F04 sp10;
    Unk80079F04 *temp_t2 = &D_800DE56C;
    Unk80079F04 *temp_s2;
    Unk80079F04 *temp_s1;

    temp_s2 = &sp10;
    *temp_s2 = *temp_t2;
    temp_s1 = &D_800DE574;

    if (D_800DE574.unk0 != 0) {
        sp10.unk0 += func_80049D60(D_800DE574.unk0) - (D_800DE574.unk0 >> 1);
    }
    if (temp_s1->unk2 != 0) {
        sp10.unk2 += func_80049D60(temp_s1->unk2) - (temp_s1->unk2 >> 1);
    }
    if (temp_s1->unk4 != 0) {
        sp10.unk4 += func_80049D60(temp_s1->unk4) - (temp_s1->unk4 >> 1);
    }
    func_80047980(arg0, arg1, temp_s2);
}
