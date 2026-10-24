/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Pair800BAB04;

typedef struct {
    Pair800BAB04 *slots;
    s32 unk4;
    s32 count;
    s32 nmap;
    Pair800BAB04 *map;
} Mgr800BAB04;

s32 func_8009E30C(s32);
s32 func_800B81C0(s32);
void func_800BA768(s32, s32);

Pair800BAB04 *func_800BAB04(Mgr800BAB04 *arg0, s32 id) {
    s32 i;
    Pair800BAB04 *slot;
    s32 obj;
    Pair800BAB04 *m;

    i = 0;
    while (1) {
        if (i >= arg0->nmap) {
            break;
        }
        m = &arg0->map[i];
        i++;
        if (id == m->a) {
            id = m->b;
            break;
        }
    }
    slot = &arg0->slots[id];
    if (++slot->a != 1) {
        return slot;
    }
    obj = func_800B81C0(func_8009E30C(0x84));
    if (obj != 0) {
        func_800BA768(obj, id);
        slot->b = obj;
        arg0->count++;
        return slot;
    }
    slot->a--;
    return NULL;
}
