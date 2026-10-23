#include "common.h"

typedef struct State80072CE8 {
    u8 pad0[0x15E];
    u16 unk15E;
    u8 pad160[0x139];
    u8 unk299;
} State80072CE8;

void func_80061BC8(void *);
extern u8 **D_800DACB0;

void func_80072CE8(State80072CE8 *arg0) {
    u16 index;

    if (arg0->unk299 == 0) {
        index = arg0->unk15E;
        if (index != 0xFFFF) {
            arg0->unk299 = 1U;
            func_80061BC8(D_800DACB0[arg0->unk15E] + 6);
        }
    }
}
