#include "common.h"
typedef struct { s32 x, y, z; } V3_F2;
s32 func_8009CAD0(void *, void *, void *);
s32 func_800390D8(void *arg0, void *arg1, void *arg2) {
    s32 r;
    r = func_8009CAD0(arg1, arg1, arg2);
    *(V3_F2 *)((u8 *)arg1 + 0x30) = *(V3_F2 *)((u8 *)arg2 + 0x24);
    return r;
}
