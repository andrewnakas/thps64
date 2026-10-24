/* cflags: -O2 */
#include "common.h"

void func_800B73D4(void *);
s32 func_800B7460(void *, s32, s32);

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Obj;

s32 func_800B7580(Obj *arg0) {
    s32 v;

    if (arg0->unk14 == 0) {
        return 1;
    }
    func_800B73D4(arg0);
    arg0->unk14 = 0;
    v = func_800B7460(arg0, 1, 8);
    if (v != 0) {
        arg0->unk10 = v;
        arg0->unkC = v;
    }
    return v != 0;
}
