#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    s16 x, y, z;
} Vec3s;

typedef struct {
    u8 pad0[0x4C];
    s32 unk4C;
    u8 pad50[8];
    Vec3i unk58;
    Vec3i unk64;
    u8 unk70[0xC];
    u8 unk7C[0xC];
    s32 unk88;
    u8 pad8C[8];
    s32 unk94;
} Cam;

void func_80046E04(Vec3i *, Vec3i *, s32 *);
void func_80046FBC(Vec3i *, s32, Vec3i *);
void func_80047980(void *, s32, Vec3s *);
void func_80047D40(Vec3s *, Vec3i *, s32);

void func_8007CBFC(Cam *arg0, Vec3i *arg1, s32 arg2) {
    union {
        Vec3i v;
        Vec3s s;
    } u;
    Vec3i tmp;
    s32 n;

    arg0->unk58 = *arg1;
    func_80046FBC(&tmp, arg2, arg1);
    n = arg0->unk4C - 1;
    func_80046E04(&u.v, &tmp, &n);
    arg0->unk64 = u.v;
    func_80047D40(&u.s, arg1, arg2);
    u.s.y = (u.s.y + 0x400) & 0xFFF;
    func_80047980(arg0->unk70, arg0->unk88, &u.s);
    u.s.y = (u.s.y - 0x400) & 0xFFF;
    u.s.x = (u.s.x + 0x400) & 0xFFF;
    func_80047980(arg0->unk7C, arg0->unk94, &u.s);
}
