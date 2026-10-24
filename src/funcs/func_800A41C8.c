/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 f[6];
    u16 unk18;
    u8 pad1A[2];
    u8 m0[0x40];
    u8 m1[0x40];
} Rec;

extern void func_8009C8EC(u8 *, u8 *);

void func_800A41C8(u8 *arg0) {
    Rec *r;

    r = (Rec *)(arg0 + (arg0[0x3A0]++ * 0x9C + 0x3A4));
    r->f[0] = *(f32 *)(arg0 + 0x160);
    r->f[1] = *(f32 *)(arg0 + 0x164);
    r->f[2] = *(f32 *)(arg0 + 0x168);
    r->f[3] = *(f32 *)(arg0 + 0x16C);
    r->f[4] = *(f32 *)(arg0 + 0x170);
    r->f[5] = *(f32 *)(arg0 + 0x174);
    r->unk18 = *(u16 *)(arg0 + 0x650);
    func_8009C8EC(r->m0, arg0 + 0xA0);
    func_8009C8EC(r->m1, arg0 + 0x120);

}
