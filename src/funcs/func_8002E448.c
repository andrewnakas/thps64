#include "common.h"

void func_80039E60(s32, s32, s32);

void func_8002E448(u8 *arg0, s32 arg1) {
    s32 v;

    if (arg1 == 1) {
        v = *(s32 *)(arg0 + 0x5C0) - 1;
        *(s32 *)(arg0 + 0x5C0) = v;
        if (v == 20) {
            *(s32 *)(arg0 + 0x5C0) = 19;
        } else if (v == 21) {
            *(s32 *)(arg0 + 0x5C0) = 19;
        } else if (v == 22) {
            *(s32 *)(arg0 + 0x5C0) = 19;
        }
    } else if (arg1 == -1) {
        v = *(s32 *)(arg0 + 0x5C0) + 1;
        *(s32 *)(arg0 + 0x5C0) = v;
        if (v == 20) {
            *(s32 *)(arg0 + 0x5C0) = 23;
        } else if (v == 21) {
            *(s32 *)(arg0 + 0x5C0) = 23;
        } else if (v == 22) {
            *(s32 *)(arg0 + 0x5C0) = 23;
        }
    }
    if (arg1 != 0) {
        func_80039E60(0x90, 10000, 0);
        v = *(s32 *)(arg0 + 0x5C0);
        if (v < 0) {
            *(s32 *)(arg0 + 0x5C0) = *(s32 *)(arg0 + 0x5C8);
        } else if (*(s32 *)(arg0 + 0x5C8) < v) {
            *(s32 *)(arg0 + 0x5C0) = 0;
        }
    }
}
