#include "common.h"

typedef struct Vec80072EB8 { s32 x, y, z; } Vec80072EB8;
typedef struct State80072EB8 {
    u8 pad0[0x2FC];
    Vec80072EB8 unk2FC;
} State80072EB8;

void func_80072EB8(State80072EB8 *arg0, Vec80072EB8 *arg1) {
    arg0->unk2FC = *arg1;
}
