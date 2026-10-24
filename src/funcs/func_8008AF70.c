#include "common.h"

typedef struct Obj8008AF70 Obj8008AF70;

typedef struct {
    s16 delta;
    s16 idx;
    void (*fn)(void *, s32);
} VEnt8008AF70;

struct Obj8008AF70 {
    u8 pad0[0x1C];
    Obj8008AF70 *next;
    u8 pad20[0x48 - 0x20];
    VEnt8008AF70 *vt;
    u8 pad4C[0x52 - 0x4C];
    u16 flags;
};

extern void func_80068ED4(void);
extern void func_8006A2B0(void);
extern void func_8006EEF0(void);
extern void func_800797CC(void);
extern Obj8008AF70 *D_800D6180;
extern Obj8008AF70 *D_800D6184;
extern Obj8008AF70 *D_800D61A8;
extern Obj8008AF70 *D_800DC5A0;
extern Obj8008AF70 *D_800DDC60;
extern Obj8008AF70 *D_800DE144;
extern Obj8008AF70 *D_800DE7A4;

#define FREE_LIST(head)                                              \
    o = head;                                                        \
    if (o != NULL) {                                                 \
        n = o->next;                                                 \
        while (1) {                                                  \
            if (!(o->flags & 0x20) && o != NULL) {                   \
                o->vt[1].fn((u8 *)o + o->vt[1].delta, 3);            \
            }                                                        \
            if (n == NULL) break;                                    \
            o = n;                                                   \
            n = o->next;                                             \
        }                                                            \
    }

void func_8008AF70(s32 arg0) {
    Obj8008AF70 *o;
    Obj8008AF70 *n;

    FREE_LIST(D_800D61A8);
    FREE_LIST(D_800DE144);
    FREE_LIST(D_800DDC60);
    if (arg0 == 1) {
        FREE_LIST(D_800D6180);
    }
    FREE_LIST(D_800DE7A4);
    FREE_LIST(D_800DC5A0);
    FREE_LIST(D_800D6184);
    D_800D61A8 = NULL;
    D_800DE144 = NULL;
    D_800DDC60 = NULL;
    D_800D6180 = NULL;
    D_800DE7A4 = NULL;
    D_800DC5A0 = NULL;
    D_800D6184 = NULL;
    func_8006A2B0();
    func_80068ED4();
    func_800797CC();
    func_8006EEF0();
}
