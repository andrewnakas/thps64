/* Game objects: the g++ vtable entry, the linked game object (D_800D6180 / D_800D61A8 lists), the skater
 * (D_800DE7A8 / D_800DE7AC) and the menu object of the 0x800A0xxx functions. Include after common.h.
 *
 * Every named field is backed by matched files (listed per field). Fields are unkXXX by offset; the quoted words
 * are what single files called them, kept as hints only. Where files disagree on width/signedness the majority is
 * used and the comment names the others: cast at the use site if your function needs the other one
 * (`(s16)o->unk21E`), or keep a private struct.
 *
 * Why a struct instead of `*(s32 *)((u8 *)p + 0x434)`: GCC 2.8 assumes struct fields and globals such as
 * D_800F36A4 do not alias, so stores/loads schedule like the game (see AGENT_BRIEF "Scheduling around global
 * stores"). Layout is checked at compile time (ASSERT_OFFSET); including this file emits no code or data.
 *
 * Opt-outs: #define SKIP_D_800DE7A8 (etc.) before including to keep your own extern for that symbol.
 */
#ifndef TYPES_OBJECT_H
#define TYPES_OBJECT_H

#include "layout.h"
#include "vecmath.h"

/* g++ 2.x vtable entry (8 bytes): this-adjust, index, function. Seen as VtEntry/VEnt/VTbl in 15+ files
 * (func_800358F8, func_80033A58, func_800A0760, func_800B398C, ...). fn is unprototyped so any argument list
 * passes; float arguments would be promoted to double then: declare a typed entry for those. */
typedef struct {
    s16 delta;
    s16 index;
    void (*fn)();
} VtEntry;
ASSERT_SIZE(VtEntry, 8);

/* exact form from func_800A0760 / func_800B398C: call virtual slot i of o (o->vt points at the entry array) */
#define VCALL(o, i) ((o)->vt[i].fn((u8 *)(o) + (o)->vt[i].delta))

/* list object: head pointers D_800D6180 / D_800D61A8 (9 + 11 files), link at +0x1C. Size not known. */

typedef struct Obj {
    u16 unk0;                        /* +0x0: flags-like; s32 in func_800654C8/func_800704C4 */
    u8 pad2[0x4 - 0x2];
    Vec3i unk4;                      /* +0x4: position (x.12): func_80048438, func_800654C8, func_800704C4 */
    u8 pad10[0x1B - 0x10];
    u8 unk1B;                        /* +0x1B: func_80048438 */
    struct Obj * next;               /* +0x1C: list link: func_80047F00, func_800480B4, func_80048438, func_800654C8, func_8008AF70 */
    u8 pad20[0x48 - 0x20];
    VtEntry * vt;                    /* +0x48: g++ vtable: func_800480B4, func_8008AF70, func_80071FA4, func_80072760 */
    u8 pad4C[0x50 - 0x4C];
    u16 unk50;                       /* +0x50: func_80047F00, func_80061ACC, func_80073D68 */
    u16 unk52;                       /* +0x52: func_80047F00, func_8008AF70 */
    u8 pad54[0x15E - 0x54];
    u16 unk15E;                      /* +0x15E: func_8005FD44, func_80061ACC, func_80071FA4 */
    u8 pad160[0x162 - 0x160];
    s16 unk162;                      /* +0x162: func_8004BE0C, func_80071FA4 */
    u8 pad164[0x16C - 0x164];
    Vec3i unk16C;                    /* +0x16C: func_800654C8 (px,py,pz) */
    u8 pad178[0x208 - 0x178];
    s32 unk208;                      /* +0x208: func_8004BD2C, func_8004D048, func_8004D2D4, func_80055A14 */
    u8 pad20C[0x21E - 0x20C];
    u16 unk21E;                      /* +0x21E: func_8004BD2C, func_8004BE0C, func_8004D048, func_80055A14 */
    u8 pad220[0x2A4 - 0x220];
    s32 unk2A4;                      /* +0x2A4: func_800654C8, func_80072760 */
    u8 * unk2A8;                     /* +0x2A8: func_80071FA4, func_80072760 */
} Obj;
ASSERT_OFFSET(Obj, unk0, 0x0);
ASSERT_OFFSET(Obj, unk4, 0x4);
ASSERT_OFFSET(Obj, unk1B, 0x1B);
ASSERT_OFFSET(Obj, next, 0x1C);
ASSERT_OFFSET(Obj, vt, 0x48);
ASSERT_OFFSET(Obj, unk50, 0x50);
ASSERT_OFFSET(Obj, unk52, 0x52);
ASSERT_OFFSET(Obj, unk15E, 0x15E);
ASSERT_OFFSET(Obj, unk162, 0x162);
ASSERT_OFFSET(Obj, unk16C, 0x16C);
ASSERT_OFFSET(Obj, unk208, 0x208);
ASSERT_OFFSET(Obj, unk21E, 0x21E);
ASSERT_OFFSET(Obj, unk2A4, 0x2A4);
ASSERT_OFFSET(Obj, unk2A8, 0x2A8);


/* skater: D_800DE7A8 (current) / D_800DE7AC (other) - 25+ files. Starts with the Obj fields. Size not known
 * (>= 0xB60). The +0x884..+0x8F4 block is matched through arguments that carry the same layout markers. */

typedef struct Skater {
    u16 unk0;                        /* +0x0: as Obj */
    u8 pad2[0x4 - 0x2];
    Vec3i unk4;                      /* +0x4: as Obj */
    u8 pad10[0x1C - 0x10];
    struct Obj * next;               /* +0x1C: as Obj (D_800D61A8 list) */
    u8 pad20[0x48 - 0x20];
    VtEntry * vt;                    /* +0x48: func_800358F8 (D_800DE7A8->vt, D_800DE7AC->vt) */
    u8 pad4C[0x84 - 0x4C];
    Vec3i unk84;                     /* +0x84: func_800361DC: D_800DE7A8+0x84..0x8C = +0x8D0.. * 20 */
    u8 pad90[0x208 - 0x90];
    s32 unk208;                      /* +0x208: func_800828A0 (D_800DE7A8), func_8004BD2C, func_8004D2D4 */
    u8 pad20C[0x21E - 0x20C];
    u16 unk21E;                      /* +0x21E: func_8004BD2C, func_8004D048, func_80055A14 */
    u8 pad220[0x2CC - 0x220];
    void * unk2CC;                   /* +0x2CC: func_800828A0: the other skater ("partner" there) */
    void * unk2D0;                   /* +0x2D0: func_800828A0 ("board" there) */
    u8 pad2D4[0x2E8 - 0x2D4];
    s32 unk2E8;                      /* +0x2E8: func_80082660: compared between D_800DE7A8 and D_800DE7AC ("score" there) */
    u8 pad2EC[0x304 - 0x2EC];
    s32 unk304;                      /* +0x304: func_800892D4 */
    u8 pad308[0x310 - 0x308];
    s32 unk310;                      /* +0x310: func_800892D4 */
    s32 unk314;                      /* +0x314: func_800892D4 */
    s32 unk318;                      /* +0x318: func_800704C4 (u16 in func_80072760) */
    s32 unk31C;                      /* +0x31C: func_800892D4 (u8 * in func_80072760) */
    s32 unk320;                      /* +0x320: func_800892D4 */
    s32 unk324;                      /* +0x324: func_800892D4, func_80072760 */
    s32 unk328;                      /* +0x328: func_80072760 */
    s32 unk32C;                      /* +0x32C: func_800892D4, func_80072760 */
    u8 pad330[0x334 - 0x330];
    s32 unk334;                      /* +0x334: func_800892D4 */
    s32 unk338;                      /* +0x338: func_800892D4 */
    s32 unk33C;                      /* +0x33C: func_800892D4 */
    u8 pad340[0x3E0 - 0x340];
    s32 unk3E0;                      /* +0x3E0: 11 files cast D_800DE7A8+0x3E0 (func_80066310, ...); "skin"/"player" in some */
    u8 pad3E4[0x3E8 - 0x3E4];
    s32 unk3E8;                      /* +0x3E8: func_8004D2D4, func_80055A14 */
    s32 unk3EC;                      /* +0x3EC: func_8004D2D4, func_80055A14 */
    u8 pad3F0[0x428 - 0x3F0];
    s32 unk428;                      /* +0x428: func_80082660, func_8004BE0C */
    u8 pad42C[0x450 - 0x42C];
    s32 unk450;                      /* +0x450: func_80066D94, func_8005427C, func_80058A94 */
    u8 pad454[0x82C - 0x454];
    s32 unk82C;                      /* +0x82C: func_80082660, func_80082AC4, func_8004D048, func_8005427C */
    u8 pad830[0x884 - 0x830];
    Mtx3s unk884;                    /* +0x884: x.12 rotation s16[3][3]: func_800269C4, func_8004BD2C, func_8004C880, func_8004D2D4, ... */
    u8 pad896[0x8A4 - 0x896];
    s32 unk8A4[8];                   /* +0x8A4: func_8005C864 copies +0x8A4 -> +0x884 (32 bytes) */
    u8 pad8C4[0x8D0 - 0x8C4];
    Vec3i unk8D0;                    /* +0x8D0: func_800361DC, func_8004BD2C, func_8004D048, func_8004D2D4, func_8005427C */
    Vec3i unk8DC;                    /* +0x8DC: func_8004D048, func_8004D2D4 */
    Vec3i unk8E8;                    /* +0x8E8: func_8004D048, func_8005427C, func_80055A14, func_8005EB20 */
    Vec3i unk8F4;                    /* +0x8F4: func_8004D048, func_80058A94 */
    u8 pad900[0x930 - 0x900];
    s32 unk930;                      /* +0x930: func_80082660 */
    u8 pad934[0x968 - 0x934];
    s32 unk968;                      /* +0x968: func_800828A0 ("player" there) */
    u8 pad96C[0x9F0 - 0x96C];
    s32 unk9F0;                      /* +0x9F0: func_80066224 */
    u8 pad9F4[0xB5C - 0x9F4];
    s32 unkB5C;                      /* +0xB5C: func_80035D08 */
} Skater;
ASSERT_OFFSET(Skater, unk0, 0x0);
ASSERT_OFFSET(Skater, unk4, 0x4);
ASSERT_OFFSET(Skater, next, 0x1C);
ASSERT_OFFSET(Skater, vt, 0x48);
ASSERT_OFFSET(Skater, unk84, 0x84);
ASSERT_OFFSET(Skater, unk208, 0x208);
ASSERT_OFFSET(Skater, unk21E, 0x21E);
ASSERT_OFFSET(Skater, unk2CC, 0x2CC);
ASSERT_OFFSET(Skater, unk2D0, 0x2D0);
ASSERT_OFFSET(Skater, unk2E8, 0x2E8);
ASSERT_OFFSET(Skater, unk304, 0x304);
ASSERT_OFFSET(Skater, unk310, 0x310);
ASSERT_OFFSET(Skater, unk314, 0x314);
ASSERT_OFFSET(Skater, unk318, 0x318);
ASSERT_OFFSET(Skater, unk31C, 0x31C);
ASSERT_OFFSET(Skater, unk320, 0x320);
ASSERT_OFFSET(Skater, unk324, 0x324);
ASSERT_OFFSET(Skater, unk328, 0x328);
ASSERT_OFFSET(Skater, unk32C, 0x32C);
ASSERT_OFFSET(Skater, unk334, 0x334);
ASSERT_OFFSET(Skater, unk338, 0x338);
ASSERT_OFFSET(Skater, unk33C, 0x33C);
ASSERT_OFFSET(Skater, unk3E0, 0x3E0);
ASSERT_OFFSET(Skater, unk3E8, 0x3E8);
ASSERT_OFFSET(Skater, unk3EC, 0x3EC);
ASSERT_OFFSET(Skater, unk428, 0x428);
ASSERT_OFFSET(Skater, unk450, 0x450);
ASSERT_OFFSET(Skater, unk82C, 0x82C);
ASSERT_OFFSET(Skater, unk884, 0x884);
ASSERT_OFFSET(Skater, unk8A4, 0x8A4);
ASSERT_OFFSET(Skater, unk8D0, 0x8D0);
ASSERT_OFFSET(Skater, unk8DC, 0x8DC);
ASSERT_OFFSET(Skater, unk8E8, 0x8E8);
ASSERT_OFFSET(Skater, unk8F4, 0x8F4);
ASSERT_OFFSET(Skater, unk930, 0x930);
ASSERT_OFFSET(Skater, unk968, 0x968);
ASSERT_OFFSET(Skater, unk9F0, 0x9F0);
ASSERT_OFFSET(Skater, unkB5C, 0xB5C);


/* menu object of the func_800A0xxx family (26 files), vtable at +0x4F8; "Menu" in func_800A0760. */

typedef struct MenuEnt {
    s32 unk0;                        /* +0x0: func_800A2FE0 */
    s32 unk4;                        /* +0x4: func_800A2FE0 ("id") */
    u8 pad8[0xA - 0x8];
    u8 unkA;                         /* +0xA: func_800A2FE0 ("kind") */
    u8 padB[0x20 - 0xB];
    s32 unk20;                       /* +0x20: id compared with Menu.unk408[]: func_800A0C8C; func_800A2FE0 */
    s32 unk24;                       /* +0x24: func_800A2FE0 */
} MenuEnt;
ASSERT_OFFSET(MenuEnt, unk0, 0x0);
ASSERT_OFFSET(MenuEnt, unk4, 0x4);
ASSERT_OFFSET(MenuEnt, unkA, 0xA);
ASSERT_OFFSET(MenuEnt, unk20, 0x20);
ASSERT_OFFSET(MenuEnt, unk24, 0x24);
ASSERT_SIZE(MenuEnt, 0x28);

typedef struct Menu {
    u8 pad0[0x14 - 0x0];
    s32 unk14;                       /* +0x14: count of unk4B4 entries: func_800A0870, func_800A08F0, func_800A0C8C, ... (9 files) */
    s32 unk18;                       /* +0x18: selected entry: func_800A0C8C, func_800A1334, func_800A13F4, ... (8 files) */
    u8 pad1C[0x408 - 0x1C];
    s32 unk408[11];                  /* +0x408: ids indexed by unk434: func_800A0C8C; elements 4..10 (+0x418..+0x430) read directly in 12 files */
    s32 unk434;                      /* +0x434: 25 files (func_800A0760 ... func_800A3CD8) */
    s32 unk438;                      /* +0x438: func_800A169C, func_800A180C, func_800A1B68 */
    s32 * unk43C;                    /* +0x43C: func_800A21E8 */
    s32 unk440;                      /* +0x440: func_800A0450, func_800A2FE0 */
    s32 unk444;                      /* +0x444: 5 files */
    s32 unk448;                      /* +0x448: 5 files */
    s32 unk44C;                      /* +0x44C: 5 files */
    u8 pad450[0x45C - 0x450];
    s32 unk45C;                      /* +0x45C: func_800A169C, func_800A1B68, func_800A21E8 */
    s32 unk460;                      /* +0x460: func_800A0450, func_800A378C, func_800A3CD8 */
    s32 unk464;                      /* +0x464: func_800A1174 */
    s32 unk468;                      /* +0x468: func_800A3750, func_800A378C, func_800A3CD8 */
    s32 unk46C;                      /* +0x46C: func_800A0450 */
    s32 unk470;                      /* +0x470: func_800A0450 */
    s32 unk474;                      /* +0x474: func_800A100C */
    s32 unk478;                      /* +0x478: func_800A3250 */
    s32 unk47C;                      /* +0x47C: func_800A169C, func_800A180C */
    s32 unk480;                      /* +0x480: func_800A180C */
    u8 pad484[0x494 - 0x484];
    s32 unk494;                      /* +0x494: func_800A3750, func_800A378C */
    s32 unk498;                      /* +0x498: func_800A1FB8 */
    s32 unk49C;                      /* +0x49C: func_800A1FB8 */
    u8 pad4A0[0x4B4 - 0x4A0];
    MenuEnt * unk4B4;                /* +0x4B4: entries of 0x28 bytes (stride in func_800A0C8C): func_800A0C8C, func_800A0450, func_800A2FE0 */
    s32 unk4B8;                      /* +0x4B8: func_800A21E8 */
    s32 unk4BC;                      /* +0x4BC: func_800A13F4 */
    u16 unk4C0;                      /* +0x4C0: func_800A13F4 */
    u8 pad4C2[0x4D8 - 0x4C2];
    s32 unk4D8;                      /* +0x4D8: func_800A1B68, func_800A21E8 */
    u8 pad4DC[0x4E0 - 0x4DC];
    u16 unk4E0;                      /* +0x4E0: func_800A0450, func_800A180C */
    u8 pad4E2[0x4E4 - 0x4E2];
    s32 unk4E4;                      /* +0x4E4: func_800A0450, func_800A180C, func_800A2FE0 */
    s32 * unk4E8;                    /* +0x4E8: func_800A21E8 */
    s32 unk4EC;                      /* +0x4EC: func_800A0450, func_800A169C, func_800A1B68 */
    f32 unk4F0;                      /* +0x4F0: func_800A3750, func_800A378C */
    f32 unk4F4;                      /* +0x4F4: func_800A3750, func_800A378C */
    VtEntry * vt;                    /* +0x4F8: g++ vtable: func_800A0760 VCALL(o, 6), func_800A100C, ... (10 files) */
} Menu;
ASSERT_OFFSET(Menu, unk14, 0x14);
ASSERT_OFFSET(Menu, unk18, 0x18);
ASSERT_OFFSET(Menu, unk408, 0x408);
ASSERT_OFFSET(Menu, unk434, 0x434);
ASSERT_OFFSET(Menu, unk438, 0x438);
ASSERT_OFFSET(Menu, unk43C, 0x43C);
ASSERT_OFFSET(Menu, unk440, 0x440);
ASSERT_OFFSET(Menu, unk444, 0x444);
ASSERT_OFFSET(Menu, unk448, 0x448);
ASSERT_OFFSET(Menu, unk44C, 0x44C);
ASSERT_OFFSET(Menu, unk45C, 0x45C);
ASSERT_OFFSET(Menu, unk460, 0x460);
ASSERT_OFFSET(Menu, unk464, 0x464);
ASSERT_OFFSET(Menu, unk468, 0x468);
ASSERT_OFFSET(Menu, unk46C, 0x46C);
ASSERT_OFFSET(Menu, unk470, 0x470);
ASSERT_OFFSET(Menu, unk474, 0x474);
ASSERT_OFFSET(Menu, unk478, 0x478);
ASSERT_OFFSET(Menu, unk47C, 0x47C);
ASSERT_OFFSET(Menu, unk480, 0x480);
ASSERT_OFFSET(Menu, unk494, 0x494);
ASSERT_OFFSET(Menu, unk498, 0x498);
ASSERT_OFFSET(Menu, unk49C, 0x49C);
ASSERT_OFFSET(Menu, unk4B4, 0x4B4);
ASSERT_OFFSET(Menu, unk4B8, 0x4B8);
ASSERT_OFFSET(Menu, unk4BC, 0x4BC);
ASSERT_OFFSET(Menu, unk4C0, 0x4C0);
ASSERT_OFFSET(Menu, unk4D8, 0x4D8);
ASSERT_OFFSET(Menu, unk4E0, 0x4E0);
ASSERT_OFFSET(Menu, unk4E4, 0x4E4);
ASSERT_OFFSET(Menu, unk4E8, 0x4E8);
ASSERT_OFFSET(Menu, unk4EC, 0x4EC);
ASSERT_OFFSET(Menu, unk4F0, 0x4F0);
ASSERT_OFFSET(Menu, unk4F4, 0x4F4);
ASSERT_OFFSET(Menu, vt, 0x4F8);


/* menu list built by func_800961C8 (func_8009E30C(0x17C) allocation + init of 15 rows) and edited by the small
 * matched helpers func_80095FAC (append row), func_80095B9C.. (find row), func_80096134 (centre), func_800960E8
 * (select). The big unmatched menu builders func_8008CB2C / func_8008EA30 / func_80091974 / func_80091800 inline
 * these helpers dozens of times (work/q/T1/repeats.py). */

typedef struct {
    s32 unk0;                        /* +0x0: func_80095FAC, func_80095B9C (passed to func_80049034), func_800961C8 */
    u16 unk4;                        /* +0x4: func_800960E8 (copy of unk6) */
    u16 unk6;                        /* +0x6: func_800960E8 (unk8 or unkA, by selection) */
    u16 unk8;                        /* +0x8: func_800960E8, func_800961C8 (s16 there) */
    u16 unkA;                        /* +0xA: func_800960E8, func_800961C8 (s16 there) */
    u8 unkC;                         /* +0xC: width-like, summed in func_80096134; func_80095FAC, func_800961C8 */
    u8 unkD;                         /* +0xD: enabled-like: func_80096134, func_80095FAC, func_800961C8 */
    u8 unkE;                         /* +0xE: func_80095FAC, func_800961C8 */
    u8 unkF[7];                      /* +0xF: colour bytes set in func_800961C8 (0xB6,0x84,0x24,0x7A,0x7A,0x7A,0x80) */
    u8 pad16[0x18 - 0x16];
} MenuRow;
ASSERT_OFFSET(MenuRow, unk0, 0x0);
ASSERT_OFFSET(MenuRow, unk4, 0x4);
ASSERT_OFFSET(MenuRow, unk6, 0x6);
ASSERT_OFFSET(MenuRow, unk8, 0x8);
ASSERT_OFFSET(MenuRow, unkA, 0xA);
ASSERT_OFFSET(MenuRow, unkC, 0xC);
ASSERT_OFFSET(MenuRow, unkD, 0xD);
ASSERT_OFFSET(MenuRow, unkE, 0xE);
ASSERT_OFFSET(MenuRow, unkF, 0xF);
ASSERT_SIZE(MenuRow, 0x18);

typedef struct {
    s8 unk0;                         /* +0x0: func_800961C8 */
    u8 pad1[0x2 - 0x1];
    u8 unk2;                         /* +0x2: selected row: func_800960E8 */
    u8 pad3[0x5 - 0x3];
    u8 unk5;                         /* +0x5: row count: func_80095FAC, func_80095B9C, func_80096134, func_800961C8 */
    u8 pad6[0x8 - 0x6];
    s32 unk8;                        /* +0x8: func_800961C8 */
    s32 unkC;                        /* +0xC: func_80096134 (centred start), func_800961C8 */
    s32 unk10;                       /* +0x10: row spacing: func_80096134, func_800961C8 */
    MenuRow rows[15];                /* +0x14: func_800961C8 initialises 15 */
} MenuList;
ASSERT_OFFSET(MenuList, unk0, 0x0);
ASSERT_OFFSET(MenuList, unk2, 0x2);
ASSERT_OFFSET(MenuList, unk5, 0x5);
ASSERT_OFFSET(MenuList, unk8, 0x8);
ASSERT_OFFSET(MenuList, unkC, 0xC);
ASSERT_OFFSET(MenuList, unk10, 0x10);
ASSERT_OFFSET(MenuList, rows, 0x14);
ASSERT_SIZE(MenuList, 0x17C);


#ifndef SKIP_D_800D6180
extern Obj *D_800D6180;
#endif
#ifndef SKIP_D_800D61A8
extern Obj *D_800D61A8;
#endif
#ifndef SKIP_D_800DE7A8
extern Skater *D_800DE7A8;
#endif
#ifndef SKIP_D_800DE7AC
extern Skater *D_800DE7AC;
#endif


#endif
