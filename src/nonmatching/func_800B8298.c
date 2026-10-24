/* cflags: -O2 */
/* NON_MATCHING: sched2 prologue tie: sw s7 beats lbu a on potential_hazard; best 93/95. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* NEAR (-O2): only prologue order differs: target loads arg a (lbu 0x83) after the s7 save */
/* Z1 (sched2 dump): the block runs past the jal, so all prologue insns have priority 1. Game order before
 * reorg: sw s7; sw s3; lbu s3(a); addu s7,a3; sw ra; jal. Ours at T-37 has sw s7 (224) and lbu a (36) both ready
 * with equal priority and the store wins on potential_hazard (memory unit blockage); the game picked lbu a, so its
 * lbu had higher priority or a different ready set. mode as ?:, if/else, (u8)a tests: no change. */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B8298;

extern void func_800B8414(s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_800B9DE0(void);
extern Gfx800B8298 *D_800F36A4;

void func_800B8298(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   u8 r, u8 g, u8 b, u8 a) {
    u32 mode;

    func_800B9DE0();
    {
        Gfx800B8298 *_g = D_800F36A4++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx800B8298 *_g = D_800F36A4++;
        _g->w0 = 0xFA000000;
        _g->w1 = (r << 24) | (g << 16) | (b << 8) | a;
    }
    {
        Gfx800B8298 *_g = D_800F36A4++;
        _g->w0 = 0xFC1197FF;
        _g->w1 = 0xFFFFFE38;
    }
    mode = 0x104240;
    if (a == 0xFF) {
        mode = 0x3024000;
    }
    {
        Gfx800B8298 *_g = D_800F36A4++;
        _g->w0 = 0xE200001C;
        _g->w1 = mode | 0x0C080000;
    }
    func_800B8414(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
