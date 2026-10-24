#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
} E18;

extern s32 func_80049034(s32, s32, s32);

static __inline__ s32 find(u8 *arg0, s32 arg1) {
    s32 i;
    E18 *e;

    i = 0;
    if (arg0[5] != 0) {
        e = (E18 *)arg0;
        do {
            if (func_80049034(arg1, e->unk14, -1) != 0) {
                return i;
            }
            i++;
            e++;
        } while (i < arg0[5]);
    }
    return 0;
}

void func_80095D5C(u8 *arg0, s32 arg1) {
    s32 i = find(arg0, arg1);
    u8 *p = arg0;
    p += i * 0x18;
    p[0x22] = 1;
}
