/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x8];
    s32 unk8;
} Sub800AC4A0;

typedef struct {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0x2C];
    Sub800AC4A0 *unk74;
    Sub800AC4A0 *unk78;
    u8 pad7C[0xB4];
} Ent800AC4A0;

extern s32 D_800FC2F0;
extern Ent800AC4A0 *D_800FC2F8;

s32 func_800AC4A0(s32 arg0) {
    s32 i;
    s32 n;
    Ent800AC4A0 *p;
    Sub800AC4A0 *s;

    if (arg0 == 0) {
        return 0;
    }
    p = D_800FC2F8;
    n = D_800FC2F0;
    for (i = 0; i < n; i++, p++) {
        if (p->unk44 == arg0) {
            return (p->unk74 != NULL ? p->unk74 : p->unk78)->unk8;
        }
    }
    return 0;
}
