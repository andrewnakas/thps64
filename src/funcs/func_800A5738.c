/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x160];
    f32 unk160;
    f32 unk164;
    f32 unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
} Obj;

void func_800A4418(Obj *, f32, f32, f32, f32, f32, f32);
void func_800A4D48(Obj *);

void func_800A5738(Obj *arg0, s32 arg1) {
    s32 i;
    f32 s = 1.05f;

    for (i = 1; i < arg1; i++) {
        s *= 1.05;
    }
    func_800A4418(arg0, arg0->unk160 * s, arg0->unk164 * s, arg0->unk168 * s, arg0->unk16C * s,
                  arg0->unk170 * s, arg0->unk174);
    func_800A4D48(arg0);
}
