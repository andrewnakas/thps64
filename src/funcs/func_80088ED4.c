#include "common.h"

void func_80088ED4(void *arg0) {
    s8 *row;
    s32 outer_index = 0;
    s32 inner_index;
    s8 *outer = arg0;
    s8 *inner;

    while (1) {
        if (outer_index >= 4) {
            break;
        }
        if (outer[0x539] != outer[0x535]) {
            for (inner_index = 0, row = outer; inner_index < 4; inner_index++) {
                inner = (s8 *)arg0 + inner_index;
                if (inner[0x535] == row[0x535] && outer_index != inner_index) {
                    inner[0x535] = row[0x539];
                }
            }
            outer[0x539] = outer[0x535];
        }
        outer++;
        outer_index++;
    }
}
