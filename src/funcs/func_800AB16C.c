/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
    s32 unk38;
    u8 pad3C[0x44];
    s32 unk80;
    u8 pad84[0x4];
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x12];
    s16 unkA2;
    s16 unkA4;
} Obj800AB16C;

s32 func_800AB16C(Obj800AB16C *arg0, u8 *arg1) {
    s32 x;
    s32 y;

    x = *arg1++ << 8;
    x += *arg1++;
    y = *arg1++ << 8;
    y += *arg1++;
    arg0->unkA2 = 1;
    arg0->unk38 = arg0->unk8C + y;
    y = *arg1++ << 8;
    y += *arg1++;
    arg0->unkA4 = 1;
    arg0->unk34 = arg0->unk88 + y;
    return arg0->unk80 + x;
}
