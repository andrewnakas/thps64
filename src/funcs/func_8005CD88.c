#include "common.h"

typedef struct Node {
    u16 h0;
    u16 h2;
    u8 pad[0x18];
    struct Node *next;
} Node;

extern u16 D_800D7234;
extern Node *D_800DAD8C;
extern Node *D_800D6180;

void func_8005CD88(void) {
    Node *p;

    if (++D_800D7234 == 0) {
        D_800D7234 = 1;
        for (p = D_800DAD8C; p != NULL; p = p->next) {
            p->h2 = 0;
        }
        for (p = D_800D6180; p != NULL; p = p->next) {
            p->h2 = 0;
        }
    }
}
