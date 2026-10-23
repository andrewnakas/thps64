#include "common.h"

typedef struct {
    u8 pad_000[0x4F0];
    s8 field_4F0;
    u8 pad_4F1[0x44];
    s8 field_535[4];
    s8 field_539[4];
    u8 pad_53D[0x13];
    s32 field_550;
    s32 field_554;
} State80088C50;

void func_80039E60(s32, s32, s32);
void func_80087DB0(void *);

/* The binary repeats this scan once for each of the first four selections. */
static inline void func_80088C50_scan(State80088C50 *arg0) {
    s32 i;
    s32 j;
    s8 *entry;
    s8 *row;

    i = 0;
    entry = (s8 *)arg0;
    while (1) {
        if (i >= 4) {
            break;
        }
        if (entry[0x539] != entry[0x535]) {
            j = 0;
            row = entry;
            do {
                if (arg0->field_535[j] == row[0x535] && i != j) {
                    arg0->field_535[j] = row[0x539];
                }
                j++;
            } while (j < 4);
            entry[0x539] = entry[0x535];
        }
        entry++;
        i++;
    }
}

s32 func_80088C50(State80088C50 *arg0) {
    if (arg0->field_4F0 == 0) {
        func_80088C50_scan(arg0);
    }
    if (arg0->field_4F0 == 1) {
        func_80088C50_scan(arg0);
    }
    if (arg0->field_4F0 == 2) {
        func_80088C50_scan(arg0);
    }
    if (arg0->field_4F0 == 3) {
        func_80088C50_scan(arg0);
    }
    if (arg0->field_4F0 == 4) {
        arg0->field_550 = (arg0->field_550 == 0);
    }
    if (arg0->field_4F0 == 5) {
        arg0->field_554 = (arg0->field_554 == 0);
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
