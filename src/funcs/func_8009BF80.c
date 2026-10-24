/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    f32 val;
    u8 pad14[0x10];
    s32 type;
    void *dst;
} Param;

typedef struct {
    u8 pad0[0x10];
    u8 enabled;
    u8 pad11[7];
    s32 count;
    u8 pad1C[0x160];
} ParamGroup;

typedef struct {
    u8 pad0[0x240];
    ParamGroup groups[8];
} Obj;

void func_8009BF80(Obj *arg0) {
    s32 i;
    s32 j;
    ParamGroup *g;
    Param *p;
    f32 f;
    u32 v;
    u8 *d;

    i = 0;
    while (1) {
        if (i >= 8) {
            break;
        }
        g = &arg0->groups[i];
        if (g->enabled != 0) {
            j = 0;
            while (1) {
                if (j >= g->count) {
                    break;
                }
                p = (Param *)((u8 *)g + 0x1C) + j;
                if (p->dst != NULL) {
                    switch (p->type) {
                    case 1:
                        f = p->val;
                        d = p->dst;
                        if (!(f >= 2147483648.0f)) {
                            v = (s32)f;
                        } else {
                            v = (s32)(f - 2147483648.0f);
                            v |= 0x80000000;
                        }
                        *d = v;
                        break;
                    case 2:
                        *(s16 *)p->dst = p->val;
                        break;
                    case 4:
                        *(s32 *)p->dst = p->val;
                        break;
                    case 8:
                        *(f32 *)p->dst = p->val;
                        break;
                    }
                }
                j++;
            }
        }
        i++;
    }
}
