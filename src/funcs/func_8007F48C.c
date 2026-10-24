/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u8 pad24[0x78 - 0x24];
} Level8007F48C;

typedef struct {
    u8 b25;
    u8 b26;
    u8 b27;
    u8 b28;
    u8 b29;
} Pick8007F48C;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0xC];
    s32 unk1C;
    u8 pad20[5];
    Pick8007F48C picks[5];
    s16 vals[5];
    u8 b48;
    u8 b49;
    u8 pad4A[0x5E - 0x4A];
    s16 table[0x28 / 3][3];
    u8 padAC[2];
    u8 padAE;
    u8 pad[0x114 - 0xAF];
    s32 unk114;
} State8007F48C;

typedef struct {
    u8 pad0[0xA20];
    u32 unkA20;
    u8 padA24[4];
    u16 unkA28;
} Player8007F48C;

s32 func_80049D60(s32);
extern Level8007F48C D_800D5C1C[];
extern s32 D_800C0E20;
extern Player8007F48C *D_800D61A8;
extern u16 D_800DE634;
extern u16 D_800DE636;
extern u16 D_800DE638;
extern u16 D_800DE63A;
extern State8007F48C D_800DE640;

void func_8007F48C(void) {
    State8007F48C *s;
    Player8007F48C *pl;
    u32 v;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    u32 a;
    u32 b;
    u32 c;
    u32 q;
    u32 m;
    Level8007F48C *lv;
    s32 sum;

    s = &D_800DE640;
    if (s->unkC == 0) {
        s->unk1C = 0;
        pl = D_800D61A8;
        v = pl->unkA20;
        for (i = 0; i < 5; i++) {
            lv = &D_800D5C1C[D_800C0E20];
            a = lv->unk18;
            if (a * 2 < v) {
                q = ((v - a * 2) << 12) / (a * 2 + a);
                q = ((1000 - D_800DE634) * q) >> 12;
                q += D_800DE634;
            } else if (a < v) {
                q = ((v - a) << 12) / a;
                q = ((D_800DE634 - D_800DE636) * q) >> 12;
                q += D_800DE636;
            } else {
                b = lv->unk1C;
                if (b < v) {
                    q = ((v - b) << 12) / (a - b);
                    q = ((D_800DE636 - D_800DE638) * q) >> 12;
                q += D_800DE638;
                } else {
                    c = lv->unk20;
                    if (c < v) {
                        q = ((v - c) << 12) / (b - c);
                        q = ((D_800DE638 - D_800DE63A) * q) >> 12;
                q += D_800DE63A;
                    } else {
                        q = (v << 12) / c;
                        q = ((D_800DE63A - 300) * q) >> 12;
                q += 300;
                    }
                }
            }
            s->vals[i] = q;
            q = pl->unkA28 * (func_80049D60(15) + 10);
            if (q > 300) {
                q = 300;
            }
            if (q >= s->vals[i]) {
                s->vals[i] = 0;
            } else {
                s->vals[i] -= q;
            }
            s->vals[i] -= func_80049D60(8);
            if (s->picks[i].b25 == s->unk114) {
                s->vals[i] += s->picks[i].b26;
            }
            if (s->picks[i].b27 == s->unk114 && s->vals[i] > s->picks[i].b28) {
                s->vals[i] -= s->picks[i].b28;
            }
            if (s->vals[i] < 0) {
                s->vals[i] = 0;
            }
            if (s->vals[i] >= 1000) {
                s->vals[i] = 999;
            }
            if (v == 0) {
                s->vals[i] = 0;
            }
        }
        s->b49 = 0;
        for (j = 0; j < 5; j++) {
            if (s->vals[j] < s->vals[s->b49]) {
                s->b49 = j;
            }
        }
        if (s->b49 == 0) {
            s->b48 = 1;
        } else {
            s->b48 = 0;
        }
        for (k = 0; k < 5; k++) {
            if (k != s->b49) {
                if (s->vals[k] > s->vals[s->b48]) {
                    s->b48 = k;
                }
            }
        }
        sum = 0;
        for (l = 0; l < 5; l++) {
            if (l != s->b49 && l != s->b48) {
                sum += s->vals[l];
            }
        }
        sum = sum / 3;
        s->table[s->unk114][s->padAE] = sum;
    }
    s->unkC++;
}
