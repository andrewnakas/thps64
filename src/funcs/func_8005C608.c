#include "common.h"

extern void func_800B36D8(s32, f32, f32);
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE7A0;
extern s32 D_800DE9C4;
typedef struct {
    u8 pad[0x988];
    s32 val;
} Slot;

extern s32 D_800DE9F4[];

void func_8005C608(void *arg0, f32 arg1, f32 arg2) {
    s32 i;

    i = *(s32 *)((u8 *)arg0 + 0x968);
    if (D_800DE7A0 == 7) {
        i ^= D_800DE9C4;
    }
    if (((Slot *)&D_800DE9F4[i])->val != 0 && D_800DC618 != 2 && D_800DC6D8 != 2) {
        func_800B36D8(i, arg1, arg2);
    }
}
