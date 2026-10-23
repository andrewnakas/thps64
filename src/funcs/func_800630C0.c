/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad[0x13];
    u8 b13;
    u8 pad2[8];
    s32 w1C;
    u8 pad3[0x28];
} Ent800630C0;

typedef struct {
    s32 a;
    s32 b;
} Pair800630C0;

void func_800620D8(void);
void func_80062548(s32, s32, s32);
extern Pair800630C0 D_800DAD70;
extern Ent800630C0 D_800DAF98[];

void func_800630C0(void) {
    s32 i;

    i = 0;
    do {
        if (D_800DAF98[i].w1C != 0 && i != D_800DAD70.a && i != D_800DAD70.b && D_800DAF98[i].b13 == 0) {
            func_80062548(i, 0, 0);
        }
        i++;
    } while (i < 0x28);
    func_800620D8();
}
