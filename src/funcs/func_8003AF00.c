/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_80039500(void *);
void func_800A72C0(void *);
void func_8003BDC0(void *);
void func_800B198C(void *);
void func_800B1A80(void *, s32);
void func_8003C1A4(void *, s32, char *, s32, char *, s32, char *, s32, char *, s32, char *, s32, char *, s32, char *, s32);
void func_800242CC(void);
void func_8003C838(void *, s32, s32);
void func_800A73EC(void *, s32);
void func_800A773C(void *, f32, f32);
extern u8 D_8001A060[];
extern char D_80019FE0[];
extern char D_80019FF4[];
extern char D_8001A008[];
extern char D_8001A014[];
extern s32 D_800D4680;
extern f32 D_800ECEF0;
extern f32 D_800EA9B0;
typedef struct {
    u8 pad0[0xF8];
    char *unkF8;
    char *unkFC;
    u8 pad100[0x14C - 0x100];
    char *unk14C;
} Strs_8003AF00;
typedef struct {
    u8 pad0[0x184];
    s32 unk184;
    s32 unk188;
} Cfg_8003AF00;
extern Strs_8003AF00 D_800DDC80;
extern Cfg_8003AF00 D_800DC3F8;
extern u8 D_800D0FC3;

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))

void *func_8003AF00(u8 *arg0) {
    f32 f;

    func_80039500(arg0);
    *(void **)(arg0 + 0x2C) = D_8001A060;
    func_800A72C0(arg0 + 0x80);
    func_8003BDC0(arg0 + 0x2C0);
    func_800B198C(arg0 + 0x930);
    func_800B198C(arg0 + 0x944);
    func_800B198C(arg0 + 0x958);
    func_800B1A80(arg0 + 0x930, 0x99);
    f = D_800D4680;
    D_800ECEF0 = f;
    D_800EA9B0 = f;
    func_8003C1A4(arg0 + 0x2C0, 7, D_80019FE0, 0x55, D_80019FF4, 0x56, D_800DDC80.unk14C, 0x57,
                  D_800DDC80.unkF8, 0x58, D_800DDC80.unkFC, 0x59, D_8001A008, 0x5A,
                  D_8001A014, 4);
    *(f32 *)(arg0 + 0x510) = 340.0f;
    W(arg0, 0x520) = 0x14A;
    func_800242CC();
    if (D_800D0FC3 >= 4) {
        func_8003C838(arg0 + 0x2C0, 1, 3);
    }
    func_800A73EC(arg0 + 0x80, 0x501);
    func_800A773C(arg0 + 0x80, 1.3f, 1.3f);
    func_800B1A80(arg0 + 0x944, 3);
    W(arg0, 0x948) = 1;
    func_800B1A80(arg0 + 0x958, 2);
    W(arg0, 0x95C) = 1;
    W(arg0, 0x48) = 0;
    *(f32 *)(arg0 + 0x78) = 0.5f;
    W(arg0, 0x7C) = 1;
    W(arg0, 0x34) = D_800DC3F8.unk184;
    W(arg0, 0x38) = D_800DC3F8.unk188;
    W(arg0, 0x3C) = 0x1E1;
    W(arg0, 0x40) = 0xED;
    W(arg0, 0x44) = 0xCA;
    arg0[0x76] = 0;
    H(arg0, 0x4C) = 0x58;
    H(arg0, 0x4E) = 0x212;
    H(arg0, 0x50) = 0x78;
    H(arg0, 0x52) = 0x58;
    H(arg0, 0x54) = 0x212;
    H(arg0, 0x56) = 0x98;
    H(arg0, 0x58) = 0x92;
    H(arg0, 0x5A) = 0x1DA;
    H(arg0, 0x5C) = 0xB9;
    H(arg0, 0x5E) = 0xB1;
    H(arg0, 0x60) = 0x217;
    H(arg0, 0x62) = 0xDD;
    H(arg0, 0x64) = 0x8C;
    H(arg0, 0x66) = 0x217;
    H(arg0, 0x68) = 0xFE;
    H(arg0, 0x6A) = 0xAE;
    H(arg0, 0x6C) = 0x1BA;
    H(arg0, 0x6E) = 0x11F;
    H(arg0, 0x70) = 0x8A;
    H(arg0, 0x72) = 0x1E0;
    H(arg0, 0x74) = 0x141;
    return arg0;
}
