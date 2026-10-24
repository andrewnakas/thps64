/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: global-alloc priority this > size, s0/s1 swap; best 49/57. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* 49/57: only s0/s1 swapped between this and size (size REG_EQUIV constant doubles its live length; lreg priority). X4 notes. */
/* Z1 (lreg): global-alloc priority this (reg 80: 6 refs/126 insns = 0.095) beats size (reg 98: 3 refs/38 insns =
 * 0.079), so this takes s0. Extra size refs in the (deleted) heap test are folded by CSE; free-function form,
 * `T *const`, local copies of fx/new result, a separate rounded local or `size >> 2` local: all 49/57. */
#include "common.h"

typedef unsigned int size_t;

extern "C" void *func_8005EAB4(u32, s32, s32);
extern s32 D_800DE524;

/* g++ 2.x vtable entry: this-adjust, index, function */
struct VtEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Fx {
    u8 pad0[0x42];
    u8 unk42;
    u8 pad43;
    VtEntry *vt;
    u8 pad48[0xC];

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
    Fx(s32 a, s32 b) __asm__("func_8007C68C");
    void SetColor(u8 r, u8 g, u8 b) __asm__("func_8007C5D0");
    void SetTime(u16 t) __asm__("func_8007C598");
};

struct Owner {
    u8 pad0[0x4C];
    s32 unk4C;
    u8 pad50[4];
    Fx *fx;

    void SetFx(u8 r, u8 g, u8 b, s32 t) __asm__("func_8007CD00");
};

void Owner::SetFx(u8 r, u8 g, u8 b, s32 t) {
    if (fx != NULL) {
        Fx *o = fx;
        o->vt[1].fn((u8 *)o + o->vt[1].delta, 3); /* virtual destructor: delete */
    }
    fx = new Fx(unk4C, 0);
    fx->unk42 = 1;
    fx->SetColor(r, g, b);
    fx->SetTime(t);
}
