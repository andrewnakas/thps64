#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x70];
} Ent80041C14;

typedef struct {
    u8 pad0[0x280];
    u16 unk280[0x18];
    s16 unk2B0;
    s16 unk2B2;
    u8 unk2B4;
    u8 unk2B5;
    u8 pad2B6;
    char unk2B7[1];
} Obj80041C14;

extern void func_800057E4(char *, char *, ...);
extern char D_8001A460[];
extern char D_8001A5E4[];
extern s32 D_800C0E20;
extern Ent80041C14 D_800D5C1C[];
extern s32 D_800D5FEC;

void func_80041C14(Obj80041C14 *o) {
    u16 t;
    char *q;
    Ent80041C14 *tbl;

    if (o->unk2B0 >= 0x5B && o->unk2B4 == 2) {
        o->unk2B0 = o->unk280[D_800C0E20 * 2];
        o->unk2B4 = 0;
        return;
    }
    t = o->unk2B0;
    if (o->unk2B0 < 0) {
        if (o->unk2B4 == 1) {
            if (D_800C0E20 == 8 && D_800D5FEC != 0) {
                q = D_8001A5E4;
                func_800057E4(o->unk2B7, q);
            } else {
                q = D_8001A460;
                tbl = D_800D5C1C;
                func_800057E4(o->unk2B7, q, tbl[D_800C0E20].unk0);
            }
            o->unk2B4 = 2;
            return;
        }
    } else if (o->unk2B4 == 1) {
        o->unk2B0 = t - 0x5A;
        return;
    }
    if (o->unk2B4 == 2) {
        o->unk2B0 += 0x5A;
    }
}
