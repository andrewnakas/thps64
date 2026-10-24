/* cflags: -O2 */
#include "common.h"

typedef struct Ev {
    f32 x, y, z;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    struct Ev *next;
    struct Ev *prev;
    u8 pad24[4];
} Ev;

typedef struct {
    Ev *head;
    Ev *tail;
    Ev evs[32];
    u8 pad508[4];
    f32 unk50C;
} EvList;

f32 func_8009F2CC(void);

s32 func_8009B16C(EvList *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    Ev *e;
    s32 i;
    s32 idx;
    s32 off;
    Ev *p;

    if (arg7 != 0 && arg0->unk50C > 0.0f) {
        return -1;
    }
    arg0->unk50C = func_8009F2CC();
    e = NULL;
    i = 0;
    off = 8;
    while (1) {
        if (i >= 32) {
            break;
        }
        p = (Ev *)((u8 *)arg0 + off);
        if (p->unk14 == 0.0f) {
            e = p;
            idx = i;
            break;
        }
        off += sizeof(Ev);
        i++;
    }
    if (e == NULL) {
        return -1;
    }
    e->x = arg1;
    e->y = arg2;
    e->z = arg3;
    e->unkC = arg4;
    e->unk10 = arg5;
    e->unk14 = arg6;
    e->unk18 = arg6;
    e->next = NULL;
    if (arg0->head == NULL) {
        arg0->head = e;
    }
    e->prev = arg0->tail;
    if (arg0->tail != NULL) {
        arg0->tail->next = e;
    }
    arg0->tail = e;
    return idx;
}
