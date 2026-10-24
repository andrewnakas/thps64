/* cflags: -O2 */
#include "common.h"

typedef struct Chan {
    u8 pad0[8];
    struct Chan *unk8;
    u8 padC[0x7C];
    s32 unk88;
} Chan;

typedef struct {
    u8 pad0[8];
    Chan *unk8;
    s32 unkC;
    u8 pad10[4];
    s16 unk14;
    u16 unk16;
    u16 unk18;
    s16 unk1A;
} Note;

typedef struct {
    s16 unk0;
    u16 unk2;
    u8 unk4;
} NoteSrc;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 padA;
    s32 unkC;
    s32 unk10;
} Event;

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Clock;

s32 func_800AE704(Chan **, s32);
Event *func_800B0208(void);
void func_800AED54(Chan *, s32, Event *);
extern Clock *D_800ECC34;

s32 func_800AE5E0(Note *arg0, NoteSrc *arg1) {
    Chan *c;
    Event *e;
    s32 r;

    c = NULL;
    arg0->unk16 = arg1->unk0;
    arg0->unk1A = arg1->unk4;
    arg0->unkC = 0;
    arg0->unk18 = arg1->unk2;
    arg0->unk14 = 0;
    arg0->unk8 = NULL;
    r = func_800AE704(&c, arg1->unk0);
    if (c != NULL) {
        if (r != 0) {
            c->unk88 = 0x200;
            c->unk8->unk8 = NULL;
            c->unk8 = (Chan *)arg0;
            arg0->unk8 = c;
            e = func_800B0208();
            {
            s32 t = D_800ECC34->unk2C;
            e->unk8 = 0xB;
            e->unkC = 0;
            e->unk4 = t;
            e->unk10 = c->unk88 - 0x40;
            }
            func_800AED54(arg0->unk8, 3, e);
            e = func_800B0208();
            if (e != NULL) {
                s32 t = D_800ECC34->unk2C + c->unk88;
                e->unk8 = 0xF;
                e->unk0 = 0;
                e->unk4 = t;
                func_800AED54(arg0->unk8, 3, e);
            }
        } else {
            c->unk88 = 0;
            c->unk8 = (Chan *)arg0;
            arg0->unk8 = c;
        }
    }
    return c != NULL;
}
