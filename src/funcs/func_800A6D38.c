/* cflags: -O2 */
#include "common.h"

typedef struct { f32 x, y, z; } Vec3;

typedef struct {
    u8 pad0[0x30];
    Vec3 pos;
    f32 w;
} Mtx44;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x58];
    Mtx44 *unk68;
    void *unk6C;
    Vec3 unk70;
    u8 pad7C[4];
    u8 unk80;
} Obj;

void func_80001A30(Mtx44 *, void *);
void func_8009C8EC(Mtx44 *, Mtx44 *);
void func_8009D8B4(Mtx44 *, Vec3 *);

static __inline__ void apply_(Mtx44 *m, Obj *o) {
    func_8009C8EC(m, o->unk68);
    func_80001A30(m, o->unk6C);
}

void func_800A6D38(Obj *arg0, s32 arg1, Mtx44 *arg2) {
    Vec3 s;

    func_8009C8EC(arg0->unk68, arg2);
    if (arg1 == 0) {
        Mtx44 *t = arg0->unk68;
        f32 k = 1.0f;
        Vec3 *p = &s;
        p->x = k;
        p->y = k;
        p->z = k;
        func_8009D8B4(t, p);
    }
    if (arg0->unk80 != 0) {
        Mtx44 m;
        apply_(&m, arg0);
    } else {
        arg0->unkC = 0;
    }
    arg0->unk70 = arg2->pos;
}
