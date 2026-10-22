#include "common.h"

void func_800394A8(void *, s32);             /* extern */
void func_80065E8C(void *, void *);        /* extern */
void func_80088ED4(void *);                            /* extern */
void func_800A735C(void *, s32);             /* extern */
void func_800B19C0(void *, s32);             /* extern */
extern u8 D_8001EFF8[];
extern u8 D_800D0FC0[];
extern u8 D_800DC3F8[];

void func_80087C94(void *arg0, s32 arg1) {
    register u8 *table __asm__("$5");
    register u8 *context __asm__("$4");

    (*(void **) ((u8 *) (arg0) + 0x2C)) = D_8001EFF8;
    if ((*(s32 *) ((u8 *) (arg0) + 0x528)) == 0) {
        func_80088ED4(arg0);
    }
    table = D_800DC3F8;
    context = D_800D0FC0;
    __asm__("" : "+r" (table), "+r" (context));
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 4) + table)) + 0x110)) = (s32) (*(s32 *) ((u8 *) (arg0) + 0x554));
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 4) + table)) + 0x118)) = (s32) (*(s32 *) ((u8 *) (arg0) + 0x550));
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x120)) = (s32) (*(s8 *) ((u8 *) (arg0) + 0x535));
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x124)) = (s32) (*(s8 *) ((u8 *) (arg0) + 0x536));
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x128)) = (s32) (*(s8 *) ((u8 *) (arg0) + 0x537));
    (*(s32 *) ((u8 *) ((((*(u8 *) ((u8 *) (context) + 0x16)) * 0x10) + table)) + 0x12C)) = (s32) (*(s8 *) ((u8 *) (arg0) + 0x538));
    func_80065E8C(context, table);
    func_800A735C(arg0 + 0x2B0, 2);
    func_800A735C(arg0 + 0x70, 2);
    func_800B19C0(arg0 + 0x5C, 2);
    func_800B19C0(arg0 + 0x48, 2);
    func_800B19C0(arg0 + 0x34, 2);
    func_800394A8(arg0, arg1);
}
