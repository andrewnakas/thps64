#include "common.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} D0FC0;

void func_800A0DBC(void *, s32);
s32 func_800A31D0(void *, s32);
void func_800A3750(void *, char *, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern char D_800194C0[];
extern char D_8001952C[];
extern D0FC0 D_800D0FC0;
extern u8 D_800D3130[];
extern s32 D_800DE9A8;

void func_8002C660(u8 *arg0) {
    char *str;
    s32 doit;
    s32 miss;
    s32 val;
    u8 *buf;
    u8 *buf2;
    D0FC0 *cfg;

    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4(arg0 + 0x30, 34.0f, 0.0f, 0.925f, 2.0f);
    if (*(s32 *)(arg0 + 0x44) != 0) {
        *(s32 *)(arg0 + 0x44) = 0;
        doit = 0;
        if (D_800DE9A8 == 2) {
            miss = 0;
            buf = D_800D3130;
            cfg = &D_800D0FC0;
            if (func_800A31D0(buf, cfg->unk2) == 0 || func_800A31D0(buf, cfg->unk3) == 0) {
                miss = 1;
            }
            if (miss != 0) {
                doit = 1;
                val = -1;
                str = D_800194C0;
            }
        } else {
            buf2 = D_800D3130;
            cfg = &D_800D0FC0;
            if (func_800A31D0(buf2, cfg->unk2) == 0) {
            doit = 1;
            val = cfg->unk2;
            str = D_8001952C;
            }
        }
        if (doit != 0) {
            func_800A3750(D_800D3130, str, val, 0, 0, 0, 0);
        }
    }
    func_800A0DBC(D_800D3130, 1);
    func_800BE5A4();
}
