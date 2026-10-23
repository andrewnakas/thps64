#include "common.h"

void func_80046D54(s32 *, s32 *, s32 *);
void func_80046DAC(s32 *, s32 *, s32 *);
void func_80046E04(s32 *, s32 *, s32 *);
void func_80046EF4(s32 *, u8 *, s32 *);
void func_80046FBC(s32 *, u8 *, u8 *);
void func_800472C0(u8 *, s32 *);
s32 func_800474C8(s32 *);

void func_8004AFD8(u8 *arg0, u8 *arg1) {
    s32 a[4];
    s32 b[4];
    s32 c[4];
    s32 d[4];
    s32 e[4];
    s32 n1;
    s32 len;
    s32 n2;
    s32 *pb;
    s32 *pc;
    s32 *pd;
    s32 *pe;
    s32 twelve;

    func_80046FBC(a, arg0 + 4, arg1 + 4);
    len = func_800474C8(a);
    if (len == 0) {
        len = 1;
    }
    pb = b;
    pc = c;
    pd = d;
    pe = e;
    twelve = 0xC;
    n1 = twelve;
    func_80046DAC(pe, a, &n1);
    func_80046EF4(pd, arg1 + 0x158, pe);
    func_80046E04(pc, pd, &len);
    n2 = twelve;
    func_80046D54(pb, pc, &n2);
    func_800472C0(arg0 + 0x84, pb);
}
