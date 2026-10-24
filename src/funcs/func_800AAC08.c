/* cflags: -O2 -Wa,-no-m4100 */
/* -O2 -Wa,-no-m4100: C matches; only gas hazard nops differ (game: nop before mult after mflo but none before the following branch) */
#include "common.h"

typedef struct {
    u8 pad0[0x74];
    s32 owner;
    u8 pad78[0x24];
    s16 vol;
    u8 pad9E[0xA];
    s16 vel;
    u8 padAA[0x86];
} Voice800AAC08;

extern s32 D_800FC2F0;
extern Voice800AAC08 *D_800FC2F8;
extern s32 D_800FC300;

u8 *func_800AAC08(u8 *arg0, u8 *p) {
    s32 vel;
    s32 vol;
    s32 i;
    Voice800AAC08 *v;

    vel = (*p * 0x6000 / 120) / D_800FC300;
    vol = (vel * *(s16 *)(arg0 + 0x98)) >> 7;
    p++;
    if (*(s32 *)(arg0 + 0x78) != 0) {
        *(s16 *)(arg0 + 0x9C) = vel;
    } else {
        v = D_800FC2F8;
        for (i = 0; i < D_800FC2F0; i++, v++) {
            if (v->owner == *(s32 *)(arg0 + 0x74)) {
                v->vel = vel;
                v->vol = vol;
            }
        }
    }
    return p;
}
