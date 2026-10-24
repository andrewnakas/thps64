/* Audio: the sound/sequence track records behind *D_800FC2F8 and the synthesis driver behind *D_800ECC34.
 * Include after common.h. Field evidence per field; unkXXX by offset, quoted words are single files' names.
 * For libultra n_al* functions themselves, follow the libultra source shapes (AGENT_BRIEF); these structs are the
 * game's variant (64-bit sample counters at +0x28/+0x30), not the stock N_ALSynth.
 * Opt-outs: #define SKIP_D_800FC2F8 / SKIP_D_800ECC34 before including. Emits no code or data.
 */
#ifndef TYPES_AUDIO_H
#define TYPES_AUDIO_H

#include "layout.h"

/* *D_800FC2F8: sound/sequence track records, 0x130 bytes (19 files; size from func_800AC8BC "Track",
 * "Ent130" in 3 files) */

typedef struct {
    s32 unk0;                        /* +0x0: "flags" in 6 files: func_800ABCDC, func_800ABE14, func_800ABEC4, ... */
    s32 unk4;                        /* +0x4: func_800AB78C, func_800ABCDC, func_800ABDA0, ... (u8 * in 1) */
    s32 unk8;                        /* +0x8: func_800AC8BC */
    u32 unkC;                        /* +0xC: func_800AB78C, func_800AC8BC ("time") */
    s32 unk10;                       /* +0x10: func_800ABCDC, func_800ABE14, func_800AC8BC */
    u32 unk14;                       /* +0x14: func_800AC8BC */
    u32 unk18;                       /* +0x18: func_800AC8BC */
    s32 unk1C;                       /* +0x1C: func_800ABCDC, func_800ABE14 */
    u8 pad20[0x30 - 0x20];
    f32 unk30;                       /* +0x30: func_800AC8BC ("vol"); a sub-struct starts here in func_800AC0CC */
    s32 unk34;                       /* +0x34: func_800AB78C, func_800AC8BC, func_800AE1A0 */
    s32 unk38;                       /* +0x38: func_800AB78C, func_800AC8BC, func_800AE1A0 */
    u32 unk3C;                       /* +0x3C: func_800AB78C, func_800AC8BC */
    s32 unk40;                       /* +0x40: func_800AB78C, func_800AC8BC */
    s32 unk44;                       /* +0x44: 12 files ("id" in 5): func_800AB2EC, func_800AB78C, func_800ABE14, ... */
    s32 unk48;                       /* +0x48: func_800AC8BC, func_800ADCF0 */
    u8 pad4C[0x74 - 0x4C];
    void * unk74;                    /* +0x74: owner: func_800AAC08, func_800AB78C, func_800AC4A0, func_800ADCF0 */
    s32 unk78;                       /* +0x78: func_800ABCDC, func_800ABDA0, func_800AC4A0 (pointer in 2) */
    s32 unk7C;                       /* +0x7C: func_800AB2EC */
    s32 unk80;                       /* +0x80: func_800ADCF0, func_800AE1A0 */
    u8 pad84[0x88 - 0x84];
    s32 unk88;                       /* +0x88: func_800AE1A0 */
    s32 unk8C;                       /* +0x8C: func_800AE1A0 */
    u8 pad90[0x94 - 0x90];
    u32 unk94;                       /* +0x94: func_800AC8BC */
    s16 unk98;                       /* +0x98: func_800AC130 */
    u16 unk9A;                       /* +0x9A: func_800AB78C, func_800AC8BC */
    s16 unk9C;                       /* +0x9C: func_800AAC08, func_800AC130 (u16 "tempo" in func_800AC8BC) */
    s16 unk9E;                       /* +0x9E: func_800ABFC4 */
    u8 padA0[0xA8 - 0xA0];
    s16 unkA8;                       /* +0xA8: func_800AAC08, func_800AC130 */
    s16 unkAA;                       /* +0xAA: func_800AB78C, func_800AC8BC */
    u16 unkAC;                       /* +0xAC: func_800AB78C */
    u8 padAE[0xB0 - 0xAE];
    s16 unkB0;                       /* +0xB0: func_800AC01C */
    u8 padB2[0xB7 - 0xB2];
    u8 unkB7;                        /* +0xB7: func_800AB78C */
    u8 padB8[0xBB - 0xB8];
    u8 unkBB;                        /* +0xBB: func_800AB78C */
    u8 padBC[0xBE - 0xBC];
    u8 unkBE;                        /* +0xBE: func_800AC01C */
    u8 padBF[0xC3 - 0xBF];
    u8 unkC3;                        /* +0xC3: func_800AC8BC */
    u8 padC4[0xC9 - 0xC4];
    u8 unkC9;                        /* +0xC9: func_800AB48C, func_800AC8BC */
    u8 padCA[0xCB - 0xCA];
    u8 unkCB;                        /* +0xCB: func_800AC1B8 */
    u8 unkCC;                        /* +0xCC: func_800AC1B8 */
    u8 padCD[0xCE - 0xCD];
    u8 unkCE;                        /* +0xCE: func_800AC8BC */
    u8 padCF[0xD2 - 0xCF];
    u8 unkD2;                        /* +0xD2: func_800AB78C, func_800AE1A0 */
    u8 unkD3;                        /* +0xD3: func_800AB78C */
    u8 unkD4;                        /* +0xD4: func_800AC8BC */
    u8 unkD5;                        /* +0xD5: func_800AC8BC */
    u8 padD6[0x130 - 0xD6];
} SndTrack;
ASSERT_OFFSET(SndTrack, unk0, 0x0);
ASSERT_OFFSET(SndTrack, unk4, 0x4);
ASSERT_OFFSET(SndTrack, unk8, 0x8);
ASSERT_OFFSET(SndTrack, unkC, 0xC);
ASSERT_OFFSET(SndTrack, unk10, 0x10);
ASSERT_OFFSET(SndTrack, unk14, 0x14);
ASSERT_OFFSET(SndTrack, unk18, 0x18);
ASSERT_OFFSET(SndTrack, unk1C, 0x1C);
ASSERT_OFFSET(SndTrack, unk30, 0x30);
ASSERT_OFFSET(SndTrack, unk34, 0x34);
ASSERT_OFFSET(SndTrack, unk38, 0x38);
ASSERT_OFFSET(SndTrack, unk3C, 0x3C);
ASSERT_OFFSET(SndTrack, unk40, 0x40);
ASSERT_OFFSET(SndTrack, unk44, 0x44);
ASSERT_OFFSET(SndTrack, unk48, 0x48);
ASSERT_OFFSET(SndTrack, unk74, 0x74);
ASSERT_OFFSET(SndTrack, unk78, 0x78);
ASSERT_OFFSET(SndTrack, unk7C, 0x7C);
ASSERT_OFFSET(SndTrack, unk80, 0x80);
ASSERT_OFFSET(SndTrack, unk88, 0x88);
ASSERT_OFFSET(SndTrack, unk8C, 0x8C);
ASSERT_OFFSET(SndTrack, unk94, 0x94);
ASSERT_OFFSET(SndTrack, unk98, 0x98);
ASSERT_OFFSET(SndTrack, unk9A, 0x9A);
ASSERT_OFFSET(SndTrack, unk9C, 0x9C);
ASSERT_OFFSET(SndTrack, unk9E, 0x9E);
ASSERT_OFFSET(SndTrack, unkA8, 0xA8);
ASSERT_OFFSET(SndTrack, unkAA, 0xAA);
ASSERT_OFFSET(SndTrack, unkAC, 0xAC);
ASSERT_OFFSET(SndTrack, unkB0, 0xB0);
ASSERT_OFFSET(SndTrack, unkB7, 0xB7);
ASSERT_OFFSET(SndTrack, unkBB, 0xBB);
ASSERT_OFFSET(SndTrack, unkBE, 0xBE);
ASSERT_OFFSET(SndTrack, unkC3, 0xC3);
ASSERT_OFFSET(SndTrack, unkC9, 0xC9);
ASSERT_OFFSET(SndTrack, unkCB, 0xCB);
ASSERT_OFFSET(SndTrack, unkCC, 0xCC);
ASSERT_OFFSET(SndTrack, unkCE, 0xCE);
ASSERT_OFFSET(SndTrack, unkD2, 0xD2);
ASSERT_OFFSET(SndTrack, unkD3, 0xD3);
ASSERT_OFFSET(SndTrack, unkD4, 0xD4);
ASSERT_OFFSET(SndTrack, unkD5, 0xD5);
ASSERT_SIZE(SndTrack, 0x130);


/* *D_800ECC34: the synthesis driver (23 files; complete to +0x64 in func_800AFD80 "Drv"; total size not known) */

typedef struct {
    void * unk0;                     /* +0x0: list head: func_800AE49C, func_800AFD80, func_800B0000, ... */
    s32 unk4;                        /* +0x4: func_800AFD80, func_800B0354, func_800B04B0 (pointer in 2) */
    s32 unk8;                        /* +0x8: func_800AFD80, func_800B0354, func_800B04B0 (pointer in 2) */
    s32 unkC;                        /* +0xC: func_800AFD80, func_800B0354, func_800B04B0 (pointer in 2) */
    s32 unk10[2];                    /* +0x10: func_800AFD80 */
    s32 unk18[2];                    /* +0x18: func_800AFD80 */
    s32 unk20[2];                    /* +0x20: func_800AFD80 (s32 at +0x20 cast in func_800B024C) */
    s64 unk28;                       /* +0x28: func_800AFD80, func_800B0000 ("paramSamples"); s32 at +0x2C read in 4 files ("Clock") */
    s64 unk30;                       /* +0x30: func_800AFD80, func_800B0000, func_800B0354 ("curSamples") */
    s32 unk38;                       /* +0x38: func_800AFD80 */
    void * unk3C;                    /* +0x3C: heap: func_800AFD80 */
    void * unk40;                    /* +0x40: free list: func_800AFD80 (s32 cast in func_800B0208, func_800B0234) */
    void * unk44;                    /* +0x44: func_800AFD80 */
    void * unk48;                    /* +0x48: func_800AFD80, func_800B0600 */
    s32 unk4C;                       /* +0x4C: func_800AFD80 */
    u8 pad50[0x54 - 0x50];
    s32 unk54;                       /* +0x54: func_800AFD80, func_800B02E4 */
    s32 unk58;                       /* +0x58: func_800AFD80, func_800B0000 ("maxOutSamples") */
    s32 * unk5C;                     /* +0x5C: func_800AFD80, func_800B0000 ("outBuf"); u32 cast in func_800B1590 */
    s32 unk60;                       /* +0x60: func_800AFD80 */
} AudioSynth;
ASSERT_OFFSET(AudioSynth, unk0, 0x0);
ASSERT_OFFSET(AudioSynth, unk4, 0x4);
ASSERT_OFFSET(AudioSynth, unk8, 0x8);
ASSERT_OFFSET(AudioSynth, unkC, 0xC);
ASSERT_OFFSET(AudioSynth, unk10, 0x10);
ASSERT_OFFSET(AudioSynth, unk18, 0x18);
ASSERT_OFFSET(AudioSynth, unk20, 0x20);
ASSERT_OFFSET(AudioSynth, unk28, 0x28);
ASSERT_OFFSET(AudioSynth, unk30, 0x30);
ASSERT_OFFSET(AudioSynth, unk38, 0x38);
ASSERT_OFFSET(AudioSynth, unk3C, 0x3C);
ASSERT_OFFSET(AudioSynth, unk40, 0x40);
ASSERT_OFFSET(AudioSynth, unk44, 0x44);
ASSERT_OFFSET(AudioSynth, unk48, 0x48);
ASSERT_OFFSET(AudioSynth, unk4C, 0x4C);
ASSERT_OFFSET(AudioSynth, unk54, 0x54);
ASSERT_OFFSET(AudioSynth, unk58, 0x58);
ASSERT_OFFSET(AudioSynth, unk5C, 0x5C);
ASSERT_OFFSET(AudioSynth, unk60, 0x60);


#ifndef SKIP_D_800FC2F8
extern SndTrack *D_800FC2F8;
#endif
#ifndef SKIP_D_800ECC34
extern AudioSynth *D_800ECC34;
#endif


#endif
