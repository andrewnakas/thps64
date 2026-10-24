/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 off;
    s16 pad;
    void (*fn)(void *);
} VEnt800A4DD0;

void func_80001A30(u8 *, s32);
void func_8009DC3C(u8 *);
void func_800A4EBC(u8 *);
void func_800A5648(u8 *);
s32 func_800BD9F4(void);
extern u8 *D_800EA560;

extern s32 D_800F36C0;
extern u8 *D_800F36C4[];

void func_800A4DD0(u8 *arg0) {
    u8 *m;
    VEnt800A4DD0 *v;

    D_800EA560 = arg0;
    m = arg0 + 0x120;
    func_8009DC3C(m);
    *(s32 *)(arg0 + 0x17C) = func_800BD9F4();
    func_80001A30(m, *(s32 *)(arg0 + 0x17C));
    { s32 n = D_800F36C0;
    { u8 **pp = &D_800F36C4[n]; *pp = arg0 + 0x17C; }
    v = (VEnt800A4DD0 *)(*(u8 **)(arg0 + 0x1C) + 8);
    D_800F36C0 = n + 1; }
    v->fn(arg0 + v->off);
    if (*(s32 *)(arg0 + 0x178) & 1) {
        func_800A4EBC(arg0);
    }
    if (*(s32 *)(arg0 + 0x178) & 4) {
        func_800A5648(arg0);
    }
}
