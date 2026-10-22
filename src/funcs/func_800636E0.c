#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    s32 *dst;
    u8 pad20[0x48 - 0x20];
} Ent800636E0;

void func_8005EA48(s32 *);
extern Ent800636E0 D_800DAF98[];
extern s32 *D_800DC2E0[];

void func_800636E0(s32 arg0) {
    s32 *dst;
    s32 *src;
    s32 size;
    s32 i;

    dst = D_800DAF98[arg0].dst;
    size = 0x7530;
    src = D_800DC2E0[arg0];
    for (i = 0; i < size / 4; i++) {
        *dst++ = *src++;
    }
    func_8005EA48(D_800DC2E0[arg0]);
    D_800DC2E0[arg0] = 0;
}
