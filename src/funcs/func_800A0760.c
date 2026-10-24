/* cflags: -O2 */
#include "common.h"

typedef struct {
    s16 delta;
    s16 index;
    void (*fn)(void *);
} VtEntry;

typedef struct {
    u8 pad0[0x434];
    s32 unk434;
    u8 pad438[0xC0];
    VtEntry *vt;
} Menu;

void func_800A04D8(Menu *, s32);
extern char D_80020A40[];
extern char D_80020A58[];
extern char D_80020A74[];
extern char D_80020A94[];
extern char D_80020AB8[];
extern char D_80020AD0[];

#define VCALL(o, i) ((o)->vt[i].fn((u8 *)(o) + (o)->vt[i].delta))

char *func_800A0760(Menu *arg0, s32 arg1) {
    switch (arg1) {
    case 2:
        func_800A04D8(arg0, arg0->unk434);
        VCALL(arg0, 6);
        return D_80020A40;
    case 1:
        VCALL(arg0, 7);
        return D_80020A58;
    case 4:
        VCALL(arg0, 6);
        return D_80020A74;
    case 11:
        VCALL(arg0, 6);
        return D_80020A94;
    case 7:
    case 8:
        VCALL(arg0, 6);
        return D_80020AB8;
    default:
        VCALL(arg0, 6);
        return D_80020AD0;
    }
}
