#include "common.h"

typedef struct State80072BCC {
    u8 pad0[0x2A8];
    u16 *unk2A8;
} State80072BCC;

void func_80072BCC(State80072BCC *arg0) {
    s32 depth = 0;
    u16 command;

    while (1) {
        command = *arg0->unk2A8++;
        if (command == 0x4120) {
            if (depth == 0) {
                break;
            }
            depth--;
        } else if ((u16)(command - 0x4112) < 5U) {
            depth++;
        }
        if (command == 0x4100) {
            break;
        }
    }
}
