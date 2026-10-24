/* cflags: -O2 */
#include "common.h"

extern u8 *D_800ECC34;

s32 func_800B02E4(s32 arg0) {
    return (f32)((f32)arg0 * (f32)*(s32 *)(D_800ECC34 + 0x54) / 1000000.0 + 0.5);
}
