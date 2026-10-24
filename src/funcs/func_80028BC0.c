/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x40];
    u8 unk40;
    u8 unk41;
    u8 pad42[2];
    f32 unk44;
    u16 unk48;
} Menu28BC0;

s32 func_8003FEF4(s32);
s32 func_8003FF2C(s32);
void func_80039E60(s32, s32, s32);
void func_8003A1CC(f32);
void func_8003A2B0(f32);
extern f32 D_800D0FEC;
extern f32 D_800D0FF0;

void func_80028BC0(Menu28BC0 *m, s32 arg1, s32 arg2) {
    s32 dy;
    s32 dx;

    dy = func_8003FEF4(arg1);
    if (dy == 0) {
        dy = func_8003FEF4(arg2);
    }
    dx = func_8003FF2C(arg1);
    if (dx == 0) {
        dx = func_8003FF2C(arg2);
    }
    switch (m->unk48) {
    case 0x65:
        if (dy == 1) {
            func_80039E60(0x90, 10000, 0);
            m->unk48 = 0x66;
        } else if (dy == -1) {
            func_80039E60(0x90, 10000, 0);
            m->unk48 = 0x67;
        } else if (dx == 1) {
            func_80039E60(0x91, 10000, 0);
            if (m->unk41 < 10) {
                m->unk41++;
            } else {
                m->unk41 = 10;
            }
            func_8003A1CC(D_800D0FEC = m->unk41 * m->unk44);
        } else if (dx == -1) {
            func_80039E60(0x91, 10000, 0);
            if (m->unk41 != 0) {
                m->unk41--;
            } else {
                m->unk41 = 0;
            }
            func_8003A1CC(D_800D0FEC = m->unk41 * m->unk44);
        }
        break;
    case 0x66:
        if (dy == 1) {
            func_80039E60(0x90, 10000, 0);
            m->unk48 = 0x67;
        } else if (dy == -1) {
            func_80039E60(0x90, 10000, 0);
            m->unk48 = 0x65;
        } else if (dx == 1) {
            func_80039E60(0x91, 10000, 0);
            if (m->unk40 < 10) {
                m->unk40++;
            } else {
                m->unk40 = 10;
            }
            func_8003A2B0(D_800D0FF0 = m->unk40 * m->unk44);
        } else if (dx == -1) {
            func_80039E60(0x91, 10000, 0);
            if (m->unk40 != 0) {
                m->unk40--;
            } else {
                m->unk40 = 0;
            }
            func_8003A2B0(D_800D0FF0 = m->unk40 * m->unk44);
        }
        break;
    case 0x67:
        if (dy == 1) {
            m->unk48 = 0x65;
        } else if (dy == -1) {
            m->unk48 = 0x66;
        }
        break;
    }
}
