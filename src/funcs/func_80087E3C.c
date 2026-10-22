#include "common.h"
extern u8 D_800D0FC0[];
extern u8 D_800DC3F8[];
void func_80087E3C(void *arg0) {
    register u8 *table __asm__("$5") = D_800DC3F8;
    register u8 *context __asm__("$3") = D_800D0FC0;

    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    __asm__("" : "+r" (table), "+r" (context));
    temp_v0 = (*(u8 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x123));
    (*(u8 *) ((u8 *) (arg0) + 0x539)) = temp_v0;
    (*(u8 *) ((u8 *) (arg0) + 0x535)) = temp_v0;
    temp_v0_2 = (*(u8 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x127));
    (*(u8 *) ((u8 *) (arg0) + 0x53A)) = temp_v0_2;
    (*(u8 *) ((u8 *) (arg0) + 0x536)) = temp_v0_2;
    temp_v0_3 = (*(u8 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x12B));
    (*(u8 *) ((u8 *) (arg0) + 0x53B)) = temp_v0_3;
    (*(u8 *) ((u8 *) (arg0) + 0x537)) = temp_v0_3;
    temp_v0_4 = (*(u8 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x12F));
    (*(u8 *) ((u8 *) (arg0) + 0x53C)) = temp_v0_4;
    (*(u8 *) ((u8 *) (arg0) + 0x538)) = temp_v0_4;
    (*(s32 *) ((u8 *) (arg0) + 0x550)) = (s32) (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 4) + table)) + 0x118));
    (*(s32 *) ((u8 *) (arg0) + 0x554)) = (s32) (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 4) + table)) + 0x110));
}
