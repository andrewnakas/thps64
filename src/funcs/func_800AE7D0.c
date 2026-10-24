/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd;

typedef struct ALParam_s {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 unity;
    union {
        f32 f;
        s32 i;
    } data;
    union {
        f32 f;
        s32 i;
    } moredata;
    s32 pad14;
    s32 wave;
} ALParam;

typedef struct {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 unity;
    f32 pitch;
    s16 volume;
    u8 pan;
    u8 fxMix;
    s32 samples;
    s32 wave;
} ALStartParamAlt;

typedef struct {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 unity;
    s32 wave;
} ALStartParam;

typedef struct {
    u8 pad0[0x88];
    s32 offset;
} PVoice;

typedef struct {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 pad;
    PVoice *pvoice;
} N_ALFreeParam;

typedef struct {
    u8 pad0[0x44];
    f32 rs_ratio;
    s32 rs_upitch;
    u8 pad4C[0x58 - 0x4C];
    s16 em_pan;
    s16 em_volume;
    s16 em_cvolL;
    s16 em_cvolR;
    s16 em_dryamt;
    s16 em_wetamt;
    u16 em_lratl;
    s16 em_lratm;
    s16 em_ltgt;
    u16 em_rratl;
    s16 em_rratm;
    s16 em_rtgt;
    s32 em_delta;
    s32 em_segEnd;
    s32 em_first;
    ALParam *em_ctrlList;
    ALParam *em_ctrlTail;
    s32 em_motion;
} N_PVoice;

#define FIXED_SAMPLE 184
#define _n_timeToSamples(x) ((((x) + (FIXED_SAMPLE / 2)) / FIXED_SAMPLE) * FIXED_SAMPLE)

extern s16 D_800ECC40[];
Acmd *func_800AEDF0(N_PVoice *, s16 *, s16 *, s32, Acmd *);
s16 func_800AF118(s16, s32, s16, u16);
void func_800AF5A4(void *, s32, void *);
s32 func_800AED54(void *, s32, void *);
void func_800B0234(ALParam *);
void func_800B02AC(PVoice *);

Acmd *func_800AE7D0(N_PVoice *filter, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    N_PVoice *e = (N_PVoice *)filter;
    s16 inp;
    s32 lastOffset;
    s32 thisOffset = sampleOffset;
    s32 samples;
    s16 loutp = 0;
    s32 fVol;
    ALParam *thisParam;
    s32 left = FIXED_SAMPLE;

    inp = 0;

    while (e->em_ctrlList != 0) {
        lastOffset = thisOffset;
        thisOffset = _n_timeToSamples(e->em_ctrlList->delta);
        samples = thisOffset - lastOffset;
        if (samples > left) {
            break;
        }
        switch (e->em_ctrlList->type) {
        case 13:
            {
                ALStartParamAlt *param = (ALStartParamAlt *)e->em_ctrlList;
                s32 tmp;

                if (param->unity) {
                    e->rs_upitch = 1;
                }
                func_800AF5A4(e, 5, (void *)param->wave);
                e->em_motion = 1;
                e->em_first = 1;
                e->em_delta = 0;
                e->em_segEnd = _n_timeToSamples(param->samples);
                tmp = ((s32)param->volume * (s32)param->volume) >> 15;
                e->em_volume = (s16)tmp;
                e->em_pan = param->pan;
                e->em_dryamt = D_800ECC40[param->fxMix];
                e->em_wetamt = D_800ECC40[127 - param->fxMix];
                if (param->samples) {
                    e->em_cvolL = 1;
                    e->em_cvolR = 1;
                } else {
                    e->em_cvolL = (e->em_volume * D_800ECC40[e->em_pan]) >> 15;
                    e->em_cvolR = (e->em_volume * D_800ECC40[127 - e->em_pan]) >> 15;
                }
                e->rs_ratio = param->pitch;
            }
            break;
        case 16:
        case 12:
        case 11:
            ptr = func_800AEDF0(e, &inp, &loutp, samples, ptr);
            if (e->em_delta >= e->em_segEnd || samples == 0) {
                e->em_ltgt = (e->em_volume * D_800ECC40[e->em_pan]) >> 15;
                e->em_rtgt = (e->em_volume * D_800ECC40[127 - e->em_pan]) >> 15;
                e->em_delta = e->em_segEnd;
                e->em_cvolL = e->em_ltgt;
                e->em_cvolR = e->em_rtgt;
            } else {
                e->em_cvolL = func_800AF118(e->em_cvolL, e->em_delta, e->em_lratm, e->em_lratl);
                e->em_cvolR = func_800AF118(e->em_cvolR, e->em_delta, e->em_rratm, e->em_rratl);
            }
            if (e->em_cvolL == 0) {
                e->em_cvolL = 1;
            }
            if (e->em_cvolR == 0) {
                e->em_cvolR = 1;
            }
            if (e->em_ctrlList->type == 12) {
                e->em_pan = (s16)e->em_ctrlList->data.i;
            }
            if (e->em_ctrlList->type == 11) {
                e->em_delta = 0;
                fVol = e->em_ctrlList->data.i;
                fVol = (fVol * fVol) >> 15;
                e->em_volume = (s16)fVol;
                e->em_segEnd = _n_timeToSamples(e->em_ctrlList->moredata.i);
            }
            if (e->em_ctrlList->type == 16) {
                e->em_dryamt = D_800ECC40[e->em_ctrlList->data.i];
                e->em_wetamt = D_800ECC40[127 - e->em_ctrlList->data.i];
            }
            e->em_first = 1;
            break;
        case 14:
            {
                ALStartParam *param = (ALStartParam *)e->em_ctrlList;

                if (param->unity) {
                    e->rs_upitch = 1;
                }
                func_800AF5A4(e, 5, (void *)param->wave);
                e->em_motion = 1;
            }
            break;
        case 15:
            ptr = func_800AEDF0(e, &inp, &loutp, samples, ptr);
            func_800AED54(e, 4, 0);
            break;
        case 0:
            {
                N_ALFreeParam *param = (N_ALFreeParam *)e->em_ctrlList;
                param->pvoice->offset = 0;
                func_800B02AC(param->pvoice);
            }
            break;
        case 7:
            ptr = func_800AEDF0(e, &inp, &loutp, samples, ptr);
            e->rs_ratio = e->em_ctrlList->data.f;
            break;
        case 8:
            ptr = func_800AEDF0(e, &inp, &loutp, samples, ptr);
            e->rs_upitch = 1;
            break;
        case 5:
            ptr = func_800AEDF0(e, &inp, &loutp, samples, ptr);
            func_800AF5A4(e, 5, (void *)e->em_ctrlList->data.i);
            break;
        default:
            ptr = func_800AEDF0(e, &inp, &loutp, samples, ptr);
            func_800AED54(e, e->em_ctrlList->type, (void *)e->em_ctrlList->data.i);
            break;
        }
        left -= samples;
        loutp += samples << 1;
        thisParam = e->em_ctrlList;
        e->em_ctrlList = e->em_ctrlList->next;
        if (e->em_ctrlList == 0) {
            e->em_ctrlTail = 0;
        }
        func_800B0234(thisParam);
    }
    ptr = func_800AEDF0(e, &inp, &loutp, left, ptr);
    if (e->em_delta > e->em_segEnd) {
        e->em_delta = e->em_segEnd;
    }
    return ptr;
}
