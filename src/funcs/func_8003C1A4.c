/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u8 data[0x30];
    u8 x30;
    u8 x31;
    u8 pad32[2];
    s32 x34;
    s32 x38;
    s32 x3C;
} Slot;

typedef struct {
    u8 pad0[0x240];
    s8 x240;
    s8 x241;
    u8 pad242[0x2A];
    Slot slots[16];
} Obj;

void func_8009E0F0(void *, s32, s32);
s32 func_8000574C(void *);
void func_800057E4(void *, void *);
void func_800A8480(Obj *, Slot *, s32 *, s32 *);

void func_8003C1A4(Obj *obj, s32 count, ...) {
    char *ap;
    char *t;
    Slot *sl;
    char *t2;
    s32 v;
    s32 i;
    s32 j;
    s32 one;
    s32 max;
    s32 n;
    Obj *p;
    s32 off;
    void *arg;

    ap = (char *)&count + 4;
    max = -1;
    for (i = 0, one = 1, p = obj, off = 0x26C; i < 16; i++) {
        func_8009E0F0((u8 *)obj + off, 0, 0x30);
        p->slots[0].x30 = one;
        p->slots[0].x31 = 0;
        p->slots[0].x38 = 0;
        p->slots[0].x3C = 0;
        p = (Obj *)((u8 *)p + 0x40);
        off += 0x40;
    }
    obj->x241 = 0;
    j = 0;
    while (1) {
        if (!(j < count)) {
            break;
        }
        t = (char *)(((s32)ap + 3) & -4);
        ap = t + 4;
        arg = *(void **)t;
        n = func_8000574C(arg);
        if (arg != NULL) {
            func_8009E0F0(&obj->slots[obj->x241], 0, 0x30);
            func_800057E4(&obj->slots[obj->x241], arg);
            obj->slots[obj->x241].x31 = n;
            obj->slots[obj->x241].x30 = 1;
            sl = &obj->slots[obj->x241];
            func_800A8480(obj, sl, &sl->x38, &sl->x3C);
            if (max < n) {
                max = n;
            }
            t2 = (char *)(((s32)(t + 4) + 3) & -4);
            ap = t2 + 4;
            v = *(s32 *)t2;
            obj->slots[obj->x241].x34 = v;
            obj->x241++;
        }
        j++;
    }
    obj->slots[0].x30 = 2;
    obj->x240 = 0;
}
