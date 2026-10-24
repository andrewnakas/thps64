/* cflags: -O2 -fno-schedule-insns */
#include "common.h"

typedef struct {
    u8 pad[0x14];
} E14;

typedef struct {
    u8 pad0[0x1C4];
    u8 *vt;
    E14 items[256];
} Obj;

extern void func_80001EC0(u8 *, u8 *, s32);
extern void func_80005070(u8 *, E14 *, s32);
extern void func_8009FF00(u8 *);
extern u8 D_800220A0[];

u8 *func_800BADC0(u8 *arg0) {
    s32 o;
    s32 i;

    func_8009FF00(arg0);
    ((Obj *)arg0)->vt = D_800220A0;
    func_80001EC0(arg0 + 0x1DC8, arg0 + 0x19C8, 0x100);
    func_80001EC0(arg0 + 0x1DE0, arg0 + 0x15C8, 0x100);
    i = 0;
    o = 0;
    while (1) {
        if (i >= 0x100) break;
        func_80005070(arg0 + 0x1DE0, (E14 *)(o + (s32)arg0 + 0x1C8), 1);
        o += 0x14;
        i++;
    }
    return arg0;
}
