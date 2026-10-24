/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *, s32);
} VEnt80081238;

extern s32 D_800C0E20;
extern u8 D_800DE640[];
extern u8 *D_800DE7A8;
extern s32 D_800DE9F4[];

void func_80081238(void) {
    u8 *p;
    u8 *o;
    VEnt80081238 *v;
    s32 *q;
    s32 sh;

    p = D_800DE640;
    if ((o = *(u8 **)(p + 0xB4)) != NULL) {
        v = (VEnt80081238 *)(*(u8 **)(o + 0x48) + 8);
        v->fn(o + v->off, 3);
    }
    if ((o = *(u8 **)(p + 0xB8)) != NULL) {
        v = (VEnt80081238 *)(*(u8 **)(o + 0x48) + 8);
        v->fn(o + v->off, 3);
    }
    if ((o = *(u8 **)(p + 0xBC)) != NULL) {
        v = (VEnt80081238 *)(*(u8 **)(o + 0x48) + 8);
        v->fn(o + v->off, 3);
    }
    *(u8 **)(p + 0xB4) = NULL;
    *(u8 **)(p + 0xB8) = NULL;
    *(u8 **)(p + 0xBC) = NULL;
    q = D_800DE9F4;
    q[*(s32 *)(D_800DE7A8 + 0x3E0) + 0x271] |= 1 << D_800C0E20;
}
