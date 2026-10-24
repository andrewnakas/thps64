/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x38];
    u16 unk38;
    u16 unk3A;
    u8 pad3C[0x2A];
    u16 unk66;
} Res;

typedef struct {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[0xE];
    s16 unk28;
    s16 unk2A;
    u8 pad2C[0xE];
    s16 unk3A;
} Out;

typedef struct {
    Res *res;
    u8 pad4[0xC];
    Out *out;
} Obj;

typedef struct {
    s32 unk0;
    Res *res;
} Ent;

extern Ent *func_800BAB04(u8 *, s32);
extern void func_800BAC04(u8 *, s32);
extern u8 D_800EECF0[];

void func_8009BB40(Obj *arg0, s32 arg1) {
    if (arg0->res != NULL) {
        if (arg1 == arg0->res->unk66) {
            return;
        }
        func_800BAC04(D_800EECF0, arg0->res->unk66);
        arg0->res = NULL;
    }
    if (arg1 >= 0) {
        arg0->res = func_800BAB04(D_800EECF0, arg1)->res;
        arg0->out->unk18 = arg0->out->unk28 = arg0->res->unk38 << 5;
        arg0->out->unk2A = arg0->out->unk3A = arg0->res->unk3A << 5;
    }

}
