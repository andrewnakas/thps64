/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 type;
    s32 pad4;
    s32 a;
    s32 b;
    s32 c;
} Goal800892D4;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x58 - 0x10];
    s32 done[2];
    u8 pad60[0x78 - 0x60];
} Prof800892D4;

typedef struct {
    u8 pad0[0x9B4];
    s32 got[2];
    s32 seen[2];
    u8 pad9C4[0x9F4 - 0x9C4];
    s32 flag;
} Save800892D4;

typedef struct {
    u8 pad0[0x304];
    s32 unk304;
    u8 pad308[8];
    s32 unk310;
    s32 unk314;
    u8 pad318[4];
    s32 unk31C;
    s32 unk320;
    s32 unk324;
    u8 pad328[4];
    s32 unk32C;
    u8 pad330[4];
    s32 unk334;
    s32 unk338;
    s32 unk33C;
} Skater800892D4;

typedef struct {
    u8 pad0[0x58];
    u32 timer;
    u32 last;
    u32 unk60;
    Skater800892D4 *sk;
    u8 pad68[0x90 - 0x68];
    s32 msg;
    s32 a;
    s32 b;
    s32 c;
    s32 time;
    s32 unkA4;
    s32 unkA8;
    u8 padAC[4];
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    u8 padBC[4];
    s32 unkC0;
    u8 padC4[4];
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
    s32 unkD8;
    s32 unkDC;
    u8 padE0[4];
    s32 unkE4;
    s32 unkE8;
    s32 unkEC;
    u8 padF0[0xFC - 0xF0];
    s32 unkFC;
    s32 unk100;
    s32 unk104;
    s32 unk108;
    s32 unk10C;
} State800892D4;

typedef struct {
    u8 pad0[0xA0];
    u8 unkA0;
    u8 padA1[0x22C - 0xA1];
    u8 unk22C;
} Pad800892D4;

extern Goal800892D4 D_8001F44C[];
extern s32 D_800C0E20;
extern Pad800892D4 D_800D49E0;
extern Prof800892D4 D_800D5C1C[];
extern Skater800892D4 *D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE7A0;
extern Skater800892D4 *D_800DE7A8;
extern Save800892D4 D_800DE9F4;
extern s32 D_800E8E60;
extern s32 D_800E8E64;
extern State800892D4 D_800FC0D0;

static inline void award800892D4(State800892D4 *s, s32 id) {
    s32 w;
    s32 b;
    s32 seen;
    s32 got;
    s32 m;

    if (id >= 0 && (s->timer == 0 || s->timer >= s->last + 600)) {
        s->last = s->timer;
        got = seen = 0;
        if (id < 32) {
            w = 0;
        } else if (id < 64) {
            w = 1;
        }
        if (D_800DE9F4.flag != 0) {
            if (!((D_800D5C1C[D_800C0E20].done[w] >> (b = id - w * 32)) & 1)) {
                seen |= D_800DE9F4.seen[w];
                got |= D_800DE9F4.got[w];
                m = 1 << b;
                D_800DE9F4.got[w] |= m;
                seen &= m;
                got &= m;
                if (!seen) {
                    if (got) {
                        s->msg = D_800E8E64;
                        D_800DE9F4.seen[w] |= m;
                    } else {
                        s->msg = D_800E8E60;
                    }
                    s->a = D_8001F44C[id].a;
                    s->b = D_8001F44C[id].b;
                    s->c = D_8001F44C[id].c;
                    s->time = 300;
                }
            }
        }
    }
}

#define AWARD800892D4(s, id) \
    { \
    s32 w; \
    s32 b; \
    s32 seen; \
    s32 got; \
    s32 m; \
 \
    if ((s->timer == 0 || s->timer >= s->last + 600)) { \
        s->last = s->timer; \
        got = seen = 0; \
        if (id < 32) { \
            w = 0; \
        } else if (id < 64) { \
            w = 1; \
        } \
        if (D_800DE9F4.flag != 0) { \
            if (!((D_800D5C1C[D_800C0E20].done[w] >> (b = id - w * 32)) & 1)) { \
                seen |= D_800DE9F4.seen[w]; \
                got |= D_800DE9F4.got[w]; \
                m = 1 << b; \
                D_800DE9F4.got[w] |= m; \
                seen &= m; \
                got &= m; \
                if (!seen) { \
                    if (got) { \
                        s->msg = D_800E8E64; \
                        D_800DE9F4.seen[w] |= m; \
                    } else { \
                        s->msg = D_800E8E60; \
                    } \
                    s->a = D_8001F44C[id].a; \
                    s->b = D_8001F44C[id].b; \
                    s->c = D_8001F44C[id].c; \
                    s->time = 300; \
                } \
            } \
        } \
    } \
    }

static inline s32 find800892D4(void) {
    s32 i;

    i = 0;
    while (1) {
        if (i >= 26) {
            return -1;
        }
        if (D_8001F44C[i].type == 0) {
            s32 w;
            s32 w2;
            if (i < 32) {
                w = 0;
            } else if (i < 64) {
                w = 1;
            }
            if (i < 32) {
                w2 = 0;
            } else if (i < 64) {
                w2 = 1;
            }
            if (!((D_800DE9F4.got[w] >> (i - w2 * 32)) & 1)) {
                return i;
            }
        }
        i++;
    }
}

void func_800892D4(void) {
    State800892D4 *s = &D_800FC0D0;

    if (D_800D5C1C[D_800C0E20].unkC != 0 || D_800DC618 == 2 || D_800DC6D8 == 2 || D_800DE7A0 != 1) {
        return;
    }
    s->sk = D_800D61A8;
    s->sk = D_800DE7A8;
    if (s->timer == 0) {
        award800892D4(s, find800892D4());
    }
    s->timer++;
    s->unk60++;
    if (s->unkC0 < s->sk->unk32C) {
        s->unkC0 = s->sk->unk32C;
    }
    if (s->unkD4 < s->sk->unk304) {
        s->unkD4 = s->sk->unk304;
        s->unk108++;
        D_800DE9F4.got[0] |= 0x100;
        D_800DE9F4.seen[0] |= 0x100;
    }
    if (s->unkB4 < s->sk->unk320) {
        s->unkB4 = s->sk->unk320;
        s->unkE8++;
        s->unk60 = 0;
    }
    if (s->unk60 >= 601) {
        s->unk60 = 0;
    }
    if (D_800D49E0.unkA0 != 0 || D_800D49E0.unk22C != 0) {
        s->unk10C++;
    } else {
        s->unk10C = 0;
    }
    if (s->unk10C >= 151) {
        AWARD800892D4(s, 1);
        s->unk10C = 0;
    }
    if (s->unkCC < s->sk->unk338) {
        s->unkCC = s->sk->unk338;
        if (++s->unk100 >= 3) {
            s->unk100 = 0;
            if (s->unk104 < 3) {
                AWARD800892D4(s, 6);
            }
        }
    }
    if (s->unkC8 < s->sk->unk334) {
        s->unkC8 = s->sk->unk334;
        s->unkFC++;
    }
    if (s->unkD0 < s->sk->unk33C) {
        s->unkD0 = s->sk->unk33C;
        s->unk104++;
    }
    if (s->unkB8 < s->sk->unk324) {
        s->unkB8 = s->sk->unk324;
        if (++s->unkEC >= 5) {
            AWARD800892D4(s, 5);
            s->unkEC = 0;
        }
    }
    if (s->unkA4 < s->sk->unk310) {
        s->unkA4 = s->sk->unk310;
        if (++s->unkD8 >= 3) {
            AWARD800892D4(s, 3);
            s->unkD8 = 0;
        }
    }
    if (s->unkA8 < s->sk->unk314) {
        s->unkA8 = s->sk->unk314;
        if (++s->unkDC >= 3) {
            AWARD800892D4(s, 2);
            s->unkDC = 0;
        }
    }
    if (s->unkB0 < s->sk->unk31C) {
        s->unkB0 = s->sk->unk31C;
        if (++s->unkE4 >= 3) {
            AWARD800892D4(s, 9);
            s->unkE4 = 0;
        }
    }
}
