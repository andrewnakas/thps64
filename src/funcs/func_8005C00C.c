#include "common.h"

s32 func_80022964(void *);
s32 func_80042C70();
s32 func_80043264(void *);
s32 func_8004356C(void *);
s32 func_80043590(void *);
s32 func_8005BE8C(void *);

void func_8005C00C(void *arg0) {
    void *temp_s0;
    void *temp_s2;
    void *temp_s3;
    s32 t;

    temp_s3 = arg0 + 0x8E8;
    t = -0x1000;
    (*(s32 *)((u8 *)(arg0) + 0x8E8)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x8EC)) = t;
    (*(s32 *)((u8 *)(arg0) + 0x8F0)) = 0;
    temp_s2 = arg0 + 0x8D0;
    func_80043590(temp_s2);
    func_8004356C(temp_s3);
    temp_s0 = arg0 + 0x8DC;
    func_80042C70();
    func_80043264(temp_s0);
    func_80022964(temp_s0);
    func_80043590(temp_s0);
    func_8004356C(temp_s2);
    func_80042C70();
    func_80043264(temp_s3);
    func_8005BE8C(arg0);
}
