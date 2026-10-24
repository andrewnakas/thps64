/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 r, g, b;
} Col;

extern Col D_8001ED80;
extern Col D_8001ED84;
extern Col D_8001ED88;

void func_800866D8(s32 arg0, u8 *s, Col *def, Col *out) {
    Col c1 = D_8001ED80;
    Col c2 = D_8001ED84;
    Col c3 = D_8001ED88;
    s32 i = 0;
    u8 c;

    while (*s != 0) {
        if (*s == '[') {
            out[i] = c1;
            s++;
            i++;
            c = *s;
            if (c == 0) {
                return;
            }
            while (1) {
                if (c == ']') {
                    out[i] = c1;
                    break;
                }
                out[i] = c1;
                s++;
                i++;
                c = *s;
                if (c == 0) {
                    break;
                }
            }
            if (*s == 0) {
                return;
            }
        }
        if (*s == '{') {
            out[i] = c1;
            s++;
            i++;
            c = *s;
            if (c == 0) {
                return;
            }
            while (1) {
                if (c == '}') {
                    out[i] = c2;
                    break;
                }
                out[i] = c2;
                s++;
                i++;
                c = *s;
                if (c == 0) {
                    break;
                }
            }
            if (*s == 0) {
                return;
            }
        }
        if (*s == '<') {
            s++;
            out[i] = c3;
            i++;
            c = *s;
            if (c == 0) {
                return;
            }
            while (1) {
                if (c == '>') {
                    out[i] = c3;
                    break;
                }
                out[i] = c3;
                s++;
                i++;
                c = *s;
                if (c == 0) {
                    break;
                }
            }
            if (*s == 0) {
                return;
            }
            s++;
        } else {
            out[i] = *def;
            s++;
        }
        i++;
    }
}
