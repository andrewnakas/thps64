/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    u32 *ptr;
    u32 acc;
    s32 left;
} BitW8006A380;

void func_8006A380(BitW8006A380 *w, s32 val, s32 n) {
    if (n != 0) {
        if (w->left < n) {
            w->acc &= (1 << (32 - w->left)) - 1;
            w->acc |= val << (32 - w->left);
            n -= w->left;
            val >>= w->left;
            *w->ptr++ = w->acc;
            w->acc = 0;
            w->left = 32;
        }
        w->acc &= (1 << (32 - w->left)) - 1;
        w->acc |= val << (32 - w->left);
        w->left -= n;
        if (w->left == 0) {
            *w->ptr++ = w->acc;
            w->acc = 0;
            w->left = 32;
        }
    }
}
