#include "common.h"

typedef struct {
    u8 pad_000[0x4F0];
    s8 field_4F0;
    u8 pad_4F1[0x5F];
    s32 field_550;
    s32 field_554;
} State80088C50;

void func_80039E60(s32, s32, s32);
void func_80087DB0(void *);

s32 func_80088C50(State80088C50 *arg0) {
    s32 inner_index0;
    s32 inner_index1;
    s32 inner_index2;
    s32 inner_index3;
    s32 outer_index0;
    s32 outer_index1;
    s32 outer_index2;
    s32 outer_index3;
    s8 *inner;
    s8 *row;
    register s8 *outer __asm__("$7");

    outer_index0 = 0;
    /* The binary inlines this scan separately for each of the four selections. */
    if (arg0->field_4F0 == 0) {
        outer = (s8 *)arg0;
next_entry0:
        if (outer_index0 < 4) {
            inner_index0 = 0;
            if (outer[0x539] != outer[0x535]) {
                row = outer;
                __asm__("" : "+r" (row), "+r" (inner_index0));
                inner = (s8 *)arg0 + inner_index0;
                do {
                    if (inner[0x535] != row[0x535]) {
                        inner_index0 += 1;
                    } else {
                        if (outer_index0 != inner_index0) {
                            inner[0x535] = (s8) (u8) row[0x539];
                        }
                        inner_index0 += 1;
                    }
                    inner = (s8 *)arg0 + inner_index0;
                } while (inner_index0 < 4);
                outer[0x539] = (s8) (u8) outer[0x535];
            }
            outer += 1;
            outer_index0 += 1;
            goto next_entry0;
        }
    }
    if (arg0->field_4F0 == 1) {
        outer_index1 = 0;
        outer = (s8 *)arg0;
next_entry1:
        if (outer_index1 < 4) {
            inner_index1 = 0;
            if (outer[0x539] != outer[0x535]) {
                row = outer;
                __asm__("" : "+r" (row), "+r" (inner_index1));
                inner = (s8 *)arg0 + inner_index1;
                do {
                    if (inner[0x535] != row[0x535]) {
                        inner_index1 += 1;
                    } else {
                        if (outer_index1 != inner_index1) {
                            inner[0x535] = (s8) (u8) row[0x539];
                        }
                        inner_index1 += 1;
                    }
                    inner = (s8 *)arg0 + inner_index1;
                } while (inner_index1 < 4);
                outer[0x539] = (s8) (u8) outer[0x535];
            }
            outer += 1;
            outer_index1 += 1;
            goto next_entry1;
        }
    }
    outer_index2 = 0;
    if (arg0->field_4F0 == 2) {
        outer = (s8 *)arg0;
next_entry2:
        if (outer_index2 < 4) {
            inner_index2 = 0;
            if (outer[0x539] != outer[0x535]) {
                row = outer;
                __asm__("" : "+r" (row), "+r" (inner_index2));
                inner = (s8 *)arg0 + inner_index2;
                do {
                    if (inner[0x535] != row[0x535]) {
                        inner_index2 += 1;
                    } else {
                        if (outer_index2 != inner_index2) {
                            inner[0x535] = (s8) (u8) row[0x539];
                        }
                        inner_index2 += 1;
                    }
                    inner = (s8 *)arg0 + inner_index2;
                } while (inner_index2 < 4);
                outer[0x539] = (s8) (u8) outer[0x535];
            }
            outer += 1;
            outer_index2 += 1;
            goto next_entry2;
        }
    }
    if (arg0->field_4F0 == 3) {
        outer_index3 = 0;
        outer = (s8 *)arg0;
next_entry3:
        if (outer_index3 < 4) {
            inner_index3 = 0;
            if (outer[0x539] != outer[0x535]) {
                row = outer;
                __asm__("" : "+r" (row), "+r" (inner_index3));
                inner = (s8 *)arg0 + inner_index3;
                do {
                    if (inner[0x535] != row[0x535]) {
                        inner_index3 += 1;
                    } else {
                        if (outer_index3 != inner_index3) {
                            inner[0x535] = (s8) (u8) row[0x539];
                        }
                        inner_index3 += 1;
                    }
                    inner = (s8 *)arg0 + inner_index3;
                } while (inner_index3 < 4);
                outer[0x539] = (s8) (u8) outer[0x535];
            }
            outer += 1;
            outer_index3 += 1;
            goto next_entry3;
        }
    }
    if (arg0->field_4F0 == 4) {
        arg0->field_550 = (s32) (arg0->field_550 == 0);
    }
    if (arg0->field_4F0 == 5) {
        arg0->field_554 = (s32) (arg0->field_554 == 0);
    }
    if (arg0->field_4F0 == 6) {
        func_80087DB0(arg0);
    }
    if (arg0->field_4F0 == 7) {
        func_80039E60(0x93, 0x2710, 0);
        return 0x18;
    }
    func_80039E60(0x91, 0x2710, 0);
    return 0;
}
