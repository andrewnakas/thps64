#include "common.h"

typedef struct Node5FD44 {
    u8 pad0[0x1C];
    struct Node5FD44 *next;
    u8 pad20[0x13E];
    u16 unk15E;
} Node5FD44;

void func_8004B0BC(Node5FD44 *);
void func_8004B13C(Node5FD44 *, Node5FD44 **);
extern Node5FD44 *D_800D6180;
extern Node5FD44 *D_800D6184;
extern s16 **D_800DACB0;
extern Node5FD44 *D_800DDC60;

void func_8005FD44(u16 *arg0, s32 arg1) {
    u16 *p;
    s32 i;
    s32 n;
    s32 id;
    Node5FD44 **q;
    s16 t;
    Node5FD44 *e;

    p = arg0 + 1;
    i = 0;
    n = *arg0;
    while (1) {
        if (i < n) {
            id = *p;
            t = *D_800DACB0[id];
            if (t == 1 || t == 7) {
                if (arg1 == 5) {
                    q = &D_800DDC60;
                    for (e = D_800DDC60; e != NULL; e = e->next) {
                        if (e->unk15E == id) {
                            func_8004B13C(e, q);
                        }
                    }
                    q = &D_800D6180;
                    for (e = D_800D6180; e != NULL; e = e->next) {
                        if (e->unk15E == id) {
                            func_8004B13C(e, q);
                        }
                    }
                } else {
                    for (e = D_800D6184; e != NULL; e = e->next) {
                        if (e->unk15E == id) {
                            func_8004B0BC(e);
                        }
                    }
                }
            }
            /* the identical arms reproduce the game's register allocation (found by decomp-permuter) */
            if (e != NULL || q != NULL) {
                i++;
                p++;
            } else {
                i++;
                p++;
            }
        } else break;
    }
}
