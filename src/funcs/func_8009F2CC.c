/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 quot;
    s32 rem;
} Div;

Div func_8009F1D0(s32, s32);
extern s32 D_800EA130;
extern s32 D_800EA134;

f32 func_8009F2CC(void) {
    Div d;
    Div e;
    s32 z;

    e = func_8009F1D0(D_800EA130, 53668);
    d = e;
    D_800EA130 = d.rem * 40014 - d.quot * 12211;
    e = func_8009F1D0(D_800EA134, 52774);
    d = e;
    D_800EA134 = d.rem * 40692 - d.quot * 3791;
    z = D_800EA130 - D_800EA134;
    if (z < 1) {
        z += 2147483562;
    }
    return (f32)(z - 1) / 2147483520.0f;
}
