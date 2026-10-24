/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxE5A4;

typedef struct {
    u32 type;
    u32 flags;
    void *ucode_boot;
    u32 ucode_boot_size;
    void *ucode;
    u32 ucode_size;
    void *ucode_data;
    u32 ucode_data_size;
    void *dram_stack;
    u32 dram_stack_size;
    void *output_buff;
    u32 output_buff_size;
    void *data_ptr;
    u32 data_size;
    void *yield_data_ptr;
    u32 yield_data_size;
    u8 pad40[0x98 - 0x40];
} TaskE5A4;

void func_800B28C0(void);
void func_800BC654(void *, TaskE5A4 *, s32, void *, s32);
extern GfxE5A4 *D_800F36A4;
extern GfxE5A4 *D_800FC8B0[];
extern s32 D_800F32B8;
extern u32 D_800FC894;
extern s32 D_800F35C0;
extern TaskE5A4 D_800F32C8[];
extern u8 D_800988A0[];
extern u8 D_80098970[];
extern u8 gspF3DEX2_NoN_fifoTextStart[];
extern u8 D_800E9890[];
extern void *D_800FC898;
extern void *D_800F3290;
extern u32 D_800FC890;
extern void *D_800FC8C4;
extern u8 D_800F0DD0[];
extern u8 *D_800F5660;
extern s32 D_800F36C0;
extern s32 *D_800F36C4[];
extern s32 D_800F32AC;
extern s32 D_800F36BC;
extern s32 D_800F5664;

void func_800BE5A4(void) {
    GfxE5A4 *g;
    GfxE5A4 *base;
    u32 len;
    TaskE5A4 *t;
    s32 i;

    {

        GfxE5A4 *_g = D_800F36A4++;

        _g->w0 = 0xE9000000;

        _g->w1 = 0;

    }
    {
        GfxE5A4 *_g = D_800F36A4++;
        _g->w0 = 0xDF000000;
        _g->w1 = 0;
    }
    base = D_800FC8B0[D_800F32B8];
    len = (u8 *)D_800F36A4 - (u8 *)base;
    if (D_800FC894 < len) {
        D_800F36A4 = &base[D_800FC894 / 8] - 3;
        {
            GfxE5A4 *_g = D_800F36A4++;
            _g->w0 = 0xE9000000;
            _g->w1 = 0;
        }
        {
            GfxE5A4 *_g = D_800F36A4++;
            _g->w0 = 0xDF000000;
            _g->w1 = 0;
        }
    }
    D_800F35C0++;
    if (D_800F35C0 == 5) {
        D_800F35C0 = 0;
    }
    t = &D_800F32C8[D_800F35C0];
    t->flags = 0;
    t->type = 1;
    t->ucode_boot_size = D_80098970 - D_800988A0;
    t->ucode_size = 0x1000;
    t->ucode_boot = D_800988A0;
    t->ucode_data_size = 0x800;
    t->dram_stack = D_800FC898;
    t->dram_stack_size = 0x400;
    t->data_ptr = D_800FC8B0[D_800F32B8];
    t->data_size = len;
    t->yield_data_ptr = D_800FC8C4;
    t->yield_data_size = 0xC00;
    t->ucode = gspF3DEX2_NoN_fifoTextStart;
    t->ucode_data = D_800E9890;
    t->output_buff = D_800F3290;
    t->output_buff_size = D_800FC890;
    func_800B28C0();
    {
        u8 *q = D_800F5660 + 0x1C8;

        func_800BC654(D_800F0DD0, t, 1, q, 0);
    }
    for (i = 0; i < D_800F36C0; i++) {
        *D_800F36C4[i] = 0;
    }
    D_800F36C0 = 0;
    D_800F32AC = 0;
    D_800F36BC = 1;
    D_800F32B8 = D_800F32B8 == 0;
    D_800F5664++;
}
