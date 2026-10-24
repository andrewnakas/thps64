/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x4];
    s32 unk4;
    u8 pad8[0x70];
    s32 unk78;
    u8 pad7C[0xB4];
} Ent800ABDA0;

extern s32 D_800FC2F0;
extern Ent800ABDA0 *D_800FC2F8;

s32 func_800ABDA0(s32 arg0) {
    s32 i;
    s32 n;
    s32 cnt;
    Ent800ABDA0 *p;

    i = 0;
    cnt = 0;
    p = D_800FC2F8;
    n = D_800FC2F0;
    for (; i < n; i++, p++) {
        if (p->unk4 != 0 && (p->unk78 != 0 ? (arg0 & 1) : (arg0 & 2))) {
            cnt++;
        }
    }
    return cnt;
}
