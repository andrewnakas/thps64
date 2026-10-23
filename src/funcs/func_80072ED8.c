#include "common.h"

typedef struct State80072ED8 {
    u8 pad0[0x2E4];
    s16 unk2E4[256];
} State80072ED8;

s16 func_80072ED8(State80072ED8 *arg0, s32 arg1) {
    return arg0->unk2E4[arg1 & 0xFF];
}
