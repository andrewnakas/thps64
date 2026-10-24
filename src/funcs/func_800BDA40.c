/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s8 x0;
    s8 y0;
    s8 z0;
    u8 padB[0x18 - 0xB];
    s8 x1;
    s8 y1;
    s8 z1;
    u8 pad1B[0x20 - 0x1B];
} Light800BDA40;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800BDA40;

extern void func_80001A30(f32 *, void *);
extern void func_80011A40(s32);
extern void *func_8009E6B4(void *, s32, s32);
extern void func_8009CAD0(f32 *);
extern void func_8009E0F0(void *, s32, s32);
extern void func_800BE144(void);
extern Gfx800BDA40 D_800F36B0;
extern s32 D_800F36C0;
extern Light800BDA40 D_800F5608;
extern u8 D_800EA110[];
extern void *D_800FC8B8[2];
extern void *D_800FC8C4;
extern void *D_800FC898;
extern u8 D_800FC8D0[];
extern u8 D_800FC910[];

void func_800BDA40(void) {
    f32 m[4][4];
    f32 *mp;
    u8 *heap;

    func_80011A40(2);
    func_80011A40(0x40);
    D_800F36B0.w0 = 0xDF000000;
    D_800F36B0.w1 = 0;
    func_800BE144();
    heap = D_800EA110;
    D_800FC8B8[0] = func_8009E6B4(heap, 0x7D00, 8);
    D_800FC8B8[1] = func_8009E6B4(heap, 0x7D00, 8);
    D_800FC8C4 = func_8009E6B4(heap, 0xC00, 0x10);
    D_800FC898 = func_8009E6B4(heap, 0x400, 0x10);
    D_800F36C0 = 0;
    func_8009CAD0(m[0]);
    mp = m[0];
    func_80001A30(mp, D_800FC8D0);
    func_80001A30(mp, D_800FC910);
    func_8009E0F0(&D_800F5608, 0, sizeof(Light800BDA40));
    D_800F5608.x0 = (m[0][0] * 128.0f < 127.0f) ? (s32)(m[0][0] * 128.0f) : 0x7F;
    D_800F5608.y0 = (m[1][0] * 128.0f < 127.0f) ? (s32)(m[1][0] * 128.0f) : 0x7F;
    D_800F5608.z0 = (m[2][0] * 128.0f < 127.0f) ? (s32)(m[2][0] * 128.0f) : 0x7F;
    D_800F5608.x1 = (m[0][1] * 128.0f < 127.0f) ? (s32)(m[0][1] * 128.0f) : 0x7F;
    D_800F5608.y1 = (m[1][1] * 128.0f < 127.0f) ? (s32)(m[1][1] * 128.0f) : 0x7F;
    D_800F5608.z1 = (m[2][1] * 128.0f < 127.0f) ? (s32)(m[2][1] * 128.0f) : 0x7F;
}
