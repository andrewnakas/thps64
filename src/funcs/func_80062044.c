/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Node {
    u8 pad[0x20];
    struct Node *next;
} Node;

extern Node *D_800DBAE0[];
extern s32 D_800FBB50;
extern Node *D_800FBB54;

Node *func_80062044(void) {
    Node *p;

    if (D_800FBB50 >= 0x200) {
        return NULL;
    }
    if (D_800FBB54 != NULL) {
        p = D_800FBB54;
        D_800FBB54 = p->next;
        return p;
    }
    do {
        D_800FBB50++;
        D_800FBB54 = D_800DBAE0[D_800FBB50];
    } while (D_800FBB50 < 0x200 && D_800FBB54 == NULL);
    if (D_800FBB50 >= 0x200) {
        return NULL;
    }
    p = D_800FBB54;
    D_800FBB54 = p->next;
    return p;
}
