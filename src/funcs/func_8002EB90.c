#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx8002EB90;

void func_800B9DE0(s32);
extern Gfx8002EB90 *D_800F36A4;

void func_8002EB90(s32 arg0, s32 arg1) {
    {
        Gfx8002EB90 *g = D_800F36A4++;
        g->w0 = 0xE7000000;
        g->w1 = 0;
    }
    {
        Gfx8002EB90 *g = D_800F36A4++;
        g->w0 = 0xE3000A01;
        g->w1 = 0x100000;
    }
    func_800B9DE0(arg1);
    {
        Gfx8002EB90 *g = D_800F36A4++;
        g->w0 = 0xFCFFFFFF;
        g->w1 = 0xFFFCF238;
    }
}
