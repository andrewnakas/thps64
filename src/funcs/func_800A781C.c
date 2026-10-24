/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x20];
    u32 mode;
    u8 pad24[0x124 - 0x24];
    u8 map[0x100];
} Font800A781C;

s32 func_800A781C(Font800A781C *arg0, u8 c, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    *arg5 = 0;
    *arg4 = 0;
    *arg3 = 0;
    *arg2 = 0;
    switch (arg0->mode) {
        case 5:
            if (arg0->map[c] == 0xFE) {
                return -1;
            }
            if (arg0->map[c] != 0xFF) {
                return arg0->map[c];
            }
            return -2;
        case 2:
            if ((u8)(c - '0') < 10) {
                return c - '0';
            }
            switch (c) {
                case ' ':
                    return -1;
                case '+':
                    return 0xA;
                case '-':
                    return 0xB;
                case '*':
                    return 0xC;
                case '/':
                    return 0xD;
                case '.':
                    return 0xE;
                case ':':
                    return 0xF;
                case '=':
                    return 0x10;
            }
            return -2;
        case 0:
        case 1:
            if ((u8)(c - 'a') < 26) {
                return c - 'a';
            }
            if ((u8)(c - 'A') < 26) {
                return c - 'A';
            }
            if ((u8)(c - '0') < 10) {
                return c - 0x16;
            }
            switch (c) {
                case ' ':
                    return -1;
                case ',':
                    return 0x24;
                case '.':
                    *arg4 = 1;
                    return 0x25;
                case ':':
                    *arg4 = 1;
                    return 0x26;
                case '[':
                    return 0x27;
                case ']':
                    *arg3 = 1;
                    return 0x27;
                case '>':
                    return 0x28;
                case '<':
                    *arg2 = 1;
                    return 0x28;
                case '/':
                    return 0x29;
                case '\'':
                    return 0x2B;
                case '#':
                case '?':
                    return 0x2D;
                case ')':
                    return 0x2F;
                case '&':
                    return 0x30;
                case '~':
                    *arg5 = 1;
                    return 0x31;
                case '`':
                    *arg5 = 1;
                    *arg2 = 1;
                    return 0x2A;
                case '!':
                    *arg5 = 1;
                case '+':
                    return 0x2A;
                case '|':
                    *arg5 = 1;
                    return 0x32;
                case '"':
                    *arg5 = 1;
                    return 0x33;
                case '@':
                    return 0x2C;
                case '(':
                    return 0x2E;
            }
            return -2;
        case 6:
            if ((u8)(c - 'a') < 26) {
                return c - 'a';
            }
            if ((u8)(c - 'A') < 26) {
                return c - 'A';
            }
            if ((u8)(c - '0') < 10) {
                return c - 0x16;
            }
            switch (c) {
                case ' ':
                    return -1;
                case '?':
                    return 0x24;
                case '!':
                    return 0x25;
                case ':':
                    *arg4 = 1;
                    return 0x26;
                case '.':
                    *arg4 = 1;
                    return 0x27;
                case '\'':
                    *arg4 = 1;
                    return 0x28;
                case '-':
                    return 0x29;
                case '+':
                    return 0x2B;
                case '#':
                    return 0x2D;
                case '*':
                    return 0x2F;
                case '@':
                    return 0x30;
                case '=':
                    return 0x31;
                case '%':
                    return 0x2A;
                case ',':
                    *arg4 = 1;
                    return 0x2C;
                case '"':
                    *arg4 = 1;
                    return 0x2E;
            }
            return -2;
    }
    return -2;
}
