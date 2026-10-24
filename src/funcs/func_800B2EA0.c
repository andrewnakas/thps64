/* cflags: -O2 */
#include "common.h"

typedef struct Node_800B2EA0 {
    s32 key;
    s32 data;
    struct Node_800B2EA0 *prev;
    struct Node_800B2EA0 *next;
} Node_800B2EA0;

typedef struct {
    s32 unk0;
    s32 unk4;
    Node_800B2EA0 *head;
    Node_800B2EA0 *tail;
} List_800B2EA0;

typedef struct {
    s32 *count;
    s32 base;
} Tbl_800B2EA0;

typedef struct {
    u8 pad0[8];
    s32 unk8;
    Tbl_800B2EA0 tbl;
    u8 pad14[4];
    List_800B2EA0 list;
    s32 unk28;
} Cache_800B2EA0;

void func_80000B08(s32, s32, s32);
void func_800A0270(List_800B2EA0 *, Node_800B2EA0 *);
void func_800A03C8(List_800B2EA0 *, Node_800B2EA0 *);
s32 func_800B310C(Tbl_800B2EA0 *, s32);
void func_800BAFDC(s32 *, s32, s32, s32, s32);
void func_800BB0D8(s32 *, s32, s32, s32, s32 *, s32, s32);
extern List_800B2EA0 D_800ECF40;
extern s32 D_800ECF50;
extern s32 D_800ECF78;
extern s32 D_800ECF7C;
extern s32 D_800ECF80;
extern s32 D_800ECF84;
extern s32 D_800ECFA0;
extern s32 D_800ECFA4;
extern s32 D_800EED10;

Node_800B2EA0 *func_800B2EA0(Cache_800B2EA0 *c, u32 pos, s32 sync, s32 prefetch) {
    List_800B2EA0 *l;
    s32 buf;
    s32 idx;
    s32 key;
    s32 size;
    s32 asz;
    Node_800B2EA0 *head;
    Node_800B2EA0 *n;
    Tbl_800B2EA0 *t;
    Node_800B2EA0 *m;

    if (c->unk28 != 0) {
        l = &D_800ECF40;
        buf = D_800ECF50;
    } else {
        l = &c->list;
        buf = c->unk8;
    }
    idx = pos >> 14;
    t = &c->tbl;
    if (idx < *c->tbl.count) {
        key = t->base + func_800B310C(t, idx);
        head = l->head;
        for (n = head; n != NULL; n = n->next) {
            if (n->key == key) {
                if (n != head) {
                    func_800A03C8(l, n);
                    func_800A0270(l, n);
                }
                return n;
            }
        }
        size = func_800B310C(&c->tbl, idx + 1) - func_800B310C(&c->tbl, idx);
        asz = (size + 1) & ~1;
        m = l->tail;
        if (m != head) {
            func_800A03C8(l, m);
            func_800A0270(l, m);
        }
        m->key = key;
        if (sync != 0) {
            D_800ECFA0 = size;
            D_800ECF80 = 1;
            D_800ECFA4 = m->data;
            func_800BB0D8(&D_800EED10, key, asz, D_800ECF7C, &D_800ECF84, 0, 0);
        } else {
            func_800BAFDC(&D_800EED10, key, asz, buf, 0);
            if (prefetch != 0 && D_800ECF80 == 0 && c->unk28 != 0 && D_800ECF78 >= 2) {
                func_800B2EA0(c, pos + 0x4000, 1, 0);
            }
            func_80000B08(buf, m->data, size);
        }
        return m;
    }
    return NULL;
}
