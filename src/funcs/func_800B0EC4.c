/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 start;
    u32 end;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 padE;
    f32 unk10;
    u8 pad14[8];
    f32 unk1C;
    s16 *unk20;
    u8 pad24[4];
} Trk;

typedef struct {
    u8 pad0[0x20];
    Trk *trk;
} Seq;

typedef struct {
    u8 pad0[0x54];
    s32 rate;
} Drv;

extern Drv *D_800ECC34;
void func_8000D560(s16 *);

#define RANGE 2.0
#define CONVERT 173123.40490667601

s32 func_800B0EC4(void *filter, s32 paramID, void *param) {
    Seq *f = (Seq *)filter;
    s32 p = (paramID - 2) % 8;
    s32 s = (paramID - 2) / 8;
    s32 val = *(s32 *)param;

    switch (p) {
    case 0:
        f->trk[s].start = (u32)val & 0xFFFFFFF8;
        break;
    case 1:
        f->trk[s].end = (u32)val & 0xFFFFFFF8;
        break;
    case 3:
        f->trk[s].unk8 = (s16)val;
        break;
    case 2:
        f->trk[s].unkA = (s16)val;
        break;
    case 4:
        f->trk[s].unkC = (s16)val;
        break;
    case 5:
        f->trk[s].unk10 = ((((f32)val) / 1000.0f) * RANGE) / D_800ECC34->rate;
        break;
    case 6: {
        f64 c = ((f32)val) / CONVERT;
        s32 len = f->trk[s].end - f->trk[s].start;
        f64 d = len;

        if (len < 0) {
            d += 4294967296.0;
        }
        f->trk[s].unk1C = c * d;
        break;
    }
    case 7:
        if (f->trk[s].unk20) {
            *f->trk[s].unk20 = (s16)val;
            func_8000D560(f->trk[s].unk20);
        }
        break;
    }
    return 0;
}
