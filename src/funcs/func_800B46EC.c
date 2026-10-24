#include "common.h"

typedef struct N800B46EC { s32 pad0; struct N800B46EC *next; s32 id; } N800B46EC;

N800B46EC *func_800B46EC(u8 *arg0, s32 arg1) {
    N800B46EC *p;

    for (p = *(N800B46EC **)(arg0 + 0x3C); p != NULL; p = p->next) {
        if (p->id == arg1) {
            break;
        }
    }
    return p;
}
