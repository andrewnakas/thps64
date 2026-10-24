/* cflags: -O2 */
#include "common.h"

s32 func_8009CAD0(f32 *); /* extern */

f32 *func_8009CB68(f32 *arg0, f32 *arg1) {
    func_8009CAD0(arg0);
    arg0[0] = arg1[0];
    arg0[5] = arg1[1];
    arg0[10] = arg1[2];
    return arg0;
}
