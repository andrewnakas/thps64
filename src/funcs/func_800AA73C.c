/* cflags: -O2 */
/* cflags: -O2 */
#include "common.h"

typedef struct Snd {
    s32 unk0;
    u8 pad4[0x8];
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 pad12[2];
    f32 unk14;
    u8 unk18;
    u8 pad19[0x1B];
    u8 unk34;
    u8 pad35[3];
    s32 unk38;
    struct Snd *unk3C;
    struct Snd *unk40;
} Snd;

typedef struct {
    s32 unk0;
    u8 pad4[0x20];
} SndChan;

typedef struct {
    u8 pad0[0x538];
    SndChan chans[1];
} SndMgr;

void func_800A9958(void *, s32, u8, u8, f32, s32, s32);
s32 func_800A9D64(void *, s32);
s32 func_800AA834(void *, Snd *);
s32 func_800AC07C(s32);

s32 func_800AA73C(u8 *arg0, Snd *arg1) {

    if (arg1 == NULL || func_800A9D64(arg0, arg1->unk0) == 0) {
        goto fail;
    }
    if (arg1->unkC != 1) {
        return 0;
    } else if (func_800AA834(arg0, arg1) != 0) {
    fail:
        return 0;
    } else {
        if (*(Snd **)(arg0 + 0x2154) == NULL) {
            *(Snd **)(arg0 + 0x2154) = arg1;
            arg1->unk3C = 0;
            (*(Snd **)(arg0 + 0x2154))->unk40 = 0;
        } else {
            arg1->unk40 = *(Snd **)(arg0 + 0x2154);
            arg1->unk3C = 0;
            (*(Snd **)(arg0 + 0x2154))->unk3C = arg1;
            *(Snd **)(arg0 + 0x2154) = arg1;
        }
        func_800A9958(arg0, arg1->unk0, arg1->unk10, arg1->unk18, arg1->unk14, arg1->unk11, 1);
        arg1->unk34 = 3;
        arg1->unk38 = func_800AC07C(((SndMgr *)arg0)->chans[arg1->unk0].unk0);
        return 1;
    }
    return 0;
}
