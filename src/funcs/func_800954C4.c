/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    u8 *name;
    u8 pad18[0x60];
} E78;

extern s32 func_80049034(u8 *, s32, s32);
extern E78 D_800D5C1C[];
extern s32 D_800DE988;

E78 *func_800954C4(s32 arg0) {
    E78 *r;
    s32 i;

    r = NULL;
    i = 0;
    if (D_800D5C1C[0].name[0] != 0) {
        do {
            if (func_80049034(D_800D5C1C[i].name, arg0, -1) != 0) {
                r = &D_800D5C1C[i];
                D_800DE988 = i;
                break;
            }
            i++;
        } while (i < 41 && D_800D5C1C[i].name[0] != 0);
    }
    return r;
}
