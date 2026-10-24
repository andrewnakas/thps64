/* cflags: -O2 */
#include "common.h"

typedef struct Node { s32 pad0; s32 id; u8 pad[0xC]; struct Node *next; } Node;

Node *func_800B267C(u8 *a0, s32 id) {
    Node *p = *(Node **)(a0 + 0x40);
    while (p != NULL) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
