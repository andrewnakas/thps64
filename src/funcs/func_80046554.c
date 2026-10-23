#include "common.h"

typedef struct {
    u32 next : 24;
    u32 lo : 8;
} Link46554;

typedef struct {
    u8 pad0[0x84];
    Link46554 link;
} Obj46554;

extern Obj46554 *D_800D0F9C;
extern s32 D_800D6104;

void func_80046554(Link46554 *arg0) {
    arg0->next = D_800D0F9C->link.next;
    D_800D0F9C->link.next = (u32) arg0;
    D_800D6104 = 1;
}
