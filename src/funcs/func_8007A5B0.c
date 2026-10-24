/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

struct Vec3 {
    s32 x, y, z;
};

struct Node {
    Vec3 pos;
    u8 padC[0x24 - 0xC];
};

struct Rope {
    u8 pad0[0x4C];
    s32 count;
    Node *nodes;
    Rope *mirror;
    Vec3 start;
    Vec3 step;
    Vec3 wave1;
    Vec3 wave2;
    u8 pad88[4];
    s32 freq1;
    s32 speed1;
    u8 pad94[4];
    s32 freq2;
    s32 speed2;
    s32 phase;
};

extern "C" f32 func_80001CA0(f32);
extern "C" Vec3 func_80046DAC(const Vec3 &, const long &);
extern "C" Vec3 func_80046E04(const Vec3 &, const long &);
extern "C" Vec3 func_80046EF4(const long &, const Vec3 &);
extern "C" Vec3 func_80046F58(const Vec3 &, const long &);
extern "C" Vec3 func_80047014(const Vec3 &, const Vec3 &);
extern "C" void func_800472C0(Vec3 &, const Vec3 &);
extern "C" s32 func_80049D60(s32);
extern s32 D_800DE808;

static inline s32 isin(s32 a) {
    if (a == 0) {
        return 0;
    }
    a %= 4096;
    return (s32)(func_80001CA0((f32)a * 0.000244140625f * 6.283185) * 4096.0f);
}

extern "C" void func_8007A5B0(Rope *r) {
    long last = r->count - 1;
    r->nodes[0].pos = r->start;
    r->nodes[last].pos = func_80047014(r->start, func_80046EF4(last, r->step));
    Vec3 *cur = &r->nodes[1].pos;
    Vec3 pos = func_80047014(r->start, r->step);
    for (s32 i = 1; i < r->count - 1; i++) {
        if (func_80049D60(0xF) == 0) {
            r->phase = func_80049D60(0x1000);
        }
        *cur = func_80047014(pos, func_80046E04(func_80046F58(func_80046DAC(r->step, 6), isin(D_800DE808 * 130 + r->phase)), 0x40));
        func_800472C0(*cur, func_80047014(
            func_80046E04(func_80046F58(r->wave1, isin((i * r->freq1 + D_800DE808 * (r->speed1 << 1) + r->phase) & 0xFFF)), 0x1000),
            func_80046E04(func_80046F58(r->wave2, isin((i * r->freq2 + D_800DE808 * (r->speed2 << 1) + r->phase) & 0xFFF)), 0x1000)));
        cur = (Vec3 *)((u8 *)cur + sizeof(Node));
        func_800472C0(pos, r->step);
    }
    if (r->mirror != NULL) {
        for (s32 j = 0; j < r->count; j++) {
            r->mirror->nodes[j].pos = r->nodes[j].pos;
        }
    }
}
