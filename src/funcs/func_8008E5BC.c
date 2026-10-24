/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct {
    s16 a, b, c, d;
} Box8;

extern Box8 D_8001FE74;
extern s32 D_800DE314;
extern s32 D_800DE318;
extern s32 D_800E9070;
extern u32 D_800E9074;
extern u32 D_800E9078;
extern s32 D_800E907C;

void func_8008E5BC(void) {
    Box8 r;
    u32 d;

    if (D_800E9070 != 0) {
        if (D_800DE318 != 0) {
            D_800E907C = 1;
            return;
        }
        if (D_800E907C != 0) {
            D_800E9074 += D_800DE314;
            r = D_8001FE74;
            d = D_800E9078;
            if (d == 0 || D_800E9074 > d) {
                r.c = 0x128;
            } else {
                r.c = (D_800E9074 * 0x128) / d;
            }
            D_800E907C = 0;
        }
    }
}
