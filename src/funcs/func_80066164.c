/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    f32 f2C;
    f32 f30;
} Unk800D0FC0;

typedef struct {
    u8 pad0[0x110];
    s32 a110[2];
    s32 a118[2];
    s32 a120[2][4];
    u8 pad140[0x44];
    s32 u184;
    s32 u188;
} Unk800DC3F8;

s32 func_800057E4(char *, char *, ...);
extern char D_8001CBC8[];
extern char D_8001CBD0[];
extern Unk800D0FC0 D_800D0FC0;
extern Unk800DC3F8 D_800DC3F8;
extern char D_800DC588[];

void func_80066164(void) {
    s32 i;

    D_800D0FC0.f2C = 1.0f;
    D_800D0FC0.f30 = 0.6f;
    D_800DC3F8.u184 = 1;
    D_800DC3F8.u188 = 1;
    for (i = 0; i < 2; i++) {
        D_800DC3F8.a110[i] = 1;
        D_800DC3F8.a118[i] = 1;
        D_800DC3F8.a120[i][0] = 0;
        D_800DC3F8.a120[i][1] = 1;
        D_800DC3F8.a120[i][2] = 2;
        D_800DC3F8.a120[i][3] = 3;
    }
    func_800057E4(D_800DC588, D_8001CBC8);
    *(s32 *)(D_800DC588 - 4) = 5;
    func_800057E4(D_800DC588 - 0x50, D_8001CBD0);
}
