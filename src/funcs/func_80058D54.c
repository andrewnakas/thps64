#include "common.h"

typedef struct { s32 x, y, z; } V3i;
typedef struct { s32 w[8]; } M8;

extern V3i func_80043264(void);
extern s32 func_80022E54(void *, V3i *);
extern void func_80022598(s16 *, M8 *);
extern void func_80022FCC(void *, M8 *);
extern void func_80042C70(void);
extern void func_8004356C(V3i *);
extern void func_80043590(void *);
extern void func_8005BED8(void *);
extern V3i D_800D6FCC;

void func_80058D54(u8 *arg0) {
    V3i v;
    M8 m;
    s16 ang[3];
    V3i t;
    s32 r;
    void *p;
    V3i *z;
    s32 k;

    func_80043590(arg0 + 0x8D0);
    z = &D_800D6FCC;
    func_8004356C(z);
    p = arg0 + 0x8E8;
    func_80042C70();
    t = func_80043264();
    {
        s32 a = t.x, b = t.y, c = t.z;
        v.x = a;
        v.y = b;
        v.z = c;
    }
    r = func_80022E54(p, &v);
    if (r > 41) {
        ang[1] = 0;
        ang[0] = 0;
        k = 11;
        goto set;
    }
    if (r < -41) {
        ang[1] = 0;
        ang[0] = 0;
        k = 0xFF5;
set:
        ang[2] = k;
        func_80022598(ang, &m);
        func_80022FCC(arg0 + 0x884, &m);
    } else {
        func_80022E54(p, z);
    }
    func_8005BED8(arg0);
}
