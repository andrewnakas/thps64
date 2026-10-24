/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x8];
    s32 unk20;
} Sub800AC504;

typedef struct {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0x2C];
    Sub800AC504 *unk74;
    Sub800AC504 *unk78;
    u8 pad7C[0xB4];
} Ent800AC504;

extern s32 D_800FC2F0;
extern Ent800AC504 *D_800FC2F8;

s32 func_800AC504(s32 arg0) {
    s32 i;
    s32 n;
    Ent800AC504 *p;
    Sub800AC504 *s;

    if (arg0 == 0) {
        return 0;
    }
    p = D_800FC2F8;
    n = D_800FC2F0;
    for (i = 0; i < n; i++, p++) {
        if (p->unk44 == arg0) {
            if (p->unk74 != NULL) {
                return p->unk74->unk20;
            }
            return p->unk78->unk14;
        }
    }
    return 0;
}
