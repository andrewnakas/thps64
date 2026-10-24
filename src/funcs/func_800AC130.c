/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 unk44;
    u8 pad48[0x50];
    s16 unk98;
    u8 pad9A[0x2];
    s16 unk9C;
    u8 pad9E[0xA];
    u16 unkA8;
    u8 padAA[0x86];
} Ent800AC130;

extern s32 D_800FC2F0;
extern Ent800AC130 *D_800FC2F8;

s32 func_800AC130(s32 arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 cnt;
    Ent800AC130 *p;

    if (arg0 == 0) {
        return 0;
    }
    if (arg1 <= 0) {
        arg1 = 1;
    } else if (arg1 > 0x100) {
        arg1 = 0x100;
    }
    i = 0;
    cnt = 0;
    p = D_800FC2F8;
    for (; i < D_800FC2F0; i++, p++) {
        if (p->unk44 == arg0) {
            cnt++;
            p->unk98 = arg1;
            p->unk9C = (p->unkA8 * arg1) >> 7;
        }
    }
    return cnt;
}
