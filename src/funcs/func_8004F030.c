#include "common.h"

typedef struct {
    s32 unk0[3];
    s32 unkC;
    s32 unk10;
    s32 unk14[2];
    s32 unk1C;
    s32 unk20[3];
} Entry;

typedef struct {
    u8 pad0[0x21E];
    u16 unk21E;
    u8 pad220[0x45C - 0x220];
    s32 unk45C;
    s32 unk460;
    u8 pad464[0x51C - 0x464];
    s32 unk51C;
} Obj;

void func_80039E60(s32, s32, s32);
void func_8004CACC(Obj *, s32, s32, s32, s32);
extern Entry D_800D63F8[];

void func_8004F030(Obj *arg0) {
    s32 flags;
    s32 id;
    Entry *e;
    Entry *e2;
    s32 t;
    Entry *tbl;

    if (arg0->unk45C == 0) {
        if ((u32)(arg0->unk21E - 0x3E) < 5U) {
            func_80039E60(0xA2, 0x2710, 0);
        }
        flags = arg0->unk460;
        id = flags & 0xFF;
        if (flags & 0x4000) {
            tbl = D_800D63F8;
            e = &tbl[id];
            t = e->unk1C;
            arg0->unk51C++;
            func_8004CACC(arg0, id, e->unkC, t, 0);
            arg0->unk460 |= 0x800;
        } else if (flags & 0x2000) {
            tbl = D_800D63F8;
            e2 = &tbl[id];
            t = e2->unk1C;
            arg0->unk51C++;
            func_8004CACC(arg0, id, e2->unkC, t, 0);
            if (e2->unk10 != 0) {
                arg0->unk460 |= 0x800;
            }
        }
    }
}
