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
} Item80091974;

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
    Item80091974 items[15];
} Menu80091974;

typedef struct {
    u8 pad0[8];
    s16 off;
    u8 padA[2];
    void (*fn)(void *, s32);
} VEnt80091974;

typedef struct {
    u8 pad0[0x48];
    VEnt80091974 *vt;
} Pop80091974;

typedef struct {
    u8 pad0[0x1C];
    struct Sk80091974 *partner;
} SkHdr80091974;

typedef struct Sk80091974 {
    u8 pad0[0x1C];
    struct Sk80091974 *partner;
    u8 pad20[0x408 - 0x20];
    s32 unk408;
    s32 unk40C;
    u8 pad410[0x428 - 0x410];
    s32 unk428;
} Sk80091974;

typedef struct {
    u8 c[3];
    u8 pad3;
    u8 who;
    u8 pad5[3];
    s32 score;
} Rec80091974;

typedef union {
    struct {
        u8 pad0[0xE4];
        Rec80091974 rec[8][8];
    } r;
    struct {
        u8 pad0[0x9B0];
        char str[0x4C];
        s32 len;
        u8 name[16];
    } s;
} Save80091974;

typedef struct {
    s32 a;
    s32 b;
} Pair80091974;

typedef struct {
    s32 unk0;
    u8 pad4[0x1C - 0x4];
    u32 unk1C;
    u8 pad20[0x4C - 0x20];
    s32 unk4C;
    u8 pad50[0xBC - 0x50];
    s32 unkBC;
} Game80091974;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} Prof80091974;

typedef struct {
    u8 pad0[0x40];
    u8 unk40;
    u8 pad41[0x81 - 0x41];
    u8 unk81;
    u8 pad82[0x91 - 0x82];
    u8 unk91;
    u8 pad92[0xE0 - 0x92];
    u8 unkE0;
    u8 padE1[0xF0 - 0xE1];
    u8 unkF0;
    u8 padF1[0x16C - 0xF1];
    s32 unk16C;
    u8 pad170[0x20D - 0x170];
    u8 unk20D;
    u8 pad20E[0x21D - 0x20E];
    u8 unk21D;
    u8 pad21E[0x26C - 0x21E];
    u8 unk26C;
    u8 pad26D[0x27C - 0x26D];
    u8 unk27C;
    u8 pad27D[0x2F8 - 0x27D];
    s32 unk2F8;
} Pad80091974;

void func_800057E4(char *, char *, ...);
void func_80022DE4(void);
void func_80022DEC(void);
s32 func_80022DF4(void);
void func_80022DFC(s32, s32);
void func_80039D2C(void);
void func_80039E60(s32, s32, s32);
void func_8003A10C(void);
void func_8003A1AC(s32, s32, s32);
void func_8003A1CC(f32);
void func_8003A268(void);
void func_8003A2B0(f32);
void func_8003A410(void *, s32, s32);
void func_80043F84(s32, s32);
void func_80043FA8(void *);
s32 func_80049034(char *, char *, s32);
void func_8005EDD0(void);
void func_80061CC4(char *);
s32 func_80069064();
void func_8006A6AC(void);
void func_8006AB44(Sk80091974 *, s32, s32, s32);
void func_8006CFB4(Sk80091974 *);
void func_8006D020(void);
s32 func_8006EC3C(void *);
void func_8006EEF0(void);
void func_8007F1F0(void);
void func_8007F48C(void);
void func_8007FC34(void);
void func_80080554(u32 *, s32 *);
void func_80081608(u32 *, s32 *);
s32 func_80081E90(void);
void func_80081EC4(void);
void func_80081ED4(void);
s32 func_80081EE4(void);
s32 func_80081EF4(void);
s32 func_80081F04(void);
void func_80082660(void);
void func_8008BB60(void);
void func_8008C800(Menu80091974 *);
void func_80091410(s32 *, s32 *, s32 *, s32 *);
void func_800916B0(void);
void func_800960E8(Menu80091974 *, s32);
s32 func_80096400(void);
void func_800964C4(s32, s32, s32);
s32 func_800964F8(void);
void func_80096540(s32);
s32 func_800971B4(void);
Menu80091974 *func_8009E30C(s32);
void func_8009E334(Menu80091974 *);
extern char D_800200C8[];
extern s32 D_800C0E20;
extern s32 D_800C0E24;
extern s32 D_800D0FD0;
extern s8 D_800D0FDA;
extern f32 D_800D0FEC;
extern f32 D_800D0FF0;
extern u8 D_800D3F34[];
extern Pad80091974 D_800D49E0;
extern u8 D_800D4A20;
extern Prof80091974 D_800D5C1C[];
extern s32 D_800D6138;
extern volatile s32 D_800D613C;
extern Sk80091974 *D_800D61A8;
extern char *D_800DAC00[];
extern s32 D_800DAC50;
extern char *D_800DAC54[];
extern s32 D_800DACAC;
extern f32 D_800DC3F8;
extern f32 D_800DC3FC;
extern char D_800DC588[];
extern s32 D_800DC5D0;
extern s32 D_800DC614;
extern Game80091974 D_800DC618;
extern s32 D_800DC724;
extern char *D_800DDC80[];
extern s32 D_800DE7A0;
extern Sk80091974 *D_800DE7A8;
extern Sk80091974 *D_800DE7AC;
extern s32 D_800DE7C8;
extern u32 D_800DE7E0;
extern s32 D_800DE7F4;
extern s32 D_800DE804;
extern s32 D_800DE820;
extern s32 D_800DE848;
extern s32 D_800DE950;
extern s32 D_800DE964;
extern s32 D_800DE968;
extern s32 D_800DE994;
extern s32 D_800DE9A8;
extern s32 D_800DE9AC;
extern s32 D_800DE9B0;
extern s32 D_800DE9C4;
extern s32 D_800DE9C8;
extern s32 D_800DE9CC;
extern s32 D_800DE9D0;
extern s32 D_800DE9D4;
extern Pair80091974 D_800DE9D8;
extern s32 D_800DE9E0;
extern s32 D_800DE9E4;
extern s32 D_800DE9E8;
extern s32 D_800DE9EC;
extern Save80091974 D_800DE9F4;
extern f32 D_800DF264;
extern f32 D_800DF268;
extern Pop80091974 *D_800E8E80[5];
extern s32 D_800E8E94;
extern u8 D_800E8E98[];
extern s32 D_800E8EE0;
extern s32 D_800E8EF4;
extern s32 D_800E8F98;
extern s32 D_800E8F9C;
extern s32 D_800E8FA0;
extern s32 D_800E8FA4;
extern u32 D_800E8FA8;
extern s32 D_800E9038;
extern s32 D_800E903C;
extern s32 D_800E9040;
extern Menu80091974 *D_800E9054;
extern Menu80091974 *D_800E9058;
extern Menu80091974 *D_800E905C;
extern Menu80091974 *D_800E9060;
extern Menu80091974 *D_800E9064;
extern Menu80091974 *D_800E9068;
extern Menu80091974 *D_800E906C;
extern Menu80091974 *D_800E9080;
extern Menu80091974 *D_800E9084;
extern s32 D_800E908C;
extern s32 D_800E9090;
extern s32 D_800E91A4;
extern s32 D_800E91AC;
extern s32 D_800E91B0;
extern s32 D_800E91B4;
extern s32 D_800E91B8;
extern Pair80091974 D_800E91BC;
extern s32 D_800E91C4;
extern s32 D_800E91D4[8];
extern s32 D_800E91F4[8];
extern char D_800E9218[];
extern char D_800E9230[];
extern s32 D_800E9248;
extern s32 D_800E924C;
extern s32 D_800E9264;
extern s32 D_800FC2D0;
extern s32 D_800FC2D4;

#define STR(off) (D_800DDC80[(off) / 4])
#define RECC (D_800DE9F4.r.rec[D_800C0E20][D_800E8F98].c[D_800E8F9C])
#define SELTEXT(m) ((m)->items[(m)->sel].text)
#define ISSEL(m, t) issel80091974(m, t)

static inline void ctor80091974(Menu80091974 *m, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
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

static inline Menu80091974 *new80091974(void) {
    Menu80091974 *m = func_8009E30C(sizeof(Menu80091974));
    ctor80091974(m, 0x100, 0, 0, 0x14F, 0x100, 0x16);
    return m;
}

static inline void add80091974(Menu80091974 *m, char *text) {
    m->items[m->count].text = text;
    m->items[m->count].visible = 1;
    m->items[m->count].enabled = 1;
    m->items[m->count].width = 0;
    m->count++;
}

static inline s32 find80091974(Menu80091974 *m, char *text) {
    s32 i;

    for (i = 0; i < m->count; i++) {
        if (func_80049034(text, m->items[i].text, -1) != 0) {
            return i;
        }
    }
    return 0;
}

static inline s32 vis80091974(Menu80091974 *m, char *text) {
    return m->items[find80091974(m, text)].visible;
}

static inline void hide80091974(Menu80091974 *m, char *text) {
    m->items[find80091974(m, text)].visible = 0;
}

static inline void show80091974(Menu80091974 *m, char *text) {
    m->items[find80091974(m, text)].visible = 1;
}

static inline void center80091974(Menu80091974 *m) {
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

static inline void select80091974(Menu80091974 *m, s32 idx) {
    s32 i;

    m->sel = idx;
    for (i = 0; i < 15; i++) {
        (&m->items[0].sel)[i * 12] = (i == m->sel) ? m->items[i].hi : m->items[i].lo;
        m->items[i].cur = m->items[i].sel;
    }
}

static inline s32 issel80091974(Menu80091974 *m, char *t) {
    return func_80049034(t, m->items[m->sel].text, -1) != 0;
}

static inline s32 coop80091974(void) {
    s32 v;
    s32 r;

    v = 0;
    if (D_800D5C1C[D_800C0E20].unkC != 0) {
        v = D_800DE7A0 == 1;
    }
    if (func_80081F04() != 0) {
        r = 0;
    } else {
        r = v & 1;
    }
    return r;
}

static inline void setstate80091974(u32 s) {
    D_800E8FA8 = s;
    D_800DE7E0 = s;
}

static inline void reset80091974(void) {
    D_800E91A4 = 0;
    D_800DE9C4 = 0;
    D_800DE9C8 = 0;
    D_800DE9CC = 0;
    D_800DE9D0 = 0;
    D_800DE9D4 = 0;
    D_800DE9D8.a = 0;
    D_800DE9D8.b = 0;
    D_800DE9E0 = 0;
    D_800DE9E4 = 0;
    D_800DE9EC = 1;
}

void func_80091974(void) {
    s32 snd;
    s32 done;
    s32 ok;
    s32 back;
    s32 alt;
    s32 any;
    s32 k;
    s32 mode;
    s32 k2;
    s32 k3;
    s32 k4;
    s32 j;
    s32 dir;
    s32 v;
    s32 lo;
    s32 hi;
    u32 now;
    u32 start;
    Sk80091974 *partner;

    snd = -1;
    if (D_800E8FA8 == 18) {
        func_8008BB60();
        return;
    }
    ok = 0;
    back = 0;
    alt = 0;
    any = 0;
    done = 0;
    if (D_800D4A20 == 0 || D_800E8FA8 != 1) {
        func_80091410(&ok, &back, &alt, &any);
    }
    if ((D_800E8FA0 != 0 && D_800D49E0.unkF0 != 0 && D_800D49E0.unkE0 != 0) || (D_800D49E0.unk27C != 0 && D_800D49E0.unk26C != 0)) {
        if (D_800E908C == 0) {
            D_800E908C = 1;
            D_800E9090 = D_800D6138;
        }
        now = D_800D6138;
        start = D_800E9090;
        if (now - start >= 121) {
            D_800E908C = 0;
            done = 1;
            D_800DE804 = 8;
            reset80091974();
        }
    } else {
        D_800E908C = 0;
    }
    D_800E8FA0 = 1;
    switch (D_800E8FA8) {
    case 18:
        if (D_800D5C1C[D_800C0E20].unkC != 0) {
            setstate80091974(func_800964F8());
        } else {
            setstate80091974(13);
        }
        break;
    case 0:
        D_800E8E94 = 0;
        partner = D_800D61A8->partner;
        if (D_800DC618.unk0 == 2 && (ok != 0 || (D_800DE950 == 0 && alt != 0))) {
            D_800DC618.unkBC = 0;
            D_800DE820 = 0;
            func_8006CFB4(D_800D61A8);
            if (partner != NULL) {
                func_8006CFB4(partner);
            }
            func_800916B0();
        } else if (any != 0 || D_800D49E0.unk16C == 0 || (D_800DE9A8 == 2 && D_800D49E0.unk2F8 == 0)) {
            if (D_800DE950 != 0) {
                D_800E9038 = 1;
                D_800DE7A8->unk408 = D_800DE994;
                if (D_800DE7AC != NULL) {
                    D_800DE7AC->unk408 = D_800DE994;
                }
                D_800DE7A8->unk40C = D_800DE994;
                if (D_800DE7AC != NULL) {
                    D_800DE7AC->unk40C = D_800DE994;
                }
                func_8006EEF0();
                func_80043FA8(&D_800D49E0);
                func_80043FA8((u8 *)&D_800D49E0 + 0x18C);
                D_800E903C = 0;
                func_8003A268();
                func_80039E60(0x17, 10000, 0);
                func_80043F84(0, 0);
                func_80043F84(0, 1);
                D_800E9080 = new80091974();
                add80091974(D_800E9080, STR(0x184));
                add80091974(D_800E9080, (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1) ? STR(0x78) : STR(0x74));
                add80091974(D_800E9080, STR(0x1A8));
                if (D_800DE848 == 0) {
                    hide80091974(D_800E9080, STR(0x1A8));
                }
                add80091974(D_800E9080, STR(0x14C));
                if (D_800DE7A0 == 7) {
                    add80091974(D_800E9080, STR(0x4));
                } else {
                    add80091974(D_800E9080, STR(0x8));
                }
                center80091974(D_800E9080);
                D_800E9080->unkC += 13;
                if (D_800D49E0.unk16C != 0 && (D_800DE9A8 == 1 || D_800D49E0.unk2F8 != 0)) {
                    setstate80091974(1);
                    if (D_800E9248 != 0 && D_800E924C != 0) {
                        D_800DE964 = 0;
                        D_800DE968 = 0;
                    } else if (D_800DE7A0 != 7) {
                        D_800DE964 = D_800E924C;
                        D_800DE968 = D_800E9248;
                    }
                } else {
                    setstate80091974(4);
                }
            }
        }
        break;
    case 1:
        if (D_800E9038 == 0) {
            done = 1;
        }
        if (D_800D49E0.unk16C == 0 || (D_800DE9A8 == 2 && D_800D49E0.unk2F8 == 0)) {
            setstate80091974(4);
        }
        if (D_800D49E0.unk40 != 0) {
            if (func_80069064() != 0) {
                D_800E903C = 0x20;
                D_800E9040 = 0;
            }
            func_80043FA8(&D_800D49E0);
            func_80043FA8((u8 *)&D_800D49E0 + 0x18C);
        } else {
            D_800DC5D0 = 0;
            if (D_800DE848 != 0) {
                show80091974(D_800E9080, STR(0x1A8));
            } else {
                hide80091974(D_800E9080, STR(0x1A8));
            }
            func_8008C800(D_800E9080);
            if (ok != 0) {
                if (ISSEL(D_800E9080, STR(0x8))) {
                    snd = 0x91;
                    func_80082660();
                    done = 1;
                    D_800DE9AC = 1;
                    D_800DE9B0 = 1;
                }
                if (ISSEL(D_800E9080, STR(0x184))) {
                    snd = 0x17;
                    done = 1;
                }
                if (ISSEL(D_800E9080, (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1) ? STR(0x78) : STR(0x74))) {
                    reset80091974();
                    done = 1;
                    D_800DE804 = 7;
                    func_8007F1F0();
                }
                if (ISSEL(D_800E9080, STR(0x1A8))) {
                    snd = 0x91;
                    setstate80091974(2);
                }
                if (ISSEL(D_800E9080, STR(0x18C))) {
                    select80091974(D_800E9054, find80091974(D_800E9054, STR(0x1BC)));
                    snd = 0x91;
                    setstate80091974(3);
                }
                if (ISSEL(D_800E9080, STR(0x14C))) {
                    snd = 0x91;
                    setstate80091974(0x26);
                }
                if (ISSEL(D_800E9080, STR(0x4))) {
                    snd = 0x91;
                    D_800E91C4 = 0;
                    D_800DE9EC = 0;
                    setstate80091974(0xE);
                }
            }
            if (back != 0) {
                snd = 0x17;
                done = 1;
            }
            func_8003A1AC(snd, 0x1000, 0);
        }
        break;
    case 2:
        if (D_800E9084 == NULL) {
            D_800E9084 = new80091974();
            D_800E9084->unk10 = 0x12;
            j = 0;
            while (1) {
                if (j >= D_800DAC50) {
                    break;
                }
                add80091974(D_800E9084, D_800DAC00[j]);
                j++;
            }
            center80091974(D_800E9084);
        }
        func_8008C800(D_800E9084);
        if (ok != 0) {
            func_80061CC4(SELTEXT(D_800E9084));
            if (D_800E9084 != NULL) {
                func_8009E334(D_800E9084);
            }
            D_800E9084 = NULL;
            done = 1;
            D_800DE804 = 7;
            func_80039E60(0x91, 10000, 0);
        }
        if (back != 0) {
            if (D_800E9084 != NULL) {
                func_8009E334(D_800E9084);
            }
            D_800E9084 = NULL;
            setstate80091974(1);
            func_80039E60(0x93, 10000, 0);
        }
        break;
    case 3:
        func_8008C800(D_800E9054);
        if (ok != 0) {
            if (ISSEL(D_800E9054, STR(0x1B8))) {
                done = 1;
                D_800DE804 = 8;
                reset80091974();
                func_80039E60(0x91, 10000, 0);
            } else {
                setstate80091974(1);
                func_80039E60(0x93, 10000, 0);
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            setstate80091974(1);
        }
        break;
    case 4:
        if (D_800D49E0.unk16C != 0 && (D_800DE9A8 == 1 || D_800D49E0.unk2F8 != 0)) {
            setstate80091974(1);
        }
        break;
    case 6:
        func_8008C800(D_800E9054);
        if (ok != 0) {
            if (ISSEL(D_800E9054, STR(0x1B8))) {
                func_80039E60(0x91, 10000, 0);
                func_80096540(1);
                func_800964C4(0x200, 0, 0xE);
                setstate80091974(0x12);
                D_800D0FDA = 0;
            } else {
                setstate80091974(8);
                func_80039E60(0x93, 10000, 0);
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            setstate80091974(0xE);
        }
        break;
    case 17:
        func_8008C800(D_800E9054);
        if (ok != 0) {
            if (ISSEL(D_800E9054, STR(0x1B8))) {
                setstate80091974(8);
                func_80039E60(0x91, 10000, 0);
            } else {
                func_80039E60(0x93, 10000, 0);
                if (coop80091974() != 0) {
                    setstate80091974(0x18);
                    select80091974(D_800E9068, find80091974(D_800E9068, STR(0xC4)));
                } else {
                    setstate80091974(0xE);
                }
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            if (coop80091974() != 0) {
                setstate80091974(0x18);
                select80091974(D_800E9068, find80091974(D_800E9068, STR(0xC4)));
            } else {
                setstate80091974(0xE);
            }
        }
        break;
    case 14:
        D_800DE7C8 = 1;
        D_800E8FA4 = 0xE;
        if (D_800E8EF4 != 0) {
            setstate80091974(8);
            break;
        }
        if (D_800E91C4 < 11) {
            D_800E91C4++;
            break;
        }
        func_8008C800(D_800E9058);
        if (ok != 0) {
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x10, 1);
            if (ISSEL(D_800E9058, STR(0x18C))) {
                if (D_800D5C1C[D_800C0E20].unkC == 0 && (vis80091974(D_800E9058, STR(0x70)) ^ 1) == 0 && D_800C0E24 == 0) {
                    setstate80091974(6);
                    D_800E8E94 = 1;
                    select80091974(D_800E9054, find80091974(D_800E9054, STR(0x1B8)));
                } else {
                    setstate80091974(0x11);
                }
            } else if (ISSEL(D_800E9058, (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1) ? STR(0x78) : STR(0x74))) {
                done = 1;
                D_800DE804 = 7;
                func_8007F1F0();
                reset80091974();
            } else if (ISSEL(D_800E9058, STR(0x84))) {
                setstate80091974(0xF);
            } else if (ISSEL(D_800E9058, STR(0x70))) {
                select80091974(D_800E9054, find80091974(D_800E9054, STR(0x1B8)));
                setstate80091974(5);
            } else if (ISSEL(D_800E9058, STR(0x164))) {
                select80091974(D_800E9054, find80091974(D_800E9054, STR(0x1B8)));
                setstate80091974(5);
            } else if (ISSEL(D_800E9058, STR(0x7C))) {
                D_800DE7F4 = 1;
                D_800DE804 = 0xB;
                done = 1;
                reset80091974();
                setstate80091974(8);
            } else if (ISSEL(D_800E9058, STR(0x80))) {
                D_800DE7F4 = 2;
                D_800DE804 = 0xA;
                setstate80091974(8);
                done = 1;
                reset80091974();
            } else if (ISSEL(D_800E9058, STR(0x0))) {
                D_800DE7F4 = 6;
                D_800DE804 = 0xC;
                setstate80091974(8);
                done = 1;
                reset80091974();
            }
        }
        break;
    case 15:
        D_800E8FA4 = 0xF;
        if (D_800E91C4 < 11) {
            D_800E91C4++;
            break;
        }
        func_80096540(0);
        func_8008C800(D_800E905C);
        if (ok != 0) {
            D_800DC614 = 0;
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x20, 1);
            if (ISSEL(D_800E905C, STR(0x6C))) {
                func_8006D020();
                setstate80091974(0xE);
            } else {
                if (ISSEL(D_800E905C, STR(0x5C))) {
                    D_800DC614 = -1;
                    D_800DE804 = 7;
                    done = 1;
                    func_8006A6AC();
                } else if (ISSEL(D_800E905C, STR(0x60))) {
                    D_800DC614 = 1;
                    D_800DE804 = 7;
                    done = 1;
                    func_8006A6AC();
                } else if (ISSEL(D_800E905C, STR(0x64))) {
                    func_800964C4(0x200, 0, 0xF);
                    setstate80091974(0x12);
                    D_800D0FDA = 1;
                }
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            setstate80091974(0xE);
        }
        break;
    case 16:
        if (D_800DE950 == 0) {
            func_8006D020();
            setstate80091974(8);
        }
        if (D_800E91C4 < 11) {
            D_800E91C4++;
            break;
        }
        func_80096540(0);
        func_8008C800(D_800E9060);
        if (ok != 0) {
            D_800DC614 = 0;
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x20, 1);
            if (ISSEL(D_800E9060, STR(0x6C))) {
                func_8006D020();
                setstate80091974(8);
            } else {
                if (ISSEL(D_800E9060, STR(0x5C))) {
                    D_800DC614 = -1;
                    D_800DE804 = 7;
                    done = 1;
                    func_8006A6AC();
                } else if (ISSEL(D_800E9060, STR(0x60))) {
                    D_800DC614 = 1;
                    D_800DE804 = 7;
                    done = 1;
                    func_8006A6AC();
                }
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            func_8006D020();
            setstate80091974(8);
        }
        break;
    case 25:
        if (D_800E91C4 < 11) {
            D_800E91C4++;
            break;
        }
        func_80096540(0);
        func_8008C800(D_800E9064);
        if (ok != 0) {
            D_800DC614 = 0;
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x20, 1);
            if (ISSEL(D_800E9064, STR(0x124))) {
                func_8006D020();
                setstate80091974(0x18);
                select80091974(D_800E9068, find80091974(D_800E9068, STR(0xC4)));
            } else {
                if (ISSEL(D_800E9064, STR(0x5C))) {
                    D_800DC614 = -1;
                    D_800DE804 = 7;
                    done = 1;
                    func_8006A6AC();
                } else if (ISSEL(D_800E9064, STR(0x60))) {
                    D_800DC614 = 1;
                    D_800DE804 = 7;
                    done = 1;
                    func_8006A6AC();
                } else if (ISSEL(D_800E9064, STR(0x64))) {
                    func_800964C4(0x200, 0, 0x19);
                    setstate80091974(0x12);
                    D_800D0FDA = 1;
                }
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            setstate80091974(0x18);
            select80091974(D_800E9068, find80091974(D_800E9068, STR(0xC4)));
        }
        break;
    case 11:
        if (D_800E91C4 < 11) {
            D_800E91C4++;
            break;
        }
        if (ok != 0 && func_800971B4() != 0) {
            func_80039E60(0x91, 10000, 0);
            for (k = 0; k < 5; k++) {
                if (D_800E8E80[k] != NULL) {
                    D_800E8E80[k]->vt->fn((u8 *)D_800E8E80[k] + D_800E8E80[k]->vt->off, 3);
                }
                D_800E8E80[k] = NULL;
            }
            setstate80091974(0xC);
            select80091974(D_800E9054, find80091974(D_800E9054, STR(0x1B8)));
        }
        break;
    case 34:
        D_800DE9EC = 0;
        dir = func_80096400();
        hi = 'Z';
        lo = 'A';
        if (D_800DE9E0 >= D_800DE9F4.s.len - 1 && D_800DE9F4.s.len >= 4) {
            hi = ' ';
            lo = ' ';
        }
        if (dir == -1) {
            D_800E9264 = 0x10;
            func_80039E60(0x11, 10000, 0);
            if (D_800DE9F4.s.name[D_800DE9E0] == ' ' || D_800DE9F4.s.name[D_800DE9E0] == 0) {
                D_800DE9F4.s.name[D_800DE9E0] = 'A';
            } else {
                D_800DE9F4.s.name[D_800DE9E0]++;
                if (D_800DE9F4.s.name[D_800DE9E0] > 'Z') {
                    D_800DE9F4.s.name[D_800DE9E0] = lo;
                }
            }
        }
        if (dir == 1) {
            D_800E9264 = 0x10;
            func_80039E60(0x11, 10000, 0);
            if (D_800DE9F4.s.name[D_800DE9E0] == ' ' || D_800DE9F4.s.name[D_800DE9E0] == 0) {
                D_800DE9F4.s.name[D_800DE9E0] = 'Z';
            } else {
                D_800DE9F4.s.name[D_800DE9E0]--;
                if (D_800DE9F4.s.name[D_800DE9E0] < 'A') {
                    D_800DE9F4.s.name[D_800DE9E0] = hi;
                }
            }
        }
        D_800DE9F4.s.len = 10;
        for (k2 = 0; k2 < 10; k2++) {
            if (D_800DE9F4.s.name[k2] == ' ' || D_800DE9F4.s.name[k2] == 0) {
                D_800DE9F4.s.len = k2;
                break;
            }
        }
        if (D_800D49E0.unk81 != 0 || D_800D49E0.unk20D != 0) {
            D_800E9264 = 0x10;
            func_80039E60(0x91, 10000, 0);
            D_800D49E0.unk81 = 0;
            D_800D49E0.unk20D = 0;
            if (--D_800DE9E0 < 0) {
                D_800DE9E0 = D_800DE9F4.s.len;
            }
            if (D_800DE9E0 >= 10) {
                D_800DE9E0 = 9;
            }
        }
        if (D_800D49E0.unk91 != 0 || D_800D49E0.unk21D != 0) {
            D_800E9264 = 0x10;
            func_80039E60(0x91, 10000, 0);
            D_800D49E0.unk91 = 0;
            D_800D49E0.unk21D = 0;
            if (++D_800DE9E0 > D_800DE9F4.s.len) {
                D_800DE9E0 = 0;
            }
            if (D_800DE9E0 >= 10) {
                D_800DE9E0 = 0;
            }
        }
        if (ok != 0) {
            for (k3 = 0; k3 < 10; k3++) {
                if (D_800DE9F4.s.name[k3] == ' ') {
                    D_800DE9F4.s.name[k3] = 0;
                    break;
                }
            }
            func_800057E4(D_800DC588, (char *)D_800DE9F4.s.name);
            ((s32 *)D_800DC588)[-1] = ((s32 *)D_800DE9F4.s.name)[-1];
            D_800DE9E4 = 1;
            D_800DE9D0 = 0;
            func_80039E60(0x91, 10000, 0);
        }
        break;
    case 33:
        D_800DE9EC = 1;
        D_800DE7A8->unk408 = D_800DE994;
        if (ok != 0) {
            done = 1;
        }
        break;
    case 12:
        D_800E8FA4 = 0xD;
        func_8008C800(D_800E9054);
        if (ok != 0) {
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x20, 1);
            if (ISSEL(D_800E9054, STR(0x1B8))) {
                func_80096540(1);
                func_800964C4(0x200, 0, 0xD);
                setstate80091974(0x12);
                D_800D0FDA = 0;
            } else {
                setstate80091974(0xD);
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            setstate80091974(0xB);
        }
        break;
    case 37:
        if (D_800E91C4 >= 11) {
            if (D_800E8F98 != -1) {
                s32 d37 = func_80096400();
                if (d37 == -1) {
                    D_800E9264 = 0x10;
                    func_80039E60(0x11, 10000, 0);
                    if (RECC == ' ' || RECC == 0) {
                        RECC = 'A';
                    } else {
                        RECC++;
                        if (RECC > 'Z') {
                            D_800DE9F4.r.rec[D_800C0E20][D_800E8F98].c[D_800E8F9C] = ' ';
                        }
                    }
                }
                if (d37 == 1) {
                    D_800E9264 = 0x10;
                    func_80039E60(0x11, 10000, 0);
                    if (RECC == ' ' || RECC == 0) {
                        RECC = 'Z';
                    } else {
                        RECC--;
                        if (RECC < 'A') {
                            D_800DE9F4.r.rec[D_800C0E20][D_800E8F98].c[D_800E8F9C] = ' ';
                        }
                    }
                }
                if (D_800D49E0.unk81 != 0 || D_800D49E0.unk20D != 0) {
                    D_800E9264 = 0x10;
                    func_80039E60(0x91, 10000, 0);
                    D_800D49E0.unk81 = 0;
                    D_800D49E0.unk20D = 0;
                    if (--D_800E8F9C < 0) {
                        D_800E8F9C = 2;
                    }
                }
                if (D_800D49E0.unk91 != 0 || D_800D49E0.unk21D != 0) {
                    D_800E9264 = 0x10;
                    func_80039E60(0x91, 10000, 0);
                    D_800D49E0.unk91 = 0;
                    D_800D49E0.unk21D = 0;
                    if (++D_800E8F9C >= 3) {
                        D_800E8F9C = 0;
                    }
                }
            }
            if (ok != 0) {
                func_80039E60(0x12, 10000, 0);
                func_800057E4(D_800DE9F4.s.str, (char *)D_800DE9F4.r.rec[D_800C0E20][D_800E8F98].c);
                D_800E8F98 = -1;
                setstate80091974(0xE);
            }
        }
        break;
    case 13:
        if (D_800E91C4 < 11) {
            D_800E91C4++;
            break;
        }
        if (D_800DE7A0 == 7) {
            D_800DE9EC = 0;
            if (--D_800DE9E8 <= 0 && D_800E91AC != 2) {
                ok = 1;
            }
            if (D_800E91AC == 2) {
                if (D_800E8EE0 != 0 && func_8006EC3C(D_800E8E98) == 0) {
                    D_800E91C4 = 0;
                    D_800DE7C8 = 1;
                    setstate80091974(0xE);
                }
            }
        }
        if (ok != 0) {
            func_80039E60(0x91, 10000, 0);
            D_800E91A4 = 0;
            mode = D_800DE7A0;

            if (mode == 7) {
                if (D_800E91AC == 2) {
                    D_800E8EE0 = 1;
                    D_800DE9D4 = 0;
                    func_80061CC4(D_800DAC54[0]);
                } else {
                    D_800DE9D4 = D_800E91B8;
                    D_800DE9CC = D_800E91B4;
                    D_800DE9C8 = D_800E91AC;
                    D_800DE9C4 = D_800E91B0;
                    D_800DE9D8.a = D_800E91BC.a;
                    D_800DE9D8.b = D_800E91BC.b;
                    done = 1;
                    func_80061CC4(D_800DAC54[D_800E91B8]);
                    D_800DE804 = mode;
                }
            } else if (D_800E8F98 != -1) {
                setstate80091974(0x25);
                for (k4 = 0; k4 < 8; k4++) {
                    D_800E91D4[k4] = -100 - (4 - k4) * 30;
                    D_800E91F4[k4] = (4 - k4) * 30 + 0x264;
                }
            } else {
                setstate80091974(0xE);
            }
        }
        break;
    case 24:
        if (D_800E91C4 < 11) {
            D_800E91C4++;
            break;
        }
        func_8008C800(D_800E9068);
        if (ok != 0) {
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x20, 1);
            if (ISSEL(D_800E9068, STR(0x18C))) {
                setstate80091974(0x11);
            } else if (ISSEL(D_800E9068, STR(0xC4))) {
                done = 1;
                D_800DE804 = 7;
            } else if (ISSEL(D_800E9068, STR(0xC8))) {
                setstate80091974(0x17);
            } else if (ISSEL(D_800E9068, STR(0x84))) {
                setstate80091974(0x19);
            }
        }
        break;
    case 27:
        func_80081608(&D_800E8FA8, &ok);
        break;
    case 23:
        func_80080554(&D_800E8FA8, &ok);
        break;
    case 7:
        func_8008C800(D_800E9054);
        D_800E8FA4 = 0xE;
        if (ok != 0) {
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x20, 1);
            if (ISSEL(D_800E9054, STR(0x1B8))) {
                func_80096540(1);
                func_800964C4(0x200, 0, 0xE);
                setstate80091974(0x12);
                D_800D0FDA = 0;
            } else {
                setstate80091974(0xE);
            }
        }
        break;
    case 22:
        func_8007FC34();
        if (ok != 0) {
            if (func_80081EE4() != 0) {
                func_8006CFB4(D_800D61A8);
                D_800E9038 = 1;
                func_8003A10C();
                if (func_80081E90() != 0) {
                    setstate80091974(0x18);
                    select80091974(D_800E9068, find80091974(D_800E9068, STR(0xC4)));
                } else {
                    setstate80091974(0x17);
                }
            } else {
                func_80081EC4();
                func_80039E60(0x34, 10000, 0);
            }
        }
        break;
    case 20:
        func_8007F48C();
        if (D_800E91C4 >= 11) {
            if (ok != 0) {
                if (func_80081EF4() != 0) {
                    func_80039E60(0x91, 10000, 0);
                    setstate80091974(0x16);
                    D_800DC614 = -1;
                    if (D_800C0E20 == 8) {
                        v = D_800DACAC;
                        func_80061CC4(D_800200C8);
                        func_8005EDD0();
                        D_800DACAC = v;
                    }
                    if (D_800E9080 != NULL) {
                        func_8009E334(D_800E9080);
                    }
                    D_800E9080 = NULL;
                    if (D_800DE804 != 8 && D_800DE804 != 4 && D_800DE804 != 3) {
                        func_80039D2C();
                    }
                    func_8006A6AC();
                    if (D_800DC618.unk1C > 90) {
                        D_800E9038 = 0;
                        partner = D_800D61A8->partner;
                        D_800DC614 = 0;
                        D_800DC618.unk4C = 0;
                        D_800DC724 = 0;
                        func_8006AB44(D_800D61A8, 2, 1, 0x7FFFFFFF);
                        if (partner != NULL) {
                            func_8006AB44(partner, 2, 1, 0x7FFFFFFF);
                        }
                        D_800DE9AC = 0;
                        func_80022DEC();
                        D_800D61A8->unk428 = D_800D613C + 0x34BDE;
                        if (D_800D61A8->partner != NULL) {
                            D_800D61A8->partner->unk428 = D_800D613C + 0x34BDE;
                        }
                    }
                } else {
                    func_80081ED4();
                    func_80039E60(0x34, 10000, 0);
                }
            }
        } else {
            D_800E91C4++;
        }
        break;
    case 19:
        setstate80091974(0x14);
        D_800E91C4++;
        break;
    case 5:
        func_8008C800(D_800E9054);
        if (ok != 0) {
            func_80039E60(0x91, 10000, 0);
            func_80022DFC(0x20, 1);
            if (ISSEL(D_800E9054, STR(0x1B8))) {
                func_80096540(1);
                func_800964C4(0x200, 0, 0xE);
                setstate80091974(0x12);
                D_800D0FDA = 0;
            } else {
                setstate80091974(0xE);
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            setstate80091974(0xE);
        }
        break;
    case 8:
        func_80022DE4();
        if (func_80022DF4() != 0) {
            if (D_800DE804 == 0) {
                D_800DE804 = 8;
            }
            reset80091974();
            done = 1;
            if (D_800E8EF4 != 0) {
                D_800D0FD0 = 1;
                D_800E8EF4 = 0;
            }
        }
        break;
    case 9:
    case 10:
        func_80022DE4();
        if (func_80022DF4() != 0) {
            if (D_800E8FA8 == 9) {
                D_800DE804 = 4;
            } else {
                D_800DE804 = 3;
            }
            done = 1;
        }
        break;
    case 38:
        func_8008C800(D_800E906C);
        if (D_800D49E0.unk81 != 0 || D_800D49E0.unk20D != 0) {
            D_800D49E0.unk81 = 0;
            D_800D49E0.unk20D = 0;
            if (ISSEL(D_800E906C, D_800E9218)) {
                if (D_800FC2D0 > 0) {
                    D_800FC2D0--;
                }
                func_800057E4(D_800E9218, STR(0x150), D_800FC2D0);
                D_800D0FEC = D_800FC2D0 * 0.1f;
                D_800DF264 = D_800D0FEC;
                D_800DC3F8 = D_800D0FEC;
                func_8003A1CC(D_800D0FEC);
                func_80039E60(0x91, 10000, 0);
            } else if (ISSEL(D_800E906C, D_800E9230)) {
                if (D_800FC2D4 > 0) {
                    D_800FC2D4--;
                }
                func_800057E4(D_800E9230, STR(0x154), D_800FC2D4);
                D_800D0FF0 = D_800FC2D4 * 0.1f;
                D_800DF268 = D_800D0FF0;
                D_800DC3FC = D_800D0FF0;
            }
        }
        if (D_800D49E0.unk91 != 0 || D_800D49E0.unk21D != 0) {
            D_800D49E0.unk91 = 0;
            D_800D49E0.unk21D = 0;
            if (ISSEL(D_800E906C, D_800E9218)) {
                if (D_800FC2D0 < 10) {
                    D_800FC2D0++;
                }
                func_800057E4(D_800E9218, STR(0x150), D_800FC2D0);
                D_800D0FEC = D_800FC2D0 * 0.1f;
                D_800DF264 = D_800D0FEC;
                D_800DC3F8 = D_800D0FEC;
                func_8003A1CC(D_800D0FEC);
                func_80039E60(0x91, 10000, 0);
            } else if (ISSEL(D_800E906C, D_800E9230)) {
                if (D_800FC2D4 < 10) {
                    D_800FC2D4++;
                }
                func_800057E4(D_800E9230, STR(0x154), D_800FC2D4);
                D_800D0FF0 = D_800FC2D4 * 0.1f;
                D_800DF268 = D_800D0FF0;
                D_800DC3FC = D_800D0FF0;
            }
        }
        if (ok != 0) {
            if (ISSEL(D_800E906C, STR(0x158))) {
                func_8003A410(D_800D3F34, 0, -1);
                func_8003A2B0(D_800D0FF0);
            } else if (ISSEL(D_800E906C, STR(0x15C))) {
                back = 1;
            }
        }
        if (back != 0) {
            func_80039E60(0x93, 10000, 0);
            setstate80091974(1);
        }
        break;
    }
    if (done != 0) {
        D_800E9038 = 0;
        D_800DE964 = 0;
        D_800DE968 = 0;
        setstate80091974(0);
        if (D_800E9080 != NULL) {
            func_8009E334(D_800E9080);
        }
        D_800E9080 = NULL;
        if ((u32)(D_800DE804 - 7) >= 2 && D_800DE804 != 4 && D_800DE804 != 3) {
            func_80039D2C();
        }
    }
}
