#include "common.h"

typedef struct {
    u8 pad0[0x40];
    u8 *unk40;
    u8 pad44[0x154 - 0x44];
} Unk80046228;

extern s32 D_8001B1A0[];
extern s32 D_8001B268[];
extern Unk80046228 D_800D4D80[];

s32 *func_80046228(void *arg0) {
    s32 flag;
    s32 r;
    u8 c;

    flag = ((*(u32 *)((u8 *)arg0 + 0x208)) >> 1) & 1;
    r = 0;
    c = *D_800D4D80[*(s32 *)((u8 *)arg0 + 0x3E0)].unk40;
    if (c == 0x52 || c == 0x72) {
        r = 1;
    }
    if (flag != r) {
        return D_8001B268;
    }
    return D_8001B1A0;
}
