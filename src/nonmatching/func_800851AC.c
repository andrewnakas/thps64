/* NON_MATCHING: 17/387 positional instructions; target 384. Aligned region
 * comparison pairs 251/384 equally. Mode reload/address setup, saved-register
 * selection, scalar spills and constant loads differ. Claude K19 draft;
 * Codex audited 851E4..85774, including both bar paths and every call.
 * Sprites start at 0x114/0x128/0x13C/0x150, stride 0x14. All counters/coordinates are
 * signed words, config mode/color channels are unsigned bytes, tick is u32.
 * Reload the tick after sprite calls; normal width uses signed *72/3000.
 */
#include "common.h"

void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800B231C(void *, u8, u8, u8, s32);
void func_800BEB0C(s32, s32, s32, s32, s32, s32, s32);

typedef struct {
    u8 pad[0x14];
} Sprite_851AC;

typedef struct {
    u8 pad0[0xBC];
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    f32 unkCC;
    u8 padD0[0x114 - 0xD0];
    Sprite_851AC spr[4];
} Hud_851AC;

extern f32 D_8001ECE0;
extern f32 D_8001ECE4;
extern f32 D_8001ECE8;
extern f32 D_8001ECEC;
extern f32 D_8001ECF0;
extern f32 D_8001ECF4;
extern f32 D_8001ECF8;
extern u8 D_800D0FC0[];
extern u8 *D_800DE7A8;
extern s32 D_800DE7A0;
extern s32 D_800DE7C4;
extern s32 D_800DE83C;
extern s32 D_800DE9A8;
extern s32 D_800E8D74[];
extern s32 D_800E8D80[];
extern s32 D_800E8D8C[];
extern s32 D_800E8D98[];
extern s32 D_800E8DA4[];
extern s32 D_800E8DB0[];
extern s32 D_800E8DBC[];
extern s32 D_800E8DC8[];
extern s32 D_800E8DD4[];
extern s32 D_800E8DE0[];
extern s32 D_800E8DEC[];
extern s32 D_800E8DF8[];
extern u32 D_800F5664;

void func_800851AC(Hud_851AC *arg0) {
    s32 mode;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 r, g, b;
    s32 *px;
    s32 *py;
    s32 *qx;
    s32 *qy;
    f32 sx;
    f32 sy;
    s32 w;
    u8 c;

    {
        u8 *p = D_800D0FC0;
        mode = p[0x28];
        if (mode == 3) {
            mode = 0;
        }
    }
    if (*(s32 *)(*(u8 **)(D_800DE7A8 + 0x2D0) + 0x5B0) != 0x17 && D_800DE7C4 == 0 && D_800DE83C != 0) {
        r = 0xFF;
        g = 0xFF;
        r2 = 0xFF;
        g2 = 0xFF;
        b2 = 0xFF;
        b = 0xFF;
        if (D_800DE7A0 == 8) {
            r = 0xA0;
            g = 0xA0;
            b = 0xFF;
            r2 = 0xFF;
            g2 = 0xA0;
            b2 = 0xA0;
        }
        if (arg0->unkCC != D_8001ECE0) {
            func_800B231C(&arg0->spr[1], r, g, b, 0xFF);
            func_800B231C(&arg0->spr[0], r, g, b, 0xFF);
            px = &D_800E8D74[mode];
            py = &D_800E8D80[mode];
            func_800B1AC4(&arg0->spr[1], *px, *py, sx = D_8001ECE4, sy = D_8001ECE8);
            func_800B1AC4(&arg0->spr[0], D_800E8DA4[mode], D_800E8DB0[mode], sx, sy);
            if (arg0->unkC4 > 0) {
                w = arg0->unkC4 * D_8001ECEC;
                c = (D_800F5664 % 40) * 3 + 100;
                func_800B231C(&arg0->spr[1], c, c, 0, 0xFF);
                func_800B1AC4(&arg0->spr[1], *px, *py, sx, sy);
                c = (40 - D_800F5664 % 40) * 3 + 100;
                func_800BEB0C(D_800E8D8C[mode], D_800E8D8C[mode] + w, D_800E8D98[mode], D_800E8D98[mode] + 2, c, c, 0);
            } else if (arg0->unkBC > 0) {
                func_800BEB0C(D_800E8D8C[mode], D_800E8D8C[mode] + arg0->unkBC * 72 / 3000, D_800E8D98[mode],
                              D_800E8D98[mode] + 2, 0, 100, 0);
            }
            if (D_800DE9A8 == 2) {
                func_800B231C(&arg0->spr[3], r2, g2, b2, 0xFF);
                func_800B231C(&arg0->spr[2], r2, g2, b2, 0xFF);
                qx = &D_800E8DBC[mode];
                qy = &D_800E8DC8[mode];
                func_800B1AC4(&arg0->spr[3], *qx, *qy, sx = D_8001ECF0, sy = D_8001ECF4);
                func_800B1AC4(&arg0->spr[2], D_800E8DEC[mode], D_800E8DF8[mode], sx, sy);
                if (arg0->unkC8 > 0) {
                    w = arg0->unkC8 * D_8001ECF8;
                    c = (D_800F5664 % 40) * 3 + 100;
                    func_800B231C(&arg0->spr[3], c, c, 0, 0xFF);
                    func_800B1AC4(&arg0->spr[3], *qx, *qy, sx, sy);
                    c = (40 - D_800F5664 % 40) * 3 + 100;
                    func_800BEB0C(D_800E8DD4[mode], D_800E8DD4[mode] + w, D_800E8DE0[mode], D_800E8DE0[mode] + 2, c, c, 0);
                } else if (arg0->unkC0 > 0) {
                    func_800BEB0C(D_800E8DD4[mode], D_800E8DD4[mode] + arg0->unkC0 * 72 / 3000, D_800E8DE0[mode],
                                  D_800E8DE0[mode] + 2, 0, 100, 0);
                }
            }
        }
    }
}
