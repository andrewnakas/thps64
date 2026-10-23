/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x10];
    s32 x10;
    u8 pad2[0x24 - 0x14];
} SCAB4;

extern SCAB4 D_800DCAB4[];
extern s32 D_800DC958;

s32 func_8006DCC4(u8 c) {
    s32 v;
    if (D_800DCAB4[D_800DC958].x10 < 15) {
        if ((u8)(c - '0') < 10) {
            return c - '0';
        }
        if (c == ':') {
            return 10;
        }
        return 0;
    }
    v = c;
    if (v == ' ') {
        return 0xFF;
    }
    if (v == '[') {
        return 0xFE;
    }
    if (v == ']') {
        return 0xFD;
    }
    if (v == '{') {
        return 0xFE;
    }
    if (v == '}') {
        return 0xFC;
    }
    if (v == '<') {
        return 0xFE;
    }
    if (v == '>') {
        return 0xFB;
    }
    if (v == '^') {
        return 0xFA;
    }
    if ((u8)(c - 'A') < 26) {
        return v - 'A';
    }
    if ((u8)(c - 'a') < 26) {
        return v - 'a';
    }
    if ((u8)(c - '0') < 10) {
        return c - '0' + 26;
    }
    switch (c) {
    case '!':
        return 0x25;
    case ':':
        return 0x26;
    case '.':
        return 0x27;
    case ',':
        return 0x28;
    case '-':
    case '_':
        return 0x29;
    case '%':
        return 0x2A;
    case '+':
        return 0x2B;
    case '\'':
        if (D_800DCAB4[D_800DC958].x10 >= 0x2D) {
            return 0x2C;
        }
    case '?':
        return 0x24;
    case '#':
        return 0x2D;
    case '"':
        return 0x2E;
    case '&':
        return 0x2F;
    case '@':
        return 0x30;
    default:
        return 0x24;
    }
}
