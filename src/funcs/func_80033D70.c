#include "common.h"

typedef struct {
    s32 unk0;
    s32 *unk4;
} Item;

typedef struct {
    u8 pad0[0xC];
    Item **unkC;
    s32 unk10;
} List;

typedef struct {
    s32 unk0;
    Item *unk4;
} Slot;

void func_80033BD4(void);
void func_80037C84(List *);
void func_80037DC8(List *, s32);
void func_80084724(List *);
void func_800BC0F4(void *);
extern s32 D_800D36D4;
extern s32 D_800D36F0;
extern u8 D_800F0DD0[];
extern List D_800FA350;
extern Slot D_800FA3D0[];

void func_80033D70(s32 arg0) {
    List *l;
    List *p;
    s32 i;
    Item *it;
    Slot *s;
    s32 none;
    s32 cur;

    func_800BC0F4(D_800F0DD0);
    cur = D_800D36D4;
    none = -1;
    if (cur != none) {
        func_80037C84(&D_800FA350);
    }
    if (arg0 == none) {
        l = NULL;
    } else {
        p = &D_800FA350;
        func_80037DC8(p, arg0);
        l = p;
    }
    func_80084724(l);
    i = 0;
    while (1) {
        if (i >= D_800FA350.unk10) break;
        it = D_800FA350.unkC[i];
        if ((*it->unk4 & 0x20200000) == 0x20200000) {
            if (D_800D36F0 < 0x30) {
                s = &D_800FA3D0[D_800D36F0++];
                s->unk4 = it;
                s->unk0 = 0;
            }
        }
        i++;
    }
    D_800D36D4 = arg0;
    func_80033BD4();
}
