/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u32 unkC;
    u8 pad10[0x84];
    u32 unk94;
    u8 pad98[0x25];
    s8 unkBD;
    u8 padBE[0x16];
    u8 unkD4;
    u8 padD5[4];
    u8 unkD9;
    u8 unkDA;
} S;

void func_800AD4FC(S *arg0) {
    u32 t;

    do {
        t = arg0->unkD9 + arg0->unkD4;
        arg0->unk94 += 0x100;
        if (t < 0x40) {
            arg0->unkD9 = t;
        } else {
            arg0->unkD9 = t & 0x3F;
            t >>= 6;
            if (arg0->unkDA == 0) {
                arg0->unkBD += t;
                if (arg0->unkBD < 0) {
                    arg0->unkBD = 0x7F;
                    arg0->unkDA = 1;
                }
            } else {
                arg0->unkBD -= t;
                if ((u8)(arg0->unkBD - 1) >= 0x7F) {
                    arg0->unkBD = 0;
                    arg0->unkDA = 0;
                }
            }
        }
    } while (arg0->unk94 < arg0->unkC);
}
