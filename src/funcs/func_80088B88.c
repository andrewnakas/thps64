#include "common.h"

void func_80039E60(s32, s32, s32);

void func_80088B88(void *arg0, s32 arg1) {
    s32 value;
    s32 selection;
    s32 range;
    void *entry;

    value = *(u8 *) ((u8 *) arg0 + 0x4F0);
    selection = *(s8 *) ((u8 *) arg0 + 0x4F0);
    if (selection == 4) {
        (*(s32 *) ((u8 *) (arg0) + 0x550)) = (s32) ((*(s32 *) ((u8 *) (arg0) + 0x550)) == 0);
        func_80039E60(0x91, 0x2710, 0);
        return;
    }
    if (selection == 5) {
        (*(s32 *) ((u8 *) (arg0) + 0x554)) = (s32) ((*(s32 *) ((u8 *) (arg0) + 0x554)) == 0);
        func_80039E60(0x91, 0x2710, 0);
        return;
    }
    range = value - 6;
    entry = arg0 + selection;
    if ((u32) (range & 0xFF) >= 2U) {
        (*(u8 *) ((u8 *) (entry) + 0x535)) = (u8) ((*(u8 *) ((u8 *) (entry) + 0x535)) + arg1);
        func_80039E60(0x91, 0x2710, 0);
        entry = arg0 + (s8) (*(u8 *) ((u8 *) (arg0) + 0x4F0));
        value = (*(s8 *) ((u8 *) (entry) + 0x535));
        if (value >= 4) {
            (*(s8 *) ((u8 *) (entry) + 0x535)) = 0;
            return;
        }
        if (value < 0) {
            (*(s8 *) ((u8 *) (entry) + 0x535)) = 3;
        }
    }
}
