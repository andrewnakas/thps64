/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x3D4];
    u8 unk3EC[0x48];
    s32 unk434;
} Obj800A15EC;

extern s32 func_8000B470(void *, void *, s32);
extern void func_800A059C(Obj800A15EC *);
extern void func_800A05D8(Obj800A15EC *);
extern void func_800A0978(Obj800A15EC *, s32, void *, s32);
extern void func_800A2FE0(Obj800A15EC *, void *, s32, void *, s32);
extern void func_800A3194(Obj800A15EC *);

s32 func_800A15EC(Obj800A15EC *arg0, s32 arg1) {
    u8 sp18[0x68];
    u8 sp80[0x8];
    void *p;
    s32 r;

    r = 0;
    func_800A059C(arg0);
    if (func_8000B470(arg0->unk3EC, sp18, arg0->unk434) == 0) {
        if (arg1 != 0) {
            func_800A0978(arg0, arg1, sp80, 4);
            p = sp80;
        } else {
            p = NULL;
        }
        func_800A2FE0(arg0, sp18, 0, p, 0);
        if (arg0->unk14 != 0) {
            r = 1;
        }
        func_800A3194(arg0);
    }
    func_800A05D8(arg0);
    return r;
}
