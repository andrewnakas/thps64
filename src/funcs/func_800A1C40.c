/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VEntry;

typedef struct {
    u8 pad[0x38];
    VEntry e7;
} VTbl;

typedef struct {
    u8 pad0[0xC];
    s32 state;
    u8 pad10[0xC];
    char buf[0x3EC - 0x1C];
    u8 sub[0x424 - 0x3EC];
    s32 unk424;
    u8 pad428[0xC];
    s32 len;
    u8 pad438[0xC];
    s32 unk444;
    s32 unk448;
    s32 unk44C;
    u8 pad450[0x4F8 - 0x450];
    VTbl *vt;
} Conn;

s32 func_8000B470(void *, s32, s32);
s32 func_8000C900(void *, s32, s32);
void func_800A04D8(Conn *, s32);
void func_800A0870(Conn *, s32, s32);
void func_800A0C6C(Conn *, s32);
void func_800A3750(Conn *, char *, s32, s32, s32, s32 *, s32);
void func_800057E4(char *, char *, s32);
extern s32 D_800EA550;
extern char D_80020EF4[];
extern char D_80020F48[];

s32 func_800A1C40(Conn *o, s32 arg1, s32 *flag) {
    s32 r;
    s32 t;

    r = func_8000B470(o->sub, arg1, o->len);
    if (flag != NULL) {
        *flag = 0;
    }
    while (1) {
        if (r != 2) break;
        func_800A04D8(o, o->len);
        if (flag != NULL) {
            *flag = 1;
        }
        r = func_8000B470(o->sub, arg1, o->len);
    }
    switch (r) {
    case 0:
        return 1;
    case 10:
        if (func_8000C900(o->sub, arg1, o->len) != 0) {
            o->vt->e7.fn((u8 *)o + o->vt->e7.off);
            o->state = 0x20;
            func_800A0C6C(o, D_800EA550);
            func_800A3750(o, D_80020EF4, o->len, 8, 2, &o->unk444, 0);
        } else {
            func_800057E4(o->buf, D_80020F48, o->len + 1);
            t = o->unk424;
            o->unk448 = D_800EA550;
            o->unk44C = t;
            o->unk444 = t;
            func_800A3750(o, o->buf, o->len, 7, 0, &o->unk444, 0);
        }
        break;
    default:
        func_800A0870(o, r, o->unk424);
        o->state = 0x1E;
        break;
    }
    return 0;
}
