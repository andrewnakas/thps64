/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800A4C84;

typedef struct {
    u8 pad0[0x17C];
    s32 unk17C;
    u8 pad180[4];
    s32 unk184;
    u8 pad188[0x650 - 0x188];
    u16 unk650;
} S800A4C84;

void func_800A602C(void);
extern s32 D_800F32B8;
extern Gfx800A4C84 *D_800F36A4;

void func_800A4C84(S800A4C84 *arg0) {
    if (arg0->unk17C != 0) {
        func_800A602C();
        {
            Gfx800A4C84 *_g = D_800F36A4++;
            _g->w0 = 0xDA380007;
            _g->w1 = arg0->unk17C;
        }
        {
            Gfx800A4C84 *_g = D_800F36A4++;
            _g->w0 = 0xDB0E0000;
            _g->w1 = arg0->unk650;
        }
        {
            Gfx800A4C84 *_g = D_800F36A4++;
            _g->w0 = 0xDC08000A;
            _g->w1 = arg0->unk184 + D_800F32B8 * 32;
        }
        {
            Gfx800A4C84 *_g = D_800F36A4++;
            _g->w0 = 0xDC08030A;
            _g->w1 = arg0->unk184 + D_800F32B8 * 32 + 0x10;
        }
    }
}
