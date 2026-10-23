#include "common.h"

typedef struct {
    s32 id;
    u8 pad4[0xC];
    s8 active;
    u8 pad11[0x44 - 0x11];
} Ent8003A4C8;

typedef struct {
    u8 pad0[4];
    Ent8003A4C8 e[3];
} Obj8003A4C8;

void func_800A9588(void *, s32);
void func_800AA8C8(void *, void *);
extern s32 D_800EA9C0;

void func_8003A4C8(Obj8003A4C8 *arg0, s32 arg1) {
    Ent8003A4C8 *e0;
    Ent8003A4C8 *e1;
    Ent8003A4C8 *e2;
    s32 *p0;
    s32 *p1;
    s32 *p2;

    arg1 &= 0xFF;
    e0 = &arg0->e[0];
    if (arg1 == arg0->e[0].id) {
        arg0->e[0].active = 0;
        p0 = &D_800EA9C0;
        func_800A9588(p0, arg0->e[0].id);
        func_800AA8C8(p0, e0);
        return;
    }
    e1 = &arg0->e[1];
    if (arg1 == arg0->e[1].id) {
        arg0->e[1].active = 0;
        p1 = &D_800EA9C0;
        func_800AA8C8(p1, e1);
        func_800A9588(p1, arg0->e[1].id);
        return;
    }
    e2 = &arg0->e[2];
    if (arg1 == arg0->e[2].id) {
        arg0->e[2].active = 0;
        p2 = &D_800EA9C0;
        func_800AA8C8(p2, e2);
        func_800A9588(p2, arg0->e[2].id);
    }
}
