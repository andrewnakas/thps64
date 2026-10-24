/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec800A6DFC;

typedef struct {
    u8 pad0[0x68];
    void *unk68;
    void *unk6C;
    u8 pad70[0x10];
    u8 unk80;
} Obj800A6DFC;

extern void func_80001BE8(void *, void *);
extern void func_8009C8EC(void *, void *);
extern void func_8009D8B4(void *, Vec800A6DFC *);

void func_800A6DFC(Obj800A6DFC *arg0, s32 arg1, void *arg2) {
    Vec800A6DFC v;

    if (arg0->unk80 != 0) {
        func_80001BE8(arg2, arg0->unk6C);
    } else {
        func_8009C8EC(arg2, arg0->unk68);
    }
    if (arg1 == 0) {
        Vec800A6DFC *p = &v;
        p->x = 1.0f;
        p->y = 1.0f;
        p->z = 1.0f;
        func_8009D8B4(arg2, p);
    }
}
