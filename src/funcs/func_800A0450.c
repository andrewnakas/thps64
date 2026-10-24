/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x1AC];
    u8 unk1AC[0x240];
    u8 unk3EC[0x18];
    u8 unk404[0x3C];
    s32 unk440;
    u8 pad444[0x1C];
    s32 unk460;
    u8 pad464[0x8];
    s32 unk46C;
    s32 unk470;
    u8 pad474[0x40];
    s32 unk4B4;
    u8 pad4B8[0x28];
    u16 unk4E0;
    u8 pad4E2[0x2];
    s32 unk4E4;
    u8 pad4E8[0x4];
    s32 unk4EC;
    u8 pad4F0[0x8];
    void *unk4F8;
} Obj800A0450;

extern void func_80001EC0(void *, void *, s32);
/* declared value-returning (v0-copy of arg0 before the tail stores, as in the game) */
extern Obj800A0450 *func_800A04D8(Obj800A0450 *, s32);
extern void func_800A72C0(void *);
extern u8 D_800216F8[];
extern s32 D_800EA550;

static __inline__ Obj800A0450 *reset800A0450(Obj800A0450 *o) {
    D_800EA550 = 0;
    o->unk4E4 = -1;
    o->unk4E0 = 0xFFFF;
    o->unk4B4 = 0;
    o->unk4EC = 0;
    o->unk46C = 0;
    o->unk470 = 0;
    o->unk440 = 0;
    o->unk460 = 1;
    return o;
}

Obj800A0450 *func_800A0450(Obj800A0450 *arg0) {
    arg0->unk4F8 = D_800216F8;
    func_800A72C0(arg0->unk1AC);
    func_80001EC0(arg0->unk3EC, arg0->unk404, 1);
    func_800A04D8(arg0, -1);
    return reset800A0450(arg0);
}
