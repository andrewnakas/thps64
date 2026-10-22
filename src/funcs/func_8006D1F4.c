#include "common.h"

extern s32 D_800DC618;
extern s32 D_800DC92C;
extern s32 D_800DC930;

void func_8006D1F4(s32 arg0, s32 arg1) {
    if (D_800DC618 == 1) {
        switch (arg0) {
        case 1:
            D_800DC92C = arg1;
            break;
        case 2:
            D_800DC930 = arg1;
            break;
        }
    }
}
