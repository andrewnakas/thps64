/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad2;
    void (*fn)(void *);
} VtEntry;

typedef struct {
    u8 pad0[0x38];
    VtEntry e38;
    u8 pad40[0x38];
    VtEntry e78;
    VtEntry e80;
} Vtbl800B3AB4;

typedef struct {
    u8 pad0[0x1C4];
    Vtbl800B3AB4 *vt;
} Obj800B3AB4;

void func_800B3AB4(Obj800B3AB4 *arg0) {
    arg0->vt->e80.fn((u8 *)arg0 + arg0->vt->e80.off);
    arg0->vt->e38.fn((u8 *)arg0 + arg0->vt->e38.off);
    arg0->vt->e78.fn((u8 *)arg0 + arg0->vt->e78.off);
}
