#include "common.h"

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32);
} VDtor8004ACF0;

typedef struct {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *, void *);
} VUpd8004ACF0;

typedef struct {
    u8 pad0[8];
    VDtor8004ACF0 dtor;
    u8 pad10[0x18 - 0x10];
    VUpd8004ACF0 update;
} VTbl8004ACF0;

typedef struct Obj8004ACF0 {
    u8 pad0[0x1C];
    struct Obj8004ACF0 *next;
    u8 pad20[0x48 - 0x20];
    VTbl8004ACF0 *vt;
    u8 pad4C[0x52 - 0x4C];
    u16 flags;
} Obj8004ACF0;

void func_8004ACF0(Obj8004ACF0 **arg0) {
    Obj8004ACF0 *o;
    Obj8004ACF0 *next;
    u16 flags;

    o = *arg0;
    if (o == NULL) {
        return;
    }
    next = o->next;
    while (1) {
        flags = o->flags;
        if (flags & 0x40) {
            if (flags & 0x80) {
                if (o != NULL) {
                    o->vt->dtor.fn((u8 *)o + o->vt->dtor.delta, 3);
                }
            } else {
                o->flags = flags | 0x80;
            }
        } else {
            o->vt->update.fn((u8 *)o + o->vt->update.delta, o);
        }
        o = next;
        if (o == NULL) {
            break;
        }
        next = next->next;
    }
}
