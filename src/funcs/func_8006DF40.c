/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct {
    s16 v[32];
    u16 unk40;
    u16 unk42;
} S8006DF40;

s32 func_8000574C(s32);
void func_8006D9F8(s32);
void func_8006E9CC(void);
void func_80086E6C(s32, f32, f32, u16, s32, s32, s32, void *, s16 *);
void func_8009E0F0(void *, s32, s32);
extern u8 D_800D0FC0[];
extern s32 D_800DC950;
extern S8006DF40 *D_800DCA9C;
extern u8 D_800DCAA4;
extern u16 D_800DCAAC;
extern u8 D_800DCC1E;
extern u8 D_800FBB90[];

s32 func_8006DF40(s32 arg0, s32 arg1, s32 arg2) {
    s16 buf[128];
    s16 *out;
    s16 *dst;
    s32 n;
    S8006DF40 *p;
    u8 *g;

    func_8006D9F8(arg2);
    if (D_800DCC1E != 0) {
        func_8006E9CC();
    }
    n = func_8000574C(arg2);
    if (D_800DCA9C != NULL) {
        D_800DCA9C->unk42 = n;
    }
    out = NULL;
    if (D_800DCA9C != NULL) {
        func_8009E0F0(buf, 0, 0x100);
        out = buf;
    }
    p = D_800DCA9C;
    dst = out;
    while (1) {
        if (n == 0) {
            break;
        }
        if (p != NULL) {
            s32 v = p->v[n & 0x1F];
            if (v < 0) {
                s32 sq;
                s32 r;
                v = -v;
                sq = v * v;
                if (arg1 + sq >= p->unk40) {
                    r = 300;
                    p->unk42--;
                } else {
                    r = sq;
                }
                *dst = r;
            }
        }
        dst++;
        n--;
    }
    g = D_800D0FC0;
    if (*(volatile s32 *)(g + 0xEC8) != 0) {
        func_80086E6C(*(volatile s32 *)(g + 0xEC8), (f32)arg0, (f32)arg1, D_800DCAAC, D_800DC950, arg2, D_800DCAA4, D_800FBB90, out);
    }
    return 1;
}
