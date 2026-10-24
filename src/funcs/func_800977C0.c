/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x84];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
} Obj_800977C0;

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
} Ctl_800977C0;

s32 func_800A050C(Ctl_800977C0 *, s32);
void func_800A0DBC(Ctl_800977C0 *, s32);
void func_800A1174(Ctl_800977C0 *, s32, s32);
void func_800A3BD4(Ctl_800977C0 *, s32 *, s32 *);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern u16 D_800D0FD8;
extern Ctl_800977C0 D_800D3130;
extern s32 D_800D3144;
extern s32 D_800E95D0;
extern s32 D_800EA550;

void func_800977C0(Obj_800977C0 *o) {
    s32 sp18[4];
    s32 sp28;

    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    if (D_800D0FD8 == 1 || D_800D0FD8 == 2) {
        func_800B1AC4((u8 *)o + 0x30, 34.0f, 0.0f, 0.91f, 2.0f);
    }
    if (o->unk90 != 0 && D_800EA550 == 0) {
        if (o->unk84 == 0) {
            if (D_800D3144 != 0) {
                o->unk8C = 1;
            } else {
                o->unk88 = 1;
            }
        }
        if (o->unk84 != 0 || D_800D3130.unk14 != 0) {
            func_800A1174(&D_800D3130, D_800E95D0, 0);
            o->unk84 = 0;
        } else if (o->unk88 == 0 && o->unk8C == 0) {
            if (func_800A050C(&D_800D3130, D_800E95D0) != 0) {
                func_800A1174(&D_800D3130, D_800E95D0, 0);
            }
            o->unk88 = 1;
            o->unk84 = 0;
        } else {
            o->unk84 = 0;
        }
    }
    if (D_800EA550 == 3) {
        func_800B1AC4((u8 *)o + 0x44, 0.0f, 406.0f, 1.0f, 1.0f);
    } else if (D_800EA550 == 2) {
        func_800A3BD4(&D_800D3130, sp18, &sp28);
        if (sp28 >= 2) {
            func_800B1AC4((u8 *)o + 0x58, 0.0f, 406.0f, 1.0f, 1.0f);
        } else {
            func_800B1AC4((u8 *)o + 0x6C, -81.0f, 406.0f, 1.0f, 1.0f);
        }
    }
    func_800A0DBC(&D_800D3130, 1);
    if (o->unk94++ < 3) {
        func_800BEF70(0, 0, 0);
    }
    func_800BE5A4();
}
