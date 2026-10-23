#include "common.h"

typedef struct State80072E88 {
    u8 pad0[0x2A4];
    u32 unk2A4;
} State80072E88;

u32 func_80072E88(State80072E88 *arg0, u32 arg1) {
    u32 flags = arg0->unk2A4;
    flags &= arg1;
    return flags;
}
