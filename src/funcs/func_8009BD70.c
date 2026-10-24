/* cflags: -O2 */
#include "common.h"

#define VA_ARG(ap, T) (((T *)(ap = (char *)((__alignof__(T) > 4 ? ((s32)ap + 7) & -8 : ((s32)ap + 3) & -4) + ((sizeof(T) + 3) & -4))))[-1])

typedef struct {
    u8 pad0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    s32 i24;
    s32 i28;
} Item;

typedef struct {
    u8 pad0[0x10];
    u8 used;
    u8 pad11[3];
    s32 unk14;
    s32 count;
    Item items[8];
    u8 pad[0x17C - 0x1C - 8 * 0x2C];
} Slot;

typedef struct {
    u8 pad0[0x240];
    Slot slots[8];
    u8 pad[0xE20 - 0x240 - 8 * 0x17C];
    u16 unkE20;
} Mgr;

void func_800057E4(void *, char *);

s32 func_8009BD70(Mgr *arg0, char *name, ...) {
    char *ap;
    s32 found;
    s32 i;
    Slot *s;
    Item *e;
    char *n;
    s32 c;

    ap = (char *)(&name + 1);
    found = -1;
    for (i = 0; i < 8; i++) {
        s = &arg0->slots[i];
        if (s->used == 0) {
            found = i;
            break;
        }
    }
    if (found != -1) {
    s->used = 1;
    func_800057E4(s, name);
    s->unk14 = 0;
    s->count = 0;
    while (1) {
        c = s->count;
        if (c >= 8) break;
        n = VA_ARG(ap, char *);
        if (n == NULL) break;
        e = &s->items[c];
        s->count = c + 1;
        func_800057E4(e, n);
        e->f14 = VA_ARG(ap, double);
        e->f18 = VA_ARG(ap, double);
        e->f1C = VA_ARG(ap, double);
        e->f20 = VA_ARG(ap, double);
        e->i28 = VA_ARG(ap, s32);
        e->i24 = VA_ARG(ap, u8);
        e->f10 = e->f1C;
    }
    arg0->unkE20++;
    return found;
    }
    return -1;
}
