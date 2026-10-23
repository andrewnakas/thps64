#include "common.h"

typedef struct State800730AC {
    u8 pad0[0x13B0];
    void * unk13B0;
} State800730AC;

extern u8 D_8001D360;

State800730AC *func_800730AC(State800730AC *arg0) {
    arg0->unk13B0 = &D_8001D360;
    return arg0;
}
