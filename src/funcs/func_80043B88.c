#include "common.h"

typedef struct {
    s32 v[4];
} Row80043B88;

typedef struct {
    Row80043B88 r[4];
    u8 pad40[0x17C - 0x40];
    Row80043B88 *p17C;
    Row80043B88 *p180;
    Row80043B88 *p184;
    Row80043B88 *p188;
} Obj80043B88;

extern Obj80043B88 D_800D49E0[];

void func_80043B88(void) {
    s32 i;
    Obj80043B88 *o;
    Row80043B88 a;
    Row80043B88 d;
    Row80043B88 b;
    Row80043B88 c;


    for (i = 0, o = D_800D49E0; i < 2; i++) {
        a = o->r[0];
        b = o->r[2];
        c = o->r[1];
        d = o->r[3];
        *o->p17C = a;
        *o->p184 = b;
        *o->p180 = c;
        *o->p188 = d;
        o++;
    }
}
