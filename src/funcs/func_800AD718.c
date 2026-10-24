/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u32 unkC;
    u8 pad10[8];
    u32 unk18;
    u8 pad1C[8];
    f32 unk24;
    u8 pad28[0xC];
    u8 *unk34;
    u8 pad38[0x34];
    f32 unk6C;
    f32 unk70;
    u8 pad74[0x30];
    u16 unkA4;
} Seq;

void func_800AD718(Seq *arg0) {
    u8 c;
    f32 f;

    do {
        arg0->unk18 += 0x100;
        if (--arg0->unkA4 == 0) {
            c = *arg0->unk34++;
            if ((s8)c < 0) {
                f = (f32)(c & 0x7F) - 64.0;
                arg0->unk70 = f;
                arg0->unk24 = f * arg0->unk6C;
                c = *arg0->unk34++;
                if ((s8)c < 0) {
                    arg0->unkA4 = (c & 0x7F) << 8;
                    arg0->unkA4 += *arg0->unk34++ + 2;
                } else {
                    arg0->unkA4 = c + 2;
                }
            } else {
                f = (f32)c - 64.0;
                arg0->unkA4 = 1;
                arg0->unk70 = f;
                arg0->unk24 = f * arg0->unk6C;
            }
        }
    } while (arg0->unk18 < arg0->unkC);
}
