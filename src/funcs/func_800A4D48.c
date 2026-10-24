/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} G8;

typedef struct {
    u8 pad0[0x120];
    u8 unk120[0x650 - 0x120];
    u16 unk650;
} Obj4D48;

extern void func_80001A30(u8 *, s32);
extern void func_8009DC3C(u8 *);
extern s32 func_800BD9F4(void);
extern G8 *D_800F36A4;

void func_800A4D48(Obj4D48 *arg0) {
    s32 m;

    func_8009DC3C(arg0->unk120);
    m = func_800BD9F4();
    func_80001A30(arg0->unk120, m);
    { G8 *_g = (G8 *)(D_800F36A4++); _g->w0 = 0xDA380007; _g->w1 = m; }
    { G8 *_g = (G8 *)(D_800F36A4++); _g->w0 = 0xDB0E0000; _g->w1 = arg0->unk650; }
}
