/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Goal_800696B0 {
    s32 key;
    u16 idx;
    u8 active;
    u8 team;
    u16 best;
    u8 padA[2];
    struct Goal_800696B0 *next;
    void *owner;
} Goal_800696B0;

typedef struct {
    u16 flags;
    u8 pad2[0x20 - 2];
    s32 unk20;
} Obj_800696B0;

extern void *D_800DE7A8;
extern Goal_800696B0 *D_800DC5E0;
extern u16 **D_800DACB0;
extern s32 D_800DE7A0;
extern u8 D_800DC5F0;
extern void *D_800D2838;
extern s32 D_800DC604;
extern s32 D_800DC608;
s32 func_800635D8(Obj_800696B0 *);
void func_80039E60(s32, s32, s32);
void func_80035138(s32, s32, s32);
void func_80045F08(void *);
void func_8006D1F4(s32, s32);
s32 func_80061904(s32);
void func_80061BC8(s32);

s32 func_800696B0(Obj_800696B0 *arg0, void *arg1, s32 arg2) {
    u8 *pl = arg1;
    s32 team;
    s32 key;
    Goal_800696B0 *g;
    s32 n;
    s32 flag;
    s32 v;
    s32 k;

    team = 2;
    if (pl == D_800DE7A8) {
        team = 1;
    }
    key = func_800635D8(arg0);
    n = 0;
    for (g = D_800DC5E0; g != NULL; g = g->next, n++) {
        if (g->key == key) {
            break;
        }
    }
    if (g == NULL) {
        return 1;
    }
    if (arg2 == -1 && (*D_800DACB0[g->idx] ^ 0xE) != 0) {
        return 1;
    }
    if (g->active != 0) {
        if (D_800DE7A0 != 8) {
            return 3;
        }
        if (g->team == team) {
            return 3;
        }
    }
    flag = 0;
    if ((*D_800DACB0[g->idx] ^ 0xE) == 0 && D_800DE7A0 == 1) {
        func_80039E60(0x2E, 10000, 0);
        func_80039E60(0x30, 10000, 0);
        func_80039E60(0x30, 10000, 0);
        func_80039E60(0x14, 10000, 0);
        arg0->flags |= 0x400;
        arg0->unk20 = 0;
        flag = 1;
    } else if (D_800DE7A0 == 8 && arg2 >= g->best) {
        g->best = arg2;
        arg0->flags |= 0x400;
        (*(s32 *)(pl + 0x2E8))++;
        func_80039E60(0x18, 10000, 0);
        k = 0xCD;
        v = 0x32;
        if (arg2 < 1000) {
            v = (1000 - arg2) * k / 1000 + 0x32;
        }
        arg0->unk20 = v & 0xFF;
        if ((v & 0xFF) != 0) {
            D_800DC5F0 = v;
        }
        func_80035138(key, D_800D2838 != D_800DE7A8, D_800DC5F0);
        if (g->active != 0) {
            (*(s32 *)(*(u8 **)(pl + 0x2CC) + 0x2E8))--;
            (*(s32 *)(pl + 0x2EC))++;
            func_80045F08(pl + 0xA1C);
            func_80039E60(0x19, 10000, 0);
        }
        g->team = team;
        flag = 1;
    }
    if (flag) {
        D_800DC604 = team;
        D_800DC608 = arg2;
        func_8006D1F4(team, n);
        func_80061BC8(func_80061904(g->idx));
        g->active = 1;
        g->owner = arg0;
    }
    return 3;
}
