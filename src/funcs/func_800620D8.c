#include "common.h"

typedef struct N620 {
    u8 pad0[0x10];
    union {
        s32 w;
        u16 h[2];
    } unk10;
    s32 unk14;
    u8 *unk18;
    s16 unk1C;
    s16 unk1E;
    struct N620 *unk20;
    struct N620 *unk24;
} N620;

extern void func_8005EA48(N620 *);
extern N620 *func_80062044(void);
extern void func_8007F198(s32, s32);
extern N620 *D_800DBAE0[];
extern s32 D_800FBB50;
extern N620 *D_800FBB54;

void func_800620D8(void) {
    N620 *n;
    N620 **tab;

    D_800FBB50 = 0;
    D_800FBB54 = D_800DBAE0[0];
    tab = D_800DBAE0;
    while ((n = func_80062044()) != NULL) {
        if (!(n->unk10.w & 0xF000)) {
            continue;
        }
        if (n->unk10.h[0] != 0) {
            continue;
        }
        (*(u16 *)(n->unk18 + 4))--;
        func_8007F198(n->unk1C, n->unk1E);
        if (n->unk20 != NULL) {
            n->unk20->unk24 = n->unk24;
        }
        if (n->unk24 != NULL) {
            n->unk24->unk20 = n->unk20;
        }
        if (n == tab[n->unk14 & 0x1FF]) {
            tab[n->unk14 & 0x1FF] = n->unk20;
        }
        func_8005EA48(n);
    }
}
