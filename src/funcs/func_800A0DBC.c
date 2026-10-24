/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x460];
    s32 unk460;
} Obj800A0DBC;

extern void func_800A0EA0(Obj800A0DBC *);
extern void func_800A119C(Obj800A0DBC *);
extern void func_800A177C(Obj800A0DBC *);
extern void func_800A1F28(Obj800A0DBC *);
extern void func_800A2438(Obj800A0DBC *);
extern void func_800A32E8(Obj800A0DBC *);
extern void func_800A378C(Obj800A0DBC *);
extern u32 D_800EA550;

s32 func_800A0DBC(Obj800A0DBC *arg0, s32 arg1) {
    arg0->unk460 = arg1;
    switch (D_800EA550) {
    case 0:
        return 0;
    case 1:
        func_800A119C(arg0);
        return 1;
    case 2:
        func_800A378C(arg0);
        return 1;
    case 3:
        func_800A2438(arg0);
        return 1;
    case 4:
        func_800A1F28(arg0);
        return 1;
    case 5:
        func_800A177C(arg0);
        return 1;
    case 6:
        func_800A0EA0(arg0);
        return 1;
    case 7:
        func_800A32E8(arg0);
    default:
        return 1;
    }
}
