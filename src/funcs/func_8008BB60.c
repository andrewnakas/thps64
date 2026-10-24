/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x58];
    u8 unk58[0x298 - 0x58];
    s32 unk298;
    s32 unk29C;
} PlBB60;

typedef struct {
    s32 unk0;
    s32 unk4;
} DcBB60;

void func_8002C040(void *, u8);
void func_8008E690(void);
s32 func_800A050C(void *, u8);
void func_8002B5F8(void *);
void func_800057E4(char *, char *, ...);
void func_800A3750(void *, char *, s32, s32, s32, s32, s32);
void func_80065E8C(void);
void func_8006A854(s32, s32);
void func_800A169C(void *, u8, s32, s32, s32, char *, char *, s32);
extern PlBB60 *D_800D0FBC;
extern u8 D_800D0FC0[];
extern u8 D_800D0FC2;
extern s32 D_800E8FB0;
extern s32 D_800E8FAC;
extern s32 D_800EA550;
extern s32 D_800E8FB4;
extern s32 D_800E8FB8;
extern s32 D_800E8FBC;
extern s32 D_800E8E94;
extern s32 D_800E8FA8;
extern s32 D_800DE7E0;
extern s32 D_800E8FA4;
extern u8 D_800D3130[];
extern s32 D_800D3148;
extern char D_800D3668[];
extern char D_8001FD18[];
extern char D_8001FD40[];
extern char D_8001FD48[];
extern char D_8001FD4C[];
extern u8 D_800DE9F4[];
extern DcBB60 D_800DC618;

#define RESET()                                                   \
    {                                                             \
        D_800E8FB0 = D_800E8FB4 = D_800E8FBC = D_800E8FB8 = 0;     \
        if (D_800E8E94 != 0) {                                    \
            s32 _e = 8; \
            D_800E8FA8 = _e;                                       \
            D_800DE7E0 = _e;                                       \
        } else {                                                  \
            s32 _t = D_800E8FA4; \
            D_800E8FA8 = _t;                              \
            D_800DE7E0 = _t;                              \
        }                                                         \
    }

void func_8008BB60(void) {
    PlBB60 *o;
    char buf[0x18];
    u8 *p;
    u8 *p2;
    char *nm;
    u8 s;
    s32 c;
    u8 *q;

    o = D_800D0FBC;
    if (D_800E8FB0 == 0) {
        D_800E8FB0 = 1;
        func_8002C040(o->unk58, D_800D0FC2);
        D_800E8FAC = 1;
    }
    c = o->unk298 == 0 || D_800EA550 != 0;
    if (c) {
        func_8008E690();
    }
    if (D_800E8FB4 == 0 && o->unk298 != 0) {
        if (o->unk29C != 0) {
            D_800E8FB4 = 1;
            q = D_800D3130;
            p = D_800D0FC0;
            if (func_800A050C(q, p[2]) == 0) {
                D_800E8FB8 = 1;
                func_8002B5F8(q);
                func_800057E4((char *)q + 0x1C, D_8001FD18, p[2] + 1);
                func_800A3750(q, (char *)q + 0x1C, p[2], 5, 0, 0, 0);
                D_800E8FAC = 2;
            }
        } else {
            RESET();
        }
    }
    c = D_800E8FBC == 0 && o->unk298 != 0 && D_800EA550 == 0;
    if (c) {
        if ((D_800E8FB8 != 0 && D_800D3148 == 1) || o->unk29C == 0) {
            RESET();
        } else {
            nm = D_800D3668;
            func_800057E4(buf, D_8001FD40, nm);
            D_800E8FBC = 1;
            p2 = D_800D0FC0;
            s = p2[0x1A];
            if (s != 1) {
                func_80065E8C();
                func_800A169C(D_800D3130, p2[2], (s32)D_800DE9F4, 0xA10, 1, buf, D_8001FD48, 0);
            } else {
                func_8006A854(D_800DC618.unk4 + 0x200, 0);
                func_800A169C(D_800D3130, p2[2], D_800DC618.unk4, 0x6000, s, buf, D_8001FD4C, 0);
            }
        }
        D_800E8FBC = 1;
    }
    if (D_800E8FBC != 0 && D_800EA550 == 0) {
        RESET();
    }
}
