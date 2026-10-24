/* cflags: -O2 */
#include "common.h"

extern s32 D_800FC310;

s32 func_800ADB48(s32 arg0) {
    s32 i;
    s32 v;
    s32 t;

    for (i = 0; i < 8; i++) {
        v = D_800FC310;
        t = v & 0x48000000;
        D_800FC310 = v * 2;
        if (t == 0x48000000 || t == 0x08000000) {
            D_800FC310 = (v * 2) | 1;
        }
    }
    return (f32)arg0 * ((f32)D_800FC310 * 1.52587890625e-05f * 1.52587890625e-05f);
}
