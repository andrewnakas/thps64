/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct State80072EA8 {
    u8 pad0[0x2A4];
    u32 unk2A4;
} State80072EA8;

void func_80072EA8(State80072EA8 *arg0, u32 arg1) {
    arg0->unk2A4 |= arg1;
}
