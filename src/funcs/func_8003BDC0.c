#include "common.h"

s32 func_8003C8F4(void *, s32);             /* extern */
s32 func_8008B490(void *, void *, s32);  /* extern */
s32 func_8008BB2C(void *, s32);          /* extern */
s32 func_8008BB50(void *);                   /* extern */
s32 func_8009E0F0(void *, s32, s32);    /* extern */
s32 func_800A72C0();                            /* extern */
s32 func_800A73EC(void *, s32);             /* extern */

void *func_8003BDC0(void *arg0) {
    s32 sp10;
    s32 var_s0;
    s32 var_s1;
    f32 t;
    f32 c;
    f32 d;
    u32 m;
    u32 v;

    func_800A72C0();
    func_8008BB50(&sp10);
    func_800A73EC(arg0, 0x501);
    func_8008B490(&sp10, arg0, 0x501);
    (*(s8 *)((u8 *)(arg0) + 0x10)) = 0;
    (*(s8 *)((u8 *)(arg0) + 0x240)) = 0;
    (*(s8 *)((u8 *)(arg0) + 0x246)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x24C)) = 0;
    (*(s8 *)((u8 *)(arg0) + 0x241)) = -1;
    (*(s8 *)((u8 *)(arg0) + 0x245)) = 5;
    (*(s8 *)((u8 *)(arg0) + 0x243)) = 1;
    (*(s8 *)((u8 *)(arg0) + 0x244)) = 4;
    (*(s32 *)((u8 *)(arg0) + 0x248)) = -1;
    (*(f32 *)((u8 *)(arg0) + 0x258)) = (f32) 100.0f;
    (*(f32 *)((u8 *)(arg0) + 0x25C)) = (f32) 100.0f;
    (*(f32 *)((u8 *)(arg0) + 0x254)) = (f32) 10.0f;
    (*(f32 *)((u8 *)(arg0) + 0x250)) = (f32) 200.0f;
    (*(f32 *)((u8 *)(arg0) + 0x264)) = (f32) 1.4f;
    (*(f32 *)((u8 *)(arg0) + 0x268)) = (f32) 1.0f;
    t = (*(f32 *)((u8 *)(arg0) + 0x264)) * 210.0f;
    c = 2147483648.0f;
    if (!(t >= c)) {
        v = (s32)t;
    } else {
        d = t - c;
        m = 0x80000000;
        v = (s32)d | m;
    }
    (*(s32 *)((u8 *)(arg0) + 0x260)) = (u16)v;
    var_s1 = 0;
    var_s0 = 0x26C;
    do {
        func_8009E0F0(arg0 + var_s0, 0, 0x30);
        var_s1 += 1;
        var_s0 += 0x40;
    } while (var_s1 < 0x10);
    func_8003C8F4(arg0, 1);
    func_8008BB2C(&sp10, 2);
    return arg0;
}
