#include "common.h"

extern u32 D_800D1E80;

s32 func_8002449C(void) {
    switch (D_800D1E80) {
        case 0: case 1: case 4: case 5: case 10: case 11: case 14: case 15:
        case 19: case 20: case 25: case 26: case 49: case 50: case 55: case 56:
        case 63:
            return 1;
        default:
            return 0;
    }
}
