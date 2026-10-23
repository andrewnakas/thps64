#include "common.h"

typedef struct {
    s32 v[4];
} Row80043CC0;

typedef struct {
    Row80043CC0 r[4];
    u8 pad40[0x17C - 0x40];
    Row80043CC0 *p17C;
    Row80043CC0 *p180;
    Row80043CC0 *p184;
    Row80043CC0 *p188;
} Obj80043CC0;

extern Obj80043CC0 D_800D49E0[];

void func_80043CC0(void) {
    s32 i;
    Obj80043CC0 *o;
    Row80043CC0 a;
    Row80043CC0 d;
    Row80043CC0 b;
    Row80043CC0 c;


    for (i = 0, o = D_800D49E0; i < 2; i++) {
        a = *o->p17C;
        b = *o->p184;
        c = *o->p180;
        d = *o->p188;
        o->r[0] = a;
        o->r[2] = b;
        o->r[1] = c;
        o->r[3] = d;
        o++;
    }
}
