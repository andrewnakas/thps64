/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u8 pad0[0x80];
    s32 unk80;
    u8 pad84[4];
    s32 unk88;
    u8 pad8C[4];
    s32 unk90;
} Obj;

void func_800977C0(Obj *);
s32 func_800B4264(s32, s32);
s32 func_800B4240(s32, s32);
s32 func_800A0D4C(void *);
void func_80039E60(s32, s32, s32);
void func_800A3250(void *, u8, s32, s32);
extern s32 D_800E95D0;
extern s32 D_800EA550;
extern s32 D_800D3144;
extern u8 D_800D3130[];
extern u8 D_800D0FC2;

s32 func_800979CC(Obj *arg0) {
    s32 ret;
    s32 go;

    ret = 0;
    func_800977C0(arg0);
    go = ret;
    if (arg0->unk90 != 0) {
        if (func_800B4264(D_800E95D0, 0x4000) != 0 || (D_800EA550 == 0 && D_800D3144 == 0 && arg0->unk88 != 0)) {
            go = 1;
        }
        if (go == 0) {
            if (arg0->unk80 == 0) {
                goto first;
            }
            if (func_800B4264(D_800E95D0, 0x1000) == 0) {
                return ret;
            }
        }
        if (func_800A0D4C(D_800D3130) != 0) {
            func_80039E60(0x91, 10000, 0);
            func_800A3250(D_800D3130, D_800D0FC2, 1, arg0->unk90 == 0);
            arg0->unk90 = 0;
        }
        return ret;
    first:
        if (func_800B4240(D_800E95D0, 0x1000) == 0) {
            arg0->unk80 = 1;
        }
    } else if (D_800EA550 == 0) {
        ret = 1;
    }
    return ret;
}
