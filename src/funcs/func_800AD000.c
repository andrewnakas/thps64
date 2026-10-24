/* cflags: -O2 -Wa,-no-m4100 */
#include "common.h"

void func_800AFAD0(u8 *, s32);
void func_800AFBD0(u8 *, s16, s32);
extern s32 D_800ECC14;
extern s32 D_800ECC18;
extern s32 D_800ECC1C;
extern s32 D_800ECC20;
extern u8 *D_800FC2F4;
extern s32 D_800FC304;
extern u16 D_800FC308;
extern u16 D_800FC30A;

void func_800AD000(u8 *arg0, s32 arg1) {
    u32 v;

    D_800ECC14 = *(u8 *)(arg0 + 0xBC);
    D_800ECC18 = *(u8 *)(arg0 + 0xC4);
    {
        s32 t1 = *(u8 *)(arg0 + 0xBB);
        D_800ECC20 = *(s16 *)(arg0 + 0x9E);
        D_800ECC1C = t1;
    }
    v = (u32)(*(u8 *)(arg0 + 0xBC) * *(u8 *)(arg0 + 0xC4) * *(u8 *)(arg0 + 0xBB) * *(s16 *)(arg0 + 0x9E)) >> 13;
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    if (*(s32 *)(arg0 + 0x78) == 0) {
        v = v * D_800FC30A;
    } else {
        v = v * D_800FC308;
    }
    v >>= 15;
    if (*(s32 *)(arg0 + 0x10) != -1) {
        v = v * *(s32 *)(arg0 + 0x10) / *(u32 *)(arg0 + 0x1C);
    }
    if (v != *(u16 *)(arg0 + 0xA0)) {
        *(u16 *)(arg0 + 0xA0) = v;
        func_800AFBD0(D_800FC2F4 + arg1 * 0x1C, v, D_800FC304);
    }
    if (*(u8 *)(arg0 + 0xBD) != *(u8 *)(arg0 + 0xBE)) {
        v = (*(u8 *)(arg0 + 0xBD) * *(s16 *)(arg0 + 0xB0) >> 7) & 0x7F;
        *(u8 *)(arg0 + 0xBE) = v;
        func_800AFAD0(D_800FC2F4 + arg1 * 0x1C, v);
    }
}
