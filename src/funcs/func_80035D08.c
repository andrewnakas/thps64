/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 adj;
    void (*fn)(void *, ...);
} VEnt35D08;

typedef struct {
    u8 pad0[0x40];
    VEnt35D08 e8;
    VEnt35D08 e9;
} VTbl35D08;

typedef struct {
    u8 pad0[0x48];
    VTbl35D08 *vt;
} Obj35D08;

typedef struct {
    u8 pad0[0x38];
    u16 w38;
    u16 w3A;
} Spr35D08;

void func_8002B6D0(void *);
void func_800349D4(void);
void func_80034390(void *, s32);
void func_80035B88(void *);
void func_80036664(void *);
s32 func_80036E64(void *);
void func_800453F0(void);
void func_80046524(void);
void func_8004A89C(void *);
void func_8004AB58(void);
void func_8004ACF0(void *);
void func_8004AD90(s32);
void func_8005E4B4(void);
void func_8005E4D0(void *, s32, s32);
void func_80068988(void);
void func_8006D4B0(void);
void func_8006D5B0(void);
void func_800857AC(s32, s32);
void func_80089040(void);
void func_800892D4(void);
void func_8008EA30(void);
void func_80091974(void);
void func_8009C3A8(void *);
void func_800A0DBC(void *, s32);
void func_800A4DD0(void *);
void func_800B3690(s32);
void func_800B389C(s32);
void func_800B8298(Spr35D08 *, s32, s32, s32, s32, s32, f32, s32, f32, s32, s32, s32, s32);
void func_800BEF70(s32, s32, s32);
void func_800BF1F4(s32, s32, s32);
void func_800BF4AC(void);
void func_800BF6AC(s32, s32, s32, s32, s32, s32, s32, s32, s32);
typedef struct {
    u8 pad0[0x40];
    u8 x40[0xE88];
    s32 xEC8;
    Spr35D08 *spr;
} G0FC0;

extern G0FC0 D_800D0FC0;
extern s32 D_800D3130;
extern u8 D_800D36E0[];
extern volatile s32 D_800D613C;
extern s32 D_800D6180;
extern s32 D_800DC5A0;
extern s32 D_800DC618;
extern s32 D_800DDC60;
extern s32 D_800DE1A4;
extern s32 D_800DE7A0;
extern s32 D_800DE7A4;
extern u8 *D_800DE7A8;
extern u8 *D_800DE7AC;
extern s32 D_800DE820;
extern s32 D_800DE838;
extern s32 D_800DE860;
extern s32 D_800DE944;
extern s32 D_800DE99C;
extern s32 D_800DE9A8;
extern s32 D_800DE9AC;
extern s32 D_800E9038;
extern s32 D_800EECE0;
typedef struct {
    u32 w0;
    u32 w1;
} Gfx35D08;

extern Gfx35D08 *D_800F36A4;

#define VT(p) (((Obj35D08 *)(p))->vt)

void func_80035D08(u8 *arg0) {
    u8 *pl[2];
    s32 paused;
    s32 i;
    s32 n;
    u8 *cam;
    s32 mode;
    Gfx35D08 *g;
    Spr35D08 *spr;

    *(s32 *)(arg0 + 0x34) = 0;
    if (D_800DE860 != 0) {
        D_800DE99C = D_800DE99C / 2;
    } else if (D_800DE838 != 0) {
        D_800DE99C = D_800DE99C * 3 / 2;
    }
    func_80036664(arg0);
    paused = 0;
    func_8004AD90(D_800DDC60);
    func_8004AD90(D_800D6180);
    pl[0] = D_800DE7A8;
    pl[1] = D_800DE7AC;
    if (D_800E9038 != 0 || D_800DE820 != 0) {
        do {
            paused = 1;
        } while (0);
    }
    D_800EECE0 = paused;
    func_800349D4();
    VT(pl[0])->e8.fn(pl[0] + VT(pl[0])->e8.adj);
    if (D_800DE9A8 == 2 && D_800DE7A0 != 7) {
        VT(pl[1])->e8.fn(pl[1] + VT(pl[1])->e8.adj);
    }
    if (paused == 0) {
        func_80068988();
        func_8004A89C(&D_800DC5A0);
        func_8004ACF0(&D_800D6180);
        func_8004ACF0(&D_800DE7A4);
        func_8004A89C(&D_800DDC60);
        func_8004AB58();
        D_800DE944 = D_800D613C;
        D_800D613C++;
    }
    if (*(s32 *)(arg0 + 0x4C) != D_800E9038) {
        func_800B389C(D_800E9038);
        *(s32 *)(arg0 + 0x4C) = D_800E9038;
        if (D_800E9038 != 0) {
            func_800B3690(1);
        }
    }
    func_80046524();
    func_80091974();
    func_800892D4();
    func_8006D4B0();
    func_8005E4D0(&D_800DE1A4, 0, 0);
    if (*(s32 *)(arg0 + 0x44) < 3) {
        *(s32 *)(arg0 + 0x44) += 1;
        func_800BEF70(0, 0, 0);
    }
    func_800BF1F4(D_800D36E0[0], D_800D36E0[1], D_800D36E0[2]);
    if (D_800DE7A0 != 7) {
        n = D_800DE9A8;
    } else {
        n = 1;
    }
    i = 0;
    while (1) {
        if (i >= n) {
            break;
        }
        cam = pl[i] + 0x1B28;
        func_800A4DD0(cam);
        func_80034390(cam, i);
        if (*(s32 *)(*(u8 **)(pl[i] + 0x2248) + 0x5B0) == 2) {
            mode = 2;
        } else {
            mode = 1;
        }
        VT(pl[0])->e9.fn(pl[0] + VT(pl[0])->e9.adj, cam, mode);
        if (n == 2) {
            VT(pl[1])->e9.fn(pl[1] + VT(pl[1])->e9.adj, cam, mode);
        }
        i++;
    }
    g = D_800F36A4++;
    g->w0 = 0xED000000;
    g->w1 = 0x4FC3BC;
    func_80035B88(g);
    func_80089040();
    if ((D_800DE9AC != 1 && D_800DE7A0 != 7) || *(s32 *)(D_800DE7A8 + 0xB5C) != 0 ||
        (D_800DE7AC != NULL && *(s32 *)(D_800DE7AC + 0xB5C) != 0) || D_800DE7A0 == 7) {
        func_800453F0();
    }
    func_8008EA30();
    func_8006D5B0();
    if (paused != 0 && D_800DC618 != 2) {
        func_800BF6AC(0, 0x13F, 0, 0xEF, 0, 0, 0, 0x96, 0);
    }
    func_800857AC(D_800D0FC0.xEC8, 1);
    func_8009C3A8(D_800D0FC0.x40);
    func_8002B6D0(arg0 + 0x58);
    func_800A0DBC(&D_800D3130, 0);
    func_800BF4AC();
    spr = D_800D0FC0.spr;
    if (spr != NULL) {
        func_800B8298(*(Spr35D08 * volatile *)&D_800D0FC0.spr, 0x122 - spr->w38, 0x122, 0xD2 - spr->w3A, 0xD2, 0, 1.0f, 0, 1.0f, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8005E4B4();
    *(s32 *)(arg0 + 0x34) = func_80036E64(arg0);
}
