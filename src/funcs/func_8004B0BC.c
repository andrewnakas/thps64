/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Obj {
    char pad0[0x1C];
    struct Obj *next; /* 1C */
    char pad20[0x10];
    struct Obj *prev; /* 30 */
    char pad34[0x18];
    struct Obj **list; /* 4C */
    char pad50[2];
    u16 flags; /* 52 */
} Obj;

extern Obj *D_800D6184;

void func_8004B0BC(Obj *arg0) {
    Obj **list;
    s32 pad[4];
    Obj **head;

    if (arg0->flags & 1) {
        head = &D_800D6184;
        if (arg0->next != NULL) {
            arg0->next->prev = arg0->prev;
        }
        if (arg0->prev != NULL) {
            arg0->prev->next = arg0->next;
        }
        if (*head == arg0) {
            *head = arg0->next;
        }
        list = arg0->list;
        arg0->next = *list;
        arg0->prev = NULL;
        *list = arg0;
        if (arg0->next != NULL) {
            arg0->next->prev = arg0;
        }
        arg0->flags &= 0xFFFE;
    }
}
