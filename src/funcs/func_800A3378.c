/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 delta;
    s16 idx;
    s32 (*fn)(void *);
} VEnt800A3378;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    u8 pad18[4];
    char text[0x3EC - 0x1C];
    u8 unk3EC[0x434 - 0x3EC];
    s32 unk434;
    u8 pad438[0x444 - 0x438];
    u8 unk444[0x478 - 0x444];
    s32 unk478;
    u8 pad47C[4];
    u8 unk480[0x4F8 - 0x480];
    VEnt800A3378 *vt;
} Obj800A3378;

extern void func_800057E4(char *, char *, ...);
extern s32 func_8000B1D0(void *, s32 *);
extern s32 func_8000B320(void *, s32 *, s32 *);
extern s32 func_8000B470(void *, void *, s32);
extern s32 func_8000C900(void *, void *, s32);
extern void func_800A04D8(Obj800A3378 *, s32);
extern void func_800A0870(Obj800A3378 *, s32, s32);
extern void func_800A0C6C(Obj800A3378 *, s32);
extern void func_800A0D0C(Obj800A3378 *, char *);
extern void func_800A2FE0(Obj800A3378 *, void *, s32, void *, s32);
extern void func_800A3194(Obj800A3378 *);
extern void func_800A3750(Obj800A3378 *, char *, s32, s32, s32, void *, f32);
extern char D_80020EC0[];
extern char D_80020EC8[];
extern char D_80021044[];
extern char D_80021048[];
extern char D_80021184[];
extern char D_80021260[];
extern char D_80021264[];
extern char D_800213A0[];
extern char D_8002147C[];
extern char D_800214EC[];
extern char D_800215A0[];
extern s32 D_800EA550;

void func_800A3378(Obj800A3378 *arg0) {
    u8 buf[0x68];
    s32 size;
    s32 total;
    s32 used;
    s32 r;
    s32 need;
    s32 avail;
    s32 slot;
    VEnt800A3378 *e;

    r = func_8000B470(arg0->unk3EC, buf, arg0->unk434);
    while (1) {
        if (r != 2) break;
        func_800A04D8(arg0, arg0->unk434);
        r = func_8000B470(arg0->unk3EC, buf, arg0->unk434);
    }
    switch (r) {
        case 0:
            r = func_8000B1D0(buf, &size);
            if (r != 0) {
                func_800A0870(arg0, r, 0);
                return;
            }
            r = func_8000B320(buf, &total, &used);
            if (r != 0) {
                func_800A0870(arg0, r, 0);
                return;
            }
            need = (size + 0xFF) / 256;
            e = &arg0->vt[9];
            avail = (e->fn((u8 *)arg0 + e->delta) + 0xFF) / 256;
            slot = arg0->unk434 + 1;
            if (need < avail || used == total) {
                func_800A0D0C(arg0, D_80021044);
                func_800A2FE0(arg0, buf, 0, arg0->unk480, 0);
                if (arg0->unk14 != 0) {
                    func_800057E4(arg0->text, D_80021048, slot, avail, avail == 1 ? D_80020EC0 : D_80020EC8);
                } else {
                    func_800057E4(arg0->text, D_80021184, slot, avail, avail == 1 ? D_80020EC0 : D_80020EC8);
                }
                func_800A3194(arg0);
                func_800A3750(arg0, arg0->text, arg0->unk434, 0, 0, NULL, 60.0f);
                return;
            }
            if (need < 0x60) {
                func_800A0D0C(arg0, D_80021260);
                func_800A2FE0(arg0, buf, 0, arg0->unk480, 0);
                if (arg0->unk14 != 0) {
                    func_800057E4(arg0->text, D_80021264, slot, need, need == 1 ? D_80020EC0 : D_80020EC8);
                } else {
                    func_800057E4(arg0->text, D_800213A0, slot, need, need == 1 ? D_80020EC0 : D_80020EC8);
                }
                func_800A3194(arg0);
                func_800A3750(arg0, arg0->text, arg0->unk434, 0, 0, NULL, 60.0f);
                return;
            }
            D_800EA550 = 0;
            return;
        case 1:
            func_800057E4(arg0->text, D_8002147C, arg0->unk434 + 1);
            func_800A3750(arg0, arg0->text, arg0->unk434, 0, 0, NULL, 60.0f);
            return;
        case 10:
            if (func_8000C900(arg0->unk3EC, buf, arg0->unk434) != 0) {
                if (arg0->unk478 != 0) {
                    e = &arg0->vt[7];
                    e->fn((u8 *)arg0 + e->delta);
                    arg0->unk10 = 0x33;
                    func_800A0C6C(arg0, D_800EA550);
                    func_800057E4(arg0->text, D_800214EC, arg0->unk434 + 1);
                    func_800A3750(arg0, arg0->text, arg0->unk434, 3, 1, arg0->unk444, 0.0f);
                } else {
                    D_800EA550 = 0;
                }
            } else {
                func_800057E4(arg0->text, D_800215A0, arg0->unk434 + 1);
                func_800A3750(arg0, arg0->text, arg0->unk434, 0, 0, NULL, 60.0f);
            }
            return;
    }
    func_800A0870(arg0, r, 0);
}
