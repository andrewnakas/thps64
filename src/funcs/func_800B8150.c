/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x20];
    s16 delta;
    s16 pad22;
    s32 (*fn)(u8 *);
} VT;

extern void func_8009B650(s32 **, s32);
extern s32 func_800BA9EC(u8 *, s32);
extern s32 *D_800EECA0;
extern u8 *D_800F5660;
extern u8 D_800F566C[];

s32 func_800B8150(void) {
    u8 *o = D_800F5660;
    VT *vt = *(VT **)(o + 0x1C4);
    s32 v;

    v = func_800BA9EC(D_800F566C, vt->fn(o + vt->delta));
    func_8009B650(&D_800EECA0, *(s32 *)(D_800F566C + 4) + v);
    return *D_800EECA0;

}
