#include "common.h"

typedef struct {
    u8 pad[0x38];
    s16 off;
    u8 pad2[2];
    void (*fn)(void *);
} VtEnt;

void func_80067308(void *arg0) {
    VtEnt *vt;

    *(u16 *)arg0 |= 0x41;
    vt = *(VtEnt **)((u8 *)arg0 + 0x48);
    vt->fn((u8 *)arg0 + vt->off);
}
