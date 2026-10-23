#include "common.h"

extern u16 **D_800DACB0;

u16 *func_80061904(s32 arg0) {
    u16 *p;

    p = D_800DACB0[arg0];
    switch (*p) {
        case 1:
            return p + 3;
        case 5:
            return p + 2;
        case 2:
        case 3:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 1000:
        case 1001:
            return p + 1;
    }
}
