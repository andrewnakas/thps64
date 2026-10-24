#include "common.h"

void func_8005EA48(void *);
extern u8 D_8001E1C8[];
extern u8 D_8001E388[];
extern s32 D_800DE520;

typedef struct {
    u8 pad0[0x44];
    void *unk44;
    u8 pad48[8];
    void *unk50;
} Obj;

void func_8007C620(Obj *arg0, s32 arg1) {
    arg0->unk44 = D_8001E1C8;
    func_8005EA48(arg0->unk50);
    arg0->unk44 = D_8001E388;
    D_800DE520 -= 1;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
