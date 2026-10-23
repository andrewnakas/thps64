#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Unk566C;

extern Unk566C D_800F566C;
extern u8 D_800D3EB0[];
s32 func_80039328(void *, s32);
void func_8009B650(void *, s32);

void func_8003925C(void) {
    Unk566C *p = &D_800F566C;
    s32 r = func_80039328(p, 0);
    s32 t = p->unk4;
    t += r;
    func_8009B650(D_800D3EB0, t);
}
