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
} Item8008EA30;

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
    Item8008EA30 items[15];
} Menu8008EA30;

typedef struct {
    u8 pad0[0x210];
    s32 unk210;
    s32 unk214;
} Pop8008EA30;

typedef struct {
    u8 pad0[0x2E8];
    s32 unk2E8;
    u8 pad2EC[0x3E0 - 0x2EC];
    s32 unk3E0;
    u8 pad3E4[0x9F0 - 0x3E4];
    s32 unk9F0;
    u8 pad9F4[0xA20 - 0x9F4];
    s32 unkA20;
    u16 padA24;
    u16 unkA26;
    u16 unkA28;
    u16 unkA2A;
    s32 unkA2C;
    char unkA30[0x64];
    char unkA94[0x64];
    char unkAF8[0x64];
    u32 unkB5C;
} Sk8008EA30;

typedef struct {
    u8 pad0[0x2C];
    char *name;
    u8 pad30[0x154 - 0x30];
} Player8008EA30;

typedef struct {
    s32 a;
    s32 b;
} Pair8008EA30;

void func_800057E4(char *, char *, ...);
f32 func_800018C0(f32);
void func_80039E60(s32, s32, s32);
s32 func_80049034(char *, char *, s32);
s32 func_80066428(s32);
void func_80069638(void);
void func_8006DEB0(void *, s32);
void func_8006DF40(s32, s32, char *, s32, s32, s32, s32);
s32 func_8006EC3C(void *);
void func_8006EC54(void *, s32);
void func_8006EC5C(void *);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
void func_8006F274(s32);
void func_8007F86C(void);
void func_8007FDA0(void);
void func_80080864(void);
void func_800818FC(void);
void func_80087194(s32, s32);
void func_8008C000(Pair8008EA30 *);
void func_8008C678(Menu8008EA30 *);
void func_8008E690(void);
void func_8008E77C(Sk8008EA30 *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_800968F4(Pop8008EA30 *, s32);
Pop8008EA30 *func_80096EE4(s32, s32, s32, f32, s32, s32, s32, f32);
s32 func_800971B4(void);
s32 func_800971C4(void);
extern char D_8001FEAC[];
extern char D_8001FEB0[];
extern char D_8001FEC4[];
extern char D_8001FED8[];
extern char D_8001FEE8[];
extern char D_8001FEF8[];
extern char D_8001FEFC[];
extern char D_8001FF00[];
extern char D_8001FF0C[];
extern char D_8001FF18[];
extern char D_8001FF24[];
extern char D_8001FF28[];
extern char D_8001FF2C[];
extern char D_8001FF3C[];
extern char D_8001FF4C[];
extern char D_8001FF5C[];
extern char D_8001FF70[];
extern char D_8001FF80[];
extern char D_8001FF90[];
extern char D_8001FF98[];
extern char D_8001FFA4[];
extern char D_8001FFB0[];
extern char D_8001FFB8[];
extern char D_8001FFC8[];
extern char D_8001FFD8[];
extern s32 D_800C0E20;
extern s32 D_800D1E88;
extern Player8008EA30 D_800D4D80[];
extern s32 D_800D5C1C[];
extern Sk8008EA30 *D_800D61A8;
extern s32 D_800D71D4;
extern s32 D_800D71D8;
extern s32 D_800D71DC;
extern s32 D_800D71E0;
extern s32 D_800D71E4;
extern s32 D_800D71E8;
extern s32 D_800D71EC;
extern s32 D_800D71F0;
extern s32 D_800DACA4;
extern s32 D_800DDC70;
extern char *D_800DDC80[];
extern s32 D_800DE7A0;
extern Sk8008EA30 *D_800DE7A8;
extern Sk8008EA30 *D_800DE7AC;
extern s32 D_800DE808;
extern s32 D_800DE834;
extern s32 D_800DE9A8;
extern s32 D_800DE9C4;
extern s32 D_800DE9C8;
extern u32 D_800DE9CC;
extern s32 D_800DE9D4;
extern Pair8008EA30 D_800DE9D8;
extern s32 D_800DE9E0;
extern s32 D_800DE9E8;
typedef struct {
    u8 c[3];
    u8 pad3;
    u8 who;
    u8 pad5[3];
    s32 score;
} Rec8008EA30;

typedef struct {
    u8 pad0[8];
    u8 lvl;
    u8 pad9[11];
} Ent8008EA30;

typedef union {
    Ent8008EA30 e[0x80];
    struct {
        u8 pad0[0xE4];
        Rec8008EA30 rec[8][8];
    } r;
    struct {
        u8 pad0[0x9FC];
        s32 len;
        u8 name[16];
    } s;
} Save8008EA30;

extern Save8008EA30 D_800DE9F4;
extern char D_800DF3F4[];
extern Pop8008EA30 *D_800E8E80[5];
extern u8 D_800E8E98[];
extern s32 D_800E8EE0;
extern s32 D_800E8EF4;
extern s32 D_800E8F98;
extern s32 D_800E8F9C;
extern s32 D_800E8FA8;
extern s32 D_800E9038;
extern s32 D_800E903C;
extern s32 D_800E9040;
extern Menu8008EA30 *D_800E9054;
extern Menu8008EA30 *D_800E9058;
extern Menu8008EA30 *D_800E905C;
extern Menu8008EA30 *D_800E9060;
extern Menu8008EA30 *D_800E9064;
extern Menu8008EA30 *D_800E9068;
extern Menu8008EA30 *D_800E906C;
extern Menu8008EA30 *D_800E9080;
extern Menu8008EA30 *D_800E9084;
extern s32 D_800E9088;
extern s32 D_800E91A4;
extern s32 D_800E91A8;
extern s32 D_800E91AC;
extern s32 D_800E91B0;
extern u32 D_800E91B4;
extern s32 D_800E91B8;
extern Pair8008EA30 D_800E91BC;
extern s32 D_800E91C4;
extern s32 D_800E91D4[8];
extern s32 D_800E91F4[8];
extern s32 D_800E9264;
extern char D_800FC1F0[];
extern char D_800FC210[];
extern char D_800FC228[];
extern char D_800FC230[];
extern char D_800FC238[];
extern char D_800FC240[];
extern char D_800FC270[];
extern u8 D_800FC290[];

#define STR(off) (D_800DDC80[(off) / 4])

static inline s32 find8008EA30(Menu8008EA30 *m, char *text) {
    s32 i;

    for (i = 0; i < m->count; i++) {
        if (func_80049034(text, m->items[i].text, -1) != 0) {
            return i;
        }
    }
    return 0;
}

static inline void hide8008EA30(Menu8008EA30 *m, char *text) {
    m->items[find8008EA30(m, text)].visible = 0;
}

static inline void show8008EA30(Menu8008EA30 *m, char *text) {
    m->items[find8008EA30(m, text)].visible = 1;
}

static inline void center8008EA30(Menu8008EA30 *m) {
    s32 n;
    s32 i;
    s32 w;

    n = 0;
    w = 0;
    for (i = 0; i < m->count; i++) {
        if (m->items[i].visible) {
            w += m->items[i].width;
            n++;
        }
    }
    m->unkC = (240 - ((n - 1) * m->unk10 + w)) / 2;
}

static inline void footer8008EA30(char *text) {
    func_8006F274(1);
    func_8006F23C(0xC0);
    func_8006F1A8(0x96, 0x64, 0x19, 0);
    func_8006DF40(0xE3, D_800E9088 + 0xD6, text, 0, 0, 0x100, 0);
    if (text == STR(0x184)) {
        func_80087194(D_800D1E88, 0);
    }
    if (text == STR(0x19C)) {
        func_80087194(D_800D1E88, 2);
    }
    if (text == STR(0x1A0)) {
        func_80087194(D_800D1E88, 1);
    }
}

void func_8008EA30(void) {
    s32 v;
    s32 n;
    s32 i11;
    s32 i34;
    s32 i37;
    s32 i13;
    s32 j;
    u8 c;
    s32 a3c;
    s32 t;
    s32 hide;
    s32 sc;
    s32 sc11;
    s32 sc2;
    u8 ch[8];
    char buf3[0x10];
    char buf[0x28];
    char buf2[0x28];
    Sk8008EA30 *sk;

    if (D_800E9038 != 0) {
        func_80069638();
    }
    func_8006F274(0);
    func_8006F23C(0x100);
    switch (D_800E8FA8) {
    case 1:
        func_80087194(D_800D1E88, 5);
        D_800DDC70 = 1;
        if (D_800DE834 != 0) {
            func_8006F274(1);
            func_8006F23C(0xC0);
            func_8006F1A8(0x96, 0x64, 0x19, 0);
            func_8006DF40(0x15C, D_800E9088 + 0xD6, STR(0x19C), 0, 0, 0x100, 0);
            func_8006F274(0);
        } else {
            func_8008E690();
        }
        if (D_800E903C != 0) {
            D_800E9040 += 0x2B2;
            D_800E903C -= 2;
            if (D_800E903C < 0) {
                D_800E903C = 0;
                D_800E9040 = 0;
            }
        }
        if (D_800E9040 == 0) {
            v = 0x1000;
        } else {
            v = D_800E9040 - (D_800E9040 / 4096) * 4096;
            v = func_800018C0((f32)v * 0.000244140625f * 6.283185) * 4096.0f;
        }
        D_800E9080->unk8 = D_800E903C * v / 4096 + 0x100;
        func_8008C678(D_800E9080);
        return;
    case 2:
        if (D_800E9084 != NULL) {
            func_8008C678(D_800E9084);
        }
        return;
    case 3:
        func_80087194(D_800D1E88, 5);
        D_800DDC70 = 1;
        func_8008E690();
        func_8006F1A8(0x96, 0x64, 0x19, 0);
        func_8006DF40(0x100, 0x5F, STR(0x1C0), 0, 0, 0x100, 0);
        D_800E9054->unkC = 0x87;
        func_8008C678(D_800E9054);
        return;
    case 4:
        func_80087194(D_800D1E88, 5);
        D_800DDC70 = 1;
        func_8006F1A8(0xB4, 0xA, 0xA, 0);
        if ((D_800DE808 / 10) & 1) {
            func_8006DF40(0x100, 0xB8, STR(0x190), 0, 0, 0x100, 0);
        }
        return;
    case 11:
        sc11 = D_800DE7A8->unk9F0;
        if (D_800E8E80[0] == NULL) {
            func_80039E60(0x13, 10000, 0);
            switch (sc11) {
            case 1:
                D_800E8E80[0] = func_80096EE4(0xA0, 0x78, 0x8C, 1.0f, 0x32, 0x7D, 0x8C, 0.4f);
                break;
            case 2:
                D_800E8E80[0] = func_80096EE4(0x6E, 0x78, 0x8C, 0.7f, 0x32, 0x96, 0x8C, 0.4f);
                D_800E8E80[1] = func_80096EE4(0xD2, 0x78, 0x8C, 0.7f, 0x32, 0x64, 0x8C, 0.4f);
                break;
            case 3:
                D_800E8E80[0] = func_80096EE4(0xA0, 0x78, 0x8C, 0.7f, 0x32, 0xA5, 0x8C, 0.4f);
                D_800E8E80[1] = func_80096EE4(0x46, 0x78, 0x8C, 0.65f, 0x32, 0x7D, 0x8C, 0.4f);
                D_800E8E80[2] = func_80096EE4(0xFA, 0x78, 0x8C, 0.65f, 0x32, 0x55, 0x8C, 0.4f);
                break;
            case 4:
                D_800E8E80[0] = func_80096EE4(0xD7, 0x9B, 0x8C, 0.7f, 0x32, 0xB9, 0x8C, 0.4f);
                D_800E8E80[1] = func_80096EE4(0x69, 0x9B, 0x8C, 0.7f, 0x32, 0x91, 0x8C, 0.4f);
                D_800E8E80[2] = func_80096EE4(0xD7, 0x55, 0x8C, 0.7f, 0x32, 0x69, 0x8C, 0.4f);
                D_800E8E80[3] = func_80096EE4(0x69, 0x55, 0x8C, 0.7f, 0x32, 0x41, 0x8C, 0.4f);
                break;
            case 5:
                D_800E8E80[0] = func_80096EE4(0xA0, 0x78, 0x8C, 0.67f, 0x32, 0xCD, 0x8C, 0.4f);
                D_800E8E80[1] = func_80096EE4(0xDC, 0x9B, 0x8C, 0.55f, 0x32, 0xA5, 0x8C, 0.4f);
                D_800E8E80[2] = func_80096EE4(0x64, 0x9B, 0x8C, 0.55f, 0x32, 0x7D, 0x8C, 0.4f);
                D_800E8E80[3] = func_80096EE4(0xDC, 0x55, 0x8C, 0.55f, 0x32, 0x55, 0x8C, 0.4f);
                D_800E8E80[4] = func_80096EE4(0x64, 0x55, 0x8C, 0.55f, 0x32, 0x2D, 0x8C, 0.4f);
                break;
            }
        }
        for (j = 0; j < 5; j++) {
            if (D_800E8E80[j] != NULL) {
                D_800E8E80[j]->unk214 = D_800DE9F4.e[D_800DE7A8->unk3E0].lvl - (sc11 - j);
                D_800E8E80[j]->unk210 = j;
            }
        }
        for (i11 = 0; i11 < 5; i11++) {
            if (D_800E8E80[i11] != NULL) {
                func_800968F4(D_800E8E80[i11], D_800DE9F4.e[D_800DE7A8->unk3E0].lvl - (sc11 - i11));
            }
        }
        func_8006F23C(0x100);
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        if (func_800971C4() != 0) {
            if (sc11 == 1) {
                func_8006DF40(0x100, 0x28, STR(0x8C), 0, 0, 0x100, 0);
            } else {
                func_800057E4(D_800FC270, STR(0x90), sc11);
                func_8006DF40(0x100, 0x28, D_800FC270, 0, 0, 0x100, 0);
            }
        }
        if (func_800971B4() != 0) {
            footer8008EA30(STR(0x184));
        }
        return;
    case 6:
    case 7:
    case 12:
        func_8006F1A8(0x96, 0x64, 0x19, 0);
        func_8006DF40(0x100, 0x50, STR(0x14), 0, 0, 0x100, 0);
        D_800E9054->unkC = 0x82;
        func_8008C678(D_800E9054);
        footer8008EA30(STR(0x19C));
        return;
    case 17:
        func_8006F1A8(0x96, 0x64, 0x19, 0);
        func_8006DF40(0x100, 0x50, STR(0xBC), 0, 0, 0x100, 0);
        D_800E9054->unkC = 0x82;
        func_8008C678(D_800E9054);
        footer8008EA30(STR(0x19C));
        return;
    case 14:
        if (D_800E8EF4 != 1 && D_800E91C4 >= 11) {
            func_8008C678(D_800E9058);
            footer8008EA30(STR(0x19C));
        }
        return;
    case 15:
        if (D_800E91C4 >= 11) {
            if (D_800DE9A8 == 2) {
                hide8008EA30(D_800E905C, STR(0x60));
                hide8008EA30(D_800E905C, STR(0x64));
            } else {
                show8008EA30(D_800E905C, STR(0x60));
                show8008EA30(D_800E905C, STR(0x64));
            }
            center8008EA30(D_800E905C);
            func_8008C678(D_800E905C);
            func_8008E690();
        }
        return;
    case 16:
        if (D_800E91C4 >= 11) {
            if (D_800DE9A8 == 2) {
                hide8008EA30(D_800E9060, STR(0x60));
            } else {
                show8008EA30(D_800E9060, STR(0x60));
            }
            center8008EA30(D_800E9060);
            func_8008C678(D_800E9060);
            func_8008E690();
        }
        return;
    case 34:
        hide = 0;
        func_8006F274(0);
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        func_8006DF40(0x100, 0x50, STR(0x144), 0, 0, 0x100, 0);
        ch[1] = 0;
        for (i34 = 0; i34 < 10; i34++) {
            if (D_800E9264 > 0) {
                D_800E9264--;
            }
            c = D_800DE9F4.s.name[i34];
            if (c == 0) {
                hide = 1;
            }
            ch[0] = c;
            if (i34 == D_800DE9E0) {
                func_8006F1A8(0xB6, 0x84, 0x24, 0);
                func_8006F23C(D_800E9264 * 6 + 0x100);
            } else {
                func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
                func_8006F23C(0x100);
            }
            if (!hide) {
                func_8006DF40(i34 * 20 + 0x9C, 0x78, (char *)ch, 0, 0, 0x100, 0);
            }
            ch[0] = 0x2D;
            func_8006F23C(0x100);
            func_8006DF40(i34 * 20 + 0x9C, 0x82, (char *)ch, 0, 0, 0x100, 0);
        }
        footer8008EA30(STR(0x1A0));
        return;
    case 33:
        func_8006F23C(0x100);
        if (D_800DE9C4 == 0) {
            func_8006F1A8(0x50, 0x50, 0x80, 0);
        } else {
            func_8006F1A8(0x80, 0x50, 0x50, 0);
        }
        if (D_800DE9C8 == 0) {
            if (D_800DE9C4 == 0) {
                func_8006DF40(0x100, 0x78, D_8001FEB0, 0, 0, 0x100, 0);
            } else {
                func_8006DF40(0x100, 0x78, D_8001FEC4, 0, 0, 0x100, 0);
            }
        } else {
            if (D_800DE9C4 == 0) {
                func_8006DF40(0x100, 0x78, D_8001FED8, 0, 0, 0x100, 0);
            } else {
                func_8006DF40(0x100, 0x78, D_8001FEE8, 0, 0, 0x100, 0);
            }
            func_800057E4(buf3, D_8001FEAC, D_800DE9CC);
            func_8006DF40(0x100, 0x8C, buf3, 0, 0, 0x100, 0);
        }
        func_8008C000(&D_800DE9D8);
        footer8008EA30(STR(0x184));
        return;
    case 37:
        func_8006F23C(0x100);
        func_800057E4(D_800FC290, STR(0x140), D_800D5C1C[D_800C0E20 * 30]);
        func_8006F1A8(0xB6, 0x84, 0x24, 0);
        func_8006DF40(0x100, 0x28, D_800FC290, 0, 0, 0x100, 0);
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        i37 = 0;
        while (1) {
            u8 *p;
            s32 y;
            s32 xo;
            s32 nx;

            if (i37 >= 8) {
                break;
            }
            D_800E91D4[i37] += 30;
            if (D_800E91D4[i37] > 180) {
                D_800E91D4[i37] = 180;
            }
            D_800E91F4[i37] -= 30;
            if (D_800E91F4[i37] < 412) {
                D_800E91F4[i37] = 412;
            }
            if (i37 == D_800E8F98) {
                func_8006F1A8(0xB6, 0x84, 0x24, 0);
            } else {
                func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
            }
            if (D_800E9264 > 0) {
                D_800E9264--;
            }
            D_800FC290[1] = 0;
            D_800FC290[0] = D_800DE9F4.r.rec[D_800C0E20][i37].c[0];
            func_8006F274(0);
            if (i37 == D_800E8F98 && D_800E8F9C == 0) {
                func_8006F23C(D_800E9264 * 6 + 0x100);
            } else {
                func_8006F23C(0x100);
            }
            func_8006DF40(D_800E91D4[i37] - 0x50, (i37 + 1) * 19 + 0x28, D_800FC290, 0, 0, 0x100, 0);
            func_8006F23C(0x100);
            D_800FC290[0] = D_800DE9F4.r.rec[D_800C0E20][i37].c[1];
            func_8006F274(0);
            if (i37 == D_800E8F98 && D_800E8F9C == 1) {
                func_8006F23C(D_800E9264 * 6 + 0x100);
            } else {
                func_8006F23C(0x100);
            }
            func_8006DF40(D_800E91D4[i37] - 0x3C, (i37 + 1) * 19 + 0x28, D_800FC290, 0, 0, 0x100, 0);
            func_8006F23C(0x100);
            D_800FC290[0] = D_800DE9F4.r.rec[D_800C0E20][i37].c[2];
            func_8006F274(0);
            if (i37 == D_800E8F98 && D_800E8F9C == 2) {
                func_8006F23C(D_800E9264 * 6 + 0x100);
            } else {
                func_8006F23C(0x100);
            }
            func_8006DF40(D_800E91D4[i37] - 0x28, (i37 + 1) * 19 + 0x28, D_800FC290, 0, 0, 0x100, 0);
            func_8006F23C(0x100);
            if (i37 == D_800E8F98 && ((D_800DE808 / 10) & 1)) {
                func_800057E4(D_800FC290, D_8001FEF8);
                func_8006F274(0);
                xo = D_800E8F9C * 20 - 0x50;
                func_8006DF40(D_800E91D4[i37] + xo, (i37 + 1) * 19 + 0x30, D_800FC290, 0, 0, 0x100, 0);
            }
            func_800057E4(D_800FC290, D_8001FEFC, D_800D4D80[D_800DE9F4.r.rec[D_800C0E20][i37].who].name);
            for (p = D_800FC290; *p != 0; p++) {
                if (*p == ' ') {
                    *p = 0;
                    break;
                }
            }
            func_8006F274(1);
            func_8006DF40(D_800E91D4[i37], y = (nx = i37 + 1) * 19 + 0x28, D_800FC290, 0, 0, 0x100, 0);
            func_800057E4(D_800FC290, D_8001FEAC, D_800DE9F4.r.rec[D_800C0E20][i37].score);
            func_8006F274(2);
            func_8006DF40(D_800E91F4[i37], y, D_800FC290, 0, 0, 0x100, 0);
            i37 = nx;
        }
        footer8008EA30(STR(0x1A0));
        return;
    case 13:
        func_8006F23C(0x100);
        if (D_800DE9A8 == 1) {
            func_8006F1A8(0xB6, 0x84, 0x24, 0);
            func_8006DF40(0x100, 0x28, STR(0x94), 0, 0, 0x100, 0);
        } else {
            func_8006F1A8(0xB6, 0x84, 0x24, 0);
            if (D_800DE7A0 == 7) {
                func_8006DF40(0x100, 0x28, D_8001FF00, 0, 0, 0x100, 0);
            } else {
                func_8006DF40(0x100, 0x28, D_8001FF0C, 0, 0, 0x100, 0);
            }
        }
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        func_8006F23C(0x100);
        if (D_800DE9A8 == 1) {
            func_8006F274(1);
            for (i13 = 0; i13 < 5; i13++) {
                D_800E91D4[i13] += 30;
                if (D_800E91D4[i13] > 90) {
                    D_800E91D4[i13] = 90;
                }
            }
            n = 0;
            func_8006DF40(D_800E91D4[n], n++ * 18 + 0x3C, STR(0x98), 0, 0, 0x100, 0);
            func_8006DF40(D_800E91D4[n], n++ * 18 + 0x3C, STR(0x9C), 0, 0, 0x100, 0);
            if (D_800DE7A0 == 1) {
                func_8006DF40(D_800E91D4[n], n++ * 18 + 0x3C, STR(0xA0), 0, 0, 0x100, 0);
            }
            func_8006DF40(D_800E91D4[3], n++ * 18 + 0x3C, STR(0xA4), 0, 0, 0x100, 0);
            func_8006DF40(D_800E91D4[4], n * 18 + 0x3C, STR(0xA8), 0, 0, 0x100, 0);
            func_8006F274(0);
            sk = D_800D61A8;
            func_8006F274(2);
            for (i13 = 0; i13 < 5; i13++) {
                D_800E91F4[i13] -= 30;
                if (D_800E91F4[i13] < 410) {
                    D_800E91F4[i13] = 410;
                }
            }
            n = 0;
            func_800057E4(D_800FC1F0, D_8001FEAC, sk->unkA20);
            func_8006DF40(D_800E91F4[n], n++ * 18 + 0x3C, D_800FC1F0, 0, 0, 0x100, 0);
            func_800057E4(D_800FC210, D_8001FEAC, D_800DE9F4.r.rec[D_800C0E20][0].score);
            func_8006DF40(D_800E91F4[n], n++ * 18 + 0x3C, D_800FC210, 0, 0, 0x100, 0);
            if (D_800DE7A0 == 1) {
                func_800057E4(D_800FC228, D_8001FF18, func_80066428(D_800C0E20), 5);
                func_8006DF40(D_800E91F4[n], n++ * 18 + 0x3C, D_800FC228, 0, 0, 0x100, 0);
            }
            func_800057E4(D_800FC230, D_8001FF24, sk->unkA26);
            func_8006DF40(D_800E91F4[3], n++ * 18 + 0x3C, D_800FC230, 0, 0, 0x100, 0);
            func_800057E4(D_800FC238, D_8001FF24, sk->unkA28);
            func_8006DF40(D_800E91F4[4], n * 18 + 0x3C, D_800FC238, 0, 0, 0x100, 0);
            if (D_800E91D4[0] == 90) {
                func_8006F274(0);
                a3c = sk->unkA2C;
                if (a3c == 0) {
                    func_8006F23C(0xDC);
                    func_8006DF40(0x100, 0x97, STR(0xAC), 0, 0, 0x100, 0);
                    func_8006F23C(0x100);
                    func_8006DF40(0x100, 0xA8, STR(0xB0), 0, 0, 0x100, 0);
                } else {
                    if (sk->unkA2A == 1) {
                        func_800057E4(D_800FC240, STR(0xB8), sk->unkA2A, a3c);
                    } else {
                        func_800057E4(D_800FC240, STR(0xB4), sk->unkA2A, a3c);
                    }
                    func_8006F23C(0xDC);
                    func_8006DF40(0x100, 0x97, D_800FC240, 0, 0, 0x100, 0);
                    func_8006F23C(0xBC);
                    func_8006DF40(0x100, 0xA6, sk->unkA30, 0, 0, 0x100, 0);
                    func_8006DF40(0x100, 0xB4, sk->unkA94, 0, 0, 0x100, 0);
                    func_8006DF40(0x100, 0xC2, sk->unkAF8, 0, 0, 0x100, 0);
                }
            }
        } else {
            func_8006F23C(0x100);
            sc = D_800DE7A8->unkA20;
            sc2 = 0;
            if (D_800DE7AC != NULL) {
                sc2 = D_800DE7AC->unkA20;
            }
            switch (D_800DE7A0) {
            case 8:
                if (D_800DE7AC->unk2E8 == D_800DE7A8->unk2E8) {
                    func_8006DF40(0x100, 0x40, D_8001FF28, 0, 0, 0x100, 0);
                } else if (D_800DE7A8->unk2E8 < D_800DE7AC->unk2E8) {
                    func_8006DF40(0x100, 0x40, D_8001FF2C, 0, 0, 0x100, 0);
                } else {
                    func_8006DF40(0x100, 0x40, D_8001FF3C, 0, 0, 0x100, 0);
                }
                func_8006F23C(0xE0);
                func_8008E77C(D_800DE7A8, 0x1E, 0x56, 0x20, 0x20, 0x80, D_800D71D4, D_800D71D8, D_800D71DC, D_800D71E0);
                func_8008E77C(D_800DE7AC, 0x11E, 0x56, 0x80, 0x20, 0x20, D_800D71E4, D_800D71E8, D_800D71EC, D_800D71F0);
                break;
            case 7:
                n = 0;
                D_800E91AC = D_800DE9C8;
                D_800E91B0 = D_800DE9C4;
                D_800E91B4 = D_800DE9CC;
                D_800E91B8 = D_800DE9D4;
                D_800E91BC.a = D_800DE9D8.a;
                D_800E91BC.b = D_800DE9D8.b;
                if (D_800DE9C4 == 0) {
                    func_8006F1A8(0x50, 0x50, 0x80, 0);
                } else {
                    func_8006F1A8(0x80, 0x50, 0x50, 0);
                }
                if (D_800DE9C8 == 0) {
                    if ((D_800DE9CC = D_800DE7A8->unkB5C) != 0) {
                        func_800057E4(buf, D_8001FF4C, D_800DE9CC);
                        func_8006DF40(0x100, n * 24 + 0x50, buf, 0, 0, 0x100, 0);
                        D_800E91AC ^= 1;
                    } else {
                        func_8006DF40(0x100, n * 24 + 0x50, D_8001FF5C, 0, 0, 0x100, 0);
                    }
                    D_800E91B0 ^= 1;
                } else {
                    func_800057E4(buf, D_8001FF70, D_800DE9CC);
                    func_8006DF40(0x100, n++ * 24 + 0x50, buf, 0, 0, 0x100, 0);
                    func_800057E4(buf, D_8001FF80, D_800DE7A8->unkB5C);
                    func_8006DF40(0x100, n++ * 24 + 0x50, buf, 0, 0, 0x100, 0);
                    if (D_800DE7A8->unkB5C == D_800DE9CC) {
                        func_8006DF40(0x100, n * 24 + 0x50, D_8001FF90, 0, 0, 0x100, 0);
                        D_800E91B0 ^= 1;
                    } else if (D_800DE7A8->unkB5C < D_800DE9CC) {
                        s32 *pp;
                        s32 *bp = (s32 *)&D_800E91BC;
                        pp = &bp[D_800DE9C4];
                        if (++*pp == D_800DE9F4.s.len) {
                            u8 c0 = D_800DE9F4.s.name[0];
                            if (c0 == 'A' || c0 == 'E' || c0 == 'I' || c0 == 'O' || c0 == 'U') {
                                func_800057E4(buf2, D_8001FF98);
                            } else {
                                func_800057E4(buf2, D_8001FFA4);
                            }
                            if (D_800E8EE0 == 0) {
                                D_800E91A8 += 0x20;
                                if (D_800E91A8 > 0x200) {
                                    func_8006F1A8(0xFF, 0x30, 0x30, 0);
                                    D_800E91A8 = 0x200;
                                }
                                func_8006F23C(D_800E91A8);
                                func_8006DF40(0x100, 0x98, buf2, 0, 0, 0x100, 0);
                                t = D_800E91A8;
                                if (t > 0x200) {
                                    t = 0x200;
                                }
                                func_8006F23C(t);
                                func_8006DF40(0x100, 0xBC, D_800DF3F4, 0, 0, 0x100, 0);
                                D_800DE9E8 = 0x2D;
                                footer8008EA30(STR(0x184));
                            } else {
                                if (D_800E91A4 == 0) {
                                    func_80039E60(0x2A, 10000, 0);
                                    D_800E91A4 = 1;
                                }
                                func_8006EC5C(D_800E8E98);
                                func_8006EC54(D_800E8E98, 0x200);
                                func_8006DEB0(D_800E8E98, 1);
                                func_8006DF40(0x100, 0x98, buf2, 0, 0, 0x100, 0);
                                if (func_8006EC3C(D_800E8E98) != 0) {
                                    D_800DE9E8 = 0x2D;
                                }
                                func_8006DEB0(D_800E8E98, 0);
                                func_8006DEB0(D_800E8E98, 1);
                                func_8006DF40(0x100, 0xBC, D_800DF3F4, 0, 0, 0x100, 0);
                                func_8006DEB0(D_800E8E98, 0);
                            }
                            D_800E91AC = 2;
                        } else {
                            buf2[1] = 0;
                            buf2[0] = D_800DE9F4.s.name[*pp - 1];
                            if (D_800E91A8 < 0x200) {
                                D_800E91A8 += 0x20;
                                if (D_800E91A8 > 0x200) {
                                    D_800E91A8 = 0x200;
                                }
                                t = D_800E91A8;
                                if (t > 0x180) {
                                    t = 0x180;
                                }
                                func_8006F23C(t);
                                func_8006DF40(0x100, 0x98, STR(0x160), 0, 0, 0x100, 0);
                                t = D_800E91A8;
                                if (t > 0x200) {
                                    t = 0x200;
                                }
                                func_8006F23C(t);
                                func_8006DF40(0x100, 0xBC, buf2, 0, 0, 0x100, 0);
                                D_800DE9E8 = 0x2D;
                            } else {
                                if (D_800E91A4 == 0) {
                                    func_80039E60(0x2A, 10000, 0);
                                    D_800E91A4 = 1;
                                }
                                func_8006EC5C(D_800E8E98);
                                func_8006EC54(D_800E8E98, 0x180);
                                func_8006DEB0(D_800E8E98, 1);
                                func_8006DF40(0x100, 0x98, STR(0x160), 0, 0, 0x100, 0);
                                if (func_8006EC3C(D_800E8E98) != 0) {
                                    D_800DE9E8 = 0x2D;
                                }
                                func_8006DEB0(D_800E8E98, 0);
                                func_8006EC54(D_800E8E98, 0x200);
                                func_8006DEB0(D_800E8E98, 1);
                                func_8006DF40(0x100, 0xBC, buf2, 0, 0, 0x100, 0);
                                func_8006DEB0(D_800E8E98, 0);
                            }
                            if (++D_800E91B8 == D_800DACA4) {
                                D_800E91B8 = 0;
                            }
                            D_800E91B0 ^= 1;
                            D_800E91AC ^= 1;
                        }
                    } else {
                        func_8006DF40(0x100, n * 24 + 0x50, D_8001FFB0, 0, 0, 0x100, 0);
                        D_800E91B4 = D_800DE7A8->unkB5C;
                        D_800E91B0 ^= 1;
                    }
                }
                func_8008C000(&D_800E91BC);
                break;
            case 6:
            default:
                func_800057E4(D_800FC1F0, D_8001FFB8, sc);
                func_800057E4(D_800FC210, D_8001FFC8, sc2);
                func_8006DF40(0x100, 0x4B, D_800FC1F0, 0, 0, 0x100, 0);
                func_8006DF40(0x100, 0x63, D_800FC210, 0, 0, 0x100, 0);
                if (sc2 < sc) {
                    func_8006DF40(0x100, 0x7B, D_8001FF3C, 0, 0, 0x100, 0);
                } else if (sc < sc2) {
                    func_8006DF40(0x100, 0x7B, D_8001FF2C, 0, 0, 0x100, 0);
                } else {
                    func_8006DF40(0x100, 0x7B, D_8001FFD8, 0, 0, 0x100, 0);
                }
                break;
            }
        }
        if (D_800DE7A0 != 7 && D_800E91C4 >= 11) {
            footer8008EA30(STR(0x184));
        }
        return;
    case 5:
        func_8006F1A8(0x96, 0x64, 0x19, 0);
        func_8006DF40(0x100, 0x67, STR(0x188), 0, 0, 0x100, 0);
        D_800E9054->unkC = 0x8F;
        func_8008C678(D_800E9054);
        footer8008EA30(STR(0x19C));
        return;
    case 24:
        if (D_800E91C4 >= 11) {
            func_8008C678(D_800E9068);
            footer8008EA30(STR(0x19C));
        }
        return;
    case 25:
        if (D_800E91C4 >= 11) {
            if (D_800DE9A8 == 2) {
                hide8008EA30(D_800E9064, STR(0x60));
            } else {
                show8008EA30(D_800E9064, STR(0x60));
            }
            center8008EA30(D_800E9064);
            func_8008C678(D_800E9064);
            func_8008E690();
        }
        return;
    case 27:
        func_800818FC();
        return;
    case 23:
        func_80080864();
        return;
    case 22:
        func_8007FDA0();
        return;
    case 20:
        func_8007F86C();
        return;
    case 38:
        func_8008C678(D_800E906C);
        footer8008EA30(STR(0x19C));
        return;
    }
}
