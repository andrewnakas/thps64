/* cflags: -O2 */
#include "common.h"

typedef struct { f32 a; s32 b; f32 c; } S800B1A10;
extern f32 D_800F329C;

void func_800B1A10(S800B1A10 *arg0) {
    s32 v;

    v = 1;
    arg0->a = 0.0f;
    arg0->c = 0.0f;
    if (D_800F329C != 1.0f) {
        v = 0;
    }
    arg0->b = v;
}
