/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x40];
    s16 delta;
    s16 pad;
    void (*fn)(u8 *);
} VT;

extern void func_800BB308(u8 *);
extern void func_800BB364(u8 *);
extern void func_800BCF80(u8 *);
extern void func_800BCFAC(u8 *);
extern u8 D_800F0B10[];
extern u8 D_800F0DD0[];
extern s32 D_800F36BC;

void func_800B3B4C(u8 *arg0) {
    VT *vt;

    func_800BCF80(D_800F0DD0);
    func_800BB308(D_800F0B10);
    func_800BB364(D_800F0B10);
    vt = *(VT **)(arg0 + 0x1C4);
    D_800F36BC = 0;
    vt->fn(arg0 + vt->delta);
    func_800BCFAC(D_800F0DD0);

}
