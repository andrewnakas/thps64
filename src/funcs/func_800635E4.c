#include "common.h"

typedef struct {
    u8 pad[0x14];
    s32 *table;
    u8 pad2[0x48 - 0x18];
} Ent_635E4;

typedef struct Node_635E4 {
    u8 pad[0x16];
    u16 idx;
    u8 pad2[3];
    u8 slot;
    struct Node_635E4 *next;
} Node_635E4;

extern Node_635E4 *D_800DAD8C;
extern Ent_635E4 D_800DAF98[];

Node_635E4 *func_800635E4(s32 arg0) {
    Node_635E4 *n;
    s32 last;
    s32 *table;

    n = D_800DAD8C;
    last = -1;
    while (n != NULL) {
        if (n->slot != last) {
            last = n->slot;
            table = D_800DAF98[last].table;
        }
        if (table[n->idx] == arg0) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}
