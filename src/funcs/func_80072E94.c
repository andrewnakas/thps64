/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct State80072E94 {
    u8 pad0[0x2A4];
    u32 unk2A4;
} State80072E94;

void func_80072E94(State80072E94 *arg0, u32 arg1) {
    arg0->unk2A4 &= ~arg1;
}
