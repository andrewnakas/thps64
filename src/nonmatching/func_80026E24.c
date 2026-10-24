/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 248/396 positional instructions; target 394. Display-list
 * cursor CSE/registers, float compare setup and integer conversion registers
 * still differ after focused attempts. Claude A3 draft, audited by Codex.
 * 26E48..26E98: conditional early return; 26E98..26FE4: vector/matrix calls.
 * 26FE4..27090: four float bounds checks, preserving unordered comparisons.
 * 27090..2724C: command stream and alpha conversion; 2724C..273F0: mode-1
 * matrices/geometry. 273F0..27424: reset ECE8 and restore arg1+17C matrix.
 * Commands are pairs of 32-bit stores, stride 8. The 27298 access is u16.
 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} V3F26E24;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx26E24;

void func_80084C00(void *);
void func_8009C8EC(f32 (*)[4], void *);
void func_8009C914(f32 (*)[4], void *, s32);
void func_8009CA00(f32 (*)[4], f32 (*)[4], void *);
void func_8009CB1C(f32 (*)[4], V3F26E24 *);
void func_8009D858(f32 (*)[4], V3F26E24 *);
void func_8009D8B4(f32 (*)[4], V3F26E24 *);
void func_8009DA14(f32 (*)[4], V3F26E24 *);
void func_800C000C(f32 (*)[4]);
u32 func_800C00A0(f32 (*)[4]);
extern u8 D_800D27B0[];
extern s32 D_800EECE8;
extern Gfx26E24 *D_800F36A4;

#define GFX(a, b)                       \
    {                                   \
        Gfx26E24 *_g = D_800F36A4++;    \
        _g->w0 = (a);                   \
        _g->w1 = (b);                   \
    }

void func_80026E24(u8 *arg0, u8 *arg1, s32 arg2) {
    f32 m1[4][4];
    V3F26E24 a;
    V3F26E24 b;
    V3F26E24 n;
    f32 m2[4][4];
    V3F26E24 s;
    f32 m3[4][4];
    f32 m4[4][4];
    f32 m5[4][4];
    f32 t;
    f32 k;
    u32 *w;
    u32 hb;
    u32 c;
    f32 (*mp)[4];
    f32 sc;
    f32 al;
    s32 bad;
    f32 limit;

    if (0.5f < *(f32 *)(arg1 + 0x84)) {
        limit = *(f32 *)(arg1 + 0x94);
        if (*(f32 *)(arg0 + 0x2250) * 0.0625f < limit && arg2 == 1) {
            return;
        }
    }
    k = 0.0625f;
    {
        f32 _x = *(f32 *)(arg0 + 0x2238) * k;
        f32 _y = *(f32 *)(arg0 + 0x223C) * k;
        f32 _z = *(f32 *)(arg0 + 0x2240) * k;

        a.x = _x;
        a.y = _y;
        a.z = _z;
    }
    b.x = a.x;
    b.y = a.y;
    b.z = a.z;
    b.y = (*(f32 *)(arg0 + 0x2250) + 10.0f) * k;
    t = (b.y - a.y) * 0.02f;
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    sc = t * 3.0f + 1.0f;
    func_8009CB1C(m1, &b);
    {
        f32 _x = -*(f32 *)(arg0 + 0x2254);
        f32 _y = -*(f32 *)(arg0 + 0x2258);
        f32 _z = -*(f32 *)(arg0 + 0x225C);

        n.x = _x;
        n.y = _y;
        n.z = _z;
    }
    func_8009DA14(m1, &n);
    mp = m1;
    func_8009C8EC(m2, mp);
    s.x = sc;
    *(s32 *)&s.y = 0;
    s.z = sc;
    func_8009D8B4(mp, &s);
    {
        f32 _x = -b.x;
        f32 _y = -b.y;
        f32 _z = -b.z;

        n.x = _x;
        n.y = _y;
        n.z = _z;
    }
    func_8009D858(mp, &n);
    func_8009CA00(m3, mp, arg1 + 0x120);
    bad = 0;
    if (m3[3][0] < -32700.0f || m3[3][0] > 32700.0f || m3[3][1] < -32700.0f || m3[3][1] > 32700.0f ||
        m3[3][2] < -32700.0f || m3[3][2] > 32700.0f || m3[3][3] < -32700.0f || m3[3][3] > 32700.0f) {
        bad = 1;
    }
    if (bad != 0) {
        return;
    }
    c = func_800C00A0(m3);
    GFX(0xDA380007, c);
    al = (1.0f - t) * 80.0f + 48.0f;
    GFX(0xE7000000, 0);
    {
        Gfx26E24 *_g = D_800F36A4++;

        _g->w0 = 0xFA000000;
        w = &_g->w1;
        if (al >= 2147483648.0f) {
            goto big;
        }
        c = (s32)al;
        goto end;
    big:
        al = al - 2147483648.0f;
        hb = 0x80000000;
        c = (s32)al | hb;
    end:
        *w = c & 0xFF;
    }
    GFX(0xFCFFFFFF, 0xFFFDF638);
    if (arg2 == 2) {
        GFX(0xE200001C, 0x0C184A50);
        GFX(0xE2001D00, 0);
    } else {
        GFX(0xEE000000, 0);
        GFX(0xE2001D00, 4);
        GFX(0xE200001C, 0x0C184978);
    }
    func_80084C00(arg0 + 0xF18);
    GFX(0xE7000000, 0);
    GFX(0xE2001D00, 0);
    if (arg2 == 1) {
        GFX(0xFCFFFFFF, 0xFFFFFE38);
        GFX(0xE200001C, 0x0C184260);
        if (*(s32 *)(arg0 + 0x344) != 0) {
            func_8009C914(m5, arg0 + 0x2290, *(s32 *)(arg0 + 0x214) + (*(u16 *)(*(u8 **)(arg0 + 0x1B18) + 0x218) << 6));
            func_8009C8EC(m4, m5);
            func_8009C8EC(m2, m4);
            *(V3F26E24 *)&m2[3][0] = *(V3F26E24 *)(arg0 + 0x22C0);
        } else {
            func_8009C8EC(m2, arg0 + 0x2290);
        }
        func_800C000C(m2);
        GFX(0x01008010, (u32)D_800D27B0);
        GFX(0x06000204, 0x406);
        GFX(0x06080C0A, 0x80E0C);
        GFX(0x06000204, 0x406);
        GFX(0x0600080A, 0xA02);
        GFX(0x06020A0C, 0x20C04);
        GFX(0x06040C0E, 0x40E06);
        GFX(0x06060E08, 0x60800);
    }
    D_800EECE8 = -1;
    GFX(0xDA380007, *(u32 *)(arg1 + 0x17C));
}
