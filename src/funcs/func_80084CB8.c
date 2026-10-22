#include "common.h"

void func_80001A30(void *, void *);
void func_8007EBE4(void *);
void func_8009C8EC(void *, void *);
void func_8009C914(void *, void *, s32);
void func_8009CB68(void *, s32 *);
extern s32 D_800F32B8;

void func_80084CB8(void *arg0, s32 arg1, s32 arg2) {
    s32 sp10[16];
    s32 sp50[4];
    s32 sp60[16];
    register s32 var_s0 __asm__("$16");
    register s32 one __asm__("$21");
    register s32 *temp_s3 __asm__("$19");
    register void *temp_a0 __asm__("$4");
    register s32 temp_v0 __asm__("$2");
    register u8 *var_s1 __asm__("$17");
    register u8 *var_s2 __asm__("$18");

    register void *temp_s4 __asm__("$20") = arg0;
    register s32 temp_s7 __asm__("$23") = arg1;
    register s32 temp_s6 __asm__("$22") = arg2;
    func_8007EBE4(*(void **) ((u8 *) temp_s4 + 0xC00));
    temp_a0 = *(void **) ((u8 *) temp_s4 + 0xC00);
    temp_v0 = D_800F32B8 * 0x600;
    __asm__("" : "+r" (temp_a0), "+r" (temp_v0));
    var_s0 = 0;
    one = 1;
    temp_s3 = sp60;
    __asm__("" : "+r" (one), "+r" (temp_s3));
    var_s2 = (u8 *) temp_s4 + temp_v0;
    var_s1 = *(u8 **) ((u8 *) temp_a0 + 0x214);
    __asm__("" : "+r" (var_s0), "+r" (var_s1), "+r" (var_s2), "+r" (temp_s4), "+r" (temp_s7));
    __asm__("" : "+r" (temp_s6));
loop_1:
    if (var_s0 < *(s32 *) ((u8 *) temp_s4 + 0xC0C)) {
        if (temp_s6 & (one << var_s0)) {
            sp50[2] = 0;
            sp50[1] = 0;
            sp50[0] = 0;
            func_8009CB68(sp10, sp50);
        } else {
            func_8009C914(temp_s3, var_s1, temp_s7);
            func_8009C8EC(sp10, temp_s3);
        }
        func_80001A30(sp10, var_s2);
        var_s2 += 0x40;
        var_s1 += 0x40;
        var_s0 += 1;
        goto loop_1;
    }
}
