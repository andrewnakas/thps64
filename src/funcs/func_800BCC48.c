/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x48];
    u64 t48;
    u64 t50;
    u64 t58;
    u64 t60;
    u8 pad68[0x18];
    s32 unk80;
    s32 pad84;
    s32 unk88;
} Req_800BCC48;

typedef struct {
    u8 pad0[0x254];
    s32 unk254;
    s32 pad258;
    s32 unk25C;
    s32 unk260;
    Req_800BCC48 *req;
    s32 pad268;
    s32 unk26C;
    u8 pad270[0x22DC - 0x270];
    s32 unk22DC;
    u8 pad22E0[8];
    u64 t22E8;
    u64 t22F0;
    u8 pad22F8[0x2314 - 0x22F8];
    s32 unk2314;
} Obj_800BCC48;

void func_80005070(s32, s32, s32);
s32 func_80011030(s32);
void func_800BCDEC(Obj_800BCC48 *);
void func_800BD05C(Obj_800BCC48 *);
u64 func_800BD540(void);

void func_800BCC48(Obj_800BCC48 *o) {
    s32 ok;
    u64 now;

    if (o->req == NULL) {
        return;
    }
    ok = 1;
    now = func_800BD540();
    o->req->t58 += now - o->req->t50;
    if (o->unk25C != 0) {
        if (func_80011030(o->unk25C) != 0) {
            ok = 0;
            o->unk260 = o->unk25C;
        }
        o->unk25C = 0;
    }
    if (ok) {
        o->req->t48 = now;
        o->req->t60 = o->req->t58;
        {
            Req_800BCC48 *r = o->req;
            u64 t = r->t60;
            if (r->unk80 != 0) {
                o->t22E8 = t;
            } else {
                o->t22F0 = t;
            }
        }
        if (o->req->unk88 != 0) {
            if (o->req->unk80 == 0) {
                if (o->unk26C != 0 && o->unk2314 == 0) {
                    func_80005070(o->unk26C, 1, 1);
                    o->unk26C = 0;
                }
                if (o->unk254 != 0) {
                    o->unk26C = o->req->unk88;
                } else {
                    func_80005070(o->req->unk88, 1, 0);
                }
            } else {
                func_80005070(o->req->unk88, 1, 0);
            }
        }
    }
    o->req = NULL;
    func_800BD05C(o);
    if (o->unk22DC != 0) {
        o->unk22DC = 0;
        func_800BCDEC(o);
    }
}
