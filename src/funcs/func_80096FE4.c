/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
#include "vecmath.h"

void func_80046C1C(void *, void *);
void func_80046D00(void *);

typedef struct {
    s32 unk0;
    Vec3i pos;
    u8 unk10[0xA8];
    u8 unkB8[0x1B0];
    Vec3i base;
    u16 unk274;
    u16 pad276;
    u16 unk278;
    u16 unk27A;
} Wobble;

void func_80096FE4(Wobble *arg0) {
    s32 v;

    func_80046C1C(arg0->unk10, arg0->unkB8);
    func_80046D00(arg0->unk10);
    arg0->pos = arg0->base;
    v = isin(arg0->unk274 & 0xFFF);
    arg0->pos.y += arg0->unk278 * v / 4096 * 4096;
    arg0->unk274 += arg0->unk27A;
}
