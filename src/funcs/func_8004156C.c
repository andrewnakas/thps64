#include "common.h"

s32 func_8003FF2C(s32);

s32 func_8004156C(s32 p, s32 *out, s32 arg2) {
    s32 d;
    *out = func_8003FF2C(arg2);
    switch (*(s32 *)(p + 0x38)) {
    case 50:
        d = *out;
        if (d == 1) {
            return 51;
        } else if (d == -1) {
            return 58;
        }
        break;
    case 51:
        d = *out;
        if (d == 1) {
            return 52;
        } else if (d == -1) {
            return 50;
        }
        break;
    case 52:
        d = *out;
        if (d == 1) {
            return 53;
        } else if (d == -1) {
            return 51;
        }
        break;
    case 53:
        d = *out;
        if (d == 1) {
            return 54;
        } else if (d == -1) {
            return 52;
        }
        break;
    case 54:
        d = *out;
        if (d == 1) {
            return 55;
        } else if (d == -1) {
            return 53;
        }
        break;
    case 55:
        d = *out;
        if (d == 1) {
            return 56;
        } else if (d == -1) {
            return 54;
        }
        break;
    case 56:
        d = *out;
        if (d == 1) {
            return 57;
        } else if (d == -1) {
            return 55;
        }
        break;
    case 57:
        d = *out;
        if (d == 1) {
            return 58;
        } else if (d == -1) {
            return 56;
        }
        break;
    case 58:
        d = *out;
        if (d == 1) {
            return 50;
        } else if (d == -1) {
            return 57;
        }
        break;
    }
    return *(s32 *)(p + 0x38);
}
