/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad[0x1E0];
    s32 *unk1E0;
    s32 unk1E4;
} S800BC970;
void func_800BC8B8(S800BC970 *);

void func_800BC970(S800BC970 *arg0, s32 arg1) {
    arg0->unk1E0[arg0->unk1E4++] = arg1;
    func_800BC8B8(arg0);
}
