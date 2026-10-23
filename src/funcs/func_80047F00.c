/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec47F00;

typedef struct Node47F00 {
    u8 pad0[0x1C];
    struct Node47F00 *next;
    u8 pad20[0x50 - 0x20];
    u16 unk50;
    u16 unk52;
} Node47F00;

extern Vec47F00 D_800D6110[];
extern s32 D_800D6134;
extern s32 D_800D614C[];
extern s32 D_800D6158[];
extern s32 D_800D6164[];
extern s32 D_800D6170[];
extern Node47F00 *D_800D6180;
extern Node47F00 *D_800DDC60;

void func_80047F00(Vec47F00 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 *p;
    s32 ok;
    Node47F00 *n;

    ok = 0;
    if (D_800D6134 >= 3) {
        for (i = 0; i < 3; i++) {
            if (D_800D6170[i] < arg4) {
                D_800D6110[i] = *arg0;
                D_800D614C[i] = arg1;
                D_800D6158[i] = arg2;
                D_800D6164[i] = arg3;
                D_800D6170[i] = arg4;
                ok = 1;
                break;
            }
        }
    } else {
        D_800D6110[D_800D6134] = *arg0;
        D_800D614C[D_800D6134] = arg1;
        D_800D6158[D_800D6134] = arg2;
        D_800D6164[D_800D6134] = arg3;
        D_800D6170[D_800D6134] = arg4;
        D_800D6134++;
        ok = 1;
    }
    if (ok) {
        for (n = D_800DDC60; n != NULL; n = n->next) {
            if (!(n->unk52 & 0x40)) {
                n->unk50 |= 4;
            }
        }
        for (n = D_800D6180; n != NULL; n = n->next) {
            if (!(n->unk52 & 0x40)) {
                n->unk50 |= 4;
            }
        }
    }
}
