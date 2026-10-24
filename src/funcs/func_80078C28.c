/* compiler: cc1plus */
#include "common.h"

struct Vec3 {
    s32 x, y, z;
};

struct Quat {
    s32 x, y, z, w;
    Quat() {}
};

struct Key {
    s32 *unk0;
    s32 *unk4;
    Vec3 pos;
    s32 unk14;
    Quat rot;
    Vec3 pos2;
    s16 unk34;
    u8 pad36[0x26];
    s32 unk5C;
};

extern "C" Vec3 func_80046FBC(const Vec3 &, const Vec3 &);
extern "C" Vec3 func_80046F58(const Vec3 &, const long &);
extern "C" Vec3 func_80046DAC(const Vec3 &, const long &);
extern "C" Vec3 func_80047014(const Vec3 &, const Vec3 &);
extern "C" void func_80067F30(Quat, Quat, s32, Quat *);

extern "C" void func_80078C28(Key *a, Key *b, s32 t, Key *out) {
    if (a->unk0 != 0) {
        a->pos = *(Vec3 *)(a->unk4 + 1);
    }
    if (b->unk0 != 0) {
        b->pos = *(Vec3 *)(b->unk4 + 1);
    }
    out->unk4 = b->unk4;
    out->pos = func_80047014(func_80046DAC(func_80046F58(func_80046FBC(b->pos, a->pos), t), 12), a->pos);
    func_80067F30(b->rot, a->rot, t, &out->rot);
    out->pos2 = func_80047014(func_80046DAC(func_80046F58(func_80046FBC(b->pos2, a->pos2), t), 12), a->pos2);
    out->unk34 = a->unk34 + ((u32)((b->unk34 - a->unk34) * t) >> 12);
    out->unk14 = b->unk14;
    out->unk5C = b->unk5C;
}
