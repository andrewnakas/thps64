#include "common.h"

void func_8004B264(void *, void *);                               /* extern */
void func_8004B330(void *, s32);                         /* extern */
void func_8004B4F8(void *);                            /* extern */
void func_80079178(void *, s32);                         /* extern */
extern u8 D_8001DF68;
extern s32 D_800DE140;
extern u8 D_800DE144;

void func_80079448(void *arg0, s32 arg1) {
    *(void **) ((u8 *) arg0 + 0x48) = &D_8001DF68;
    func_8004B264(arg0, &D_800DE144);
    D_800DE140 -= 1;
    func_80079178(arg0 + 0x404, 2);
    func_80079178(arg0 + 0x35C, 2);
    func_80079178(arg0 + 0x2B4, 2);
    func_80079178(arg0 + 0x20C, 2);
    func_8004B330(arg0, 0);
    if (arg1 & 1) {
        func_8004B4F8(arg0);
    }
}
