#include "common.h"

typedef struct Node6330C {
    u8 pad[0x1C];
    struct Node6330C *next;
} Node6330C;

typedef struct {
    u8 pad[0xC];
    Node6330C node;
} Obj6330C;

typedef struct {
    u8 pad[0x1C];
    Obj6330C *obj;
    u8 pad2[0x28];
} Slot6330C;

s32 func_80062F18(s32);
extern Node6330C *D_800DAD8C;
extern s32 D_800DAD84[];
extern s32 D_800DAD80;
extern Slot6330C D_800DAF98[];

void func_8006330C(s32 arg0) {
    Obj6330C *obj;
    Node6330C *head;
    Node6330C *p;

    if (D_800DAD8C == NULL) {
        D_800DAD8C = &D_800DAF98[arg0].obj->node;
    } else {
        obj = D_800DAF98[arg0].obj;
        head = &obj->node;
        p = head;
        if (obj->node.next != NULL) {
            do {
                p = p->next;
            } while (p->next != NULL);
        }
        p->next = D_800DAD8C;
        D_800DAD8C = head;
    }
    D_800DAD84[func_80062F18(arg0)] = D_800DAD80;
}
