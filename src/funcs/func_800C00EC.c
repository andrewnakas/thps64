#include "common.h"
typedef struct { u8 pad0[0x40]; s64 unk40[8]; u8 pad80[0x18]; } S;
extern S D_800F32C8[];
void func_800C00EC(void) {
    s32 i;
    S *p;
    s64 *q;
    s32 end;

    i = 4;
    end = -1;
    p = D_800F32C8;
    q = p->unk40;
    do {
        q[7] = 0;
        q[4] = 0;
        q[6] = 0;
        q[0] = 0;
        q[5] = 0;
        q += 19;
    } while (--i != end);
}
