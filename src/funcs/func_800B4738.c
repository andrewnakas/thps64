#include "common.h"

typedef struct N800B4738 { struct N800B4738 *prev; struct N800B4738 *next; } N800B4738;

void func_800B4738(u8 *arg0, N800B4738 *arg1) {
    if (*(N800B4738 **)(arg0 + 0x3C) == arg1) {
        *(N800B4738 **)(arg0 + 0x3C) = arg1->next;
    }
    if (arg1->prev != NULL) {
        arg1->prev->next = arg1->next;
    }
    if (arg1->next != NULL) {
        arg1->next->prev = arg1->prev;
    }
}
