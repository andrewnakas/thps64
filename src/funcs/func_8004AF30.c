#include "common.h"

typedef struct {
    u8 pad[8];
    s16 off;
    s16 pad2;
    void (*fn)(void *, s32);
} VtEntry;

void func_8004AF30(void *arg0) {
    u8 *obj;
    VtEntry *vt;

    *(u16 *)((u8 *)arg0 + 0x52) &= 0xFFF7;
    obj = *(u8 **)((u8 *)arg0 + 0x14C);
    if (obj != 0) {
        vt = *(VtEntry **)(obj + 0x44);
        vt->fn(obj + vt->off, 3);
        *(void **)((u8 *)arg0 + 0x14C) = 0;
    }
}
