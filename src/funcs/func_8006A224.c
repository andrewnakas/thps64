#include "common.h"

typedef struct Node_8006A224 {
    s32 x0;
    s16 x4;
    u8 x6;
    u8 pad7;
    s16 x8;
    s16 padA;
    struct Node_8006A224 *next;
    s32 x10;
} Node_8006A224;

extern Node_8006A224 *D_800DC5E0;
extern u8 **D_800DACB0;

Node_8006A224 *func_8006A224(Node_8006A224 *a0, u16 a1) {
    u8 *p;

    a0->next = D_800DC5E0;
    D_800DC5E0 = a0;
    a0->x10 = 0;
    a0->x4 = a1;
    a0->x6 = 0;
    p = D_800DACB0[a1];
    p += *(u16 *)(p + 2) * 2 + 4;
    if ((s32)p & 3) {
        p += 2;
    }
    a0->x0 = *(s32 *)p;
    a0->x8 = 0;
    return a0;
}
