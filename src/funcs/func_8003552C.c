/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    void *a;
    s32 b;
} Pair8003552C;

s32 func_80038F9C(void *, s32);
extern s32 D_800D36D0;
extern s32 D_800D36E4;
extern u8 D_800FA140[];
extern s32 D_800FA350;
extern Pair8003552C D_800FA3B0[];

void func_8003552C(s32 arg0) {
    Pair8003552C *p;
    s32 *q;
    s32 r;
    s32 i;
    s32 found;
    s32 b;

    if ((D_800FA350 != 0x19) || (arg0 != 0x287DA779)) {
        b = (s32)D_800FA3B0;
        p = (Pair8003552C *)(D_800D36E4 * 8 + b);
        q = &p->b;
        i = 0;
        if (D_800D36D0 > 0) {
            do {
                p->a = &D_800FA140[i * 0x58];
                found = 1;
                r = func_80038F9C(&D_800FA140[i * 0x58], arg0);
                *q = r;
                if (r != 0) {
                    goto done;
                }
                i++;
            } while (i < D_800D36D0);
        }
        found = 0;
done:
        if (found != 0) {
            D_800D36E4 += 1;
        }
    }
}
