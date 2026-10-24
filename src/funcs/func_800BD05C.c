/* cflags: -O2 */
#include "common.h"

typedef struct {
    void **items;
    s32 tail;
    s32 unk8;
    s32 head;
    s32 unk10;
    s32 count;
    s32 size;
} Q_800BD05C;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Ev_800BD05C;

typedef struct {
    u8 pad0[8];
    s32 unk8;
} Lnk_800BD05C;

typedef struct {
    u8 pad0[0x40];
    s64 unk40;
    u8 pad48[8];
    s64 unk50;
    s64 unk58;
    u8 pad60[0x68 - 0x60];
    s64 unk68;
    u8 pad70[0x80 - 0x70];
    s32 unk80;
    u8 pad84[0x90 - 0x84];
    Lnk_800BD05C *unk90;
} Obj_800BD05C;

typedef struct {
    u8 pad0[0x1EC];
    Q_800BD05C q1EC;
    Q_800BD05C q208;
    Q_800BD05C q224;
    Q_800BD05C q240;
    s32 unk25C;
    Obj_800BD05C *unk260;
    Obj_800BD05C *unk264;
    Obj_800BD05C *unk268;
    s32 unk26C;
    u8 pad270[0x22AC - 0x270];
    Ev_800BD05C *unk22AC;
    u8 pad22B0[4];
    s32 unk22B4;
    u8 pad22B8[0x22D4 - 0x22B8];
    s32 unk22D4;
    u8 pad22D8[0x2314 - 0x22D8];
    s32 unk2314;
} Mgr_800BD05C;

void func_80003010(s32);
void func_80005070(s32, s32, s32);
void func_8000CAD0(void);
void func_80011680(f32);
void func_800116E0(s32);
void func_800BC8B8(Mgr_800BD05C *);
void func_800BCFF0(Mgr_800BD05C *, Obj_800BD05C *);
void func_800BD030(void);
s64 func_800BD540(void);
void func_800BD6F4(Q_800BD05C *);
extern s32 D_800F56BC;

static inline s32 qidx(Q_800BD05C *q) {
    s32 h = q->head;

    if (h >= q->tail) {
        q->tail = h - 1;
    }
    return h * 4;
}

void func_800BD05C(Mgr_800BD05C *m) {
    Q_800BD05C *q;
    Q_800BD05C *qa;
    Q_800BD05C *p;
    Q_800BD05C *qb;
    Obj_800BD05C *o;
    Obj_800BD05C *it;
    Lnk_800BD05C *l;
    Ev_800BD05C *ev;
    s32 force;
    s32 diff;
    void *x;
    s64 t;

    force = 0;
    if (m->unk264 != NULL) {
        if (m->q1EC.count != 0 && m->unk264->unk80 == 0 && m->unk25C == 0) {
            func_800BD030();
        }
    } else {
        q = &m->q1EC;
        o = NULL;
        if (q->count != 0) {
            o = *(void **)((u8 *)m->q1EC.items + qidx(q));
            goto found;
        }
        q = &m->q208;
        if (m->unk260 != NULL) {
            o = m->unk260;
            force = 1;
            m->unk260 = NULL;
            o->unk50 = func_800BD540();
        } else if (q->count != 0 && m->unk268 == NULL) {
            it = *(void **)((u8 *)m->q208.items + qidx(q));
            l = it->unk90;
            if (l->unk8 == 0) {
                o = it;
                l->unk8 = 1;
            found:
                func_800BD6F4(q);
                func_8000CAD0();
                o->unk58 = 0;
                t = func_800BD540();
                o->unk50 = t;
                o->unk40 = t;
            }
        }
        if (o != NULL && (m->unk2314 == 0 || force != 0)) {
            func_800BCFF0(m, o);
        }
    }
    q = &m->q240;
    if (m->unk268 == NULL) {
        qa = &m->q224;
        if (qa->count != 0) {
            qb = &m->q208;
            diff = 0;
            if (qb->count != 0) {
                x = *(void **)((u8 *)m->q224.items + qidx(qa));
                if (x != *(void **)((u8 *)m->q208.items + qidx(qb))) {
                    diff = 1;
                }
            } else {
                diff = 1;
            }
            if (diff != 0) {
                m->unk268 = *(void **)((u8 *)m->q224.items + qidx(&m->q224));
                func_800BD6F4(&m->q224);
                m->unk268->unk68 = func_800BD540();
            }
            q = &m->q240;
        }
    }
    if (q->count != 0) {
        ev = *(void **)((u8 *)m->q240.items + qidx(q));
        if (m->unk22B4 >= ev->unk4 && m->unk22AC == NULL) {
            func_800116E0(ev->unk0);
            if (m->unk22D4 != 0) {
                func_80003010(0);
                m->unk22D4 = 0;
                if (D_800F56BC == 0 && m->unk2314 == 0) {
                    func_80011680(0.833f);
                }
            }
            p = &m->q240;
            m->unk22AC = ev;
            ev->unk8 = 3;
            func_800BD6F4(p);
            if (p->count < 2 && m->unk26C != 0) {
                func_80005070(m->unk26C, 1, 0);
                m->unk26C = 0;
            }
        }
    }
    func_800BC8B8(m);
}
