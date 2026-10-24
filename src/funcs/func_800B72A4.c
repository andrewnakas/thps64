#include "common.h"

typedef struct N800B72A4 { u8 pad[0x10]; struct N800B72A4 *next; } N800B72A4;
typedef struct { N800B72A4 *head; N800B72A4 *tail; } L800B72A4;

void func_800B72A4(L800B72A4 *arg0, N800B72A4 *arg1) {
    if (arg0->head == NULL) {
        arg0->head = arg1;
    }
    if (arg0->tail != NULL) {
        arg0->tail->next = arg1;
    }
    arg0->tail = arg1;
    arg1->next = NULL;
}
