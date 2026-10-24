#include "common.h"

typedef struct State80072FE8 {
    u8 pad0[0x13B0];
    void *unk13B0;
} State80072FE8;

void func_8009E334(void *);
extern u8 D_8001D360;

void func_80072FE8(State80072FE8 *arg0, s32 arg1) {
    s32 temp_a1;

    arg0->unk13B0 = &D_8001D360;
    temp_a1 = arg1 & 1;
    if (temp_a1 != 0) {
        func_8009E334(arg0);
    }
}
