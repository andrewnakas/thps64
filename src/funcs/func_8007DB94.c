/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { s32 a; s32 b; } E8007DB94;
typedef struct {
    u8 pad[0x4C];
    E8007DB94 *unk4C;
    u32 unk50;
} S8007DB94;

void func_8007DB94(S8007DB94 *arg0, s32 arg1, s32 arg2) {
    E8007DB94 *p;
    u32 i;

    p = &arg0->unk4C[arg1 * arg0->unk50];
    for (i = 0; i < arg0->unk50; i++) {
        p[i].a = arg2;
    }
}
