/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VEnt180C;

typedef struct {
    u8 pad[0x30];
    VEnt180C e6;
} VTbl180C;

typedef struct {
    u8 pad0[0xC];
    s32 state;
    u8 pad10[0xC];
    char buf[0x3EC - 0x1C];
    u8 sub[0x424 - 0x3EC];
    s32 unk424;
    u8 pad428[0xC];
    s32 len;
    s32 unk438;
    u8 pad43C[8];
    s32 unk444;
    s32 unk448;
    s32 unk44C;
    u8 pad450[0x47C - 0x450];
    s32 unk47C;
    s32 unk480;
    u8 unk484[0x4E0 - 0x484];
    u16 unk4E0;
    u16 pad4E2;
    s32 unk4E4;
    u8 pad4E8[0x4F8 - 0x4E8];
    VTbl180C *vt;
} Conn180C;

s32 func_800A1C40(Conn180C *, void *, s32 *);
s32 func_8000B470(void *, void *, s32);
void func_800A0870(Conn180C *, s32, s32);
void func_800A3750(Conn180C *, char *, s32, s32, s32, s32 *, s32);
s32 func_8000ACA0(void *, u16, s32, void *, s32 *, s32 *);
s32 func_80008100(void *, u16, s32, void *, s32 *, s32, s32 *);
void func_800A0B0C(Conn180C *, void *, char *, s32);
u32 func_8000574C(char *);
void func_800057E4(char *, char *, ...);
void func_800A0C6C(Conn180C *, s32);
void func_800A1B68(Conn180C *, void *, s32);
extern s32 D_800EA550;
extern char D_80020DB0[];
extern char D_80020DD4[];
extern char D_80020DF4[];
extern char D_80020EC0[];
extern char D_80020EC8[];
extern char D_80020ED0[];
extern char D_80020ED8[];

void func_800A180C(Conn180C *o, s32 flag) {
    u8 msg[0x68];
    char tmp[0x10];
    s32 v98;
    s32 v9C;
    s32 r;
    s32 q;
    char *p;

    if (func_800A1C40(o, msg, &v98) == 0) {
        return;
    }
    r = func_8000B470(o->sub, msg, o->len);
    if (r != 0) {
        goto err;
    }
    if (v98 != 0 && o->unk47C != 0) {
        o->unk444 = o->unk44C = o->unk424;
        o->unk448 = D_800EA550;
        func_800A3750(o, D_80020DB0, o->len, 9, 1, &o->unk444, 0);
        return;
    }
    r = func_8000ACA0(msg, o->unk4E0, o->unk4E4, o->unk484, &o->unk480, &v9C);
    switch (r) {
    case 0:
        if (flag == 0) {
            goto done;
        }
        func_800A0B0C(o, o->unk484, tmp, 0x10);
        p = tmp;
        if (func_8000574C(p) >= 4) {
            p = tmp + 3;
        }
        func_800057E4(o->buf, D_80020DD4, p);
        func_800A0C6C(o, D_800EA550);
        o->state = 0x1F;
        func_800A3750(o, o->buf, o->len, 3, 0, &o->unk444, 0);
        return;
    case 5:
        break;
    default:
        goto err;
    }
    r = func_80008100(msg, o->unk4E0, o->unk4E4, o->unk484, &o->unk480, o->unk438, &v9C);
    if (r == 0) {
    done:
        func_800A1B68(o, msg, v9C);
        return;
    }
    switch (r) {
    case 0:
        goto done;
    case 7:
    case 8:
        if (flag != 0 || v98 == 0) {
            s32 n1;
            q = (o->unk438 + 0xFF) / 256;
            n1 = o->len + 1;
            func_800057E4(o->buf, D_80020DF4, n1, q, q == 1 ? D_80020EC0 : D_80020EC8,
                          q == 11 ? D_80020ED0 : D_80020ED8, n1);
            o->unk444 = o->unk44C = o->unk424;
            o->unk448 = D_800EA550;
            o->vt->e6.fn((u8 *)o + o->vt->e6.off);
            func_800A3750(o, o->buf, o->len, 7, 0, &o->unk444, 0);
            o->state = 0x1E;
            return;
        }
        func_800A0870(o, 2, o->unk424);
        o->state = 0x1E;
        return;
    }
    func_800A0870(o, r, o->unk424);
    o->state = 0x1E;
    return;
err:
    func_800A0870(o, r, 0);
}
