/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VEnt;

typedef struct {
    u8 pad[0x38];
    VEnt e7;
} VTbl;

typedef struct {
    u8 pad0[0x4];
    s32 state;
    u8 pad8[0x428 - 0x8];
    s32 unk428;
    u8 pad42C[0x434 - 0x42C];
    s32 len;
    u8 pad438[0x444 - 0x438];
    s32 unk444;
    s32 unk448;
    s32 unk44C;
    u8 pad450[0x4F8 - 0x450];
    VTbl *vt;
} Conn;

extern void func_800A3750(Conn *, char *, s32, s32, s32, s32 *, s32);
extern char D_80020C90[];
extern s32 D_800EA550;

void func_800A0F30(Conn *o) {
    o->state = 0x29;
    o->unk444 = o->unk44C = o->unk428;
    o->unk448 = D_800EA550;
    o->vt->e7.fn((u8 *)o + o->vt->e7.off);
    func_800A3750(o, D_80020C90, o->len, 3, 1, &o->unk444, 0);
}
