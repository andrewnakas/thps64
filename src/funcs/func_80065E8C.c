#include "common.h"

typedef struct {
    u8 pad0[0x110];
    s32 a[2];
    s32 b[2];
    s32 c[2][4];
    char name1[0x44];
    s32 x184;
    s32 x188;
    s32 len;
    char name2[1];
} SrcState;

typedef struct {
    u8 pad0[0x870];
    f32 x870;
    f32 x874;
    u8 pad1[0x980 - 0x878];
    s32 a[2];
    s32 b[2];
    s32 c[2][4];
    char name1[0x44];
    s32 x9F4;
    s32 x9F8;
    s32 len;
    char name2[11];
} DstState;

typedef struct {
    u8 pad0[0x2C];
    f32 x2C;
    f32 x30;
} CamState;

void func_800057E4(char *, char *);
void func_800660C4(void);
extern CamState D_800D0FC0;
extern SrcState D_800DC3F8;
extern DstState D_800DE9F4;

void func_80065E8C(void) {
    DstState *d;
    SrcState *s;
    s32 *dA;
    s32 *dC;
    s32 *sC;
    s32 *sA;
    s32 i;
    s32 j;
    char *dn;
    char *sn;
    DstState *pd;
    char *x;
    char *y;

    d = &D_800DE9F4;
    d->x870 = D_800D0FC0.x2C;
    d->x874 = D_800D0FC0.x30;
    s = &D_800DC3F8;
    d->x9F4 = s->x184;
    d->x9F8 = s->x188;
    i = 0;
    sC = (s32 *)&D_800DC3F8;
    dC = (s32 *)&D_800DE9F4;
    sA = (s32 *)&D_800DC3F8;
    dA = (s32 *)&D_800DE9F4;
    do {
        dA[0x980 / 4] = sA[0x110 / 4];
        dA[0x988 / 4] = sA[0x118 / 4];
        dC[0x990 / 4] = sC[0x120 / 4];
        dC[0x994 / 4] = sC[0x124 / 4];
        dC[0x998 / 4] = sC[0x128 / 4];
        dC[0x99C / 4] = sC[0x12C / 4];
        sC += 4;
        dC += 4;
        sA++;
        i++;
        dA++;
    } while (i < 2);
    dn = D_800DE9F4.name2;
    sn = D_800DC3F8.name2;
    func_800057E4(dn, sn);
    ((s32 *)dn)[-1] = ((s32 *)sn)[-1];
    for (j = ((s32 *)sn)[-1]; j < 11; j++) {
        pd = (DstState *)(dn - 0xA00);
        *(j + pd->name2) = 0;
    }
    x = D_800DE9F4.name1;
    y = D_800DC3F8.name1;
    func_800057E4(x, y);
    func_800660C4();
}
