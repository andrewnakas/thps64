/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad[0x1D4];
    s32 *unk1D4;
    s32 unk1D8;
} S800BC7F0;

void func_800BC7F0(S800BC7F0 *arg0, s32 arg1) {
    arg0->unk1D4[arg0->unk1D8++] = arg1;
}
