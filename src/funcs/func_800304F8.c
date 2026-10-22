#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    s32 name;
    u8 pad30[0x154 - 0x30];
} Ent800304F8;

void func_800057E4(void *, void *, s32);
extern s32 D_800199F0;
extern Ent800304F8 D_800D4D80[];

void func_800304F8(u8 *arg0) {
    u16 y;
    s32 *fmt;

    if (*(s16 *)(arg0 + 0x780) == 130 && *(s32 *)(arg0 + 0x784) == 2) {
        *(s32 *)(arg0 + 0x784) = 0;
        return;
    }
    y = *(s16 *)(arg0 + 0x780);
    if (*(s16 *)(arg0 + 0x780) < -40) {
        if (*(s32 *)(arg0 + 0x784) == 1) {
            fmt = &D_800199F0;
            func_800057E4(arg0 + 0x740, fmt, D_800D4D80[*(s32 *)(arg0 + 0x78C)].name);
            *(s32 *)(arg0 + 0x784) = 2;
            return;
        }
    } else if (*(s32 *)(arg0 + 0x784) == 1) {
        *(s16 *)(arg0 + 0x780) = y - 40;
        return;
    }
    if (*(s32 *)(arg0 + 0x784) == 2) {
        *(s16 *)(arg0 + 0x780) += 40;
    }
}
