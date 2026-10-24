/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x66];
    u16 unk66;
} Res;

typedef struct {
    u8 pad0[4];
    Res *unk4;
} Handle;

typedef struct {
    u8 pad0[0x508];
    Res *unk508;
} Obj;

Handle *func_800BAB04(void *, s32);
void func_800BAC04(void *, s32);
extern u8 D_800EECF0[];

void func_8009B5B0(Obj *arg0, s32 arg1) {
    if (arg0->unk508 != NULL) {
        if (arg1 == arg0->unk508->unk66) {
            return;
        }
        func_800BAC04(D_800EECF0, arg0->unk508->unk66);
        arg0->unk508 = NULL;
    }
    if (arg1 != -1) {
        arg0->unk508 = func_800BAB04(D_800EECF0, arg1)->unk4;
    }
}
