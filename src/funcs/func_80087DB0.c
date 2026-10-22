#include "common.h"
extern u8 D_800D0FC0[];
extern u8 D_800DC3F8[];
void func_80087DB0(void *arg0) {
    register u8 *table __asm__("$7") = D_800DC3F8;
    register u8 *context __asm__("$6") = D_800D0FC0;

    __asm__("" : "+r" (table), "+r" (context));
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x120)) = 0;
    (*(s8 *) ((u8 *) (arg0) + 0x539)) = 0;
    (*(s8 *) ((u8 *) (arg0) + 0x535)) = 0;
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x124)) = 1;
    (*(s8 *) ((u8 *) (arg0) + 0x53A)) = 1;
    (*(s8 *) ((u8 *) (arg0) + 0x536)) = 1;
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x128)) = 2;
    (*(s8 *) ((u8 *) (arg0) + 0x53B)) = 2;
    (*(s8 *) ((u8 *) (arg0) + 0x537)) = 2;
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x12C)) = 3;
    (*(s8 *) ((u8 *) (arg0) + 0x53C)) = 3;
    (*(s8 *) ((u8 *) (arg0) + 0x538)) = 3;
    (*(s32 *) ((u8 *) (arg0) + 0x550)) = 1;
    (*(s32 *) ((u8 *) (arg0) + 0x554)) = 1;
    (*(s32 *) ((u8 *) (arg0) + 0x528)) = 1;
}
