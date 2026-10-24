/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[4];
    u8 pfs[0x68];
    s16 unk6C;
    u8 unk6E;
    u8 pad6F;
    f32 unk70;
    f32 unk74;
    u8 unk78;
    u8 pad79[3];
    f32 unk7C;
} Chan;

u32 func_8000B470(s32, void *, s32);
s32 func_8000C900(s32, void *, s32);
extern s32 D_800F30E4;
extern s32 D_800FC36C;
extern u8 D_800FC371;
extern Chan D_800FC380[];

void func_800B3130(s32 arg0) {
    Chan *c;
    u32 r;
    s16 v;

    c = &D_800FC380[arg0];
    if (D_800F30E4 == 0) {
        r = func_8000B470(D_800FC36C, c->pfs, arg0);
        c->unk6C = 0;
        D_800FC371 &= ~(1 << arg0);
        c->unk78 = 0;
        c->unk74 = c->unk70 = c->unk7C = 0.0f;
        switch (r) {
        case 0:
            v = 1;
            goto store;
        case 10:
            if (func_8000C900(D_800FC36C, c->pfs, arg0) == 0) {
                c->unk6C = 2;
                c->unk6E = 0;
                D_800FC371 |= 1 << arg0;
                break;
            }
            v = 3;
            goto store;
        case 11:
            c->unk6C = 2;
            if (func_8000C900(D_800FC36C, c->pfs, arg0) != 0) {
                c->unk6E = 1;
                v = 3;
            store:
                c->unk6C = v;
            }
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        }
    }
}
