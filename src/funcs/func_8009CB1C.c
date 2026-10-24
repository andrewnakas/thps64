/* cflags: -O2 */
#include "common.h"

f32 *func_8009CAD0(f32 *);

f32 *func_8009CB1C(f32 *a0, f32 *a1) {
    func_8009CAD0(a0);
    a0[12] = a1[0];
    a0[13] = a1[1];
    a0[14] = a1[2];
    return a0;
}
