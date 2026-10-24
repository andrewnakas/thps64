/* cflags: -O2 */
#include "common.h"

typedef struct {
    void (*fn0)(void);
    void (*fn4)(void);
    void (*fn8)(void *);
} Vt800BB8F8;

typedef struct {
    void *p;
    s32 n;
} Buf800BB8F8;

typedef struct {
    s32 a;
    s32 b;
} E8_800BB8F8;

typedef struct {
    E8_800BB8F8 *base;
    s32 size;
    void *c;
    void *d;
} Req800BB8F8;

typedef struct {
    u8 pad0[0x2314];
    s32 busy;
} St800BB8F8;

extern Vt800BB8F8 *D_800F0D3C;
extern Buf800BB8F8 *D_800F0D40;
extern Buf800BB8F8 *D_800FC834;
extern E8_800BB8F8 *D_800FC838;
extern St800BB8F8 D_800F0DD0;
extern u8 D_80097C40[];
extern u8 D_800E95E0[];

void func_800BBCFC(void);
s32 func_80010A40(void);
void func_80010A50(void *, s32);
s32 func_800BBAFC(void);
void *func_80003520(void *);
E8_800BB8F8 *func_800B0000(E8_800BB8F8 *, s32 *, void *, s32);

void func_800BB8F8(void) {
    Req800BB8F8 req;
    s32 out;
    s32 i;
    Buf800BB8F8 *b;
    E8_800BB8F8 *r;

    i = 0;
    req.c = D_80097C40;
    req.d = D_800E95E0;
    req.base = D_800FC838;
    D_800F0D3C->fn0();
    while (1) {
        while (D_800F0DD0.busy != 0) {
        }
        D_800F0D3C->fn4();
        func_800BBCFC();
        if (func_80010A40() < 0) {
            continue;
        }
        if (D_800F0D40 != NULL) {
            func_80010A50(D_800F0D40->p, D_800F0D40->n * 4);
        }
        b = &D_800FC834[i % 3];
        b->n = func_800BBAFC();
        r = func_800B0000(D_800FC838, &out, func_80003520(b->p), b->n);
        if (out != 0) {
            req.size = (r - D_800FC838) * sizeof(E8_800BB8F8);
            D_800F0D3C->fn8(&req);
            D_800F0D40 = b;
        }
        i++;
    }
}
