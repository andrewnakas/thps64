/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
/* NON_MATCHING: aln 0.700. Equivalent C; only the s-register assignment differs (game: idx s5, e s0, p s1, len s3). */
/* near-miss 136/177 (C1, from Y2): switch case order fixed to game order (0xA, 0x45, 0x2A/2C, 6, 7, ...); remaining = s-reg permutation only (game: idx s5, e s0, p s1, len s3; ours idx s3, e s1, p s0, len s5). 9-min permuter: nothing valid. */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 off4;
    s32 n8;
    s32 unkC;
} Hdr_800621C4;

typedef struct {
    u8 name[0x11];
    u8 unk11;
    u8 unk12;
    u8 pad13;
    s32 *unk14;
    u8 *unk18;
    Hdr_800621C4 *hdr;
    s32 *unk20;
    s32 *unk24;
    s32 *unk28;
    s32 *unk2C;
    s32 *unk30;
    s32 *unk34;
    u8 pad38[3];
    u8 unk3B;
    u8 pad3C[0x48 - 0x3C];
} Ent_800621C4;

extern Ent_800621C4 D_800DAF98[];
extern s32 *D_800DAD80;
extern s32 D_800DE5FC;
extern s32 D_800DE600;
void func_8005E500(s32);
void *func_80062F18(s32);
void func_8005E1B8(void *, s32 *);
void func_80062FB0(Hdr_800621C4 *, s32 *);
void func_8005EA18(Hdr_800621C4 *, s32);

void func_800621C4(s32 idx) {
    Hdr_800621C4 *h;
    s32 *p;
    s32 *q;
    s32 l1;
    Ent_800621C4 *e;
    s32 tag;
    s32 len;
    s32 done;

    D_800DAD80 = NULL;
    h = D_800DAF98[idx].hdr;
    D_800DAF98[idx].unk18 = (u8 *)(h->n8 * 36 + (s32)h + 0x10);
    q = (s32 *)((u8 *)h + h->off4);
    while (1) {
        if (*q++ == -1) {
            break;
        }
        l1 = *q++;
        q = (s32 *)((u8 *)q + l1);
    }
    D_800DAF98[idx].unk14 = q;
    D_800DE5FC = 0;
    D_800DE600 = 0;
    if (D_800DAF98[idx].name[0] == 'b') {
        if (D_800DAF98[idx].name[1] == 'i') {
            if (D_800DAF98[idx].name[2] == 't') {
                if (D_800DAF98[idx].name[3] == 's') {
                    if (D_800DAF98[idx].name[4] == 0) {
                        D_800DE5FC = 1;
                        D_800DE600 = 1;
                    }
                }
            }
        }
    }
    e = D_800DAF98;
    e += idx;
    e->unk3B = 1;
    D_800DE5FC = 0;
    D_800DE600 = 0;
    func_8005E500(idx);
    e->unk11 = 0;
    e->unk30 = NULL;
    e->unk34 = NULL;
    p = (s32 *)((u8 *)h + h->off4);
    done = 0;
loop2:
    tag = *p;
    if (tag != -1) {
        p++;
        len = *p;
        p++;
        switch (tag) {
        case 0xA:
            func_8005E1B8(func_80062F18(idx), p);
            break;
        case 0x45:
            func_80062FB0(h, p);
            done = 1;
            break;
        case 0x2A:
        case 0x2C:
            e->unk20 = p;
            e->unk11 = 1;
            break;
        case 6:
            e->unk30 = p;
            D_800DAD80 = p - 2;
            break;
        case 7:
            e->unk34 = p;
            break;
        case 0x52454948:
            e->unk24 = p;
            break;
        case 0x73424752:
            e->unk2C = p;
            break;
        }
        p = (s32 *)((u8 *)p + len);
        goto loop2;
    }
    p++;
    if (done) {
        func_8005EA18(h, (u8 *)p - (u8 *)h);
    }
    D_800DAF98[idx].unk12 = 1;
}
