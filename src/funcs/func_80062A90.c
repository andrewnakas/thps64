/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 name[0x15];
    u8 active;
    u8 kind;
    u8 slot;
    u8 unk18;
} Req;

typedef struct Node {
    u8 pad[0x1C];
    struct Node *next;
} Node;

typedef struct {
    u8 name[0x1C];
    u8 *data;
    u8 pad20[0x3C - 0x20];
    u8 unk3C;
    u8 pad3D[0x48 - 0x3D];
} Ent;

void func_800621C4(s32);
void func_80062548(s32, s32, s32);
s32 func_80062F18(s32);
u8 *func_8008486C(void *, Req *, s32);
extern s32 D_800DAD70[];
extern s32 D_800DAD80;
extern s32 D_800DAD84[];
extern Node *D_800DAD8C;
extern s32 D_800DAD90;
extern s32 D_800DAD94;
extern s32 D_800DADA0;
extern Req D_800DADA4[];
extern Ent D_800DAF98[];
extern s32 *D_800DBAD8[];
extern s32 D_800DE318;
extern u8 D_800E8A20[];

static inline s32 which2_(s32 slot, s32 *tt) {
    if (slot == tt[0]) {
        return 0;
    }
    if (slot == tt[1]) {
        return 1;
    }
    return -1;
}

static inline s32 *skip_(u8 *d) {
    s32 *p = (s32 *)(d + ((s32 *)d)[1]);
    s32 n;

    while (1) {
        if (*p == -1) {
            break;
        }
        p++;
        n = *p;
        p++;
        p = (s32 *)((u8 *)p + n);
    }
    return p + 1;
}

void func_80062A90(s32 arg0, s32 arg1, s32 arg2) {
    Req *r;
    u8 *src;
    u8 *dst;
    s32 slot;
    Node *head;
    Node *t;
    s32 k;
    u8 *d;
    Req *tbl;

    tbl = D_800DADA4;
    r = &tbl[D_800DAD94];
    if (r->active == 0) {
        return;
    }
    switch (D_800DADA0) {
    case 0:
        switch (r->kind) {
        case 1:
            if (D_800DAD70[0] != -1 && D_800DAD70[1] != -1) {
                r->slot = D_800DAD70[D_800DAD90];
                func_80062548(r->slot, 0, 0);
                D_800DAD70[D_800DAD90] = r->slot;
            } else if (D_800DAD70[0] == -1) {
                D_800DAD70[0] = r->slot;
            } else {
                D_800DAD70[1] = r->slot;
            }
            src = r->name;
            {
                Ent *e1 = D_800DAF98;
                dst = e1[r->slot].name;
            }
            arg2 = 0;
            while (*src != '.') {
                if (arg2 >= 0x11) {
                    break;
                }
                *dst++ = *src++;
                arg2++;
            }
            *dst = 0;
        case 0:
        case 2:
            D_800DAF98[r->slot].data = func_8008486C(D_800E8A20, r, arg2);
            break;
        }
        D_800DAF98[r->slot].unk3C = r->unk18;
        D_800DADA0 = 1;
        break;
    case 1:
        if (D_800DE318 == 0) {
            D_800DADA0 = 2;
        }
        break;
    case 2:
        switch (r->kind) {
        case 1:
            func_800621C4(r->slot);
            slot = r->slot;
            if (D_800DAD8C == NULL) {
                D_800DAD8C = (Node *)(D_800DAF98[slot].data + 0xC);
            } else {
                d = D_800DAF98[slot].data;
                head = (Node *)(d + 0xC);
                t = head;
                if (((Node *)(d + 0xC))->next != NULL) {
                    do {
                        t = t->next;
                    } while (t->next != NULL);
                }
                t->next = D_800DAD8C;
                D_800DAD8C = head;
            }
            D_800DAD84[func_80062F18(slot)] = D_800DAD80;
            k = which2_(r->slot, D_800DAD70);
            {
                Ent *e2 = D_800DAF98;
                D_800DBAD8[k] = skip_(e2[r->slot].data);
            }
            break;
        case 0:
            func_800621C4(r->slot);
            break;
        case 2:
            break;
        }
        r->active = 0;
        D_800DAD94 = (D_800DAD94 + 1) % 20;
        D_800DADA0 = 0;
        break;
    }
}
