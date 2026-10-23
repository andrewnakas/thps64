#include "common.h"

typedef struct Node80061ACC {
    u8 pad0[0x1C];
    struct Node80061ACC *next;
    u8 pad20[0x50 - 0x20];
    u16 flags;
    u8 pad52[0x15E - 0x52];
    u16 id;
} Node80061ACC;

extern Node80061ACC *D_800D6180;
extern s16 **D_800DACB0;
extern Node80061ACC *D_800DDC60;

void func_80061ACC(u16 *arg0) {
    u16 *ids;
    s32 i;
    s32 count;
    s16 **tbl;
    s32 id;
    s16 type;
    Node80061ACC *n;

    ids = arg0 + 1;
    i = 0;
    count = *arg0;
    tbl = D_800DACB0;


    while (1) {
        if (i >= count) break;
        id = *ids;
        type = *tbl[id];
        if (type == 1 || type == 7) {
            for (n = D_800DDC60; n != NULL; n = n->next) {
                if (n->id == id) {
                    n->flags |= 1;
                }
            }
            for (n = D_800D6180; n != NULL; n = n->next) {
                if (n->id == id) {
                    n->flags |= 1;
                }
            }
        }
        i++;
        ids++;
    }
}
