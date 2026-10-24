/* cflags: -fcse-follow-jumps */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    u8 unk14;
    u8 pad15[0x2F];
} Chan39D2C;

typedef struct {
    u8 pad0[0x2C];
    f32 unk2C;
    s32 unk30;
} Cfg39D2C;

void func_800A8EF0(void *, s32);
extern Cfg39D2C D_800D0FC0;
extern f32 D_800D0FEC;
extern Chan39D2C D_800D3F34[];
extern u8 D_800EA9C0[];

static __inline__ void setvol(u8 *p, f32 x) {
    f32 f = x * 127.0f;
    u32 v;
    u32 m;
    f32 g;
    if (f >= 2147483648.0f) {
        goto big;
    }
    v = (s32)f;
    goto end;
big:
    g = f - 2147483648.0f;
    m = 0x80000000;
    v = (s32)g;
    v |= m;
end:
    *p = v;
}

void func_80039D2C(void) {
    Chan39D2C *c;

    func_800A8EF0(D_800EA9C0, D_800D0FC0.unk30);
    c = D_800D3F34;
    setvol(&c->unk14, D_800D0FC0.unk2C);
    setvol(&(c + 1)->unk14, D_800D0FEC);
    c += 2;
    setvol(&c->unk14, D_800D0FEC);
}
