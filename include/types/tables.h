/* Global tables and records of the game, with the layouts the matched files agree on. Include after common.h.
 *
 * Every named field is backed by matched files (listed per field); names are unkXXX by offset. Element sizes are
 * checked (ASSERT_SIZE) and match every matched file that declares the array (counts in the comments). Where files
 * disagree on a field's width/signedness the majority is used and the comment names the others.
 *
 * Opt-outs: #define SKIP_D_xxxxxxxx before including to keep your own extern for that symbol (for example when a
 * file uses `extern u8 D_800D0FC0[]` byte indexing). Including this file emits no code or data.
 */
#ifndef TYPES_TABLES_H
#define TYPES_TABLES_H

#include "layout.h"

/* D_800D5C1C[]: 0x78-byte records, indexed by the current player/level number (29 files, all 0x78) */

typedef struct {
    s32 unk0;                        /* +0x0: func_8003FFF0, func_80041C14, func_80041D28 */
    s32 unk4;                        /* +0x4: func_8003FFF0, func_80041C14, func_80041D28 */
    u8 pad8[0xC - 0x8];
    s32 unkC;                        /* +0xC: 14 files (func_800361DC, func_80036FA4, func_80039E60, func_80080554, func_80081F94, ...) */
    s32 unk10;                       /* +0x10: func_800406F0, func_80040A18 */
    char * unk14;                    /* +0x14: string: func_80035720, func_80095068, func_800954C4 */
    u8 pad18[0x2A - 0x18];
    u16 unk2A;                       /* +0x2A: func_8003FFF0, func_800416F4 */
    u8 pad2C[0x2E - 0x2C];
    u16 unk2E;                       /* +0x2E: func_8003FFF0, func_800416F4 */
    u8 pad30[0x38 - 0x30];
    s32 unk38;                       /* +0x38: func_80045870, func_800459B8 */
    u8 pad3C[0x58 - 0x3C];
    s32 unk58[2];                    /* +0x58: func_800892D4 */
    s32 unk60;                       /* +0x60: func_80035720 */
    s32 unk64;                       /* +0x64: func_80077A60 */
    s32 unk68;                       /* +0x68: func_80077A60 */
    s32 unk6C;                       /* +0x6C: func_80077A60 */
    s16 unk70;                       /* +0x70: func_80077A60 */
    s16 unk72;                       /* +0x72: func_80077A60 */
    s16 unk74;                       /* +0x74: func_80077A60 */
    u8 pad76[0x78 - 0x76];
} Rec5C1C;
ASSERT_OFFSET(Rec5C1C, unk0, 0x0);
ASSERT_OFFSET(Rec5C1C, unk4, 0x4);
ASSERT_OFFSET(Rec5C1C, unkC, 0xC);
ASSERT_OFFSET(Rec5C1C, unk10, 0x10);
ASSERT_OFFSET(Rec5C1C, unk14, 0x14);
ASSERT_OFFSET(Rec5C1C, unk2A, 0x2A);
ASSERT_OFFSET(Rec5C1C, unk2E, 0x2E);
ASSERT_OFFSET(Rec5C1C, unk38, 0x38);
ASSERT_OFFSET(Rec5C1C, unk58, 0x58);
ASSERT_OFFSET(Rec5C1C, unk60, 0x60);
ASSERT_OFFSET(Rec5C1C, unk64, 0x64);
ASSERT_OFFSET(Rec5C1C, unk68, 0x68);
ASSERT_OFFSET(Rec5C1C, unk6C, 0x6C);
ASSERT_OFFSET(Rec5C1C, unk70, 0x70);
ASSERT_OFFSET(Rec5C1C, unk72, 0x72);
ASSERT_OFFSET(Rec5C1C, unk74, 0x74);
ASSERT_SIZE(Rec5C1C, 0x78);


/* D_800D4D80[]: 0x154-byte records (43 files; 42 declare 0x154-byte elements, one a 0x138-byte prefix) */

typedef struct {
    s32 unk0;                        /* +0x0: func_8003CD64 ("model" in func_800828A0; char * in func_80095068) */
    char * unk4;                     /* +0x4: func_80095068 */
    u8 pad8[0xC - 0x8];
    s32 unkC;                        /* +0xC: func_8004BE0C, func_8004C3D8, func_8004D398 */
    u8 unk10;                        /* +0x10: func_8004C774, func_8004C7CC */
    u8 unk11;                        /* +0x11: func_8004C774, func_8004C7CC */
    u8 unk12;                        /* +0x12: func_8004C774, func_8004C7CC */
    u8 unk13;                        /* +0x13: func_80028348, func_80095068 */
    s8 unk14;                        /* +0x14: func_80095068 */
    u8 pad15[0x18 - 0x15];
    s32 unk18[4];                    /* +0x18: func_8002F904, func_80032450, func_8003D674, ... */
    s32 unk28;                       /* +0x28: func_8002CF90 */
    char * unk2C;                    /* +0x2C: string: func_8002DA0C, func_8002EC80, func_80030428, ... (s32 in 3 files) */
    s32 unk30;                       /* +0x30: func_8003CFA0 (void *[6] in func_8002F220) */
    s32 unk34;                       /* +0x34: func_8003CFA0 */
    s32 unk38;                       /* +0x38: func_8003CFA0 */
    s32 unk3C;                       /* +0x3C: func_8003CFA0 */
    u8 unk40[0x114];                 /* +0x40: sub-records; files disagree on their stride/start (8 x at +0x40, 8 x at +0x54, 7 x at +0x56/+0x58/+0x5C/+0x60): see func_80032C0C, func_8003E2E0, func_8003D674 */
} Rec4D80;
ASSERT_OFFSET(Rec4D80, unk0, 0x0);
ASSERT_OFFSET(Rec4D80, unk4, 0x4);
ASSERT_OFFSET(Rec4D80, unkC, 0xC);
ASSERT_OFFSET(Rec4D80, unk10, 0x10);
ASSERT_OFFSET(Rec4D80, unk11, 0x11);
ASSERT_OFFSET(Rec4D80, unk12, 0x12);
ASSERT_OFFSET(Rec4D80, unk13, 0x13);
ASSERT_OFFSET(Rec4D80, unk14, 0x14);
ASSERT_OFFSET(Rec4D80, unk18, 0x18);
ASSERT_OFFSET(Rec4D80, unk28, 0x28);
ASSERT_OFFSET(Rec4D80, unk2C, 0x2C);
ASSERT_OFFSET(Rec4D80, unk30, 0x30);
ASSERT_OFFSET(Rec4D80, unk34, 0x34);
ASSERT_OFFSET(Rec4D80, unk38, 0x38);
ASSERT_OFFSET(Rec4D80, unk3C, 0x3C);
ASSERT_OFFSET(Rec4D80, unk40, 0x40);
ASSERT_SIZE(Rec4D80, 0x154);


/* D_800DAF98[]: 0x48-byte records (27 files, all 0x48) */

typedef struct {
    u8 unk0;                         /* +0x0: func_80061F60 (s8), func_80062548, func_80062A90 */
    u8 pad1[0x12 - 0x1];
    u8 unk12;                        /* +0x12: func_80048438, func_80061F60 (s8), func_80062548, ... */
    u8 unk13;                        /* +0x13: func_80061F60 (s8), func_80062548, func_800630C0, ... */
    s32 * unk14;                     /* +0x14: func_800635E4, func_80063654 */
    s32 * unk18;                     /* +0x18: func_80061F60, func_80062548, func_800633C4, ... */
    void * unk1C;                    /* +0x1C: func_8004DED8, func_8005E500, func_80061F60, ... */
    u8 * unk20;                      /* +0x20: func_8004A204, func_8004AE2C, func_8005DE04, ... (s32 in 2) */
    s32 unk24;                       /* +0x24: func_80061F60 */
    s32 unk28;                       /* +0x28: func_8005DEBC, func_80061F60, func_80062548 */
    u32 * unk2C;                     /* +0x2C: func_8004BBD4 */
    s32 unk30;                       /* +0x30: func_80061F60, func_80062548 */
    s32 unk34;                       /* +0x34: func_80061F60, func_80062548 */
    u16 unk38;                       /* +0x38: func_8005CDF0, func_8005DE04 */
    s8 unk3A;                        /* +0x3A: func_8005E500 */
    s8 unk3B;                        /* +0x3B: func_80061F60, func_80062548 (u8) */
    u8 unk3C;                        /* +0x3C: func_80061F60, func_80062548, func_80062A90 (s8) */
    u8 pad3D[0x48 - 0x3D];
} RecAF98;
ASSERT_OFFSET(RecAF98, unk0, 0x0);
ASSERT_OFFSET(RecAF98, unk12, 0x12);
ASSERT_OFFSET(RecAF98, unk13, 0x13);
ASSERT_OFFSET(RecAF98, unk14, 0x14);
ASSERT_OFFSET(RecAF98, unk18, 0x18);
ASSERT_OFFSET(RecAF98, unk1C, 0x1C);
ASSERT_OFFSET(RecAF98, unk20, 0x20);
ASSERT_OFFSET(RecAF98, unk24, 0x24);
ASSERT_OFFSET(RecAF98, unk28, 0x28);
ASSERT_OFFSET(RecAF98, unk2C, 0x2C);
ASSERT_OFFSET(RecAF98, unk30, 0x30);
ASSERT_OFFSET(RecAF98, unk34, 0x34);
ASSERT_OFFSET(RecAF98, unk38, 0x38);
ASSERT_OFFSET(RecAF98, unk3A, 0x3A);
ASSERT_OFFSET(RecAF98, unk3B, 0x3B);
ASSERT_OFFSET(RecAF98, unk3C, 0x3C);
ASSERT_SIZE(RecAF98, 0x48);


/* D_800FC580[]: 0x1C bytes per controller port, filled next to the controller reads in func_800B3D14
 * (14 files, all 0x1C) */

typedef struct {
    u8 unk0;                         /* +0x0: func_800B3CF0, func_800B3D14, func_800B411C (f32 unk0 in 2 files) */
    u8 unk1;                         /* +0x1: func_800B3CF0, func_800B3D14, func_800B411C */
    u8 pad2[0x4 - 0x2];
    f32 unk4;                        /* +0x4: func_800B4200, func_800B43B0, ... (s32 in func_800B3D14) */
    f32 unk8;                        /* +0x8: func_800B4200, func_800B43B0, ... (s32 in func_800B3D14) */
    u16 unkC;                        /* +0xC: func_800B3D14, func_800B4240, func_800B4264, ... */
    u16 unkE;                        /* +0xE: func_800B3D14, func_800B4264, func_800B42A8, ... */
    f32 unk10;                       /* +0x10: func_800B4380, func_800B43B0 (s32 in 2) */
    f32 unk14;                       /* +0x14: func_800B42EC, func_800B43F0, ... */
    f32 unk18;                       /* +0x18: func_800B42EC, func_800B43F0, ... */
} RecC580;
ASSERT_OFFSET(RecC580, unk0, 0x0);
ASSERT_OFFSET(RecC580, unk1, 0x1);
ASSERT_OFFSET(RecC580, unk4, 0x4);
ASSERT_OFFSET(RecC580, unk8, 0x8);
ASSERT_OFFSET(RecC580, unkC, 0xC);
ASSERT_OFFSET(RecC580, unkE, 0xE);
ASSERT_OFFSET(RecC580, unk10, 0x10);
ASSERT_OFFSET(RecC580, unk14, 0x14);
ASSERT_OFFSET(RecC580, unk18, 0x18);
ASSERT_SIZE(RecC580, 0x1C);


/* D_800FC380[]: 0x80 bytes per controller port (6 files, all 0x80) */

typedef struct {
    u16 unk0;                        /* +0x0: func_800B3260 (s32 in func_800B345C) */
    u8 unk2;                         /* +0x2: func_800B3260 */
    u8 pad3[0x4 - 0x3];
    u8 unk4[0x68];                   /* +0x4: passed to the 0x68-byte controller-pak routines: func_800B3130, func_800B3420, func_800B345C */
    s16 unk6C;                       /* +0x6C: func_800B3130, func_800B3260, func_800B3420, ... (u16 in 1) */
    u8 unk6E;                        /* +0x6E: func_800B3130, func_800B3260 */
    u8 pad6F[0x70 - 0x6F];
    f32 unk70;                       /* +0x70: func_800B3130, func_800B34DC, func_800B379C */
    f32 unk74;                       /* +0x74: func_800B3130, func_800B34DC, func_800B379C */
    u8 unk78;                        /* +0x78: func_800B3130, func_800B34DC */
    u8 pad79[0x7C - 0x79];
    f32 unk7C;                       /* +0x7C: func_800B3130, func_800B34DC */
} RecC380;
ASSERT_OFFSET(RecC380, unk0, 0x0);
ASSERT_OFFSET(RecC380, unk2, 0x2);
ASSERT_OFFSET(RecC380, unk4, 0x4);
ASSERT_OFFSET(RecC380, unk6C, 0x6C);
ASSERT_OFFSET(RecC380, unk6E, 0x6E);
ASSERT_OFFSET(RecC380, unk70, 0x70);
ASSERT_OFFSET(RecC380, unk74, 0x74);
ASSERT_OFFSET(RecC380, unk78, 0x78);
ASSERT_OFFSET(RecC380, unk7C, 0x7C);
ASSERT_SIZE(RecC380, 0x80);


/* D_800DCAB4[]: 0x24-byte records (7 files, all 0x24) */

typedef struct {
    u8 pad0[0x10 - 0x0];
    s32 unk10;                       /* +0x10: count: func_8006DCC4, func_8006E590 */
    void * unk14;                    /* +0x14: items of 0x24 bytes: func_8006DA28, func_8006E590, func_8006EB50 */
    u8 unk18;                        /* +0x18: func_8006EA58 */
    u8 pad19[0x1A - 0x19];
    u16 unk1A;                       /* +0x1A: func_8006DA28, func_8006E9CC, func_8006EA0C (s16 in 1) */
    u8 pad1C[0x24 - 0x1C];
} RecCAB4;
ASSERT_OFFSET(RecCAB4, unk10, 0x10);
ASSERT_OFFSET(RecCAB4, unk14, 0x14);
ASSERT_OFFSET(RecCAB4, unk18, 0x18);
ASSERT_OFFSET(RecCAB4, unk1A, 0x1A);
ASSERT_SIZE(RecCAB4, 0x24);


/* D_800D63F8[]: 0x2C-byte records (4 files, all 0x2C) */

typedef struct {
    s32 unk0[3];                     /* +0x0: func_8002EFA0, func_8003CD64, func_8004EF10 (whole record copied as s32[11] in 2) */
    s32 unkC;                        /* +0xC: func_8004F030 */
    s32 unk10;                       /* +0x10: func_8004F030 */
    s32 unk14[2];                    /* +0x14: func_8004F030 */
    s32 unk1C;                       /* +0x1C: func_8004EF10, func_8004F030 */
    s32 unk20[3];                    /* +0x20: func_8004EF10, func_8004F030 */
} Rec63F8;
ASSERT_OFFSET(Rec63F8, unk0, 0x0);
ASSERT_OFFSET(Rec63F8, unkC, 0xC);
ASSERT_OFFSET(Rec63F8, unk10, 0x10);
ASSERT_OFFSET(Rec63F8, unk14, 0x14);
ASSERT_OFFSET(Rec63F8, unk1C, 0x1C);
ASSERT_OFFSET(Rec63F8, unk20, 0x20);
ASSERT_SIZE(Rec63F8, 0x2C);


/* D_800D0FC0: game-wide state block (67 files; most index it as u8[]). Its bytes are also referenced as their
 * own symbols (D_800D0FC2, D_800D0FD6, D_800D0FE3, D_800D0FEC, ...): the relocation is masked, either form
 * builds the same word. Size not known (> 0xED0). */

typedef struct {
    u8 unk0;                         /* +0x0: func_800242CC, func_8002C660, func_8003B578 */
    u8 unk1;                         /* +0x1: func_800242CC, func_8002C660, func_8003BA00 */
    u8 unk2;                         /* +0x2: 30+ files (also its own symbol D_800D0FC2, 10 files) */
    u8 unk3;                         /* +0x3: 15+ files (D_800D0FC3) */
    u8 unk4;                         /* +0x4: func_80023430 (D_800D0FC4) */
    u8 pad5[0x8 - 0x5];
    s32 unk8;                        /* +0x8: func_8003E6E0 */
    s32 unkC;                        /* +0xC: func_8003E6E0 (D_800D0FCC, 4 files) */
    s32 unk10;                       /* +0x10: func_80023430, func_80023818, func_80029DFC */
    u8 unk14;                        /* +0x14: 20+ files (D_800D0FD4) */
    u8 unk15;                        /* +0x15: func_8002F220, func_800305C8, func_80035720, ... */
    u8 unk16;                        /* +0x16: 20+ files (D_800D0FD6; s8 in 3) */
    u8 pad17[0x18 - 0x17];
    u16 unk18;                       /* +0x18: D_800D0FD8 u16 in 4 files, s16 in 5 */
    u8 unk1A;                        /* +0x1A: func_8008BB60 */
    u8 unk1B;                        /* +0x1B: func_80023430, func_80030EA4, func_8003E2E0, ... */
    u8 unk1C;                        /* +0x1C: func_80023430, func_80030EA4, func_8003E2E0, ... */
    u8 unk1D;                        /* +0x1D: func_80023430, func_80030EA4, func_8003E2E0, ... */
    u8 unk1E;                        /* +0x1E: func_80030EA4 */
    u8 unk1F;                        /* +0x1F: func_80030EA4 */
    u8 unk20;                        /* +0x20: func_80030EA4 */
    u8 pad21[0x23 - 0x21];
    u8 unk23;                        /* +0x23: D_800D0FE3 (u8 in 7 files, s8 in 2) */
    u8 unk24[2];                     /* +0x24: func_800242CC */
    u8 unk26[2];                     /* +0x26: func_800242CC, func_80043630 */
    u8 unk28;                        /* +0x28: func_80035B88 (D_800D0FE8) */
    u8 unk29;                        /* +0x29: D_800D0FE9 */
    u8 pad2A[0x2C - 0x2A];
    f32 unk2C;                       /* +0x2C: func_80029024, func_80039D2C, func_8003A6CC, ... (D_800D0FEC, 4 files) */
    f32 unk30;                       /* +0x30: func_80029024, func_8003A6CC, ... (s32 in func_80039D2C) */
    f32 unk34;                       /* +0x34: func_80023818 */
    u8 pad38[0xEBC - 0x38];
    s32 unkEBC;                      /* +0xEBC: func_80036FA4 */
    s32 unkEC0;                      /* +0xEC0: func_80035720 */
    u8 padEC4[0xEC8 - 0xEC4];
    s32 unkEC8;                      /* +0xEC8: func_80035D08 */
    void * unkECC;                   /* +0xECC: func_80023430, func_80035D08, func_80042068 */
} State0FC0;
ASSERT_OFFSET(State0FC0, unk0, 0x0);
ASSERT_OFFSET(State0FC0, unk1, 0x1);
ASSERT_OFFSET(State0FC0, unk2, 0x2);
ASSERT_OFFSET(State0FC0, unk3, 0x3);
ASSERT_OFFSET(State0FC0, unk4, 0x4);
ASSERT_OFFSET(State0FC0, unk8, 0x8);
ASSERT_OFFSET(State0FC0, unkC, 0xC);
ASSERT_OFFSET(State0FC0, unk10, 0x10);
ASSERT_OFFSET(State0FC0, unk14, 0x14);
ASSERT_OFFSET(State0FC0, unk15, 0x15);
ASSERT_OFFSET(State0FC0, unk16, 0x16);
ASSERT_OFFSET(State0FC0, unk18, 0x18);
ASSERT_OFFSET(State0FC0, unk1A, 0x1A);
ASSERT_OFFSET(State0FC0, unk1B, 0x1B);
ASSERT_OFFSET(State0FC0, unk1C, 0x1C);
ASSERT_OFFSET(State0FC0, unk1D, 0x1D);
ASSERT_OFFSET(State0FC0, unk1E, 0x1E);
ASSERT_OFFSET(State0FC0, unk1F, 0x1F);
ASSERT_OFFSET(State0FC0, unk20, 0x20);
ASSERT_OFFSET(State0FC0, unk23, 0x23);
ASSERT_OFFSET(State0FC0, unk24, 0x24);
ASSERT_OFFSET(State0FC0, unk26, 0x26);
ASSERT_OFFSET(State0FC0, unk28, 0x28);
ASSERT_OFFSET(State0FC0, unk29, 0x29);
ASSERT_OFFSET(State0FC0, unk2C, 0x2C);
ASSERT_OFFSET(State0FC0, unk30, 0x30);
ASSERT_OFFSET(State0FC0, unk34, 0x34);
ASSERT_OFFSET(State0FC0, unkEBC, 0xEBC);
ASSERT_OFFSET(State0FC0, unkEC0, 0xEC0);
ASSERT_OFFSET(State0FC0, unkEC8, 0xEC8);
ASSERT_OFFSET(State0FC0, unkECC, 0xECC);


/* D_800DC618 and D_800DC6D8: two 0xC0-byte blocks with the same layout (12 + 9 files; func_8006AB44 types
 * both). The size is the distance between them; nothing above +0xBC is accessed. */

typedef struct {
    s32 unk0;                        /* +0x0: func_800361DC, func_80044F78, func_8006A854, ... */
    u8 * unk4;                       /* +0x4: func_800361DC, func_8006AB44, func_8006D120 */
    u8 * unk8;                       /* +0x8: func_8006AB44, func_8006D120 */
    s32 unkC;                        /* +0xC: func_8006AB44 */
    s32 * unk10;                     /* +0x10: func_8006AB44, func_8006C7D4, func_8006CDAC */
    s32 unk14;                       /* +0x14: func_8006AB44, func_8006C7D4, func_8006CDAC */
    s32 unk18;                       /* +0x18: func_8006AB44, func_8006C7D4, func_8006CDAC */
    s32 unk1C;                       /* +0x1C: func_80044F78, func_8006A538, func_8006A6AC (u32 in 2) */
    s32 unk20;                       /* +0x20: func_80044F78, func_8006AB44, func_8006C7D4 */
    s32 unk24;                       /* +0x24: func_8006AB44 */
    s32 unk28[4];                    /* +0x28: func_8006AB44 */
    s32 unk38;                       /* +0x38: func_8006AB44 */
    s32 unk3C;                       /* +0x3C: func_8006AB44 */
    s32 unk40;                       /* +0x40: func_8006AB44 */
    s32 unk44;                       /* +0x44: func_8006AB44 */
    s32 unk48;                       /* +0x48: func_8006AB44 */
    s32 unk4C;                       /* +0x4C: func_800361DC, func_80044F78, func_8006AB44, func_8006C7D4 */
    u8 unk50[0x34];                  /* +0x50: 5 small records, stride differs per file (func_8006A538, func_8006AB44, func_8006C7D4) */
    s16 unk84;                       /* +0x84: func_8006AB44, func_8006C7D4 */
    s16 unk86;                       /* +0x86: func_8006AB44, func_8006C7D4 */
    s16 unk88;                       /* +0x88: func_8006AB44, func_8006C7D4 */
    s16 unk8A;                       /* +0x8A: func_8006AB44 */
    s16 unk8C;                       /* +0x8C: func_8006AB44 */
    s16 unk8E;                       /* +0x8E: func_8006AB44 */
    s16 unk90;                       /* +0x90: func_8006AB44 */
    s16 unk92;                       /* +0x92: func_8006AB44 */
    s32 unk94;                       /* +0x94: func_8006AB44 */
    s32 unk98;                       /* +0x98: func_8006AB44 */
    s32 unk9C;                       /* +0x9C: func_8006AB44 */
    s32 unkA0;                       /* +0xA0: func_8006AB44 */
    s32 unkA4;                       /* +0xA4: func_8006AB44 */
    s32 unkA8;                       /* +0xA8: func_8006AB44 */
    s32 unkAC;                       /* +0xAC: func_8006AB44 */
    s32 unkB0;                       /* +0xB0: func_8006AB44 */
    s32 unkB4;                       /* +0xB4: func_8006AB44 */
    s32 unkB8;                       /* +0xB8: func_8006AB44 */
    s32 unkBC;                       /* +0xBC: func_8006AB44, func_8006CD84 */
} BlkC0;
ASSERT_OFFSET(BlkC0, unk0, 0x0);
ASSERT_OFFSET(BlkC0, unk4, 0x4);
ASSERT_OFFSET(BlkC0, unk8, 0x8);
ASSERT_OFFSET(BlkC0, unkC, 0xC);
ASSERT_OFFSET(BlkC0, unk10, 0x10);
ASSERT_OFFSET(BlkC0, unk14, 0x14);
ASSERT_OFFSET(BlkC0, unk18, 0x18);
ASSERT_OFFSET(BlkC0, unk1C, 0x1C);
ASSERT_OFFSET(BlkC0, unk20, 0x20);
ASSERT_OFFSET(BlkC0, unk24, 0x24);
ASSERT_OFFSET(BlkC0, unk28, 0x28);
ASSERT_OFFSET(BlkC0, unk38, 0x38);
ASSERT_OFFSET(BlkC0, unk3C, 0x3C);
ASSERT_OFFSET(BlkC0, unk40, 0x40);
ASSERT_OFFSET(BlkC0, unk44, 0x44);
ASSERT_OFFSET(BlkC0, unk48, 0x48);
ASSERT_OFFSET(BlkC0, unk4C, 0x4C);
ASSERT_OFFSET(BlkC0, unk50, 0x50);
ASSERT_OFFSET(BlkC0, unk84, 0x84);
ASSERT_OFFSET(BlkC0, unk86, 0x86);
ASSERT_OFFSET(BlkC0, unk88, 0x88);
ASSERT_OFFSET(BlkC0, unk8A, 0x8A);
ASSERT_OFFSET(BlkC0, unk8C, 0x8C);
ASSERT_OFFSET(BlkC0, unk8E, 0x8E);
ASSERT_OFFSET(BlkC0, unk90, 0x90);
ASSERT_OFFSET(BlkC0, unk92, 0x92);
ASSERT_OFFSET(BlkC0, unk94, 0x94);
ASSERT_OFFSET(BlkC0, unk98, 0x98);
ASSERT_OFFSET(BlkC0, unk9C, 0x9C);
ASSERT_OFFSET(BlkC0, unkA0, 0xA0);
ASSERT_OFFSET(BlkC0, unkA4, 0xA4);
ASSERT_OFFSET(BlkC0, unkA8, 0xA8);
ASSERT_OFFSET(BlkC0, unkAC, 0xAC);
ASSERT_OFFSET(BlkC0, unkB0, 0xB0);
ASSERT_OFFSET(BlkC0, unkB4, 0xB4);
ASSERT_OFFSET(BlkC0, unkB8, 0xB8);
ASSERT_OFFSET(BlkC0, unkBC, 0xBC);
ASSERT_SIZE(BlkC0, 0xC0);


#ifndef SKIP_D_800D5C1C
extern Rec5C1C D_800D5C1C[];
#endif
#ifndef SKIP_D_800D4D80
extern Rec4D80 D_800D4D80[];
#endif
#ifndef SKIP_D_800DAF98
extern RecAF98 D_800DAF98[];
#endif
#ifndef SKIP_D_800FC580
extern RecC580 D_800FC580[];
#endif
#ifndef SKIP_D_800FC380
extern RecC380 D_800FC380[];
#endif
#ifndef SKIP_D_800DCAB4
extern RecCAB4 D_800DCAB4[];
#endif
#ifndef SKIP_D_800D63F8
extern Rec63F8 D_800D63F8[];
#endif
#ifndef SKIP_D_800D0FC0
extern State0FC0 D_800D0FC0;
#endif
#ifndef SKIP_D_800DC618
extern BlkC0 D_800DC618;
#endif
#ifndef SKIP_D_800DC6D8
extern BlkC0 D_800DC6D8;
#endif


#endif
