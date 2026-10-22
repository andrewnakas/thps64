#include "common.h"

typedef struct {
    u8 pad0[0x38];
    s32 val;
    u8 pad3C[0x78 - 0x3C];
} Ent800459B8;

void func_800057E4(void *, void *, s32, s32);
void func_80045870(s32);
void func_8006EE1C(void *, void *, s32, s32, s32);
extern s32 D_8001B25C;
extern s32 D_800C0E20;
extern Ent800459B8 D_800D5C1C[];
extern u8 *D_800D61A8;
extern s32 D_800DC95C;
extern s32 D_800DE7A0;
extern s32 D_800FA930;

void func_800459B8(void) {
    s32 n;
    s32 *p;
    s32 *s;

    if (D_800DE7A0 == 1) {
        n = *(s32 *)(D_800D61A8 + 0xEF8) + 1;
        *(s32 *)(D_800D61A8 + 0xEF8) = n;
        if (n == 5) {
            *(s32 *)(D_800D61A8 + 0xEF8) = 99;
            func_80045870(1);
            return;
        }
        p = &D_800FA930;
        s = &D_8001B25C;
        func_800057E4(p, s, n, D_800D5C1C[D_800C0E20].val);
        s = &D_800DC95C;
        func_8006EE1C(p, s, 1, 0, 0);
    }
}
