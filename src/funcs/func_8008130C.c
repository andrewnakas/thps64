/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0;
    u8 who;
    u8 add;
    u8 who2;
    u8 sub;
} Mod130C;

typedef struct {
    u8 pad0;
    u8 order[10];
    u8 padB;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x24 - 0x18];
    Mod130C mods[5];
    u8 pad3D[0x4A - 0x3D];
    u8 kind[10];
    u8 slot[10];
    u8 pad5E[0x5E - 0x5E];
    s16 vals[10][3];
    s16 tot[10];
    u8 base;
    u8 padAF[0xC0 - 0xAF];
    char *name;
    char buf[0x110 - 0xC4];
    s32 unk110;
    s32 pick;
    s32 unk118;
} State130C;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x78 - 8];
} Lvl130C;

void func_80049DC4(s32);
s32 func_80049D60(s32);
void func_800057E4(char *, char *, s32, s32, s32);
extern State130C D_800DE640;
extern s32 D_800D6138;
extern s32 D_800E9290;
extern s32 D_800C0E20;
extern s16 D_800DE634;
extern s16 D_800DE636;
extern s16 D_800DE638;
extern s16 D_800DE63A;
extern s16 D_800DE63C;
extern Lvl130C D_800D5C1C[];
extern char D_8001E4D0[];

void func_8008130C(void) {
    State130C *s;
    s32 i;
    s32 v;
    u8 a;
    u8 b;
    u8 a2;
    s32 k;
    s32 r;
    s32 j;
    s32 c;

    s = &D_800DE640;
    if (s->base == 0) {
        s->unkC = 0;
        s->unk10 = 0;
        s->unk14 = 0;
        s->unk118 = 0;
        func_80049DC4(D_800D6138);
        {
            s32 m;
            for (m = 0; m < 10; m++) {
                s->order[m] = m;
            }
        }
        v = D_800E9290;
        s->pick = v;
        if (v == 10) {
            s->pick = func_80049D60(10);
            s->order[s->pick] = v;
        }
        if (D_800C0E20 == 8) {
            D_800DE634 = 0x3CF;
            D_800DE636 = 0x3A7;
            D_800DE638 = 0x38E;
            D_800DE63A = 0x35C;
            D_800DE63C = 0x302;
        } else {
            D_800DE634 = 0x3CF;
            D_800DE636 = 0x398;
            D_800DE638 = 0x366;
            D_800DE63A = 0x334;
            D_800DE63C = 0x208;
        }
        a = 0;
        do {
            s->mods[a].who = func_80049D60(10);
            s->mods[a].who2 = func_80049D60(10);
            s->mods[a].add = func_80049D60(30);
            s->mods[a].sub = func_80049D60(30);
            a++;
        } while (a < 5);
        a2 = 0;
        while (1) {
            if (a2 >= 10) break;
            for (b = 0; b < 3; b++) {
                s->vals[a2][b] = 0;
            }
            s->tot[a2] = 0;
            s->slot[a2] = a2;
            a2++;
        }
        s->base = 0;
        {
            s32 m;
            for (m = 0; m < 10; m++) {
                s->kind[m] = 0xFF;
            }
        }
        k = 0;
        while (1) {
            if (k >= 10) break;
            r = func_80049D60(10 - k);
            c = 0;
            j = -1;
            while (c <= r) {
                j++;
                if (s->kind[j] == 0xFF) {
                    c++;
                }
            }
            s->kind[j] = k;
            k++;
        }
        for (i = 0; i < 10; i++) {
            if (s->kind[i] == 9) {
                s->kind[i] = s->kind[s->pick];
            }
        }
        s->kind[s->pick] = 0xFF;
        s->unk110 = 0;
    } else {
        s->unk110 = 0;
    }
    s->name = NULL;
    func_800057E4(s->buf, D_8001E4D0, D_800D5C1C[D_800C0E20].unk0, D_800D5C1C[D_800C0E20].unk4, s->base + 1);
    s->name = s->buf;
}
