/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);
void func_80039E60(s32, s32, s32);
s32 func_80049D60(s32);
void func_8009B16C(void *, f32, f32, f32, f32, f32, f32, s32);
extern u8 D_800D36F8[];
extern void *D_800D61A8;
extern s32 D_800DE808;
extern s32 D_800DE814;
extern s32 D_800DE818;
extern s32 D_800DE9A8;

typedef struct {
    s32 x, y, z;
} Vec3i_8004C14C;

typedef struct {
    u16 flags;
    u8 pad2[2];
    Vec3i_8004C14C pos;
    u8 pad10[0x7A0 - 0x10];
    s32 unk7A0;
    u8 pad7A4[0x2250 - 0x7A4];
    f32 unk2250;
} Obj_8004C14C;

void func_8004C14C(Obj_8004C14C *arg0) {
    Vec3i_8004C14C p;
    s32 y;
    s32 r;
    s32 a;
    s32 b;
    s32 s;
    s32 c;

    if (D_800DE9A8 == 2) {
        return;
    }
    if (arg0 == D_800D61A8) {
        y = D_800DE814;
    } else {
        y = D_800DE818;
    }
    if (y < arg0->pos.y + 0x19000) {
        if (!(arg0->flags & 8)) {
            func_80039E60(0x2B, 10000, 0);
        }
        arg0->flags |= 8;
        if (!(D_800DE808 & 3)) {
            p = arg0->pos;
            p.y = y;
            r = func_80049D60(0x18) + 0x10;
            a = func_80049D60(0x1000);
            if (a == 0) {
                s = 0;
            } else {
                s = func_80001CA0((a - a / 4096 * 4096) * 0.00024414062f * 6.283185) * 4096.0f;
            }
            p.x += r * s;
            b = a;
            if (b == 0) {
                c = 0x1000;
            } else {
                b = a - b / 4096 * 4096;
                c = func_800018C0(b * 0.00024414062f * 6.283185) * 4096.0f;
            }
            p.z += r * c;
            {
            s32 lo = arg0->unk7A0 <= 0x1FFFF;
            func_8009B16C(D_800D36F8, (f32)(arg0->pos.x / 4096) * 0.0625f, arg0->unk2250 * 0.0625f,
                          (f32)(arg0->pos.z / 4096) * 0.0625f, 1.5625f, 12.5f, 2.0f, lo);
            }
        }
    } else {
        arg0->flags &= ~8;
    }
}
