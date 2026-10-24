/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 state;
} Snd;

typedef struct {
    u8 pad0[0x68];
    u64 start;
    u64 now;
    u64 elapsed;
    u8 pad80[4];
    s32 unk84;
    u8 pad88[4];
    s32 unk8C;
    Snd *snd;
} Track;

typedef struct {
    u8 pad0[0x240];
    u8 sub[0x24];
    Track *cur;
    Track *next;
    u8 pad26C[0x22B4 - 0x26C];
    s32 unk22B4;
    u8 pad22B8[0x22DC - 0x22B8];
    s32 unk22DC;
    u8 pad22E0[0x22F8 - 0x22E0];
    u64 elapsed;
    u8 pad2300[0x2310 - 0x2300];
    f32 secs;
} Player;

u64 func_800BD540(void);
void func_80005070(s32, s32, s32);
void func_800BD680(void *, Snd *);
void func_800BC1E0(Player *, s32);
void func_800BD05C(Player *);

void func_800BCDEC(Player *p) {
    u64 us;

    if (p->next == NULL) {
        return;
    }
    if (p->cur == p->next) {
        p->unk22DC = 1;
        return;
    }
    p->next->now = func_800BD540();
    p->next->elapsed = p->next->now - p->next->start;
    p->elapsed = p->next->elapsed;
    us = (p->elapsed * 64) / 3000;
    p->secs = (f32)us * 6.000000212225132e-05f;
    if (p->next->unk8C != 0) {
        func_80005070(p->next->unk8C, 2, 0);
    }
    if (p->next->unk84 != 0) {
        p->next->snd->state = 2;
        func_800BD680(p->sub, p->next->snd);
        func_800BC1E0(p, p->unk22B4);
    }
    p->next = NULL;
    func_800BD05C(p);
}
