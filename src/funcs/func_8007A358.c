/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* Class operator new (same family as func_8007A9E8): size rounded up front (CSE folds it; the param stays a
 * user-variable pseudo, so loop.c leaves `li s0, size` inside the spawn loop), two identical heap calls that
 * cross-jumping merges after reload. The heap test compares size against D_800DE524 (unknowable: it is deleted
 * with the merged branch), but its use of size keeps the size pseudo at 3 refs, so local-alloc does not move
 * the constant next to the srl and it stays in s0 across the call. vt = vtable pointer of each class. */
#include "common.h"

typedef unsigned int size_t;

struct Vec3 {
    s32 x, y, z;
};

extern "C" void *func_8005EAB4(u32, s32, s32);
extern "C" s32 func_80049D60(s32);
extern "C" void func_80079E18(void *);
extern u8 D_8001E248;
extern u8 D_8001E230;
extern Vec3 D_800D6188;
extern s32 D_800DE524;

struct Obj {
    u8 pad0[8];
    s16 unk8;
    u8 padA[0xE];
    Vec3 pos;
    Vec3 vel;
    u8 pad30[0x10];
    s16 unk40;
    u8 pad42[2];
    void *vt;
    s16 unk48;
    s16 unk4A;
    s32 unk4C;
    u8 pad50[9];
    u8 unk59;
    u8 pad5A[4];
    s16 unk5E;
    u8 pad60[0x10];

    void SetColor() {
        unk4C = (unk4C & 0xFF000000) | 0x646464;
    }
    void SetTime(s16 t) {
        unk40 = t;
    }

    void *operator new(size_t size) {
        u32 *p;

        size = (size + 3) & ~3;
        if (size < (u32)D_800DE524) {
            p = (u32 *)func_8005EAB4(size, 0, 1);
        } else {
            p = (u32 *)func_8005EAB4(size, 0, 1);
        }
        u32 *q = p;
        for (u32 i = 0; i < (size >> 2); i++) {
            *q++ = 0;
        }
        return p;
    }
};

struct Obj1 : Obj {
    s32 unk70;
    s32 unk74;
    Obj1(const Vec3 &p, s16 a, s32 b) {
        func_80079E18(this);
        vt = &D_8001E248;
        pos = p;
        unk5E = a;
        unk4C |= 0x02000000;
        unk70 = b;
        unk74 = unk59 - 1;
        SetColor();
        SetTime(300);
    }
};

struct Obj2 : Obj {
    Obj2(const Vec3 &p, const Vec3 &v, s16 a, s16 b) {
        func_80079E18(this);
        vt = &D_8001E230;
        pos = p;
        vel = v;
        unk4C |= 0x02000000;
        unk5E = b;
        unk4A = a;
        unk48 = 0;
        SetColor();
        SetTime(200);
    }
};

extern "C" void func_8007A358(Obj *arg0) {
    s32 i;

    if (arg0->unk8 == 0) {
        new Obj1(arg0->pos, func_80049D60(500) + 2000, 1);
    }
    if (arg0->unk8 == 5) {
        for (i = 0; i < 1; i++) {
            Vec3 p = arg0->pos;
            p.y += (func_80049D60(100) + 50) << 12;
            new Obj2(p, D_800D6188, func_80049D60(60) + 30, 3000);
        }
    }
    arg0->unk8++;
}
