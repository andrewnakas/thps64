#include "common.h"

typedef struct {
    u8 pad0[0x44];
    void *unk44;
    u8 pad48[0x20];
    void *unk68;
} Obj8007C52C;

extern void func_8005EA48(void *);
extern u8 D_8001E1A8[];
extern u8 D_8001E388[];
extern s32 D_800DE520;

void func_8007C52C(Obj8007C52C *arg0, s32 arg1) {
    arg0->unk44 = D_8001E1A8;
    func_8005EA48(arg0->unk68);
    arg0->unk44 = D_8001E388;
    D_800DE520--;
    if (arg1 & 1) {
        func_8005EA48(arg0);
    }
}
