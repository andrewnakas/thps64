/* cflags: -O2 */
#include "common.h"

typedef struct {
    u16 button;
    s8 stick_x;
    s8 stick_y;
    u8 errno;
} ContPad;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[0x1A];
} Unk_800FC580;

void func_800B4094(Unk_800FC580 *, s32, s32, s32);
extern s32 D_800ECFC0;
extern Unk_800FC580 D_800FC580[];
extern ContPad *D_800FC640[];

s32 func_800B411C(s32 arg0, s32 arg1) {
    s32 i;
    ContPad **pp;
    ContPad **b;

    if (D_800ECFC0 == 0 && arg1 == 0) {
        return 1;
    }
    i = 0;
    b = D_800FC640;
    pp = &b[arg0];
    while (1) {
        if (i >= 4) {
            break;
        }
        func_800B4094(&D_800FC580[i], (*pp)[i].stick_x, (*pp)[i].stick_y, (*pp)[i].button);
        D_800FC580[i].unk1 = (*pp)[i].errno != 8;
        i++;
    }
    return 1;
}
