#include "common.h"

typedef struct {
    u8 pad0;
    u8 who;
    u8 add;
    u8 who2;
    u8 sub;
} Mod;

typedef struct {
    u8 pad0[0x10];
    s32 count;
    u8 pad14[4];
    u8 unk18;
    u8 pad19[7];
    s32 unk20;
    Mod mods[5];
    u8 pad3D[0x4A - 0x3D];
    u8 kind[10];
    u8 pad54[0x5E - 0x54];
    s16 vals[13][3];
    u8 padAC[2];
    u8 base;
    u8 padAF[0x114 - 0xAF];
    s32 skip;
} State;

s32 func_80049D60(s32);
extern u16 D_800DE636;
extern u16 D_800DE638;
extern u16 D_800DE63A;
extern u16 D_800DE63C;
extern State D_800DE640;

void func_8007FC34(void) {
    State *s;
    u8 i;
    u8 k;
    s32 kind;
    u8 *m;
    s32 v;

    s = &D_800DE640;
    if (s->count == 0) {
        s->unk20 = 0;
        i = 0;
        while (1) {
            if (i >= 10) break;
            if (i != s->skip) {
                kind = s->kind[i];
                if (kind == 0) {
                    v = D_800DE636;
                } else if (kind == 1) {
                    v = D_800DE638;
                } else if (kind == 2) {
                    v = D_800DE63A;
                } else {
                    v = D_800DE63C + func_80049D60(D_800DE63A - D_800DE63C);
                }
                v -= func_80049D60(0x12);
                for (k = 0; k < 5; k++) {
                    m = (u8 *)s + k * 5;
                    if (i == m[0x25]) {
                        v += m[0x26];
                    }
                    if (i == m[0x27]) {
                        v -= m[0x28];
                    }
                }
                s->vals[i][s->base] = v;
            }
            i++;
        }
        s->unk18 = 0;
    }
    s->count++;
}
