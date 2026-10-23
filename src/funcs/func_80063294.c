#include "common.h"

typedef struct {
    u8 pad[0x48];
} Ent;

extern Ent D_800DAF98[];
s32 func_80049034(void *, Ent *, s32);

s32 func_80063294(void *a) {
    s32 i;
    Ent *e;

    i = 0;
    e = D_800DAF98;
    do {
        if (func_80049034(a, e, -1) != 0) {
            return i;
        }
        i++;
        e++;
    } while (i < 40);
    return -1;
}
