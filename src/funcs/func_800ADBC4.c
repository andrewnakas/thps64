/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[8];
    s32 unk10;
    u8 pad14[0x14];
    f32 unk28;
    u8 pad2C[0x2C];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    u8 pad64[8];
    f32 unk6C;
    u8 pad70[0xC];
    s32 unk7C;
    u8 pad80[0x18];
    s16 unk98;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    u16 unkA0;
    s16 unkA2;
    s16 unkA4;
    u8 padA6[2];
    s16 unkA8;
    u8 padAA[6];
    s16 unkB0;
    u8 padB2[0xA];
    u8 unkBC;
    u8 unkBD;
    u8 unkBE;
    u8 unkBF;
    u8 padC0;
    u8 unkC1;
    u8 unkC2;
    u8 padC3[3];
    u8 unkC6;
    u8 unkC7;
    u8 unkC8;
    u8 unkC9;
    u8 padCA[2];
    u8 unkCC;
    u8 padCD[6];
    u8 unkD3;
    u8 padD4[0x5C];
} Voice;

extern s32 D_800FC300;
extern s32 D_800FC314;
extern s32 D_800FC318;

static __inline__ void voice_set_(Voice *arg0, s32 rate, u8 vol, f32 a, f32 b, f32 c, f32 d, f32 e, s32 one) {
    s32 v;

    arg0->unkD3 = vol;
    arg0->unkBC = vol;
    arg0->unkBF = one;
    arg0->unkC6 = one;
    arg0->unkC1 = vol;
    arg0->unkC7 = 0xFF;
    arg0->unkC2 = vol;
    arg0->unk9A = one;
    arg0->unkA2 = one;
    arg0->unkA4 = one;
    arg0->unkBD = 0x40;
    arg0->unkC8 = 0xF;
    v = D_800FC314;
    arg0->unkA0 = 0xFFFF;
    arg0->unk10 = -1;
    arg0->unk9E = 0x80;
    arg0->unkB0 = 0x80;
    arg0->unk98 = 0x80;
    arg0->unk28 = a;
    arg0->unk6C = b;
    arg0->unk58 = c;
    arg0->unk5C = d;
    arg0->unk60 = e;
    arg0->unkA8 = rate;
    arg0->unk9C = rate;
    if (v == 0) {
        v = D_800FC318;
    }
    arg0->unk7C = v;
}

void func_800ADBC4(Voice *arg0) {
    u8 *p;
    u32 i;
    u8 keep;

    p = (u8 *)arg0;
    keep = arg0->unkC9;
    i = 0;
    arg0->unk4 = 0;
    do {
        *p = 0;
        i++;
        p++;
    } while (i < sizeof(Voice));
    arg0->unkCC = 0xFF;
    arg0->unkBE = 0xFF;
    voice_set_(arg0, 0x6000 / D_800FC300, 0x7F, 99.9f, 0.03125f, 1.0f, 0.003921568859368563f, 0.06666667014360428f, 1);
    arg0->unkC9 = keep;
}
