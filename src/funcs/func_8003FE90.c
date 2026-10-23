#include "common.h"

typedef struct {
    u8 v;
    u8 pad[31];
} Sub;

typedef struct {
    u8 pad[0x5C];
    Sub s[7];
    u8 pad2[0x154 - 0x5C - 0xE0];
} Ent;

extern Ent D_800D4D80[];

s32 func_8003FE90(u8 a, u8 b) {
    s32 r;
    s32 i;

    r = 0;
    for (i = 0; i < 8; i++) {
        if (b < D_800D4D80[a].s[i].v) {
            break;
        }
        r = i;
    }
    return r;
}
