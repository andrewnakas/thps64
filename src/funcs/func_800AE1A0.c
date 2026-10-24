/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 flags;
    s32 unk4;
    u8 pad8[0x2C];
    s32 unk34;
    s32 unk38;
    u8 pad3C[8];
    s32 id;
    u8 pad48[0x2C];
    void *owner;
    u8 pad78[8];
    s32 unk80;
    u8 pad84[4];
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x42];
    u8 unkD2;
    u8 padD3[0x130 - 0xD3];
} Node;

typedef struct {
    u8 pad0[4];
    s32 count;
    u8 pad8[4];
    s32 *a;
    s32 *b;
    s32 *c;
    u8 pad18[0xC];
    s32 unk24;
    s32 init;
} Model;

void func_800ADEBC(void *, Model *, s32);
s32 func_800ADCF0(Model *, s32);
void func_800ADBC4(Node *);
extern s32 D_800FC30C;
extern Node *D_800FC2F8;
extern s32 D_800FC314;

s32 func_800AE1A0(Model *arg0) {
    Model *m = arg0;
    s32 n;
    s32 id;
    s32 i;
    Node *e;
    s32 t;

    n = m->count;
    if (m->init == 0) {
        m->init = 1;
        func_800ADEBC(&m->a, m, 7);
        func_800ADEBC(m->a, m, n);
        func_800ADEBC(m->b, m, n);
        func_800ADEBC(m->c, m, n);
    }
    id = D_800FC30C++;
    e = &D_800FC2F8[func_800ADCF0(m, -1)];
    func_800ADBC4(e);
    e->unkD2 = 1;
    e->owner = m;
    e->flags |= 3;
    t = m->unk24;
    e->id = id;
    e->unk4 = e->unk80 = t;
    for (i = 0; i < n; i++) {
        if (m->a[i] != 0) {
            e = &D_800FC2F8[func_800ADCF0(m, i)];
            func_800ADBC4(e);
            e->unkD2 = 1;
            e->owner = m;
            e->flags |= 1;
            e->unk38 = e->unk8C = m->b[i];
            e->unk34 = e->unk88 = m->c[i];
            t = m->a[i];
            e->id = id;
            e->unk4 = e->unk80 = t;
        }
    }
    D_800FC314 = 0;
    return id;
}
