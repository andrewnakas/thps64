/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A85C8(void *, f32, f32, char *, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

typedef struct {
    u8 pad0[0x68];
    u8 a68[0x2B8 - 0x68];
    s32 v2B8;
    s32 v2BC;
    s32 v2C0;
    s32 v2C4;
} S800297DC;

void func_800297DC(S800297DC *arg0, char **lines, s32 n) {
    s32 i;
    s32 y;
    u8 c;

    for (i = 0; i < n; i++) {
        y = arg0->v2B8 - i * arg0->v2BC;
        if (i == n - 1 && y >= 0x1FE) {
            arg0->v2C4 = 1;
        }
        if ((u32)(y + 0x19) < 0x217) {
            c = *lines[i];
            if (c == ' ' || c == '#') {
                continue;
            }
            if (c != '~') {
                func_800A7AF8(arg0->a68, 0xFC, 0xC2, 0x6B, 0xFF);
                func_800A7B10(arg0->a68, 0x98, 0x5E, 7, 0xFF);
                func_800A85C8(arg0->a68, 1.4f, 2.0f, lines[i], 325.0f, y, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0);
            } else {
                func_800A7AF8(arg0->a68, 0xFF, 0x6E, 0x16, 0xFF);
                func_800A7B10(arg0->a68, 0xC3, 0x54, 5, 0xFF);
                func_800A85C8(arg0->a68, 1.5f, 2.0f, lines[i], 325.0f, y, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0);
            }
        } else if (y < -0x1A) {
            break;
        }
    }
}
