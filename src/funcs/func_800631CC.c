#include "common.h"

typedef struct {
    u8 pad0[0x12];
    u8 x12;
    u8 pad13[0x48 - 0x13];
} Ent48;

s32 func_80049034(s32, Ent48 *, s32);
void func_80062548(s32, s32, s32);
extern Ent48 D_800DAF98[];

void func_800631CC(s32 arg0) {
    Ent48 *p;
    s32 i;
    s32 r;
    s32 r2;

    for (i = 0, p = D_800DAF98; i < 40; i++, p++) {
        if (func_80049034(arg0, p, -1) != 0) {
            r = i;
            goto found;
        }
    }
    r = -1;
found:
    if (D_800DAF98[r].x12 != 0) {
        for (i = 0, p = D_800DAF98; i < 40; i++, p++) {
            if (func_80049034(arg0, p, -1) != 0) {
                r2 = i;
                goto found2;
            }
        }
        r2 = -1;
found2:
        func_80062548(r2, 1, 0);
    }
}
