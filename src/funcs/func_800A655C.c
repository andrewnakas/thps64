/* cflags: -O2 */
#include "common.h"

s32 func_800A66F0(void *);                      /* extern */
f64 func_800A67B4(s32 *);                       /* extern */
extern s32 D_800EA570;

typedef struct {
    f64 last;
    f64 start;
    u8 pad10[0x8];
    f64 total;
    u8 pad20[0x20];
    s32 count;
    s32 period;
    u8 paused;
} Timer800A655C;

void func_800A655C(Timer800A655C *arg0) {
    f64 now;
    f64 d;

    now = func_800A67B4(&D_800EA570);
    if (arg0->paused == 0 && arg0->start != -1.0) {
        d = now - arg0->start;
        arg0->count++;
        arg0->start = -1.0;
        arg0->last = d;
        arg0->total += d;
        if (arg0->period != 0 && arg0->count % arg0->period == 0) {
            func_800A66F0(arg0);
        }
    }
}
