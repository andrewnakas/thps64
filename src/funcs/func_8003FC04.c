/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x36];
    s16 x36;
    s16 x38;
    u8 pad3A[2];
    s32 mode;
    u8 pad40[0x27];
    u8 state;
} St8003FC04;

void func_80039E60(s32, s32, s32);
void func_800B1A80(void *, u8);
extern u8 D_800D47C8[];

void func_8003FC04(St8003FC04 *arg0) {
    s32 mode;
    s32 s;

    func_80039E60(0x90, 0x2710, 0);
    mode = arg0->mode;
    switch (mode) {
    case 1:
        s = arg0->state;
        if (s == 0) {
            arg0->state = 1;
            arg0->x36 = 0x8B;
            arg0->x38 = 0x127;
            func_800B1A80((u8 *)arg0 + 0x390, D_800D47C8[arg0->state]);
        } else if (s == 1) {
            arg0->state = 2;
            arg0->x36 = 0x8B;
            arg0->x38 = 0x127;
            func_800B1A80((u8 *)arg0 + 0x390, D_800D47C8[arg0->state]);
        } else {
            arg0->state = 0;
            arg0->x38 = 0x127;
            func_800B1A80((u8 *)arg0 + 0x390, D_800D47C8[arg0->state]);
        }
        break;
    case 2:
        s = arg0->state;
        if (s == 0) {
            arg0->state = mode;
            arg0->x36 = 0x8B;
            func_800B1A80((u8 *)arg0 + 0x390, D_800D47C8[arg0->state]);
        } else if (s == 1) {
            arg0->state = 0;
            arg0->x36 = 0x8B;
            arg0->x38 = 0x127;
            func_800B1A80((u8 *)arg0 + 0x390, D_800D47C8[arg0->state]);
        } else {
            arg0->state = 1;
            arg0->x38 = 0x127;
            func_800B1A80((u8 *)arg0 + 0x390, D_800D47C8[arg0->state]);
        }
        break;
    }
}
