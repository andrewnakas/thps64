/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC9];
    u8 unkC9;
    u8 padCA[0x66];
} Track_800AB48C;

typedef struct {
    u16 a;
    s16 b;
    s8 c;
} Arg_800AB48C;

typedef struct {
    s32 unk0;
    s32 count;
    s32 unk8;
    u16 padC;
    u16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} Cfg_800AB48C;

typedef struct Task_800AB48C {
    s32 unk0;
    struct Task_800AB48C *self;
    s32 (*func)(void);
} Task_800AB48C;

void func_8009E0F0(void *, s32, s32);
void func_800AB734(s32, s32);
void func_800AC234(s32, s32);
void func_800AC3DC(s32);
void func_800AC580(s32);
void func_800ADBC4(Track_800AB48C *);
void func_800AE450(Task_800AB48C *);
void func_800AE5E0(u8 *, Arg_800AB48C *);
void func_800B17F0(s32, s32);
void *func_800B1850(s32);
void func_800B1880(void);
void func_800BB5E0(s32);
void func_800BB7B0(Cfg_800AB48C *, s32, s32);
s32 func_800AC8BC(void);
extern void *D_800ECB3C;
extern Task_800AB48C D_800ECBF8;
extern s32 D_800ECC10;
extern s32 D_800F56BC;
extern s32 D_800FC2F0;
extern u8 *D_800FC2F4;
extern Track_800AB48C *D_800FC2F8;
extern Track_800AB48C *D_800FC2FC;
extern s32 D_800FC300;
extern s32 D_800FC304;
extern s32 D_800FC30C;
extern s32 D_800FC310;
extern s32 D_800FC314;
extern s32 D_800FC318;
extern s32 D_800FC320;
extern s32 D_800FC324;
extern s32 D_800FC328;
extern s32 D_800FC32C;

void func_800AB48C(Cfg_800AB48C *cfg) {
    Arg_800AB48C arg;
    s32 i;

    D_800ECC10 = cfg->unk0;
    D_800FC2F0 = cfg->count + 4;
    if (D_800F56BC == 0) {
        D_800FC300 = 50;
    } else {
        D_800FC300 = 60;
    }
    D_800FC304 = 1000000 / D_800FC300;
    func_800B17F0(cfg->unk10, cfg->unk14);
    func_800BB5E0(cfg->unk8);
    D_800ECB3C = func_800B1850(1000);
    func_8009E0F0(D_800ECB3C, 0, 1000);
    D_800FC2F4 = func_800B1850((D_800FC2F0 - 4) * 0x1C);
    D_800FC2F8 = func_800B1850(D_800FC2F0 * 0x130);
    D_800FC2FC = D_800FC2F8 + 4;
    func_800AC580(cfg->unk24);
    D_800FC314 = 0;
    D_800FC318 = 0;
    if (cfg->unk18 != 0 && cfg->unk1C != 0) {
        func_800AC234(cfg->unk18, cfg->unk1C);
    }
    D_800FC328 = 0;
    D_800FC324 = 0;
    if (cfg->unk20 != 0) {
        func_800AC3DC(cfg->unk20);
    }
    D_800FC32C = 0;
    D_800FC320 = 2;
    func_800BB7B0(cfg, D_800FC300, 2);
    func_800AB734(3, 0x7FFF);
    D_800FC30C = 1;
    D_800FC310 = 0x12345678;
    D_800ECBF8.unk0 = 0;
    D_800ECBF8.func = func_800AC8BC;
    D_800ECBF8.self = &D_800ECBF8;
    func_800AE450(&D_800ECBF8);
    for (i = 0; i < D_800FC2F0; i++) {
        D_800FC2F8[i].unkC9 = 0;
        func_800ADBC4(&D_800FC2F8[i]);
        arg.c = 0;
        arg.a = cfg->unkE;
        arg.b = 0;
        if (i >= 4) {
            func_800AE5E0(D_800FC2F4 + (i - 4) * 0x1C, &arg);
        }
    }
    func_800B1880();
}
