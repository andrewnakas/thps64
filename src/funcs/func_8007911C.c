#include "common.h"

void func_800230FC(s32, s32 *);                        /* extern */
void func_80067A48(s32, s32);                          /* extern */

void func_8007911C(void *arg0) {
    s32 sp10[3];
    s32 temp_s1;

    temp_s1 = arg0 + 0x88;
    func_80067A48(arg0 + 0x6C, temp_s1);
    sp10[0] = *(s32 *) ((u8 *) arg0 + 0x7C);
    sp10[1] = *(s32 *) ((u8 *) arg0 + 0x80);
    sp10[2] = *(s32 *) ((u8 *) arg0 + 0x84);
    func_800230FC(temp_s1, sp10);
}
