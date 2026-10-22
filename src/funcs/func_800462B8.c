#include "common.h"

typedef struct {
    u8 pad[0xEE4];
    s32 flags[5];
} St800462B8;

void func_80045870(s32);
extern s32 D_800D60E4;
extern St800462B8 *D_800D61A8;

s32 func_800462B8(u32 arg0) {
    St800462B8 *p;

    D_800D60E4 = 0x28;
    if (arg0 < 5) {
        D_800D61A8->flags[arg0] = 1;
    }
    p = D_800D61A8;
    if (p->flags[0] == 1 && p->flags[1] == p->flags[0] && p->flags[2] == p->flags[1] &&
        p->flags[3] == p->flags[2] && p->flags[4] == p->flags[3]) {
        func_80045870(2);
        return 1;
    }
    return 0;
}
