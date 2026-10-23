#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

void func_800433E4(V3 *);
void func_80043288(void);
void func_80043264(V3 *);
void func_800233B8(s32);

void func_800474C8(V3 *a) {
    V3 t;

    t.x = a->x >> 12;
    t.y = a->y >> 12;
    t.z = a->z >> 12;
    func_800433E4(&t);
    func_80043288();
    func_80043264(&t);
    func_800233B8(t.x + t.y + t.z);
}
