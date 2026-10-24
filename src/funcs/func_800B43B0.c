#include "common.h"
typedef struct { s32 pad0; f32 x; f32 y; u16 cur; u16 prev; f32 o[2]; f32 pad18; } Ent800FC580;
extern Ent800FC580 D_800FC580[];
void func_800B43B0(s32 i, u16 v, f32 x, f32 y) {
    Ent800FC580 *e = &D_800FC580[i];
    u16 c = e->cur;
    f32 ox = e->x;
    f32 oy = e->y;
    e->x = x;
    e->y = y;
    e->cur = v;
    e->prev = c;
    { f32 *p = e->o; p[1] = ox; } e->o[1] = oy;
}
