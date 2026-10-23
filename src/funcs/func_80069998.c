/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Node {
    s32 unk0;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u16 unk8;
    u16 padA;
    struct Node *unkC;
    u16 *unk10;
} Node;

void func_80035138(s32, s32, u8);
u16 *func_800635E4(s32);
extern s32 D_800D2838;
extern Node *D_800DC5E0;
extern u8 D_800DC5F0;
extern u8 D_800DC604[];
extern u16 D_800DC608[];
extern s32 D_800DE7A0;
extern s32 D_800DE7A8;

void func_80069998(s32 arg0) {
    Node *s;
    u16 *r;

    if (D_800DE7A0 == 8) {
        s = D_800DC5E0;
        while (1) {
            if (s == NULL) {
                break;
            }
            if (s->unk4 == arg0) {
                if (s->unk6 == 0 || D_800DE7A0 == 8) {
                    r = func_800635E4(s->unk0);
                    s->unk10 = r;
                    s->unk8 = D_800DC608[1];
                    s->unk7 = D_800DC604[3];
                    *r |= 0x400;
                    func_80035138(s->unk0, D_800D2838 != D_800DE7A8, D_800DC5F0);
                    s->unk6 = 1;
                }
                break;
            }
            s = s->unkC;
        }
    }
}
