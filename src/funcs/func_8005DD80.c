#include "common.h"

s32 func_80023278(s32);                         /* extern */
s32 func_80023280(s32);                         /* extern */
s32 func_800232DC(s32, void *);              /* extern */
s32 func_80043264(s32);                         /* extern */
s32 func_800434BC(void *);                   /* extern */
s32 func_8007EBE4(s32);                             /* extern */

void func_8005DD80(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp10[12];
    s32 temp_s0;

    temp_s0 = func_8007EBE4(arg1) + (arg2 * 0x18);
    func_800232DC(arg1 + 0x10, sp10);
    func_80023280(temp_s0);
    func_80043264(arg0);
    func_800434BC(sp10);
    func_80023278(arg1 + 4);
    func_80043264(arg0);
}
