#include "common.h"

void func_80088ED4(void *arg0) {
    s32 outer_index = 0;
    s32 inner_index;
    s8 *outer = arg0;
    s8 *inner;
    register s8 *row __asm__("$7");

next_entry:
    if (outer_index < 4) {
        inner_index = 0;
        if (outer[0x539] != outer[0x535]) {
            row = outer;
            /* Keep the inner row base separate from the advancing outer iterator. */
            for (inner_index = 0; inner_index < 4; inner_index++) {
                inner = (s8 *)arg0 + inner_index;
                if (inner[0x535] == row[0x535] && outer_index != inner_index) {
                    inner[0x535] = row[0x539];
                }
            }
            outer[0x539] = outer[0x535];
        }
        outer++;
        outer_index++;
        goto next_entry;
    }
}
