/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 padC[0x8C - 0xC];
} Voice;

typedef struct Upd {
    struct Upd *next;
    u8 pad4[0x1C - 4];
} Upd;

typedef struct {
    u8 pad0[0x14];
    s32 count;
    s32 max;
    Voice **list;
    void *unk20;
    u8 pad24[0x44 - 0x24];
} VList;

typedef struct {
    u8 pad0[4];
    void *handler;
    u8 pad8[0x14 - 8];
} Node14;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 l10[2];
    s32 l18[2];
    s32 l20[2];
    s64 t28;
    s64 t30;
    s32 unk38;
    void *heap;
    Upd *free;
    Node14 *node;
    VList *vl;
    s32 unk4C;
    u8 pad50[4];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
} Drv;

typedef struct {
    u8 pad0[4];
    s32 maxVoices;
    s32 maxUpdates;
    u8 padC[4];
    s32 unk10;
    void *heap;
    s32 unk18;
    u8 unk1C;
} Cfg;

void *func_80010480(s32, s32, void *, s32, s32);
void *func_800B1660(s32, Cfg *, void *);
void func_8000CB30(Voice *, void *);
void func_800B0A88(Voice *, s32, void *);
s32 func_800B0BC0();
s32 func_800B0600();
extern Drv *D_800ECC34;

void func_800AFD80(Cfg *c) {
    s32 i;
    Voice *pv;
    Voice *pvoices;
    void *hp = c->heap;
    Upd *params;
    Upd *paramPtr;

    D_800ECC34->unk0 = 0;
    D_800ECC34->unk4 = 0;
    D_800ECC34->unk8 = 0;
    D_800ECC34->unkC = 0;
    D_800ECC34->unk4C = c->maxVoices;
    D_800ECC34->t30 = 0;
    D_800ECC34->t28 = 0;
    D_800ECC34->unk54 = c->unk18;
    D_800ECC34->unk58 = 0xB8;
    D_800ECC34->unk38 = c->unk10;
    D_800ECC34->unk5C = 0;
    D_800ECC34->unk60 = 1;

    D_800ECC34->vl = func_80010480(0, 0, hp, 1, 0x44);
    D_800ECC34->vl->count = 0;
    D_800ECC34->vl->max = c->maxVoices;
    D_800ECC34->vl->list = func_80010480(0, 0, hp, c->maxVoices, 4);

    D_800ECC34->node = func_80010480(0, 0, hp, 1, 0x14);

    if (c->unk1C != 0) {
        D_800ECC34->vl->unk20 = func_800B1660(0, c, hp);
        D_800ECC34->node->handler = func_800B0BC0;
    } else {
        D_800ECC34->node->handler = func_800B0600;
    }

    D_800ECC34->l10[0] = 0;
    D_800ECC34->l10[1] = 0;
    D_800ECC34->l20[0] = 0;
    D_800ECC34->l20[1] = 0;
    D_800ECC34->l18[0] = 0;
    D_800ECC34->l18[1] = 0;

    pvoices = func_80010480(0, 0, hp, c->maxVoices, 0x8C);
    for (i = 0; i < c->maxVoices; i++) {
        pv = &pvoices[i];
        func_8000CB30(pv, D_800ECC34->l10);
        pv->unk8 = 0;
        func_800B0A88(pv, D_800ECC34->unk38, hp);
        D_800ECC34->vl->list[D_800ECC34->vl->count++] = pv;
    }

    params = func_80010480(0, 0, hp, c->maxUpdates, 0x1C);
    D_800ECC34->free = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr = &params[i];
        paramPtr->next = D_800ECC34->free;
        D_800ECC34->free = paramPtr;
    }
    D_800ECC34->heap = hp;
}
