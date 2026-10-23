/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 id;
    u8 pad[0x54];
} Entry58;

s32 func_80038F9C(Entry58 *, s32);
extern s32 D_800D36D0;
extern Entry58 D_800FA140[];

s32 func_8003561C(s32 arg0, Entry58 **arg1, s32 *arg2) {
    s32 i;

    for (i = 0; i < D_800D36D0; i++) {
        *arg1 = &D_800FA140[i];
        if ((*arg2 = func_80038F9C(&D_800FA140[i], arg0)) != 0) {
            return 1;
        }
    }
    return 0;
}
