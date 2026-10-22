#include "common.h"

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
} VEnt80065A18;

typedef struct {
    u8 pad0[0x10];
    VEnt80065A18 die;
} VTbl80065A18;

void func_80043628(void *, s32, s32);
void func_80049E80(void *, s32, s32, s32, s32);

s32 func_80065A18(u8 *arg0, s32 arg1) {
    VTbl80065A18 *vt;

    (*(u8 *)(arg0 + 0x297))++;
    if (*(u16 *)(arg0 + 0x2CE) != 0) {
        if (*(s16 *)(arg0 + 0x162) > 0) {
            *(s16 *)(arg0 + 0x162) -= arg1;
            if (*(s16 *)(arg0 + 0x162) <= 0) {
                vt = *(VTbl80065A18 **)(arg0 + 0x48);
                vt->die.fn(arg0 + vt->die.delta);
                func_80043628(arg0, 0, 1);
            } else {
                func_80049E80(arg0, 3, 0xFF, 0xFF, 0xFF);
            }
        }
    }
    return 1;
}
