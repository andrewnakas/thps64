#include "common.h"

void func_8004644C(u32 arg0, s16 *arg1, s16 *arg2) {
    switch (arg0) {
    case 0:
    case 1:
        *arg1 = 0;
        *arg2 = 0;
        break;
    case 4:
        *arg1 = 0;
        *arg2 = 0x3C;
        break;
    case 6:
        *arg1 = 0x80;
        *arg2 = 0x3C;
        break;
    case 2:
        *arg1 = 0x80;
        *arg2 = 0;
        break;
    case 5:
        *arg1 = 0;
        *arg2 = -0x3C;
        break;
    case 7:
        *arg1 = -0x80;
        *arg2 = -0x3C;
        break;
    case 3:
        *arg1 = -0x80;
        *arg2 = 0;
        break;
    }
}
