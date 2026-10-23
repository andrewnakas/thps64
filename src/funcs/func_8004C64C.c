/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_8004C64C(s32 cur, s32 target, s32 step) {
    if (cur < target) {
        if (target < cur + step) {
            return target;
        }
        return cur + step;
    }
    cur -= step;
    if (cur < target) {
        return target;
    }
    return cur;
}
