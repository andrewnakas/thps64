/* cflags: -O2 */
#include "common.h"

void func_800BA840(s32 arg0, u16 *arg1, u8 *arg2) {
    u32 c;
    u32 ro;
    u32 go;
    u32 bo;
    u32 a;
    u8 *r;
    u8 *g;
    u8 *b;
    u32 rv;
    u32 gv;
    u32 bv;

    c = *arg1;
    ro = (c >> 8) & 0xF8;
    go = (c >> 3) & 0xF8;
    bo = (c << 2) & 0xF8;
    a = c & 1;
    r = arg2 + ro;
    g = arg2 + go;
    b = arg2 + bo;
    rv = *r;
    gv = *g;
    bv = *b;
    *arg1 = ((rv >> 3) << 11) | ((gv >> 3) << 6) | ((bv >> 3) << 1) | a;
}
