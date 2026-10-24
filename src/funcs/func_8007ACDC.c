#include "common.h"

s32 func_80049D60(s32);
extern u8 D_8001E128;
extern u8 D_8001E388;
extern s32 D_800DE520;

typedef struct {
    s32 x, y, z;
} Vec_7ACDC;

typedef struct {
    u8 pad0[0xA];
    s16 unkA;
    u8 padC[0xC];
    Vec_7ACDC unk18;
    Vec_7ACDC unk24;
    u8 pad30[0xC];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 pad3F[5];
    void *unk44;
    s32 unk48[3][3];
    s32 unk6C;
    u8 unk70[3];
    u8 unk73[3];
    u8 unk76;
} Obj_7ACDC;

Obj_7ACDC *func_8007ACDC(Obj_7ACDC *arg0, Vec_7ACDC *arg1, Vec_7ACDC *arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 rx, ry, rz;

    arg0->unk44 = &D_8001E388;
    arg0->unk3C = 1;
    arg0->unk3D = 1;
    arg0->unk3E = 1;
    D_800DE520 += 1;
    arg0->unk44 = &D_8001E128;
    arg0->unk18 = *arg1;
    rx = arg7 * 2 + 1;
    ry = arg8 * 2 + 1;
    rz = arg9 * 2 + 1;
    {
        s32 t = (func_80049D60(rx) - arg7) << 12;
        s32 b = arg1->x;
        arg0->unk48[0][0] = b + t;
    }
    {
        s32 t = (func_80049D60(ry) - arg8) << 12;
        s32 b = arg1->y;
        arg0->unk48[0][1] = b + t;
    }
    {
        s32 t = (func_80049D60(rz) - arg9) << 12;
        s32 b = arg1->z;
        arg0->unk48[0][2] = b + t;
    }
    {
        s32 t = (func_80049D60(rx) - arg7) << 12;
        s32 b = arg1->x;
        arg0->unk48[1][0] = b + t;
    }
    {
        s32 t = (func_80049D60(ry) - arg8) << 12;
        s32 b = arg1->y;
        arg0->unk48[1][1] = b + t;
    }
    {
        s32 t = (func_80049D60(rz) - arg9) << 12;
        s32 b = arg1->z;
        arg0->unk48[1][2] = b + t;
    }
    {
        s32 t = (func_80049D60(rx) - arg7) << 12;
        s32 b = arg1->x;
        arg0->unk48[2][0] = b + t;
    }
    {
        s32 t = (func_80049D60(ry) - arg8) << 12;
        s32 b = arg1->y;
        arg0->unk48[2][1] = b + t;
    }
    {
        s32 t = (func_80049D60(rz) - arg9) << 12;
        s32 b = arg1->z;
        arg0->unk48[2][2] = b + t;
    }
    arg0->unk24 = *arg2;
    arg0->unk6C = arg3;
    arg0->unk70[0] = arg4 >> 2;
    arg0->unk70[1] = arg5 >> 2;
    arg0->unk70[2] = arg6 >> 2;
    arg0->unk73[0] = arg4 >> 2;
    arg0->unk73[1] = arg5 >> 2;
    arg0->unk73[2] = arg6 >> 2;
    arg0->unkA = func_80049D60(0x1E) + 0x1E;
    arg0->unk76 = 4;
    return arg0;
}
