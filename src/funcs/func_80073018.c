#include "common.h"

typedef struct State80073018 {
    u8 pad0[0x13B0];
    void * unk13B0;
} State80073018;

extern u8 D_8001D348;

State80073018 *func_80073018(State80073018 *arg0) {
    arg0->unk13B0 = &D_8001D348;
    return arg0;
}
