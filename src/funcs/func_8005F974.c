/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct VEnt8005F974 {
    s16 off0;
    s16 pad2;
    void *fn4;
} VEnt8005F974;

typedef struct Obj8005F974 {
    u16 flags;
    u8 pad2[0x1A];
    struct Obj8005F974 *next;
    u8 pad20[0x28];
    u8 *vtbl;
    u8 pad4C[0x112];
    u16 id;
    u8 pad160[2];
    s16 unk162;
    u8 pad164[0x135];
    u8 unk299;
    u8 pad29A[0xA];
    s32 unk2A4;
} Obj8005F974;

typedef struct Trig8005F974 {
    u8 pad0[4];
    struct Trig8005F974 *next;
    u8 pad8[2];
    u16 id;
    u8 padC[0x37];
    u8 type;
} Trig8005F974;

typedef struct Ent8005F974 {
    u8 pad0[8];
    u32 *p8;
    u8 padC[0x33];
    u8 unk3F;
} Ent8005F974;

extern "C" void func_80025430(void *, Ent8005F974 *);
extern "C" Ent8005F974 *func_80035250(s32);
extern "C" void func_8005F634(s32);
extern "C" u16 *func_80061904(s32);
extern "C" u16 *func_800635E4(s32);
extern "C" void func_80063830(Obj8005F974 *, s32, s32);
extern "C" void func_8007E5E4(Trig8005F974 *);
extern "C" void *func_8009E30C(s32);
extern Obj8005F974 *D_800D6180;
extern s32 D_800D6188;
extern s32 D_800D61A0;
extern s16 **D_800DACB0;
extern Obj8005F974 *D_800DDC60;
extern Trig8005F974 *D_800DE5AC;

static inline void notify8005F974(Obj8005F974 *q, s32 id, s32 mode) {
    for (; q != NULL; q = q->next) {
        if (q->id == id) {
            switch (mode) {
            case 0:
                ((void (*)(void *))((VEnt8005F974 *)(q->vtbl + 0x10))->fn4)((u8 *)q + ((VEnt8005F974 *)(q->vtbl + 0x10))->off0);
                break;
            case 1:
                ((void (*)(void *, s32, s32 *, s32))((VEnt8005F974 *)(q->vtbl + 0x30))->fn4)((u8 *)q + ((VEnt8005F974 *)(q->vtbl + 0x30))->off0, q->unk162, &D_800D6188, 0);
                break;
            }
        }
    }
}

static inline void activate8005F974(Obj8005F974 *o) {
    u16 *list;
    u16 *sub;
    u16 n;
    s32 j;

    list = func_80061904(o->id);
    sub = list + 1;
    n = *list;
    for (j = 0; j < n; j++, sub++) {
        func_8005F634(*sub);
    }
    o->unk299 = 1;
    func_80063830(o, D_800D61A0, D_800D61A0 + 0x84);
}

extern "C" void func_8005F974(s32 arg0, s32 arg1) {
    u16 count;
    s32 i;
    u16 *list;
    u16 id;
    s32 n;
    s16 *s;
    s32 found;
    Obj8005F974 *p;
    Trig8005F974 *tr;
    s32 v;
    u16 *r;
    Ent8005F974 *e;

    list = func_80061904(arg0);
    count = *list++;
    i = 0;
    while (1) {
        if (i >= count) {
            break;
        }
        id = *list++;
        n = id;
        s = D_800DACB0[n];
        found = 0;
        switch (*s) {
        case 1:
            {
                Obj8005F974 *o;
                s32 tid;

                p = D_800D6180;
                tid = n;
                while (1) {
                    if (p == NULL) {
                        break;
                    }
                    if (p->id == tid && (p->flags & 0x100)) {
                        o = p;
                        if (o->unk2A4 & 0x10) {
                            p->flags |= 0x20;
                            if (!(p->unk2A4 & 0x20)) {
                                activate8005F974(o);
                                found = 1;
                            }
                        }
                    }
                    p = p->next;
                }
            }
            if (found) {
                break;
            }
            notify8005F974(D_800DDC60, id, arg1);
            notify8005F974(D_800D6180, id, arg1);
            break;
        case 2:
        case 9:
            s++;
            s = (s16 *)((u8 *)s + (*s * 2 + 2));
            if ((s32)s & 2) {
                s++;
            }
            v = *(s32 *)s;
            r = func_800635E4(v);
            e = func_80035250(v);
            if (r != NULL) {
                if (arg1 == 1) {
                    if (e != NULL && (*e->p8 & 2) && e->unk3F == 0) {
                        func_80025430(func_8009E30C(0xB98), e);
                        e->unk3F = arg1;
                    }
                } else {
                    *r |= 0x41;
                }
            }
            break;
        case 0x1F4:
        case 0x1F5:
            for (tr = D_800DE5AC; tr != NULL; tr = tr->next) {
                if (tr->type == 2 && tr->id == id) {
                    func_8007E5E4(tr);
                    break;
                }
            }
            break;
        case 10:
        case 11:
        case 12:
        case 14:
            break;
        }
        i++;
    }
}
