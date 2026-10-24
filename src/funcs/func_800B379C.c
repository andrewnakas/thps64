/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x6C];
    s16 unk6C;
    s16 pad6E;
    f32 unk70;
    f32 unk74;
    u8 pad78[8];
} Chan;

void func_80004ED0(void *, s32, s32);
void func_80005070(void *, s32, s32);
extern s32 D_800ECFB0;
extern u8 D_800FC350[];
extern Chan D_800FC380[];

void func_800B379C(s32 arg0, f32 arg1, f32 arg2) {
    struct {
        void *mq;
        s32 unk4;
    } lk;
    Chan *c;
    f32 v;

    if (D_800ECFB0 != 0) {
        lk.mq = D_800FC350;
        func_80005070(D_800FC350, 0, 1);
        c = &D_800FC380[arg0];
        if (c->unk6C == 2) {
            if (arg2 < 0.0f) {
                arg2 = 0.0f;
            } else if (1.0f < arg2) {
                arg2 = 1.0f;
            }
            if (!(arg2 < c->unk70)) {
                if (c->unk70 == arg2) {
                    v = arg1;
                    if (v < c->unk74) {
                        v = c->unk74;
                    }
                    c->unk74 = v;
                } else {
                    c->unk74 = arg1;
                    c->unk70 = arg2;
                }
            }
        }
        func_80004ED0(lk.mq, 0, 1);
    }
}
