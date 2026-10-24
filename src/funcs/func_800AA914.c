/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    u8 pad34[0x5C];
    f32 unk90;
    u8 pad94[0xA];
    s16 unk9E;
    u8 padA0[0x10];
    s16 unkB0;
    u8 padB2[0xC];
    u8 unkBE;
    u8 padBF[0xC];
    u8 unkCB;
    u8 unkCC;
} Voice;

typedef struct Snd {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 pad12[2];
    f32 unk14;
    u8 unk18;
    u8 pad19[0x1B];
    u8 unk34;
    u8 pad35[3];
    Voice *unk38;
    struct Snd *unk3C;
    struct Snd *unk40;
} Snd;

typedef struct {
    s32 unk0;
    u8 pad4[0x20];
} SndChan;

typedef struct {
    u8 pad0[0x538];
    SndChan chans[199];
    u8 pad2134[0x20];
    Snd *unk2154;
} SndMgr;

void func_800ABE14(s32, s32);
void func_800AA8C8(SndMgr *, Snd *);

void func_800AA914(SndMgr *arg0) {
    Snd *s;

    for (s = arg0->unk2154; s != NULL; s = s->unk40) {
        if (s->unkC == 5) {
            func_800ABE14(arg0->chans[s->unk0].unk0, 0);
            func_800AA8C8(arg0, s);
        } else if ((u32)(s->unkC - 1) < 2) {
            s->unk34 = 3;
            if (s->unk8 == s->unk4 && s->unk38 != NULL) {
                s->unk38->unk9E = s->unk10;
                s->unk38->unkB0 = s->unk18;
                s->unk38->unkBE = 0xFF;
                s->unk38->unk30 = s->unk38->unk90 + s->unk14;
                s->unk38->unkCB = s->unk11;
                s->unk38->unkCC = 0xFF;
            }
        }
    }
}
