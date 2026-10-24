/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x66];
    u16 unk66;
} Res;

typedef struct {
    u8 pad0[0x50];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    u8 pad5C[0x1C];
    s32 unk78;
    s32 unk7C;
    Res *unk80;
} Obj;

void func_8009E334(Obj *);
void func_8009ECF8(void *, s32);
void func_800BAC04(void *, s32);
extern u8 D_800EA110[];
extern u8 D_800EECF0[];

void func_800B81F0(Obj *arg0, s32 arg1) {
    func_8009ECF8(D_800EA110, arg0->unk54);
    func_8009ECF8(D_800EA110, arg0->unk58);
    func_8009ECF8(D_800EA110, arg0->unk50);
    func_8009ECF8(D_800EA110, arg0->unk78);
    func_8009ECF8(D_800EA110, arg0->unk7C);
    if (arg0->unk80 != NULL) {
        func_800BAC04(D_800EECF0, arg0->unk80->unk66);
    }
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
