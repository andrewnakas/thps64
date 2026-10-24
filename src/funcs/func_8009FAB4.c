/* cflags: -O2 */
#include "common.h"

s32 func_8009F588(f32, f32); /* extern */

void func_8009FAB4(f32 arg0) {
    func_8009F588(__builtin_sqrtf(1.0001f - arg0 * arg0), arg0);
}
