/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* Inline Child::operator new: debug-flag branch with identical alloc calls (as in the global operator new
 * func_8007E618; its %hi(D_800DE524) stays hoisted in s6), then size rounded up and the block cleared. */
#include "common.h"

typedef unsigned int size_t;

extern "C" void *func_8005EAB4(u32, s32, s32);
extern "C" void func_80079E9C(void *);
extern u8 D_8001E158;
extern u8 D_8001E170;
extern u8 D_8001E388;
extern s32 D_800DE520;
extern s32 D_800DE524;

struct Vec_7A9E8 {
    s32 x, y, z;
};

struct Child_7A9E8 {
    u8 pad0[0x3C];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[3];
    u8 unk42;
    u8 pad43;
    void *unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    u8 pad54[4];
    u8 unk58;
    u8 pad59[5];
    s16 unk5E;
    u8 pad60[0x18];

    void *operator new(size_t size) {
        u32 *p;

        if (D_800DE524 != 0) {
            p = (u32 *)func_8005EAB4(size, 0, 1);
        } else {
            p = (u32 *)func_8005EAB4(size, 0, 1);
        }
        size = (size + 3) & ~3;
        u32 *q = p;
        for (u32 i = 0; i < (size >> 2); i++) {
            *q++ = 0;
        }
        return p;
    }
    Child_7A9E8() {
        func_80079E9C(this);
        unk44 = &D_8001E170;
    }
};

struct Obj_7A9E8 {
    u8 pad0[0x3C];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[5];
    void *unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    u8 pad54[4];
    Vec_7A9E8 *unk58;
    Child_7A9E8 **unk5C;
};

extern "C" Obj_7A9E8 *func_8007A9E8(Obj_7A9E8 *arg0, Vec_7A9E8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                                    s32 arg6, s32 arg7) {
    arg0->unk44 = &D_8001E388;
    arg0->unk3C = 1;
    arg0->unk3D = 1;
    arg0->unk3E = 1;
    D_800DE520 += 1;
    arg0->unk44 = &D_8001E158;
    arg0->unk48 = arg2;
    arg0->unk4C = arg3 - 1;
    arg0->unk50 = arg0->unk48 * arg0->unk4C + 1;
    arg0->unk58 = (Vec_7A9E8 *)func_8005EAB4(arg0->unk50 * sizeof(Vec_7A9E8), 0, 1);
    for (s32 i = 0; i < arg0->unk50; i++) {
        arg0->unk58[i] = *arg1;
    }
    arg0->unk5C = (Child_7A9E8 **)func_8005EAB4(arg2 * 4, 0, 1);
    s32 i = arg0->unk48 - 1;
    while (1) {
        if (i < 0) break;
        arg0->unk5C[i] = new Child_7A9E8;
        arg0->unk5C[i]->unk42 = 1;
        arg0->unk5C[i]->unk5E = arg6;
        if (arg7 != 0) {
            arg0->unk5C[i]->unk4C |= 0x02000000;
        }
        i--;
    }
    arg0->unk5C[0]->unk58 |= 0x10;
    return arg0;
}
