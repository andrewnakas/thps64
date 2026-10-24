/* cflags: -O2 */
/* NON_MATCHING: aln ratio 0.940; expand_preferences gives the loop byte c b's a2 copy-preference; game keeps c v0 + copy b a2; plus pitch copy and CC andi, best 256/266. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 256/266 (D8 draft, unchanged). Left: (1) dispatch loop: the game keeps c = lb in v0 and a copy b in
 * a2 (andi reads a2). Ours gives c a2 because global.c expand_preferences copies b's a2 copy-preference to c (the
 * copy insn b = c has REG_DEAD c and they do not conflict); c needs to conflict with b (b live at the loop top) or
 * stop dying at the copy, and CSE merges every form tried (inline dispatch helper with param b: same loop, 249).
 * (2) pitch temp copy a2/v1 with separate andi per arm, (3) unkCC read-back andi 0xFF. */
#include "common.h"

typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4;
    u8 unk5;
} ACB5CNote;

typedef struct {
    u8 pad0[0x18];
    u8 *unk18;
    u8 pad1C[4];
    u16 *unk20;
} ACB5CT;

typedef struct {
    u8 pad0[0x14];
    u16 *unk14;
} ACB5CU;

typedef struct {
    u8 pad0[0x28];
    f32 *unk28;
    s32 *unk2C;
} ACB5CV;

typedef struct {
    u8 pad0[0x1C];
} ACB5CVoice;

typedef struct ACB5C {
    u8 pad0[4];
    u8 *unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x2C - 0x10];
    f32 unk2C;
    u8 pad30[0x3C - 0x30];
    s32 unk3C;
    s32 unk40;
    u8 pad44[0x4C - 0x44];
    f32 unk4C;
    f32 unk50;
    s32 unk54;
    u8 pad58[0x74 - 0x58];
    ACB5CT *unk74;
    ACB5CU *unk78;
    ACB5CV *unk7C;
    u8 pad80[4];
    ACB5CNote *unk84;
    u8 pad88[0x9A - 0x88];
    u16 unk9A;
    u8 pad9C[0xA0 - 0x9C];
    u16 unkA0;
    u8 padA2[0xAA - 0xA2];
    u16 unkAA;
    u16 unkAC;
    u16 unkAE;
    u8 padB0[0xB7 - 0xB0];
    u8 unkB7;
    u8 padB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    u8 padBC;
    u8 unkBD;
    u8 padBE[0xC3 - 0xBE];
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 padC6[0xC9 - 0xC6];
    u8 unkC9;
    u8 unkCA;
    u8 unkCB;
    u8 unkCC;
    u8 unkCD;
    u8 padCE;
    u8 unkCF;
    u8 unkD0;
    u8 unkD1;
    u8 unkD2;
    u8 unkD3;
    u8 unkD4;
    u8 padD5;
    u8 unkD6;
    u8 unkD7;
} ACB5C;

typedef u8 *(*ACB5CFunc)(ACB5C *, u8 *, s32);

void func_800AAAE0(ACB5C *, u8 *);
void func_800ACF84(ACB5C *, s32);
void func_800AD280(ACB5C *);
void func_800AD4E0(ACB5C *);
void func_800AFA50(ACB5CVoice *, s32);
void func_800AFBD0(ACB5CVoice *, s32, s32);
void func_800AFD10(ACB5CVoice *);
extern ACB5CFunc D_800ECB44[];
extern ACB5CVoice *D_800FC2F4;
extern s32 D_800FC304;

static inline s32 sext8_(s32 v) { return (v & 0x80) ? (v & 0xFF) - 0x100 : (v & 0xFF); }

void func_800ACB5C(ACB5C *s, s32 arg1) {
    u8 *p;
    u8 *q;
    u8 *r;
    s32 c;
    s32 b;
    s32 note;
    u16 idx;
    f32 f;
    ACB5CV *v;

    p = s->unk4;
    while (p != NULL) {
        c = *(s8 *)p;
        if (c >= 0) {
            break;
        }
        b = c;
        p = D_800ECB44[b & 0x7F](s, p + 1, b);
    }
    s->unk4 = p;
    if (p != NULL) {
        s->unk4C = s->unk50;
        q = s->unk4;
        note = *q++;
        s->unk4 = q;
        if (s->unkD2 != 0) {
            s->unkBB = *q++;
            s->unk4 = q;
            if ((s8)s->unkBB < 0) {
                s->unkBB = s->unkBB & 0x7F;
                s->unkD2 = 0;
                s->unkD3 = s->unkBB;
            }
        } else {
            s->unkBB = s->unkD3;
        }
        if (s->unkAC != 0) {
            if (s->unkB7 == 0) {
                s->unk9A = s->unkAC;
                goto done;
            }
            r = s->unk4;
            s->unkB7 = 0;
            b = *r++;
            s->unk4 = r;
            if ((s8)b >= 0) {
                goto shrt;
            }
            goto lng;
        }
        r = s->unk4;
        b = *r++;
        s->unk4 = r;
        if ((s8)b >= 0) {
        shrt:
            s->unk9A = (u8)b;
        } else {
        lng:
            s->unk9A = (*r << 0) + ((b & 0x7F) << 8);
            s->unk4 = r + 1;
        }
    done:
        s->unkAA = 0;
        s->unkD1 = 0;
        s->unk40 = s->unk3C;
        s->unk3C = s->unk3C + (s->unk9A << 8);
        s->unkD0 = s->unkCF;
        if (s->unk74 != NULL && s->unk84 == NULL && s->unk74->unk20[s->unkAE] == 0xFFFF) {
            note = 0x60;
        }
        if (note != 0x60) {
            v = s->unk7C;
            if (s->unk84 != NULL) {
                s->unkAE = s->unk84[note].unk0;
                s->unkBD = s->unk84[note].unk4 >> 1;
                func_800AAAE0(s, s->unk74->unk18 + s->unk84[note].unk2 * 7);
                note = s->unk84[note].unk5;
            }
            if (s->unkD6 == 0) {
                func_800AD280(s);
            }
            if (s->unkD4 != 0) {
                func_800AD4E0(s);
            }
            idx = s->unkAE;
            if (s->unk74 != NULL) {
                idx = s->unk74->unk20[idx];
            } else {
                idx = s->unk78->unk14[idx];
            }
            if (s->unkD7 == 0) {
                s->unk8 = v->unk2C[idx];
                if (s->unkC9 != 0 && s->unkA0 != 0) {
                    s->unkA0 = 0;
                    func_800AFBD0(&D_800FC2F4[arg1], 0, D_800FC304);
                } else {
                    func_800ACF84(s, arg1);
                }
            }
            f = (f32)note + v->unk28[idx];
            s->unk2C = f;
            s->unk2C = f + sext8_(s->unkB9 * (1 - s->unkBA));
            if (s->unkCA != s->unkCC) {
                s->unkCC = s->unkCA;
                func_800AFA50(&D_800FC2F4[arg1], (u8)(s->unkCB + (((0x80 - s->unkCB) * s->unkCC) >> 7)));
            }
        } else if (s->unkC3 < 4) {
            s->unkC3 = 4;
            s->unkC5 = 1;
            s->unk54 = s->unkC;
            s->unkCD = s->unkC4;
        }
    } else if (s->unkC9 != 0) {
        s->unkC9 = 0;
        func_800AFBD0(&D_800FC2F4[arg1], 0, D_800FC304);
        func_800AFD10(&D_800FC2F4[arg1]);
    }
}
