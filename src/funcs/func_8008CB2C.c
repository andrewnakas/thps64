/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    char *text;
    s16 cur;
    s16 sel;
    s16 hi;
    s16 lo;
    u8 width;
    u8 visible;
    u8 enabled;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 r1;
    u8 g1;
    u8 b1;
    u8 a;
    u8 pad16[2];
} Item8008CB2C;

typedef struct {
    s8 unk0;
    u8 pad1;
    u8 sel;
    u8 pad3[2];
    u8 count;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Item8008CB2C items[15];
} Menu8008CB2C;

typedef struct {
    s32 data[0x22];
} Blob8008CB2C;

typedef struct {
    s32 pad0[3];
    s32 unkC;
    u8 pad10[0x68];
} Prof8008CB2C;

typedef struct {
    char *unk0;
    u8 pad4[0x5C - 0x4];
    char *unk5C;
    char *unk60;
    char *unk64;
    u8 pad68[4];
    char *unk6C;
    char *unk70;
    u8 pad74[4];
    char *unk78;
    char *unk7C;
    char *unk80;
    char *unk84;
    u8 pad88[0xC4 - 0x88];
    char *unkC4;
    char *unkC8;
    u8 padCC[0x124 - 0xCC];
    char *unk124;
    u8 pad128[0x154 - 0x128];
    char *unk154;
    char *unk158;
    char *unk15C;
    u8 pad160[4];
    char *unk164;
    u8 pad168[0x18C - 0x168];
    char *unk18C;
    u8 pad190[0x1B8 - 0x190];
    char *unk1B8;
    char *unk1BC;
} Strs8008CB2C;

Menu8008CB2C *func_8009E30C(s32);
void func_800960E8(Menu8008CB2C *, s32);
s32 func_80049034(char *, char *, s32);
void func_800057E4(char *, char *, ...);
extern Blob8008CB2C D_8001FD8C;
extern s32 D_800C0E20;
extern f32 D_800D0FEC;
extern f32 D_800D0FF0;
extern Prof8008CB2C D_800D5C1C[];
extern Strs8008CB2C D_800DDC80;
extern char *D_800DDCF4;
extern char *D_800DDCF8;
extern char *D_800DDD04;
extern char *D_800DDDD0;
extern char *D_800DDDE4;
extern s32 D_800DE7A0;
extern u8 D_800DF424[];
extern u8 *D_800E9034;
extern Menu8008CB2C *D_800E9054;
extern Menu8008CB2C *D_800E9058;
extern Menu8008CB2C *D_800E905C;
extern Menu8008CB2C *D_800E9060;
extern Menu8008CB2C *D_800E9064;
extern Menu8008CB2C *D_800E9068;
extern Menu8008CB2C *D_800E906C;
extern Blob8008CB2C D_800E9094;
extern Blob8008CB2C D_800E911C;
extern char D_800E9218[];
extern char D_800E9230[];
extern s32 D_800FC2D0;
extern s32 D_800FC2D4;

static inline void ctor8008CB2C(Menu8008CB2C *m, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s32 i;

    m->unk8 = a1;
    m->unkC = a2;
    m->unk0 = a3;
    m->unk10 = a6;
    m->count = 0;
    for (i = 0; i < 15; i++) {
        m->items[i].r0 = 0xB6;
        m->items[i].g0 = 0x84;
        m->items[i].b0 = 0x24;
        m->items[i].r1 = 0x7A;
        m->items[i].g1 = 0x7A;
        m->items[i].b1 = 0x7A;
        m->items[i].a = 0x80;
        m->items[i].hi = a4;
        m->items[i].lo = a5;
    }
    func_800960E8(m, 0);
}

static inline Menu8008CB2C *new8008CB2C(void) {
    Menu8008CB2C *m = func_8009E30C(sizeof(Menu8008CB2C));
    ctor8008CB2C(m, 0x100, 0, 0, 0x14F, 0x100, 0x16);
    return m;
}

static inline void add8008CB2C(Menu8008CB2C *m, char *text) {
    m->items[m->count].text = text;
    m->items[m->count].visible = 1;
    m->items[m->count].enabled = 1;
    m->items[m->count].width = 0;
    m->count++;
}

static inline s32 find8008CB2C(Menu8008CB2C *m, char *text) {
    s32 i;

    for (i = 0; i < m->count; i++) {
        if (func_80049034(text, m->items[i].text, -1) != 0) {
            return i;
        }
    }
    return 0;
}

static inline void hide8008CB2C(Menu8008CB2C *m, char *text) {
    m->items[find8008CB2C(m, text)].visible = 0;
}

static inline void center8008CB2C(Menu8008CB2C *m) {
    s32 n;
    s32 i;
    s32 w;

    n = 0;
    for (i = 0, w = 0; i < m->count; i++) {
        if (m->items[i].visible) {
            w += m->items[i].width;
            n++;
        }
    }
    m->unkC = (240 - ((n - 1) * m->unk10 + w)) / 2;
}

static inline void select8008CB2C(Menu8008CB2C *m, s32 idx) {
    s32 i;

    m->sel = idx;
    for (i = 0; i < 15; i++) {
        (&m->items[0].sel)[i * 12] = (i == m->sel) ? m->items[i].hi : m->items[i].lo;
        m->items[i].cur = m->items[i].sel;
    }
}

void func_8008CB2C(void) {
    D_800E9034 = D_800DF424;
    D_800E911C = D_8001FD8C;
    D_800E9094 = D_8001FD8C;

    D_800E9054 = new8008CB2C();
    add8008CB2C(D_800E9054, D_800DDC80.unk1B8);
    add8008CB2C(D_800E9054, D_800DDC80.unk1BC);

    D_800E9058 = new8008CB2C();
    add8008CB2C(D_800E9058, D_800DDC80.unk164);
    add8008CB2C(D_800E9058, (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1) ? D_800DDC80.unk78 : D_800DDCF4);
    add8008CB2C(D_800E9058, D_800DDC80.unk0);
    add8008CB2C(D_800E9058, D_800DDC80.unk7C);
    add8008CB2C(D_800E9058, D_800DDC80.unk80);
    add8008CB2C(D_800E9058, D_800DDC80.unk84);
    add8008CB2C(D_800E9058, D_800DDC80.unk70);
    add8008CB2C(D_800E9058, D_800DDC80.unk18C);
    if (D_800DE7A0 != 1) {
        hide8008CB2C(D_800E9058, D_800DDC80.unk70);
    }
    if (D_800DE7A0 != 1 || D_800D5C1C[D_800C0E20].unkC != 0) {
        hide8008CB2C(D_800E9058, D_800DDC80.unk0);
    }
    if (D_800DE7A0 != 3) {
        hide8008CB2C(D_800E9058, D_800DDC80.unk164);
    }
    if (D_800DE7A0 == 2 || D_800DE7A0 == 7) {
        hide8008CB2C(D_800E9058, D_800DDC80.unk84);
    }
    center8008CB2C(D_800E9058);
    select8008CB2C(D_800E9058, find8008CB2C(D_800E9058, (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1) ? D_800DDCF8 : D_800DDCF4));

    D_800E905C = new8008CB2C();
    add8008CB2C(D_800E905C, D_800DDC80.unk5C);
    add8008CB2C(D_800E905C, D_800DDC80.unk60);
    add8008CB2C(D_800E905C, D_800DDC80.unk64);
    add8008CB2C(D_800E905C, D_800DDC80.unk6C);
    center8008CB2C(D_800E905C);

    D_800E9060 = new8008CB2C();
    add8008CB2C(D_800E9060, D_800DDC80.unk5C);
    add8008CB2C(D_800E9060, D_800DDC80.unk60);
    add8008CB2C(D_800E9060, D_800DDC80.unk6C);
    center8008CB2C(D_800E9060);

    D_800E9064 = new8008CB2C();
    add8008CB2C(D_800E9064, D_800DDC80.unk5C);
    add8008CB2C(D_800E9064, D_800DDC80.unk60);
    add8008CB2C(D_800E9064, D_800DDC80.unk64);
    add8008CB2C(D_800E9064, D_800DDC80.unk124);
    center8008CB2C(D_800E9064);

    D_800E9068 = new8008CB2C();
    add8008CB2C(D_800E9068, D_800DDC80.unkC4);
    add8008CB2C(D_800E9068, D_800DDC80.unk84);
    add8008CB2C(D_800E9068, D_800DDC80.unkC8);
    add8008CB2C(D_800E9068, D_800DDC80.unk18C);
    center8008CB2C(D_800E9068);

    D_800E906C = new8008CB2C();
    D_800FC2D0 = D_800D0FEC * 10.0f;
    if (D_800FC2D0 > 10) {
        D_800FC2D0 = 10;
    } else if (D_800FC2D0 < 0) {
        D_800FC2D0 = 0;
    }
    func_800057E4(D_800E9218, D_800DDDD0, D_800FC2D0);
    add8008CB2C(D_800E906C, D_800E9218);
    D_800FC2D4 = D_800D0FF0 * 10.0f;
    if (D_800FC2D4 > 10) {
        D_800FC2D4 = 10;
    } else if (D_800FC2D4 < 0) {
        D_800FC2D4 = 0;
    }
    func_800057E4(D_800E9230, D_800DDC80.unk154, D_800FC2D4);
    add8008CB2C(D_800E906C, D_800E9230);
    add8008CB2C(D_800E906C, D_800DDC80.unk158);
    add8008CB2C(D_800E906C, D_800DDC80.unk15C);
    center8008CB2C(D_800E906C);
}
