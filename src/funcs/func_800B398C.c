/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
} VtEntry;

typedef struct {
    VtEntry e[16];
} Vtbl;

typedef struct {
    u8 pad0[0x1C4];
    Vtbl *vt;
    u8 unk1C8[0x18];
    s32 unk1E0;
} Stream;

void func_80001EC0(void *, s32, s32);
void func_80004620(Stream *);
void func_80005070(void *, s32, s32);
s32 func_8009E6B4(void *, s32, s32);
void func_8009FFD8(Stream *, s32, s32, s32);
extern u8 D_800EA110[];

#define VCALL(o, i) ((o)->vt->e[i].fn((u8 *)(o) + (o)->vt->e[i].delta))

void func_800B398C(Stream *arg0) {
    s32 a;
    s32 b;

    arg0->unk1E0 = func_8009E6B4(D_800EA110, VCALL(arg0, 10) * 4, 4);
    func_80001EC0(arg0->unk1C8, arg0->unk1E0, VCALL(arg0, 10));
    func_80005070(arg0->unk1C8, 1, 1);
    func_80005070(arg0->unk1C8, 1, 1);
    a = VCALL(arg0, 11);
    b = VCALL(arg0, 12);
    func_8009FFD8(arg0, a, b, VCALL(arg0, 9));
    func_80004620(arg0);
}
