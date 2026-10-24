/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0xC];
    s32 unk24;
} Ent;

typedef struct {
    s32 unk0;
    s32 unk4;
    Ent ents[32];
    s32 unk508;
    s32 unk50C;
    u8 unk510;
} Obj;

void func_8009B620(Obj *, s32, s32, s32, s32);

Obj *func_8009B0A0(Obj *arg0) {
    s32 i;

    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk508 = 0;
    arg0->unk50C = 0;
    arg0->unk510 = 0;
    for (i = 0; i < 32; i++) {
        arg0->ents[i].unk14 = 0;
        arg0->ents[i].unk24 = 0;
    }
    func_8009B620(arg0, 0xE6, 0xE6, 0xFF, 0x64);
    return arg0;
}
