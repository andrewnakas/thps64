/* cflags: -O2 */
#include "common.h"

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 pad3[0x69];
    u16 unk6C;
    u8 unk6E;
    u8 pad6F[0x11];
} Pad;

s32 func_800074F0(s32);
void func_80007574(Pad *);
void func_800B3130(s32);
extern s32 D_800FC36C;
extern Pad D_800FC380[];

s32 func_800B3260(s32 arg0) {
    Pad *p = &D_800FC380[arg0];

    p->unk6E = 0;
    p->unk6C = 0;
    if (func_800074F0(D_800FC36C) == 8) {
        return 0;
    }
    func_80007574(p);
    if (!(p->unk0 & 4)) {
        return 0;
    }
    if (!(p->unk2 & 1)) {
        return 0;
    }
    func_800B3130(arg0);
    return 1;
}
