/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 unk0;
    u8 pad4[0x34];
} Ent;

extern Ent D_800FBD40[];
extern u8 D_800FC0C0;

Ent *func_8008464C(void) {
    s32 i = 0;
    Ent *best;
    f32 min;

    if (D_800FC0C0 == 0) {
        return NULL;
    }
    min = 1000000.0f;
    best = NULL;
    for (i = 0; i < D_800FC0C0; i++) {
        if (D_800FBD40[i].unk0 < min) {
            min = D_800FBD40[i].unk0;
            best = &D_800FBD40[i];
        }
    }
    return best;
}
