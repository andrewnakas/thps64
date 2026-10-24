/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x1B0];
    s32 unk1B0;
    u8 pad1B4[4];
    s32 unk1B8;
    u8 pad1BC[8];
    void *unk1C4;
} Obj;

void func_80007430(void);
void func_8009E334(Obj *);
void func_8009ECF8(void *, s32);
void func_800A00AC(Obj *);
void func_800A03C8(void *, Obj *);
extern u8 D_80020A00[];
extern u8 D_800EA110[];
extern u8 D_800EA540[];

void func_8009FF4C(Obj *arg0, s32 arg1) {
    arg0->unk1C4 = D_80020A00;
    if (arg0->unk1B0 != 0) {
        func_80007430();
        func_800A00AC(arg0);
        if (arg0->unk1B8 != 0) {
            func_8009ECF8(D_800EA110, arg0->unk1B0);
        }
    }
    func_800A03C8(D_800EA540, arg0);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
