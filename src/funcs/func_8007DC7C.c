#include "common.h"

void func_8005EA48(void *);
extern u8 D_8001E2D8[];
extern u8 D_8001E388[];
extern s32 D_800DE520;

typedef struct {
    u8 pad0[0x44];
    void *unk44;
    void *unk48;
} Obj;

void func_8007DC7C(Obj *arg0, s32 arg1) {
    arg0->unk44 = D_8001E2D8;
    func_8005EA48(arg0->unk48);
    arg0->unk44 = D_8001E388;
    D_800DE520 -= 1;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
