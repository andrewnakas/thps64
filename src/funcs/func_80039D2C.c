/* cflags: -fcse-follow-jumps */
#include "common.h"
#include "helpers.h"

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

void func_80039D2C(void) {
    Chan39D2C *c;

    func_800A8EF0(D_800EA9C0, D_800D0FC0.unk30);
    c = D_800D3F34;
    f2u_store_u8_x127(&c->unk14, D_800D0FC0.unk2C);
    f2u_store_u8_x127(&(c + 1)->unk14, D_800D0FEC);
    c += 2;
    f2u_store_u8_x127(&c->unk14, D_800D0FEC);
}
