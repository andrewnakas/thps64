#include "common.h"

typedef struct
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Unk80079C10;
s32 func_8005EAB4(s32, s32, s32);
extern u8 D_8001E2D8;
extern u8 D_8001E388;
extern s32 D_800DE520;
void *func_80079C10(void *arg0, Unk80079C10 *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9)
{
    s32 temp_v0;
    int new_var;
    u32 var_a0;
    u32 temp_a1;
    u32 var_a0_2;
    u32 var_a0_3;
    *((s32 *) (((u8 *) arg0) + 0x44)) = &D_8001E388;
    *((u8 *) (((u8 *) arg0) + 0x3C)) = 1;
    *((u8 *) (((u8 *) arg0) + 0x3D)) = 1;
    *((u8 *) (((u8 *) arg0) + 0x3E)) = 1;
    D_800DE520 += 1;
    *((s32 *) (((u8 *) arg0) + 0x44)) = &D_8001E2D8;
    *((s32 *) (((u8 *) arg0) + 0x50)) = 8U;
    *((u16 *) (((u8 *) arg0) + 0x5C)) = 0x200;
    *((s32 *) (((u8 *) arg0) + 0x54)) = 1;
    temp_v0 = func_8005EAB4((*((s32 *) (((u8 *) arg0) + 0x50))) * 0x10, 0, 1);
    *((s32 *) (((u8 *) arg0) + 0x48)) = temp_v0;
    *((s32 *) (((u8 *) arg0) + 0x4C)) = (s32) (temp_v0 + ((*((s32 *) (((u8 *) arg0) + 0x50))) * 8));
    *((Unk80079C10 *) (((u8 *) arg0) + 0x18)) = *arg1;
    var_a0 = 0;
    if ((*((s32 *) (((u8 *) arg0) + 0x50))) != 0)
    {
        do
        {
            *((s32 *) ((var_a0 * 8) + (*((s32 *) (((u8 *) arg0) + 0x48))))) = arg2;
            var_a0 += 1;
        }
        while (var_a0 < ((u32) (*((s32 *) (((u8 *) arg0) + 0x50)))));
    }
    do
    {
        register u32 first __asm__("$3") = (arg6 & 0xFF) << 16;
        register u32 second __asm__("$2") = (arg5 & 0xFF) << 8;
        __asm__("" : "+r" (first), "+r" (second));
        second |= 0x32000000;
        first |= second;
        first |= arg4 & 0xFF;
        *((s32 *) (((u8 *) arg0) + 0x58)) = first;
        temp_a1 = (((arg9 & 0xFF) << 0x10) | ((arg8 & 0xFF) << 8)) | (arg7 & 0xFF);
        var_a0_2 = 0;
        if ((*((s32 *) (((u8 *) arg0) + 0x50))) != 0)
        {
            do
            {
                new_var = *((s32 *) (((u8 *) arg0) + 0x48));
                new_var = ((var_a0_2 * 8) + new_var) + 4;
                *((s32 *) new_var) = (s32) temp_a1;
                var_a0_2 += 1;
            }
            while (var_a0_2 < ((u32) (*((s32 *) (((u8 *) arg0) + 0x50)))));
        }
    }
    while (0);
    var_a0_3 = 0;
    if ((*((s32 *) (((u8 *) arg0) + 0x50))) != 0)
    {
        do
        {
            *((s32 *) ((var_a0_3 * 8) + (*((s32 *) (((u8 *) arg0) + 0x4C))))) = arg3;
            *((s32 *) (((var_a0_3 * 8) + (*((s32 *) (((u8 *) arg0) + 0x4C)))) + 4)) = 0x3A000000;
            var_a0_3 += 1;
        }
        while (var_a0_3 < ((u32) (*((s32 *) (((u8 *) arg0) + 0x50)))));
    }
    *((s32 *) (((u8 *) arg0) + 0x64)) = -1;
    return arg0;
}
