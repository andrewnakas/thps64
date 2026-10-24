/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: aln 0.951. Equivalent C; differs only in loop shape: the entry `if (p) next = p->next;` branch is threaded straight to the exit, and %hi(D_800D61A8) is not hoisted into s4. */
/* Z3 near-miss 89/91 (-O2 nosched; F4 draft 87/91 at -O1). Change: the object walk is a goto loop instead of
   while(1): loop.c then no longer hoists %hi(D_800D6184), and CSE folds the obj_remove_ head into lui + %lo(lw/sw)
   like the game. Left: (1) the entry `if (p) next = p->next;` branch is threaded straight to the exit (game: to the
   loop-top test, as a real loop), (2) %hi(D_800D61A8) is set inside the loop (game: hoisted by loop.c into s4 at
   entry). A real while loop gives both of those but also hoists %hi(D_800D6184) (81/91 at -O2, 87/91 at -O1 with
   a full lui/addiu head). */
#include "common.h"

typedef struct Obj {
    u8 pad0[4];
    u8 pos[0x18];
    struct Obj *next;
    u8 pad20[0x10];
    struct Obj *prev;
    u8 pad34[0x18];
    struct Obj **list;
    u16 pad50;
    u16 flags;
} Obj;

u32 func_80047C34(void *, void *);
extern Obj *D_800D6184;
extern u32 D_800D619C;
extern Obj *D_800D61A8;
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;

static inline void obj_remove_(Obj **head, Obj *p) {
    Obj *t;

    t = p->next;
    if (t != NULL) {
        t->prev = p->prev;
    }
    t = p->prev;
    if (t != NULL) {
        t->next = p->next;
    }
    if (*head == p) {
        *head = p->next;
    }
}

static inline void obj_insert_(Obj **list, Obj *p) {
    p->next = *list;
    p->prev = NULL;
    *list = p;
    if (p->next != NULL) {
        p->next->prev = p;
    }
}

void func_8004AB58(void) {
    Obj *p;
    Obj *next;
    u32 dist;
    u32 d2;

    p = D_800D6184;
    if (p != NULL) {
        next = p->next;
    }
loop:
    if (p == NULL) {
        return;
    }
    if (p->flags & 2) {
        dist = func_80047C34(D_800D61A8->pos, p->pos);
        if (D_800DE9A8 == 2 && D_800DE7A0 != 7) {
            d2 = func_80047C34(D_800D61A8->next->pos, p->pos);
            if (d2 < dist) {
                dist = d2;
            }
        }
        if (dist <= D_800D619C && (p->flags & 1)) {
            obj_remove_(&D_800D6184, p);
            obj_insert_(p->list, p);
            p->flags &= 0xFFFE;
        }
    }
    p = next;
    if (p == NULL) {
        return;
    }
    next = p->next;
    goto loop;
}
