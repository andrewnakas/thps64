/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd_800AEDF0;

typedef struct {
    u8 pad0[0x54];
    s32 unk54;
    s16 pan;
    s16 vol;
    s16 unk5C;
    s16 unk5E;
    u16 unk60;
    u16 unk62;
    u16 unk64;
    u16 unk66;
    u16 unk68;
    u16 unk6A;
    u16 unk6C;
    u16 unk6E;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    u8 pad7C[8];
    s32 unk84;
} Env_800AEDF0;

s32 func_80003520(s32);
s16 func_800AEFF8(f64, f64, s32, u16 *);
Acmd_800AEDF0 *func_800AF870(Env_800AEDF0 *, u16 *, Acmd_800AEDF0 *);
extern s16 D_800ECC40[];

#define aSetVolume(pkt, f, v, t, r) { Acmd_800AEDF0 *_a = (Acmd_800AEDF0 *)pkt; \
    _a->w0 = (0x09 << 24) | ((f) << 16) | ((u32)(v) & 0xFFFF); \
    _a->w1 = (((u32)(t) & 0xFFFF) << 16) | ((u32)(r) & 0xFFFF); }
#define aEnvMixer(pkt, f, t, s) { Acmd_800AEDF0 *_a = (Acmd_800AEDF0 *)pkt; \
    _a->w0 = (0x03 << 24) | ((f) << 16) | ((u32)(t) & 0xFFFF); \
    _a->w1 = (u32)(s); }

Acmd_800AEDF0 *func_800AEDF0(void *filter, u16 *inp, s32 arg2, s32 outCount, Acmd_800AEDF0 *p) {
    Acmd_800AEDF0 *ptr = p;
    Env_800AEDF0 *e = filter;

    if (e->unk84 != 1 || !outCount) {
        return ptr;
    }
    ptr = func_800AF870(e, inp, ptr);
    if (e->unk78) {
        e->unk78 = 0;
        e->unk68 = (e->vol * D_800ECC40[e->pan]) >> 15;
        e->unk66 = func_800AEFF8((f64)e->unk5C, (f64)(s16)e->unk68, e->unk74, &e->unk64);
        e->unk6E = (e->vol * D_800ECC40[0x80 - e->pan - 1]) >> 15;
        e->unk6C = func_800AEFF8((f64)e->unk5E, (f64)(s16)e->unk6E, e->unk74, &e->unk6A);
        aSetVolume(ptr++, 0, e->unk68, e->unk66, e->unk64);
        aSetVolume(ptr++, 6, e->unk5C, e->unk60, e->unk62);
        aSetVolume(ptr++, 4, e->unk6E, e->unk6C, e->unk6A);
        aEnvMixer(ptr++, 1, e->unk5E, func_80003520(e->unk54));
    } else {
        aEnvMixer(ptr++, 0, 0, func_80003520(e->unk54));
    }
    *inp += 0xB8 << 1;
    e->unk70 += 0xB8;
    return ptr;
}
