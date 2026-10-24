/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x20];
    f32 unk20;
    u8 pad24[0x92];
    u8 unkB6;
    u8 padB7[0x1E];
    u8 unkD5;
    u8 padD6[0x6];
    f32 unkDC;
} Obj800AAD1C;

u8 *func_800AAD1C(Obj800AAD1C *arg0, u8 *arg1) {
    arg0->unkB6 = *arg1++;
    arg0->unkD5 = *arg1++;
    arg0->unk20 = (f32)*arg1 / 50.0;
    arg0->unkDC = 6.2831852 / (f32)arg0->unkD5;
    return arg1 + 1;
}
