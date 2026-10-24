#include "common.h"

typedef struct {
    u8 pad0[0x8];
    s16 delta;
    s16 pad;
    void (*fn)(u8 *, s32);
} VT;

extern void func_8005EA48(u8 *);
extern void func_8007C620(u8 *, s32);
extern u8 D_8001E188[];

void func_8007CDE4(u8 *arg0, s32 arg1) {
    u8 *o;

    *(u8 **)(arg0 + 0x44) = D_8001E188;
    o = *(u8 **)(arg0 + 0x54);
    if (o != NULL) {
        VT *vt = *(VT **)(o + 0x44);
        vt->fn(o + vt->delta, 3);
    }
    func_8007C620(arg0, 0);
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }

}
