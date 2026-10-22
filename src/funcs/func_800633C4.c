#include "common.h"

typedef struct {
    u8 pad0[0x10];
    u16 unk10;
} Obj800633C4;

typedef struct {
    u8 pad0[0x18];
    s32 *unk18;
    u8 *unk1C;
    u8 pad20[0x48 - 0x20];
} Ent800633C4;

extern Ent800633C4 D_800DAF98[];

void func_800633C4(s32 arg0) {
    Ent800633C4 *base;
    Ent800633C4 *e;
    u8 *p;
    s32 n;
    s32 len;
    u32 cnt;
    Obj800633C4 **r;
    u32 i;
    Obj800633C4 **q;

    base = D_800DAF98;
    e = &base[arg0];
    p = e->unk1C;
    n = e->unk18[-1];
    p += ((s32 *)p)[1];
    while (1) {
        if (*(s32 *)p == -1) {
            break;
        }
        p += 4;
        len = *(s32 *)p;
        p += 4;
        p += len;
    }
    q = (Obj800633C4 **)(p + n * 4 + 8);
    cnt = ((u32 *)q)[-1];
    i = 0;
    if (i < cnt) {
        r = q;
        do {
            (*r)->unk10--;
            i++;
            r++;
        } while (i < cnt);
    }
}
