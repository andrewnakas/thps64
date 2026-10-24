/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s32 *func_8005EAB4(u32, s32, s32);
extern s32 D_800DE524;

static __inline__ void clr(s32 *q, u32 size) {
    u32 i;
    for (i = 0; i < size; i++) {
        *q++ = 0;
    }
}

s32 *func_8007E618(u32 arg0) {
    s32 *p;

    if (D_800DE524 != 0) {
        p = func_8005EAB4(arg0, 0, 1);
    } else {
        p = func_8005EAB4(arg0, 0, 1);
    }
    clr(p, (arg0 + 3) >> 2);
    return p;

}
