#include "common.h"

extern s32 D_800DE7A0;
void func_800463CC(s32, s32, s32, s32);

void func_8004CACC(s32 p, s32 idx, s32 arg2, s32 score) {
    s32 *c;
    s32 t;
    if (*(s32 *)(p + 0x858) != 0) {
        if (D_800DE7A0 == 7) {
            *(s32 *)(p + 0x428) = 0;
        }
        c = (s32 *)(p + idx * 4);
        c[0x520 / 4]++;
        c[0x660 / 4]++;
        if (score < 0) {
            score = -score;
        } else {
            t = score;
            switch ((u32)c[0x520 / 4]) {
            case 0:
            case 1:
                break;
            case 2:
                { s32 m = t * 75; t = m / 100; }
                break;
            case 3:
                t = t / 2;
                break;
            case 4:
                t = t / 4;
                break;
            default:
                t = score / 10;
                break;
            }
            score = t;
        }
        if (*(s32 *)(p + 0x444) == 4) {
            s32 *d;
            score = 0;
            d = (s32 *)(p + idx * 4);
            d[0x520 / 4]--;
            d[0x660 / 4]--;
        }
        func_800463CC(p, arg2, score, 0);
    }
}
