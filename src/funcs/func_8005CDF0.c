/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
} Ent8005CDF0;

typedef struct {
    u8 pad0[0x38];
    u16 unk38;
    u8 pad3A[0x48 - 0x3A];
} Def8005CDF0;

typedef struct {
    u8 pad0[0x1B];
    u8 unk1B;
    u8 pad1C[0x27C - 0x1C];
    void *unk27C;
    Ent8005CDF0 *unk280;
    Ent8005CDF0 *unk284;
} Obj8005CDF0;

void *func_8005EAB4(s32, s32, s32);
extern Def8005CDF0 D_800DAF98[];

void func_8005CDF0(Obj8005CDF0 *arg0, u8 *arg1) {
    s32 n;
    s32 i;
    s32 j;

    n = *(u16 *)(arg1 + 2);
    arg0->unk284 = (Ent8005CDF0 *)(arg1 + 4);
    arg0->unk27C = func_8005EAB4(D_800DAF98[arg0->unk1B].unk38 * 0x18, 0, 1);
    arg0->unk280 = func_8005EAB4(n * 0xC, 0, 1);
    for (i = 0; i < n; i++) {
        Ent8005CDF0 *e = arg0->unk280;
        e[i].fA = 0;
        e[i].f8 = 0;
        e[i].f6 = 0;
        e[i].f4 = 0;
        e[i].f2 = 0;
        e[i].f0 = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arg0->unk284[i].f2 == arg0->unk284[j].f0) {
                arg0->unk284[i].fA = j;
                break;
            }
        }
        if (j == n) {
            arg0->unk284[i].fA = 0xFFFF;
        }
    }
}
