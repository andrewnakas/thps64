/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
} Msg;

typedef struct {
    u8 pad0[0x88];
    s32 unk88;
} Target;

typedef struct {
    u8 pad0[8];
    Target *unk8;
} Obj;

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Clock;

void func_800AED54(Target *, s32, Msg *);
Msg *func_800B0208(void);
extern Clock *D_800ECC34;

void func_800AFD10(Obj *arg0) {
    Msg *m;

    if (arg0->unk8 != NULL) {
        m = func_800B0208();
        if (m != NULL) {
            s32 t = D_800ECC34->unk2C + arg0->unk8->unk88;
            m->unk8 = 0xF;
            m->unk0 = 0;
            m->unk4 = t;
            func_800AED54(arg0->unk8, 3, m);
        }
    }
}
