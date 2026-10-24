/* cflags: -O2 -fno-schedule-insns */
#include "common.h"

extern u32 func_8000B470(void *, void *, s32);
extern void func_800A04D8(u8 *, s32);
extern void func_800A059C(u8 *);
extern void func_800A05D8(u8 *);

s32 func_800A050C(u8 *arg0, s32 arg1) {
    u8 sp10[0x68];
    s32 r;
    u32 t;

    func_800A059C(arg0);
    t = func_8000B470(arg0 + 0x3EC, sp10, arg1);
    r = 0;
    switch (t) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
        break;
    case 2:
        func_800A04D8(arg0, arg1);
    case 0:
    case 10:
        r = 1;
        break;
    }
    func_800A05D8(arg0);
    return r;
}
