/* cflags: -O2 */
#include "common.h"

s32 func_800A6730(s32 *); /* extern */
f64 func_800A67B4(s32 *); /* extern */
s32 func_800A6864(s32 *); /* extern */

void func_800C0150(f32 arg0) {
    s32 sp10[2];

    func_800A6730(sp10);
    func_800A6864(sp10);
    while (func_800A67B4(sp10) < (f64) arg0) {
    }
}
