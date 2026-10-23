#include "common.h"

typedef struct {
    u8 pad[0x38];
    s16 off;
    u8 pad2[2];
    void (*fn)(void *);
} VT;

extern s32 func_8004AEE0(u8 *);

void func_80067238(u8 *arg0) {
    VT *vt;

    if (func_8004AEE0(arg0) == 0) {
        *(u16 *)(arg0 + 0x52) |= 0x40;
        *(u16 *)(arg0 + 0) |= 0x41;
        vt = *(VT **)(arg0 + 0x48);
        vt->fn(arg0 + vt->off);
    }
}
