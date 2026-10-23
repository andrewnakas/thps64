#include "common.h"

typedef struct Obj {
    u8 pad0[0x1C];
    struct Obj *next;
    u8 pad20[0x15E - 0x20];
    u16 unk15E;
} Obj;

void func_8004B0BC(Obj *);
void func_8004B13C(Obj *, Obj **);
extern Obj *D_800D6180;
extern Obj *D_800D6184;
extern s16 **D_800DACB0;
extern Obj *D_800DDC60;

void func_8005FD44(u16 *arg0, s32 arg1) {
    s32 i;
    u16 *ids;
    s32 id;
    Obj **head;
    Obj **head2;
    u16 n;
    Obj *p;
    s16 type;

    ids = arg0 + 1;
    n = *arg0;
    i = 0;
    while (1) {
        if (i >= n) {
            break;
        }
        id = *ids;
        type = *D_800DACB0[id];
        if (type == 1 || type == 7) {
            if (arg1 == 5) {
                head = &D_800DDC60;
                for (p = *head; p != NULL; p = p->next) {
                    if (p->unk15E == id) {
                        func_8004B13C(p, head);
                    }
                }
                head2 = &D_800D6180;
                for (p = *head2; p != NULL; p = p->next) {
                    if (p->unk15E == id) {
                        func_8004B13C(p, head2);
                    }
                }
            } else {
                for (p = D_800D6184; p != NULL; p = p->next) {
                    if (p->unk15E == id) {
                        func_8004B0BC(p);
                    }
                }
            }
        }
        i++;
        ids++;
    }
}
