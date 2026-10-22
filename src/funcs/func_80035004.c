#include "common.h"

typedef struct {
    u8 pad0[0x10];
    u8 unk10[0xA4 - 0x10];
    u8 unkA4[0xD8 - 0xA4];
} A80035004;

typedef struct {
    u8 pad0[0x58];
} B80035004;

void func_800392A0(void *, s32);
void func_8009B114(void *, s32);
void func_8009BAD4(void *, s32);
void func_800A415C(void *, s32);
void func_800A6944(void *, s32);
extern s32 D_800D36F8;
extern s32 D_800F65E0;
extern A80035004 D_800F78C0[48];
extern B80035004 D_800FA140[6];
extern s32 D_800FA350;

void func_80035004(void) {
    A80035004 *a;
    B80035004 *b;
    A80035004 *pa;
    B80035004 *pb;
    A80035004 *ta;
    B80035004 *tb;

    func_8009B114(&D_800D36F8, 2);
    func_800A415C(&D_800F65E0, 2);
    ta = D_800F78C0;
    if (ta != NULL) {
        a = ta + 48;
        if (ta != a) {
            pa = D_800F78C0;
            do {
                a--;
                func_8009BAD4(a->unkA4, 2);
                func_800A6944(a->unk10, 2);
            } while (a != pa);
        }
    }
    tb = D_800FA140;
    if (tb != NULL) {
        b = tb + 6;
        if (tb != b) {
            pb = D_800FA140;
            do {
                b--;
                func_800392A0(b, 2);
            } while (b != pb);
        }
    }
    func_800392A0(&D_800FA350, 2);
}
