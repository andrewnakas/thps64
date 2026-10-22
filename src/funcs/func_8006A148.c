#include "common.h"

typedef struct Node8006A148 {
    u8 pad[0xC];
    struct Node8006A148 *next;
} Node8006A148;

extern Node8006A148 *D_800DC5E0;

void func_8006A148(void) {
    Node8006A148 *p;

    p = D_800DC5E0;
    while (1) {
        if (p == NULL) {
            break;
        }
        p = p->next;
    }
}
