#include "common.h"

void func_8009E0F0(s32, s32, s32);                         /* extern */
#define D_8001EDF4 (*(const f32 *) 0x8001EDF4)
extern s32 D_800F5628;

void func_80086FBC(void *arg0) {
    func_8009E0F0(arg0 + 0xA0, 0, 0x18);
    *(s32 *) ((u8 *) arg0 + 0x1388) = 0;
    *(u16 *) ((u8 *) arg0 + 0x0) = 0;
    *(u16 *) ((u8 *) arg0 + 0x2) = 0;
    *(f32 *) ((u8 *) arg0 + 0xCC) = (f32) D_8001EDF4;
    *(f32 *) ((u8 *) arg0 + 0xD0) = (f32) D_8001EDF4;
    *(s32 *) ((u8 *) arg0 + 0xC0) = 0;
    *(s32 *) ((u8 *) arg0 + 0xBC) = 0;
    *(s32 *) ((u8 *) arg0 + 0xC8) = 0;
    *(s32 *) ((u8 *) arg0 + 0xC4) = 0;
    D_800F5628 = *(s32 *) ((u8 *) arg0 + 0x595C);
}
