/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    u8 pad1C[0x8];
    f32 unk24;
    f32 unk28;
} Mtx8009CBB4;

extern f32 func_800018C0(f32);
extern f32 func_80001CA0(f32);
static __inline__ Mtx8009CBB4 *set(Mtx8009CBB4 *m, f32 s, f32 c) {
    m->unk18 = s;
    m->unk24 = -s;
    m->unk28 = c;
    m->unk14 = c;
    return m;
}

extern Mtx8009CBB4 *func_8009CAD0(Mtx8009CBB4 *);

Mtx8009CBB4 *func_8009CBB4(Mtx8009CBB4 *arg0, f32 arg1) {
    f32 s;
    f32 c;

    func_8009CAD0(arg0);
    s = func_80001CA0(arg1);
    c = func_800018C0(arg1);
    return set(arg0, s, c);
}
