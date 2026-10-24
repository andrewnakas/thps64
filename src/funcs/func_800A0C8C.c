/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x20];
    s32 unk20;
    u8 pad24[4];
} Ent;

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x408 - 0x1C];
    s32 unk408[11];
    s32 unk434;
    u8 pad438[0x4B4 - 0x438];
    Ent *unk4B4;
} Obj;

void func_800A0C8C(Obj *arg0) {
    s32 id;
    s32 i;

    arg0->unk18 = -1;
    if (arg0->unk434 == -1) {
        return;
    }
    id = arg0->unk408[arg0->unk434];
    if (id == -1) {
        return;
    }
    for (i = 0; i < arg0->unk14; i++) {
        if (arg0->unk4B4[i].unk20 == id) {
            arg0->unk18 = i;
            return;
        }
    }
}
