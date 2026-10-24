/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 x, y, z;
    u8 pad10[0x88 - 0x10];
    s32 unk88;
    u8 pad8C[0x208 - 0x8C];
    u32 unk208;
    u8 pad20C[0x21C - 0x20C];
    s16 unk21C;
    u16 unk21E;
    u8 pad220[0x227 - 0x220];
    u8 unk227;
    u8 pad228[0x340 - 0x228];
    s32 unk340;
    s32 unk344;
    u8 pad348[0x3E8 - 0x348];
    s32 unk3E8;
    s32 unk3EC;
    u8 pad3F0[0x45C - 0x3F0];
    s32 unk45C;
    u8 pad460[0x804 - 0x460];
    s32 unk804;
    u8 pad808[0x838 - 0x808];
    s32 unk838;
    u8 pad83C[0x884 - 0x83C];
    s16 m[3][3];
    u8 pad896[0x8D0 - 0x896];
    s32 v[6];
    s32 vel[3];
    u8 pad8F4[0x964 - 0x8F4];
    u8 *unk964;
} Obj_80055A14;

extern s32 D_800DE994;
void func_8004D398(Obj_80055A14 *, s32);
void func_8004638C(Obj_80055A14 *, s32);
s32 func_8004D2D4(Obj_80055A14 *);
void func_8004A204(Obj_80055A14 *, s32, s32, s32, s32);
void func_8004D048(Obj_80055A14 *, s32, s32);
void func_8004CC10(Obj_80055A14 *);

void func_80055A14(Obj_80055A14 *arg0) {
    s32 k;
    s32 m;
    s32 r;
    s16 t;
    s32 n;
    s16 pad[4];

    arg0->unk804 = 5;
    if (arg0->unk21E != 0x22 && arg0->unk21E != 0x3F) {
        func_8004D398(arg0, 0);
        return;
    }
    if (arg0->unk21E < 0x3E && arg0->unk21C >= 20 && arg0->unk21C < 25 && (n = arg0->unk340) >= 0) {
        if (*arg0->unk964 != 0) {
            s32 *pp = &D_800DE994;
            m = 2;
            k = 4;
            r = *pp / k % k;
            if (m < r) {
                r = k - r;
            }
            arg0->unk21C = r + 20;
            func_8004638C(arg0, 20);
            if (++arg0->unk340 > 20) {
                func_8004D398(arg0, 0);
                func_8004D2D4(arg0);
                func_8004A204(arg0, 0x38, 0, -1, -1);
                arg0->unk344 = 9;
                return;
            }
        } else {
            arg0->unk340 = -n;
        }
    }
    if (arg0->unk227 == 0) {
        if (arg0->unk21E >= 0x3E) {
            return;
        }
        if (arg0->unk21C < 0x1F) {
            return;
        }
    }
    arg0->unk88 = (40 - arg0->unk340 * 3) << 12;
    arg0->unk838 = 0;
    func_8004D048(arg0, 0, 0x17FC);
    arg0->unk45C = 1;
    func_8004CC10(arg0);
    arg0->x += arg0->vel[0] * 30;
    arg0->y += arg0->vel[1] * 30;
    arg0->z += arg0->vel[2] * 30;
    if (arg0->unk21E < 0x3E) {
        return;
    }
    arg0->unk208 ^= 2;
    arg0->unk3E8 = 0;
    arg0->m[0][2] = t = -*(u16 *)((u8 *)arg0 + 0x8D2);
    arg0->v[0] = t;
    arg0->m[1][2] = t = -*(u16 *)((u8 *)arg0 + 0x8D6);
    arg0->v[1] = t;
    arg0->m[2][2] = t = -*(u16 *)((u8 *)arg0 + 0x8DA);
    arg0->v[2] = t;
    arg0->m[0][0] = t = -*(u16 *)((u8 *)arg0 + 0x8DE);
    arg0->v[3] = t;
    arg0->m[1][0] = t = -*(u16 *)((u8 *)arg0 + 0x8E2);
    arg0->v[4] = t;
    arg0->m[2][0] = t = -*(u16 *)((u8 *)arg0 + 0x8E6);
    arg0->v[5] = t;
    arg0->unk3EC = 0;
    func_8004D2D4(arg0);
    func_8004A204(arg0, 0, 0, -1, -1);
}
