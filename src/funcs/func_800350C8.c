#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 padC[0xD8 - 0xC];
} Unk800350C8;

extern s32 D_800D36EC;
extern Unk800350C8 D_800F78C0[];

s32 func_800350C8(s32 arg0) {
    s32 i;
    s32 n;
    s32 t;
    s32 q;
    Unk800350C8 *p;

    t = D_800D36EC;
    i = 0;
    if (t > 0) {
        q = (s32)D_800F78C0;
        n = t;
        p = (Unk800350C8 *)q;
        do {
            if (p->unk8 == arg0) {
                return p->unk4;
            }
            i++;
            p++;
        } while (i < n);
    }
    return 0;
}
