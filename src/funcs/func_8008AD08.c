/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u8 bits[8];
} Ent8008AD08;

void func_800B1AC4(u8 *, f32, f32, f32, f32);
extern s32 D_800C0E20;
extern u8 D_800D0FC0[];
extern Ent8008AD08 D_800DE9F4[];

void func_8008AD08(u8 *arg0) {
    s32 i;
    s32 y;

    y = 0x6A;
    i = 0;
    do {
        if ((D_800DE9F4[D_800D0FC0[0x14]].bits[D_800C0E20] >> i) & 1) {
            func_800B1AC4(arg0 + 0xC4, 53.0f, y, 1.0f, 1.0f);
        }
        i++;
        y += 0x3A;
    } while (i < 5);
}
