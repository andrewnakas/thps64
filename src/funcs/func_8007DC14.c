#include "common.h"

typedef struct { s32 a; s32 b; } E8007DC14;
typedef struct {
    u8 pad[0x48];
    E8007DC14 *unk48;
    s32 pad4C;
    u32 unk50;
} S8007DC14;

void func_8007DC14(S8007DC14 *arg0, s32 arg1) {
    u32 i;

    for (i = 0; i < arg0->unk50; i += 2) {
        arg0->unk48[i].a = arg1;
    }
}
