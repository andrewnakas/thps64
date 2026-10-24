/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NEARLY: only diff is one nop: gas 2.6 (-m4100) pads a `mult` that directly follows a label (.L80067F00, cross-jump target) with a nop; the game has none. Toolchain issue, C is otherwise exact. Same label+mult shape in func_80045E38, 80047980, 80047D40, 80048928, 800495B4, 8004C14C, 80063AD8, 8006F280, 8006F3F0. */
#include "common.h"

typedef struct {
    s32 x, y, z, w;
} Quat67B44;

typedef struct {
    s16 m[3][3];
} Mat67B44;


s32 func_800233EC(s32);
extern s32 D_800DC5B0[];

void func_80067B44(s16 m[3][3], Quat67B44 *q) {
    s32 tr;
    s32 s;
    s32 i, j, k;
    s32 a, b, c;

    a = m[0][0];
    b = m[1][1];
    tr = a + b + m[2][2];
    i = a < b;
    if (tr > 0) {
        s = func_800233EC((tr + 0x1000) << 12);
        q->w = s >> 1;
        if (s != 0) {
            s = 0x800000 / s;
        }
        q->x = ((m[1][2] - m[2][1]) * s) >> 12;
        q->y = ((m[2][0] - m[0][2]) * s) >> 12;
        q->z = ((m[0][1] - m[1][0]) * s) >> 12;
        return;
    }
    if (((Mat67B44 *)m)->m[i][i] < m[2][2]) {
        i = 2;
    }
    j = D_800DC5B0[i];
    k = D_800DC5B0[j];
    s = func_800233EC(((((Mat67B44 *)m)->m[i][i] - (((Mat67B44 *)m)->m[j][j] + ((Mat67B44 *)m)->m[k][k])) + 0x1000) << 12);
    switch (i) {
    case 0:
        q->x = s >> 1;
        break;
    case 1:
        q->y = s >> 1;
        break;
    case 2:
        q->z = s >> 1;
        break;
    }
    if (s != 0) {
        s = 0x800000 / s;
    }
    q->w = ((((Mat67B44 *)m)->m[j][k] - ((Mat67B44 *)m)->m[k][j]) * s) >> 12;
    switch (j) {
    case 0:
        q->x = ((((Mat67B44 *)m)->m[i][0] + ((Mat67B44 *)m)->m[0][i]) * s) >> 12;
        break;
    case 1:
        q->y = ((m[i][1] + m[1][i]) * s) >> 12;
        break;
    case 2:
        q->z = ((m[i][2] + m[2][i]) * s) >> 12;
        break;
    }
    switch (k) {
    case 0:
        q->x = ((((Mat67B44 *)m)->m[i][0] + ((Mat67B44 *)m)->m[0][i]) * s) >> 12;
        break;
    case 1:
        q->y = ((m[i][1] + m[1][i]) * s) >> 12;
        break;
    case 2:
        q->z = ((m[i][2] + m[2][i]) * s) >> 12;
        break;
    }
}
