/* cflags: -O2 */
#include "common.h"

s32 func_80002B20(s32);

typedef struct {
    u8 pad0[0x22C0];
    s32 unk22C0;
    s32 unk22C4[4];
} Obj;

void func_800BC1E0(Obj *arg0, s32 arg1) {
    s32 mask = func_80002B20(1);

    if (++arg0->unk22C0 == 4) {
        arg0->unk22C0 = 0;
    }
    arg0->unk22C4[arg0->unk22C0] = arg1;
    func_80002B20(mask);
}
