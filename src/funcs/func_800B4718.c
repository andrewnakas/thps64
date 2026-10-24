/* cflags: -O2 */
#include "common.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
} Node;

void func_800B4718(u8 *arg0, Node *arg1) {
    Node **head = (Node **)(arg0 + 0x3C);

    if (*head != NULL) {
        (*head)->next = arg1;
    }
    arg1->prev = *head;
    *head = arg1;
    arg1->next = NULL;
}
