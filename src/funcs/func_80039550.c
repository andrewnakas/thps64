#include "common.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    u8 pad16[2];
    s32 g;
    u8 pad18[0x2C];
} Sub39550;

typedef struct {
    u8 unk0;
    u8 pad1[3];
    Sub39550 s[3];
    s32 unkD0;
    s32 unkD4;
    s32 unkD8[9];
    u8 padFC[4];
    f32 unk100;
    u8 unk104;
    u8 unk105;
    u8 unk106;
    u8 unk107;
    u8 unk108;
    u8 unk109;
    u8 unk10A;
} S39550;

S39550 *func_80039550(S39550 *p) {
    p->unk109 = 0x40;
    p->unk10A = 0;
    p->unk106 = 0xAF;
    p->unk107 = 0xAF;
    p->unk108 = 0xAF;
    p->unk0 = 0xFF;
    p->unkD4 = 0;
    p->s[0].a = 0xA8;
    p->s[0].d = 1;
    p->s[0].e = 0x7F;
    p->s[0].f = 0;
    p->s[0].g = 0;
    p->s[0].c = 0;
    p->s[0].b = 0;
    p->s[1].a = 0xA8;
    p->s[1].d = 1;
    p->s[1].e = 0x7F;
    p->s[1].f = 0;
    p->s[1].g = 0;
    p->s[1].c = 0;
    p->s[1].b = 0;
    p->s[2].a = 0xA8;
    p->s[2].d = 1;
    p->s[2].e = 0x7F;
    p->s[2].f = 0;
    p->s[2].g = 0;
    p->s[2].c = 0;
    p->s[2].b = 0;
    p->unkD8[0] = 1;
    p->unkD8[1] = 2;
    p->unkD8[2] = 3;
    p->unkD8[3] = 4;
    p->unkD8[4] = 5;
    p->unkD8[5] = 6;
    p->unkD8[6] = 7;
    p->unkD8[7] = 8;
    p->unkD8[8] = 9;
    p->unk104 = 8;
    p->unk105 = 2;
    p->unk100 = 0.75f;
    p->unkD0 = 1;
    return p;
}
