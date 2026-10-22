#include "common.h"

typedef struct Node80062488 {
    u8 pad[0x1C];
    struct Node80062488 *next;
} Node80062488;

typedef struct {
    u8 pad[0x1C];
    u8 *p;
    u8 pad2[0x48 - 0x20];
} Ent80062488;

extern s32 D_800DAD70[];
extern s32 D_800DAD84[];
extern Node80062488 *D_800DAD8C;
extern Ent80062488 D_800DAF98[];

void func_80062488(s32 arg0) {
    Node80062488 *a;
    Node80062488 *b;
    s32 idx;
    s32 i;
    s32 *q;

    q = D_800DAD84;
    i = arg0 & 0xFF;
    q[i] = 0;
    a = (Node80062488 *)(D_800DAF98[D_800DAD70[i]].p + 0xC);
    idx = D_800DAD70[(arg0 ^ 1) & 0xFF];
    b = NULL;
    if (idx != -1) {
        b = (Node80062488 *)(D_800DAF98[idx].p + 0xC);
    }
    if (b == NULL) {
        D_800DAD8C = NULL;
        return;
    }
    if (a == D_800DAD8C) {
        D_800DAD8C = b;
        return;
    }
    while (b->next != a) {
        b = b->next;
    }
    b->next = NULL;
}
